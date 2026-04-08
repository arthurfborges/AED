// Last updated: 08/04/2026, 10:31:39
1#include <stdlib.h>
2
3bool isPalindrome(int x) {
4
5    if(x<0 || (x % 10 == 0 && x != 0)){
6        return false;
7    }
8
9    char backToFront[11] = {0}, number[11] = {0}, buf;
10    int up=0;
11
12    sprintf(number, "%d",x );
13
14    for(int down =9; down >= 0 ; down--){
15        if(number[down]){
16            backToFront[up] = number[down];
17            up++;
18        }
19    }
20        printf("test %s", backToFront);
21        
22    if(strcmp(number,backToFront)== 0){
23        return true;
24    }else{
25
26        return false;
27    }
28}
29