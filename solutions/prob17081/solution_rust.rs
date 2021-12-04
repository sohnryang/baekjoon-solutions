/*
 * Baekjoon Online Judge #17081
 * https://www.acmicpc.net/problem/17081
 */

use std::{
    cmp::{max, min},
    collections::{HashMap, HashSet},
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

#[derive(Debug, Clone, Copy)]
enum BoxType {
    Weapon(i32),
    Armor(i32),
    Item(ItemType),
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
enum ItemType {
    HR,
    RE,
    CO,
    EX,
    DX,
    HU,
    CU,
}

struct Player {
    level: i32,
    hitpoint: i32,
    max_hitpoint: i32,
    attack: i32,
    defense: i32,
    experience: i32,
    items: HashSet<ItemType>,
    weapon_attack: i32,
    armor_defense: i32,
    last_attacked_by: Option<String>,
}
impl Player {
    fn take_damage(&mut self, damage: i32) {
        self.hitpoint -= damage;
    }

    fn is_dead(&self) -> bool {
        self.hitpoint <= 0
    }

    fn step_on_spike_trap(&mut self) {
        if self.items.contains(&ItemType::DX) {
            self.take_damage(1);
        } else {
            self.take_damage(5);
        }
        self.last_attacked_by = Some("SPIKE TRAP".to_owned());
    }

    fn acquire_item(&mut self, item: ItemType) {
        if self.items.len() == 4 {
            return;
        }
        self.items.insert(item);
    }

    fn step_on_box(&mut self, stepped_box: BoxType) {
        match stepped_box {
            BoxType::Weapon(attack) => self.weapon_attack = attack,
            BoxType::Armor(defense) => self.armor_defense = defense,
            BoxType::Item(item) => self.acquire_item(item),
        }
    }

    fn get_effective_attack(&self, monster: &Monster, first_attack: bool) -> i32 {
        max(
            1,
            (self.attack + self.weapon_attack)
                * (if first_attack && self.items.contains(&ItemType::CO) {
                    if self.items.contains(&ItemType::DX) {
                        3
                    } else {
                        2
                    }
                } else {
                    1
                })
                - monster.defense,
        )
    }

    fn get_effective_defense(&self) -> i32 {
        self.defense + self.armor_defense
    }

    fn fight_monster(&mut self, monster: &mut Monster) {
        let mut player_turn = true;
        let mut first_attack = true;
        let mut first_attacked = true;
        let mut no_hit = true;
        if monster.is_boss && self.items.contains(&ItemType::HU) {
            self.hitpoint = self.max_hitpoint;
        }
        while !self.is_dead() && !monster.is_dead() {
            if player_turn {
                monster.take_damage(self.get_effective_attack(monster, first_attack));
                if first_attack {
                    first_attack = false;
                }
            } else {
                let damage = monster.get_effective_attack(self, first_attacked);
                self.take_damage(damage);
                if damage != 0 && no_hit {
                    self.last_attacked_by = Some(monster.name.clone());
                    no_hit = false;
                }
                if first_attacked {
                    first_attacked = false;
                }
            }
            player_turn = !player_turn;
        }
        if !self.is_dead() {
            if self.items.contains(&ItemType::EX) {
                self.experience += (monster.experience as f64 * 1.2) as i32;
            } else {
                self.experience += monster.experience;
            }
            if self.items.contains(&ItemType::HR) {
                self.hitpoint = min(self.hitpoint + 3, self.max_hitpoint);
            }
            if self.experience >= self.level * 5 {
                self.level += 1;
                self.experience = 0;
                self.max_hitpoint += 5;
                self.hitpoint = self.max_hitpoint;
                self.attack += 2;
                self.defense += 2;
            }
        }
    }
}

#[derive(Debug, Clone)]
struct Monster {
    name: String,
    attack: i32,
    defense: i32,
    hitpoint: i32,
    max_hitpoint: i32,
    experience: i32,
    is_boss: bool,
}
impl Monster {
    fn get_effective_attack(&self, player: &Player, first_attack: bool) -> i32 {
        if first_attack && self.is_boss && player.items.contains(&ItemType::HU) {
            0
        } else {
            max(1, self.attack - player.get_effective_defense())
        }
    }

    fn take_damage(&mut self, damage: i32) {
        self.hitpoint -= damage;
    }

    fn is_dead(&self) -> bool {
        self.hitpoint <= 0
    }
}

#[derive(PartialEq, Eq)]
enum GameStatus {
    InProgress,
    Defeat,
    Win,
}

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());

    let n_input: i32 = scan.next();
    let m_input: i32 = scan.next();
    let mut grid_input: Vec<Vec<char>> = vec![];
    let mut player_pos = (0, 0);
    let mut boss_pos = (0, 0);
    let mut monster_count = 0;
    let mut box_count = 0;
    for y in 0..n_input {
        let line: Vec<char> = scan.next::<String>().chars().collect();
        monster_count += line.iter().filter(|&&x| x == '&').count();
        box_count += line.iter().filter(|&&x| x == 'B').count();
        if line.contains(&'@') {
            player_pos = (y, line.iter().position(|&x| x == '@').unwrap() as i32);
        }
        if line.contains(&'M') {
            boss_pos = (y, line.iter().position(|&x| x == 'M').unwrap() as i32);
            monster_count += 1;
        }
        grid_input.push(
            line.clone()
                .iter()
                .map(|&x| if x == '@' { '.' } else { x })
                .collect(),
        );
    }
    let cmd_input: String = scan.next();
    let mut monster_table = HashMap::new();
    for _ in 0..monster_count {
        let y: i32 = scan.next();
        let x: i32 = scan.next();
        let pos = (y - 1, x - 1);
        let is_boss = pos == boss_pos;
        let name: String = scan.next();
        let attack: i32 = scan.next();
        let defense: i32 = scan.next();
        let hitpoint: i32 = scan.next();
        let experience: i32 = scan.next();
        let monster = Monster {
            name,
            attack,
            defense,
            hitpoint,
            max_hitpoint: hitpoint,
            experience,
            is_boss,
        };
        monster_table.insert(pos, monster);
    }
    let mut box_table = HashMap::new();
    for _ in 0..box_count {
        let y: i32 = scan.next();
        let x: i32 = scan.next();
        let pos = (y - 1, x - 1);
        let box_type: char = scan.next();
        if box_type == 'O' {
            let item = match &*scan.next::<String>() {
                "HR" => ItemType::HR,
                "RE" => ItemType::RE,
                "CO" => ItemType::CO,
                "EX" => ItemType::EX,
                "DX" => ItemType::DX,
                "HU" => ItemType::HU,
                "CU" => ItemType::CU,
                _ => panic!(),
            };
            box_table.insert(pos, BoxType::Item(item));
        } else {
            let param: i32 = scan.next();
            box_table.insert(
                pos,
                match box_type {
                    'W' => BoxType::Weapon(param),
                    'A' => BoxType::Armor(param),
                    _ => panic!(),
                },
            );
        }
    }

    let mut turns_passed = 0;
    let mut player = Player {
        level: 1,
        hitpoint: 20,
        max_hitpoint: 20,
        attack: 2,
        defense: 2,
        experience: 0,
        items: HashSet::new(),
        weapon_attack: 0,
        armor_defense: 0,
        last_attacked_by: None,
    };
    let mut current_pos = player_pos;
    let mut game_status = GameStatus::InProgress;
    for cmd in cmd_input.chars() {
        turns_passed += 1;
        let new_pos = match cmd {
            'U' => (current_pos.0 - 1, current_pos.1),
            'D' => (current_pos.0 + 1, current_pos.1),
            'L' => (current_pos.0, current_pos.1 - 1),
            'R' => (current_pos.0, current_pos.1 + 1),
            _ => panic!(),
        };
        if 0 <= new_pos.0
            && new_pos.0 < n_input
            && 0 <= new_pos.1
            && new_pos.1 < m_input
            && grid_input[new_pos.0 as usize][new_pos.1 as usize] != '#'
        {
            current_pos = new_pos;
        }
        let current_cell = grid_input[current_pos.0 as usize][current_pos.1 as usize];
        match current_cell {
            '^' => player.step_on_spike_trap(),
            'B' => {
                player.step_on_box(box_table[&current_pos]);
                grid_input[current_pos.0 as usize][current_pos.1 as usize] = '.';
            }
            'M' | '&' => {
                player.fight_monster(monster_table.get_mut(&current_pos).unwrap());
                if !player.is_dead() {
                    grid_input[current_pos.0 as usize][current_pos.1 as usize] = '.';
                    if current_pos == boss_pos {
                        game_status = GameStatus::Win;
                        break;
                    }
                }
            }
            '.' => (),
            _ => panic!(),
        }
        if player.is_dead() {
            if player.items.contains(&ItemType::RE) {
                player.items.remove(&ItemType::RE);
                player.hitpoint = player.max_hitpoint;
                if *player.last_attacked_by.as_ref().unwrap() != "SPIKE TRAP".to_owned() {
                    let fought_monster = monster_table.get_mut(&current_pos).unwrap();
                    fought_monster.hitpoint = fought_monster.max_hitpoint;
                }
                current_pos = player_pos;
                continue;
            }
            game_status = GameStatus::Defeat;
            break;
        }
    }

    if game_status != GameStatus::Defeat {
        grid_input[current_pos.0 as usize][current_pos.1 as usize] = '@';
    }
    for line in grid_input {
        writeln!(out, "{}", line.iter().collect::<String>()).ok();
    }
    writeln!(out, "Passed Turns : {}", turns_passed).ok();
    writeln!(out, "LV : {}", player.level).ok();
    writeln!(
        out,
        "HP : {}/{}",
        max(0, player.hitpoint),
        player.max_hitpoint
    )
    .ok();
    writeln!(out, "ATT : {}+{}", player.attack, player.weapon_attack).ok();
    writeln!(out, "DEF : {}+{}", player.defense, player.armor_defense).ok();
    writeln!(out, "EXP : {}/{}", player.experience, player.level * 5).ok();
    match game_status {
        GameStatus::InProgress => writeln!(out, "Press any key to continue.").ok(),
        GameStatus::Defeat => writeln!(
            out,
            "YOU HAVE BEEN KILLED BY {}..",
            player.last_attacked_by.unwrap()
        )
        .ok(),
        GameStatus::Win => writeln!(out, "YOU WIN!").ok(),
    };
}
