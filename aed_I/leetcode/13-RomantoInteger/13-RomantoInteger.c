// Last updated: 09/04/2026, 17:27:52
1int romanToInt(char* s) {
2    int number = 0;
3    int x = 0;
4    int len = strlen(s);
5
6    while (x < len) {
7        // Case: I
8        if (s[x] == 'I') {
9            if (s[x + 1] == 'V') { number += 4; x += 2; }
10            else if (s[x + 1] == 'X') { number += 9; x += 2; }
11            else { number += 1; x++; }
12        } 
13        // Case: X
14        else if (s[x] == 'X') {
15            if (s[x + 1] == 'L') { number += 40; x += 2; }
16            else if (s[x + 1] == 'C') { number += 90; x += 2; }
17            else { number += 10; x++; }
18        } 
19        // Case: C
20        else if (s[x] == 'C') {
21            if (s[x + 1] == 'D') { number += 400; x += 2; }
22            else if (s[x + 1] == 'M') { number += 900; x += 2; }
23            else { number += 100; x++; }
24        } 
25        // Single Character Cases
26        else if (s[x] == 'V') { number += 5; x++; }
27        else if (s[x] == 'L') { number += 50; x++; }
28        else if (s[x] == 'D') { number += 500; x++; }
29        else if (s[x] == 'M') { number += 1000; x++; }
30        else {
31            x++; // Fallback for unexpected characters
32        }
33    }
34
35    return number;
36}