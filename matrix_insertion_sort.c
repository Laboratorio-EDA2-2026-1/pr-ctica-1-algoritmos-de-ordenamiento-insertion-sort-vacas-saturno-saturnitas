#include <stdio.h>
#include <stdlib.h>

void swap_columns(int **matrix, int n, int col1, int col2) {
    int i, temp; //Variables auxiliares
    for (i = 0; i < n; i++) {
        temp = matrix[i][col1];
        matrix[i][col1] = matrix[i][col2];
        matrix[i][col2] = temp;
    }
}

void sort_matrix(int **matrix, int n) {
    // Usamos "insertion sort" por columnas
    int fila, j, k;
    for (fila = 0; fila < n; fila++) {
        for (j = 1; j < n; j++) {
            k = j;
            while (k > 0 && matrix[fila][k] < matrix[fila][k-1]) {
                swap_columns(matrix, n, k, k-1);
                k--;
            }
        }
    }
}

int main() {
    int n = 3;
    // Reserva dinámica de la matriz
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // Ejemplo de entrada
    int ejemplo[3][3] = {
        {4, 7, 2},
        {9, 5, 6},
        {8, 1, 3}
    };

    // Copiar ejemplo a la matriz dinámica
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = ejemplo[i][j];
        }
    }

    printf("Matriz original:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Llamada a la función que deben completar
    sort_matrix(matrix, n);

    printf("\nMatriz ordenada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Liberar memoria
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}