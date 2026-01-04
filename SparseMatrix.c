#include <stdio.h>

#define MAX_TERMS 100 // Alabileceğimiz maksimum non-zero eleman sayısı

void convertToSparse(int rows, int cols, int matrix[rows][cols]) {
    int sparseMatrix[MAX_TERMS][3];
   
    sparseMatrix[0][0] = rows;
    sparseMatrix[0][1] = cols;
    
    int k = 1; 
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[k][0] = i;      // Hangi satırda?
                sparseMatrix[k][1] = j;      // Hangi sütunda?
                sparseMatrix[k][2] = matrix[i][j]; // Değer ne?
                k++;
            }
        }
    }
    
    sparseMatrix[0][2] = k - 1;

    printf("\nOrijinal Matris:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nSparse Matris (Triplet Representation):\n");
    printf("Row\tCol\tValue\n");
    printf("---\t---\t-----\n");
    
    for (int i = 0; i < k; i++) {
        if (i == 0) {
            printf("%d\t%d\t%d  <-- Metadata (Rows, Cols, Non-Zero Count)\n", 
                   sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
            printf("---\t---\t-----\n");
        } else {
            printf("%d\t%d\t%d\n", 
                   sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
        }
    }
    
    int normalSize = rows * cols * sizeof(int);
    int sparseSize = k * 3 * sizeof(int);
    
    printf("\n--- Bellek Analizi ---\n");
    printf("Normal Matris: %d byte\n", normalSize);
    printf("Sparse Matris: %d byte\n", sparseSize);
    
    if (sparseSize < normalSize)
        printf("SONUC: Bellek tasarrufu saglandi!\n");
    else
        printf("SONUC: Bu matris yeterince seyrek degil, tasarruf saglanamadi.\n");
}

int main() {
    int matrix[5][6] = {
        {0, 0, 0, 0, 9, 0},
        {0, 8, 0, 0, 0, 0},
        {4, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 5},
        {0, 0, 2, 0, 0, 0}
    };

    convertToSparse(5, 6, matrix);

    return 0;
}
