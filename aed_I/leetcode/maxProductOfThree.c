#include <stdio.h>
#include <stdlib.h>

int maximumProduct(int* nums, int numsSize);

int main (){
    int numeros[3] = {1000, 1000, 1000}, tamNums = 3;

    int x = maximumProduct(numeros, tamNums);

    printf("aqui: %d", x);

}

int compareInt(const void *p1, const void *p2){
    return (*(int*)p1 - *(int*)p2);
}

int compareInt(const void *p1, const void *p2){
    return (*(int*)p1 - *(int*)p2);
}

int maximumProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compareInt);

    if(nums[numsSize-1] * nums[numsSize - 2] * nums[numsSize - 3] > nums[0] * nums[1] * nums[numsSize-1]){
        return nums[numsSize-1] * nums[numsSize - 2] * nums[numsSize - 3];
    }else{
        return nums[0] * nums[1] * nums[numsSize-1];
    }

}
