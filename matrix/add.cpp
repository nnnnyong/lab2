#include <iostream>
#include <vector>

std::vector<std::vector<int>> allocate_matrix(int rows, int cols) {
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));
    return matrix;
}

void init_matrix(std::vector<std::vector<int>>& matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

void print_matrix(const std::vector<std::vector<int>>& matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    int rows, cols;
    
    std::cout << "enter size of matrix : ";
    std::cin >> rows >> cols;

    std::vector<std::vector<int>> first_matrix = allocate_matrix(rows, cols);
    std::vector<std::vector<int>> second_matrix = allocate_matrix(rows, cols);
    std::vector<std::vector<int>> sum = allocate_matrix(rows, cols);

    std::cout << "enter first matrix\n";
    init_matrix(first_matrix, rows, cols);

    std::cout << "enter second matrix\n";
    init_matrix(second_matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = first_matrix[i][j] + second_matrix[i][j];
        }
    }

    std::cout << "\nfirst matrix is \n";
    print_matrix(first_matrix, rows, cols);

    std::cout << "\nsecond matrix is \n";
    print_matrix(second_matrix, rows, cols);

    std::cout << "\nsum of two matrix is \n";
    print_matrix(sum, rows, cols);

    return 0;
}

