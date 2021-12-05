/*
 * Baekjoon Online Judge #20541
 * https://www.acmicpc.net/problem/20541
 */

use std::{
    collections::{BTreeMap, BTreeSet, HashMap},
    io::{stdin, stdout, BufWriter, Write},
};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>,
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

#[derive(Default, Clone, Debug)]
struct Album {
    name: String,
    id: i32,
    parent_id: Option<i32>,
    subalbum_ids: BTreeMap<String, i32>,
    photos: BTreeSet<String>,
}

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());

    let n_input: i32 = scan.next();
    let root_album = Album {
        name: "album".to_owned(),
        id: 0,
        ..Default::default()
    };
    let mut album_table = HashMap::new();
    album_table.insert(0, root_album);
    let mut selected_album_id = 0;
    let mut album_counter = 1;
    for _ in 0..n_input {
        // writeln!(out, "selected_album_id = {}", selected_album_id).ok();
        // writeln!(out, "album_table = {:?}", album_table).ok();

        let command: String = scan.next();
        if command == "mkalb".to_owned() {
            let name: String = scan.next();
            if album_table[&selected_album_id]
                .subalbum_ids
                .contains_key(&name)
            {
                writeln!(out, "duplicated album name").ok();
                continue;
            }
            album_table
                .get_mut(&selected_album_id)
                .unwrap()
                .subalbum_ids
                .insert(name.clone(), album_counter);
            let album = Album {
                name,
                parent_id: Some(selected_album_id),
                id: album_counter,
                ..Default::default()
            };
            album_table.insert(album_counter, album);
            album_counter += 1;
        } else if command == "rmalb".to_owned() {
            let arg: String = scan.next();
            let mut ids = match arg.parse() {
                Ok(-1) => match album_table
                    .get_mut(&selected_album_id)
                    .unwrap()
                    .subalbum_ids
                    .values()
                    .cloned()
                    .next()
                {
                    Some(x) => {
                        let album_name = album_table[&x].name.clone();
                        album_table
                            .get_mut(&selected_album_id)
                            .unwrap()
                            .subalbum_ids
                            .remove(&album_name);
                        vec![x]
                    }
                    None => vec![],
                },
                Ok(0) => {
                    let removed = album_table
                        .get_mut(&selected_album_id)
                        .unwrap()
                        .subalbum_ids
                        .values()
                        .map(|&x| x)
                        .collect::<Vec<i32>>();
                    album_table
                        .get_mut(&selected_album_id)
                        .unwrap()
                        .subalbum_ids
                        .clear();
                    removed
                }
                Ok(1) => match album_table
                    .get_mut(&selected_album_id)
                    .unwrap()
                    .subalbum_ids
                    .values()
                    .rev()
                    .cloned()
                    .next()
                {
                    Some(x) => {
                        let album_name = album_table[&x].name.clone();
                        album_table
                            .get_mut(&selected_album_id)
                            .unwrap()
                            .subalbum_ids
                            .remove(&album_name);
                        vec![x]
                    }
                    None => vec![],
                },
                Ok(_) => panic!(),
                Err(_) => match album_table
                    .get_mut(&selected_album_id)
                    .unwrap()
                    .subalbum_ids
                    .remove(&arg)
                {
                    Some(x) => vec![x],
                    None => vec![],
                },
            };
            let mut deleted_albums = 0;
            let mut deleted_photos = 0;
            while !ids.is_empty() {
                let id_to_delete = ids.pop().unwrap();
                let album_to_delete = album_table[&id_to_delete].clone();
                deleted_albums += 1;
                deleted_photos += album_to_delete.photos.len() as i32;
                ids.extend(album_to_delete.subalbum_ids.values());
                album_table.remove(&id_to_delete);
            }
            writeln!(out, "{} {}", deleted_albums, deleted_photos).ok();
        } else if command == "insert".to_owned() {
            let photo_name: String = scan.next();
            if album_table
                .get_mut(&selected_album_id)
                .unwrap()
                .photos
                .contains(&photo_name)
            {
                writeln!(out, "duplicated photo name").ok();
                continue;
            }
            album_table
                .get_mut(&selected_album_id)
                .unwrap()
                .photos
                .insert(photo_name);
        } else if command == "delete".to_owned() {
            let arg: String = scan.next();
            let result = match arg.parse() {
                Ok(-1) => match album_table
                    .get_mut(&selected_album_id)
                    .unwrap()
                    .photos
                    .iter()
                    .cloned()
                    .next()
                {
                    Some(x) => album_table
                        .get_mut(&selected_album_id)
                        .unwrap()
                        .photos
                        .remove(&x) as i32,
                    None => 0,
                },
                Ok(0) => {
                    let photo_count = album_table
                        .get_mut(&selected_album_id)
                        .unwrap()
                        .photos
                        .len();
                    album_table
                        .get_mut(&selected_album_id)
                        .unwrap()
                        .photos
                        .clear();
                    photo_count as i32
                }
                Ok(1) => match album_table
                    .get_mut(&selected_album_id)
                    .unwrap()
                    .photos
                    .iter()
                    .rev()
                    .cloned()
                    .next()
                {
                    Some(x) => album_table
                        .get_mut(&selected_album_id)
                        .unwrap()
                        .photos
                        .remove(&x) as i32,
                    None => 0,
                },
                Ok(_) => panic!(),
                Err(_) => album_table
                    .get_mut(&selected_album_id)
                    .unwrap()
                    .photos
                    .remove(&arg) as i32,
            };
            writeln!(out, "{}", result).ok();
        } else if command == "ca".to_owned() {
            let arg: String = scan.next();
            if arg == "..".to_owned() {
                selected_album_id = album_table[&selected_album_id].parent_id.unwrap_or(0);
            } else if arg == "/".to_owned() {
                selected_album_id = 0;
            } else {
                selected_album_id = *album_table[&selected_album_id]
                    .subalbum_ids
                    .get(&arg)
                    .unwrap_or(&selected_album_id)
            }
            writeln!(out, "{}", album_table[&selected_album_id].name).ok();
        }
    }
}
