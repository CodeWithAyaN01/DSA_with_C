#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    int **array;

    // Input the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Dynamically allocate memory for the array of pointers (for rows)
    array = (int **)malloc(rows * sizeof(int *));
    
    // Dynamically allocate memory for each row (for columns)
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
    }



    // Input elements into the 2D array
    printf("Enter the elements of the 2D array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element at [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    // Print the 2D array
    printf("The 2D array is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(array[i]);  // Free each row
    }
    free(array);  // Free the array of pointers

    return 0;
}
