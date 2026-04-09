// Last updated: 09/04/2026, 17:33:41
1int romanToInt(char* s) {
2    int number = 0;
3    int x = 0;
4    int len = strlen(s);
5
6    while (x < len) {
7        if (s[x] == 'I'){
8            if(s[x + 1] == 'V'){
9                number += 4; 
10                x += 2; 
11            }
12            else if(s[x + 1] == 'X'){
13                number += 9; 
14                x += 2; 
15            }
16            else{
17                number += 1; 
18                x++; 
19            }
20        } 
21
22        else if (s[x] == 'X'){
23            if(s[x + 1] == 'L'){
24                number += 40; 
25                x += 2; 
26            }
27            else if (s[x + 1] == 'C'){
28                number += 90; 
29                x += 2; 
30            }
31            else{
32                number += 10; 
33                x++; 
34            }
35
36        }else if (s[x] == 'C') {
37            if(s[x + 1] == 'D'){
38                number += 400; 
39                x += 2;
40            }
41            else if(s[x + 1] == 'M'){
42                number += 900; 
43                x += 2;
44            }
45            else { 
46                number += 100; 
47                x++; 
48            }
49        } 
50
51        else if(s[x] == 'V'){
52            number += 5; x++; 
53        }
54        else if(s[x] == 'L'){ 
55            number += 50; x++; 
56        }
57        else if(s[x] == 'D'){
58            number += 500; x++; 
59        }
60        else if(s[x] == 'M'){
61             number += 1000; x++;
62        }
63    }
64
65    return number;
66}