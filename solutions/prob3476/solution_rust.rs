/*
 * Baekjoon Online Judge #3476
 * https://www.acmicpc.net/problem/3476
 */

use std::{
    collections::{HashMap, HashSet},
    io::{stdin, stdout, BufWriter, Write},
};

fn check_plural(noun: &str) -> bool {
    ["I", "you"].contains(&noun)
}

fn main() {
    let mut out = BufWriter::new(stdout());

    let mut t_input_str = String::new();
    stdin().read_line(&mut t_input_str).ok();
    let t_input = t_input_str.trim().parse::<i32>().unwrap();
    for t in 1..=t_input {
        writeln!(out, "Dialogue #{}:", t).ok();
        let mut subject_to_pred = HashMap::<_, Vec<_>>::new();
        let mut pred_to_subject = HashMap::new();
        let mut pred_counter = 0;
        let mut contradicted = false;

        loop {
            let mut dialogue_input = String::new();
            stdin().read_line(&mut dialogue_input).ok();
            dialogue_input = dialogue_input.trim().to_owned();

            if dialogue_input.ends_with("!") {
                writeln!(out, "{}\n", dialogue_input).ok();
                break;
            }

            let punctuations: &[_] = &['.', '?'];
            let tokens = dialogue_input
                .trim_end_matches(punctuations)
                .split(' ')
                .collect::<Vec<_>>();
            if dialogue_input.ends_with(".") {
                if contradicted {
                    continue;
                }
                let subject = tokens[0];
                let is_negative =
                    (subject == "nobody") != ["don't", "doesn't"].contains(&tokens[1]);
                let mut verb = if is_negative && subject != "nobody" {
                    tokens[2].to_owned()
                } else {
                    tokens[1].to_owned()
                };
                let object = match tokens[1] {
                    "don't" | "doesn't" => tokens[3..].join(" "),
                    _ => {
                        verb = verb.strip_suffix("s").unwrap_or(&verb).to_owned();
                        tokens[2..].join(" ")
                    }
                };
                if ["nobody", "everybody"].contains(&subject) {
                    if subject_to_pred
                        .values()
                        .any(|v: &Vec<(_, String, String, bool)>| {
                            v.iter()
                                .find(|&(_, v, o, x)| {
                                    *v == verb && *o == object && *x != is_negative
                                })
                                .is_some()
                        })
                    {
                        contradicted = true;
                        continue;
                    }
                }
                if let Some(pred_entry) = subject_to_pred.get(&subject.to_owned()) {
                    let existing_pred = pred_entry
                        .iter()
                        .filter(|&(_, v, o, _)| *v == verb && *o == object)
                        .collect::<Vec<_>>();
                    if existing_pred
                        .into_iter()
                        .find(|&&(_, _, _, x)| x != is_negative)
                        .is_some()
                    {
                        contradicted = true;
                        continue;
                    }
                };
                if let Some(everybody_entry) = subject_to_pred.get(&"everybody".to_owned()) {
                    let existing_pred = everybody_entry
                        .iter()
                        .filter(|&(_, v, o, _)| *v == verb && *o == object)
                        .collect::<Vec<_>>();
                    if existing_pred
                        .into_iter()
                        .find(|&&(_, _, _, x)| x != is_negative)
                        .is_some()
                    {
                        contradicted = true;
                        continue;
                    }
                };
                subject_to_pred
                    .entry(subject.replace("nobody", "everybody").to_owned())
                    .or_insert(vec![])
                    .push((pred_counter, verb.clone(), object.clone(), is_negative));
                pred_to_subject
                    .entry((verb, object))
                    .or_insert(vec![])
                    .push((
                        subject.replace("nobody", "everybody").to_owned(),
                        is_negative,
                    ));
                pred_counter += 1;
            } else {
                writeln!(out, "{}", dialogue_input).ok();
                if contradicted {
                    writeln!(out, "I am abroad.\n").ok();
                    continue;
                }
                match tokens[0] {
                    "does" | "do" => {
                        let subject = tokens[1];
                        let verb = tokens[2].to_owned();
                        let object = tokens[3..].join(" ");
                        let mut preds = subject_to_pred
                            .entry(subject.to_owned())
                            .or_default()
                            .clone();
                        preds.extend(
                            subject_to_pred
                                .entry("everybody".to_owned())
                                .or_default()
                                .clone(),
                        );
                        let is_plural = check_plural(subject);
                        let matched_pred_negativity = preds
                            .iter()
                            .filter(|&(_, v, o, _)| *v == verb && *o == object)
                            .map(|(_, _, _, x)| *x)
                            .collect::<HashSet<_>>();
                        if matched_pred_negativity.is_empty() {
                            writeln!(out, "maybe.\n").ok();
                            continue;
                        } else if matched_pred_negativity.contains(&true) {
                            write!(
                                out,
                                "no, {} {} {}",
                                match subject {
                                    "I" => "you",
                                    "you" => "I",
                                    x => x,
                                },
                                if is_plural { "don't" } else { "doesn't" },
                                verb
                            )
                            .ok();
                        } else {
                            write!(
                                out,
                                "yes, {} {}",
                                match subject {
                                    "I" => "you",
                                    "you" => "I",
                                    x => x,
                                },
                                if is_plural { verb } else { verb + "s" }
                            )
                            .ok();
                        }
                        if object.is_empty() {
                            writeln!(out, ".").ok();
                        } else {
                            writeln!(out, " {}.", object).ok();
                        }
                    }
                    "who" => {
                        let verb = tokens[1].strip_suffix("s").unwrap().to_owned();
                        let object = tokens[2..].join(" ");
                        if let Some(subjects) = pred_to_subject.get(&(verb.clone(), object.clone()))
                        {
                            let subject_names = subjects
                                .iter()
                                .filter(|&&(_, x)| !x)
                                .map(|(x, _)| x.clone())
                                .collect::<Vec<_>>();
                            if subjects.contains(&("everybody".to_owned(), true)) {
                                write!(out, "nobody {}", verb + "s").ok();
                            } else if subjects
                                .iter()
                                .find(|&x| *x == ("everybody".to_owned(), false))
                                .is_some()
                            {
                                write!(out, "everybody {}", verb + "s").ok();
                            } else if subject_names.is_empty() {
                                writeln!(out, "I don't know.\n").ok();
                                continue;
                            } else if subject_names.len() == 1 {
                                let real_subject = match &*subject_names[0].clone() {
                                    "I" => "you".to_owned(),
                                    "you" => "I".to_owned(),
                                    x => x.to_owned(),
                                };
                                write!(
                                    out,
                                    "{} {}",
                                    real_subject,
                                    if check_plural(&*real_subject) {
                                        verb
                                    } else {
                                        verb + "s"
                                    },
                                )
                                .ok();
                            } else {
                                let last_idx = subject_names.len() - 1;
                                for (i, subject) in subject_names.iter().enumerate() {
                                    let real_subject = match &*subject.clone() {
                                        "I" => "you".to_owned(),
                                        "you" => "I".to_owned(),
                                        x => x.to_owned(),
                                    };
                                    if i == 0 {
                                        write!(out, "{}", real_subject.clone()).ok();
                                    } else if i == last_idx {
                                        write!(out, " and {} ", real_subject.clone()).ok();
                                    } else {
                                        write!(out, ", {}", real_subject.clone()).ok();
                                    }
                                }
                                write!(out, "{}", verb).ok();
                            }
                            if object.is_empty() {
                                writeln!(out, ".").ok();
                            } else {
                                writeln!(out, " {}.", object).ok();
                            }
                        } else {
                            writeln!(out, "I don't know.").ok();
                        };
                    }
                    "what" => {
                        let subject = tokens[2];
                        let is_plural = check_plural(subject);
                        let mut preds = subject_to_pred
                            .entry(subject.to_owned())
                            .or_default()
                            .clone();
                        if subject != "everybody" {
                            preds.extend(
                                subject_to_pred
                                    .entry("everybody".to_owned())
                                    .or_default()
                                    .clone(),
                            );
                        }
                        preds.sort();
                        let mut statements = vec![];
                        let mut is_statement_negative = HashMap::new();
                        for pred in preds {
                            let (_, verb, object, is_negative) = pred;
                            is_statement_negative
                                .insert((verb.clone(), object.clone()), is_negative);
                            let mut statement_arr = vec![];
                            if is_negative {
                                statement_arr.push(if is_plural {
                                    "don't".to_owned()
                                } else {
                                    "doesn't".to_owned()
                                });
                                statement_arr.push(verb);
                            } else {
                                statement_arr.push(if is_plural { verb } else { verb + "s" });
                            }
                            if !object.is_empty() {
                                statement_arr.push(object);
                            }
                            statements.push(statement_arr.join(" "));
                        }
                        let mut used = HashSet::new();
                        let mut statements_unique = vec![];
                        for s in statements {
                            if used.contains(&s.clone()) {
                                continue;
                            }
                            used.insert(s.clone());
                            statements_unique.push(s);
                        }
                        if statements_unique.is_empty() {
                            writeln!(out, "I don't know.\n").ok();
                            continue;
                        }
                        let last_idx = statements_unique.len() - 1;
                        write!(
                            out,
                            "{}",
                            match subject {
                                "I" => "you",
                                "you" => "I",
                                x => x,
                            }
                        )
                        .ok();
                        if last_idx == 0 {
                            writeln!(out, " {}.\n", statements_unique[0]).ok();
                            continue;
                        }
                        for (i, s) in statements_unique.iter().enumerate() {
                            if i == 0 {
                                write!(out, " {}", s).ok();
                            } else if i == last_idx {
                                writeln!(out, ", and {}.", s).ok();
                            } else {
                                write!(out, ", {}", s).ok();
                            }
                        }
                    }
                    _ => panic!(),
                }
                writeln!(out, "").ok();
            }
        }
    }
}
