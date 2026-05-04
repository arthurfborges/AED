// 961. N-Repeated Element in Size 2N Array

int repeatedNTimes(int* nums, int numsSize) {
    int reps = numsSize/2;
    int count;
    int i;

    for( i=0; count!= reps; i++){
        count =0;
        for(int x =0; x<numsSize; x++){
            if(nums[i] == nums[x]){
                count ++;
                if(count == reps){
                    return nums[i];
                }
            }
        }
    }
    return nums[i];
}