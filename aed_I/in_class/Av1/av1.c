#include <stdio.h>
#include <stdlib.h>



int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize);

int main() {
    int linhas = 3, cols = 3, returnSize;
    int* mat[3];
    int l1[] = {1, 2, 3};
    int l2[] = {4, 5, 6};
    int l3[] = {7, 8, 9};    
    int colSizes[] = {3, 3, 3};
    
    mat[0] = l1; mat[1] = l2; mat[2] = l3;
    int* result = findDiagonalOrder(mat, linhas, colSizes, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d, ", result[i]);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int m = matSize, n = matColSize[0];
    *returnSize = m * n;
    int* result = (int*)malloc((*returnSize) * sizeof(int) + 1);

    int l = 0, c = 0;

    for(int i = 0; i < *returnSize; i++){
        result[i]= mat[l][c];  //ERRO aqui "heap-buffer-overflow located 0 bytes after 12-byte region" pq?

        if(l * c % 2 == 0){ //cima direita
            if(l == 0){
                c++;
            }else if(c == n - 1){ // ultima col
                l++;
            }else{
                l--;
                c++;
            } 
        }else{   // baixo esquerda
            if(c == 0){
                l++;
            }else if(l == m - 1){
                c++;
            }else{
                c--;
                l++;
            }

        }
    }


    return result;
}
