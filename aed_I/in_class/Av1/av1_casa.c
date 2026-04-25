#include <stdio.h>
#include <stdlib.h>



int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize);

int main() {
    int linhas = 3, cols = 2, returnSize;
    int* mat[3];
    int l1[] = {1, 2};
    int l2[] = {3, 4};
    int l3[] = {5, 6};    
    int colSizes[] = {2, 2, 2};
    
    mat[0] = l1; mat[1] = l2; mat[2] = l3;
    int* result = findDiagonalOrder(mat, linhas, colSizes, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d, ", result[i]);
    }

    free(result);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int m = matSize, n = matColSize[0];
    *returnSize = m * n;
    int* result = (int*)malloc((*returnSize) * sizeof(int));

    int l = 0, c = 0;

    for(int i = 0; i < *returnSize; i++){
        result[i]= mat[l][c];  

        if((l + c) % 2 == 0){ //cima direita
            if(c == n - 1){
                l++;
            }else if(l == 0){ 
                c++;
            }else{
                l--;
                c++;
            } 
        }else{   // baixo esquerda
            if(l == m - 1){
                c++;
            }else if(c == 0){
                l++;
            }else{
                c--;
                l++;
            }

        }
    }


    return result;
}
