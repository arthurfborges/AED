// Last updated: 16/04/2026, 14:44:55
1void reverseString(char* s, int sSize) {
2    char temp;
3    
4    for(int i=0; i<sSize/2; i++){
5        temp = s[i];
6        
7        s[i] = s[sSize - i - 1];
8        s[sSize - i - 1] = temp;
9    }
10    
11}