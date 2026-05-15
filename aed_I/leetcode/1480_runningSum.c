#include <stdio.h>
#include <stdlib.h>


int* runningSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    for(int x = 1; x<(numsSize ) ; x++){
        nums[x] = nums[x] + nums[x-1];
    }
    
    return nums;
}

int main(){
    int case1[] = {1,2,3,4}, size = 4, Rsize;
    
    int *a = runningSum(case1, size, &Rsize);
    for(int x = 0; x< Rsize; x++){
        printf("%d, ", a[x]);
    }

}