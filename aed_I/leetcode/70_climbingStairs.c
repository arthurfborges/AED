int climbStairs(int n) {
    if(n <= 3){return n;}

    int first = 1;
    int second = 1;
    int current = 1;

    for(int i =0; i<n -1 ; i++){
        current = first + second;
        first = second;
        second = current;
    }
    return second;
}