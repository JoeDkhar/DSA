#include <stdio.h>

void row_sum_calculation(int a[10][10], int rows, int cols) {
    printf("\nRow sums:\n");
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += a[i][j];
        }
        printf("Sum of row %d: %d\n", i + 1, sum);
    }
}

void column_sum_calculation(int a[10][10], int rows, int cols) {
    printf("\nColumn sums:\n");
    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += a[i][j];
        }
        printf("Sum of column %d: %d\n", j + 1, sum);
    }
}

void matrix_addition(int a[10][10], int b[10][10], int rows, int cols) {
    int sum[10][10];
    printf("\nMatrix Addition:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = a[i][j] + b[i][j];
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }
}

void matrix_subtraction(int a[10][10], int b[10][10], int rows, int cols) {
    int sub[10][10];
    printf("\nMatrix Subtraction (A - B):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sub[i][j] = a[i][j] - b[i][j];
            printf("%d\t", sub[i][j]);
        }
        printf("\n");
    }
}

void matrix_multiplication(int a[10][10], int b[10][10], int a_rows, int a_cols, int b_rows, int b_cols) {
    if (a_cols != b_rows) {
        printf("\nMatrix multiplication not possible: Columns of A must be equal to rows of B\n");
        return;
    }
    int res[10][10] = {0};
    printf("\nMatrix Multiplication (A * B):\n");
    for (int i = 0; i < a_rows; i++) {
        for (int j = 0; j < b_cols; j++) {
            res[i][j] = 0;
            for (int k = 0; k < a_cols; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
            printf("%d\t", res[i][j]);
        }
        printf("\n");
    }
}

void input_matrix(int matrix[10][10], int rows, int cols) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main() {
    int a[10][10], b[10][10];
    int choice, rows, cols, b_rows, b_cols;

    while (1) {
        printf("\nMATRIX OPERATIONS\n");
        printf("1. Row Sum Calculation\n");
        printf("2. Column Sum Calculation\n");
        printf("3. Matrix Addition\n");
        printf("4. Matrix Subtraction\n");
        printf("5. Matrix Multiplication\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 6) {
            break;
        }

        printf("\nEnter the number of rows and columns for matrix A: ");
        scanf("%d %d", &rows, &cols);
        input_matrix(a, rows, cols);

        switch (choice) {
            case 1:
                row_sum_calculation(a, rows, cols);
                break;

            case 2:
                column_sum_calculation(a, rows, cols);
                break;

            case 3:
                printf("\nEnter the number of rows and columns for matrix B (same size as A for addition): ");
                scanf("%d %d", &b_rows, &b_cols);
                if (b_rows != rows || b_cols != cols) {
                    printf("Error: Matrices must have the same dimensions for addition.\n");
                } else {
                    input_matrix(b, b_rows, b_cols);
                    matrix_addition(a, b, rows, cols);
                }
                break;

            case 4:
                printf("\nEnter the number of rows and columns for matrix B (same size as A for subtraction): ");
                scanf("%d %d", &b_rows, &b_cols);
                if (b_rows != rows || b_cols != cols) {
                    printf("Error: Matrices must have the same dimensions for subtraction.\n");
                } else {
                    input_matrix(b, b_rows, b_cols);
                    matrix_subtraction(a, b, rows, cols);
                }
                break;

            case 5:
                printf("\nEnter the number of rows and columns for matrix B (columns of A must match rows of B): ");
                scanf("%d %d", &b_rows, &b_cols);
                if (cols != b_rows) {
                    printf("Error: Matrix A columns must be equal to Matrix B rows for multiplication.\n");
                } else {
                    input_matrix(b, b_rows, b_cols);
                    matrix_multiplication(a, b, rows, cols, b_rows, b_cols);
                }
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
