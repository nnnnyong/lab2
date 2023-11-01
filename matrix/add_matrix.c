#include <stdio.h>
#include <stdlib.h>

int **allocate_matrix(int rows, int cols){
	int **matrix = (int **)malloc(sizeof(int*) * rows);
        for (int i = 0; i < rows; i++)
                matrix[i] = (int *)malloc(sizeof(int) * cols);

	return matrix;
}
void init_matrix(int **matrix, int rows, int cols){
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			scanf("%d", &matrix[i][j]);
}
void print_matrix(int **matrix, int rows, int cols){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			printf("%d ", matrix[i][j]);
			if (j == cols - 1)
				printf("\n");
		}
	}
}

int main(){
	int rows, cols;
	int **first_matrix, **second_matrix, **sum;

	printf("enter size of matrix : ");
	scanf("%d %d", &rows, &cols);


	// allocate matrix dynamically
 	first_matrix = allocate_matrix(rows, cols);
	second_matrix = allocate_matrix(rows, cols);
	sum = allocate_matrix(rows, cols);

	printf("\nenter first matrix\n");
	init_matrix(first_matrix, rows, cols);

	printf("\nenter second matrix\n");
	init_matrix(second_matrix, rows, cols);

	
	// add two matrix
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			sum[i][j] = first_matrix[i][j] + second_matrix[i][j];
		
	printf("\nfirst matrix is \n");
	print_matrix(first_matrix, rows, cols);

	printf("\nsecond matrix is \n");
	print_matrix(second_matrix, rows, cols);

	printf("\nsum of two matrix is \n");
	print_matrix(sum, rows, cols);	

	free(first_matrix);
	free(second_matrix);
	free(sum);

}
