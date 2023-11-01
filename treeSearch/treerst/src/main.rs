use std::collections::BTreeMap;
use std::io::{self, Write};

struct Node {
    age: i32,
    score_m: i32,
    score_f: i32,
}

fn main() {
    let mut num_st = String::new();
    let mut i = 0;
    let mut tree: BTreeMap<String, Node> = BTreeMap::new();

    print!("학생의 수를 입력 : ");
    io::stdout().flush().expect("Failed to flush");
    io::stdin().read_line(&mut num_st).expect("Failed to read input");
    let num_st: i32 = num_st.trim().parse().expect("Invalid input");

    while i < num_st {
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read input");
        let input_parts: Vec<&str> = input.trim().split_whitespace().collect();

        if input_parts.len() == 4 {
            let name = input_parts[0].to_string();
            let age: i32 = input_parts[1].parse().expect("Invalid input");
            let score_m: i32 = input_parts[2].parse().expect("Invalid input");
            let score_f: i32 = input_parts[3].parse().expect("Invalid input");

            if let Some(existing) = tree.get(&name) {
                if existing.age == age && existing.score_m == score_m && existing.score_f == score_f {
                    println!("\"{}\"님이 트리에 이미 존재합니다.", name);
                }
            } else {
                tree.insert(name.clone(), Node {
                    age,
                    score_m,
                    score_f,
                });
                println!("\"{}\"님이 트리에 추가되었습니다.", name);
                i += 1;
            }
        }
    }

    println!("이름    나이 중간성적 기말성적");
    for (name, node) in &tree {
        println!(
            "{:<10} {:<4} {:<8} {:<8}",
            name, node.age, node.score_m, node.score_f
        );
    }
}

