// Last updated: 16/04/2026, 09:05:33
1int* runningSum(int* nums, int numsSize, int* returnSize) {
2    *returnSize = numsSize;
3
4    for(int x = 1; x<(numsSize ) ; x++){
5        nums[x] = nums[x] + nums[x-1];
6    }
7    
8    return nums;
9}