use std::io;

fn allocate_matrix(rows: usize, cols: usize) -> Vec<Vec<i32>> {
    vec![vec![0; cols]; rows]
}

fn init_matrix(matrix: &mut Vec<Vec<i32>>, rows: usize, cols: usize) {
    for i in 0..rows {
        for j in 0..cols {
            let mut input = String::new();
            io::stdin().read_line(&mut input).expect("Failed to read input");
            let value: i32 = input.trim().parse().expect("Invalid input");
            matrix[i][j] = value;
        }
    }
}

fn print_matrix(matrix: &Vec<Vec<i32>>, rows: usize, cols: usize) {
    for i in 0..rows {
        for j in 0..cols {
            print!("{} ", matrix[i][j]);
            if j == cols - 1 {
                println!();
            }
        }
    }
}

fn main() {
    let mut rows = String::new();
    let mut cols = String::new();

    println!("Enter the size of the matrix :");
    io::stdin().read_line(&mut rows).expect("Failed to read input");
    io::stdin().read_line(&mut cols).expect("Failed to read input");

    let rows: usize = rows.trim().parse().expect("Invalid input");
    let cols: usize = cols.trim().parse().expect("Invalid input");

    let mut first_matrix = allocate_matrix(rows, cols);
    let mut second_matrix = allocate_matrix(rows, cols);
    let mut sum = allocate_matrix(rows, cols);

    println!("Enter the first matrix:");
    init_matrix(&mut first_matrix, rows, cols);

    println!("Enter the second matrix:");
    init_matrix(&mut second_matrix, rows, cols);

    // add two matrix
    for i in 0..rows {
        for j in 0..cols {
            sum[i][j] = first_matrix[i][j] + second_matrix[i][j];
        }
    }

    println!("First matrix is:");
    print_matrix(&first_matrix, rows, cols);

    println!("Second matrix is:");
    print_matrix(&second_matrix, rows, cols);

    println!("Sum of two matrices is:");
    print_matrix(&sum, rows, cols);
}

