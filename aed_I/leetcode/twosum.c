int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = malloc(sizeof(int)*2);        

        for(int y=0;y<numsSize ;y++){
            for(int x= y+1;x<numsSize;x++){
                if(nums[x] == target-nums[y]){
                    result[0] = x;
                    result[1] = y;
                    *returnSize = 2;
                    return result;
                }
            }
        }
    return 0;
};