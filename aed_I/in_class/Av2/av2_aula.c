/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//recorde testecases: 77/223
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* output = (int*)malloc(numsSize * sizeof(int));
    if (!output){
        printf("erro no malloc");
        exit(1);
    } 
    int x = 0;
    

    for(int i = 0; i < numsSize; i++){
            output[i] = -1; // nao achou
            x = i + 1; 
        while(x  < numsSize){ 
            if(nums[i] < nums[x]){
                output[i] = nums[x];
                break;
            }
            
            x++;

            if( x > numsSize){ // volta p o inicio e vai ate o indice inicial
                x=0;

                while(x < i){ // problema sempre no ultimo, erro neste loop talvez
                    if(nums[i] < nums[x]){
                        output[i] = nums[x];
                        break;
                    }
                    x++;
                }
            }
        }
    }
    return output;
}
// fila circular

// loopar até achar o primeiro maior, se acha maior add a um vetor de maiores, 
// se loopar todo e nao achar  maior, retorna -1, returnSize = numSize

// se chega no fim o vetor ou seja i > numsSize, volta p o inicio e vai ate i
