/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//recorde testecases: 77/223
int* nextGreaterElements ( int* nums, int numsSize, int* returnSize ) {
    *returnSize = numsSize;
    int* output = ( int* ) malloc ( numsSize * sizeof ( int ) );    
    if ( !output ) {
        printf ( "erro no malloc" );
        exit ( 1 );
    }

    int x = 0;
    int check;
    

    for ( int i = 0; i < numsSize; i++ ) {
        output[i] = -1; // nao achou
        x = i + 1; // pra nao verificar c ele mesmo
        check =0;

        while ( x  < numsSize ) { 
            if ( nums[i] < nums[x] ) {
                output[i] = nums[x];
                check= 1;
                break;
            }   
            x++;
        } // agora percorre todo o array antes de verificar o check, ao inves de verifcar a cada iteraçao de i

        if ( !check ) { // volta p o inicio e vai ate o indice inicial
            x=0;
            while ( x < i ) { 
                if ( nums[i] < nums[x] ) {
                    output[i] = nums[x];
                    break;
                }
                x++;
            }
        }
    }
    return output;
}

