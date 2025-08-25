#include <stdio.h>
#include <stdlib.h>

/*
 * EJERCICIO:
 * Se quiere definir un programa que, dada una matriz cuadrada con valores enteros,
 * devuelva una permutación de los valores de modo que:
 *
 * 1. Cada renglón esté ordenado de menor a mayor.
 * 2. Todos los elementos del segundo renglón (de arriba hacia abajo)
 *    sean mayores que los del primero, los del tercero mayores que los del segundo, etc.
 *
 * Regla importante:
 * - Cuando se ordenan los elementos de un renglón, por cada elemento de dicho renglón,
 *   se mueven también todos los elementos que se encuentran por debajo en la misma columna.
 *
 * INSTRUCCIONES:
 * - Completa la función sort_matrix() que debe modificar la matriz en su lugar.
 * - Puedes escribir funciones auxiliares si lo deseas.
 * - NO cambies la firma de sort_matrix().
 */

void sort_matrix(int **matrix, int n) {
    // TODO: Implementa aquí el algoritmo.
    // Necesitarás el método de inserción,
    // pero recuerda aplicar la regla de mover toda la columna.
    
    int i, j, r, k, key;
    // r -> índice del renglón actual que estamos ordenando
    // i -> índice de la columna en el algoritmo de inserción
    // j -> posición que retrocede en el insertion sort
    // k -> índice auxiliar para recorrer filas hacia abajo al intercambiar columnas
    // key -> variable auxiliar para hacer intercambios de elementos
    
    for (r = 0; r < n; r++) { // Recorremos cada renglón de la matriz
        for (i = 1; i < n; i++) {
            j = i;

            /* Algoritmo de inserción:
            Mientras el elemento de la izquierda sea mayor que el actual,
            intercambiamos columnas completas. */
            while (j > 0 && matrix[r][j-1] > matrix[r][j]) {
                // Intercambio de columnas completas desde fila r hacia abajo
                for (k = r; k < n; k++) {
                    key = matrix[k][j];
                    matrix[k][j] = matrix[k][j-1];
                    matrix[k][j-1] = key;
                }
                j--; // Retrocedemos una posición para seguir comparando
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
