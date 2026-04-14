#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int romanToInt(char* s);

int main(){
    char test[] = "LVIII";
    int a = romanToInt(test);
    printf("Solution: %d \n", a);
}

int romanToInt(char* s) {
    int number = 0;
    int x = 0;
    int len = strlen(s);

    while (x < len) {
        if (s[x] == 'I'){
            if(s[x + 1] == 'V'){
                number += 4; 
                x += 2; 
            }
            else if(s[x + 1] == 'X'){
                number += 9; 
                x += 2; 
            }
            else{
                number += 1; 
                x++; 
            }
        } 

        else if (s[x] == 'X'){
            if(s[x + 1] == 'L'){
                number += 40; 
                x += 2; 
            }
            else if (s[x + 1] == 'C'){
                number += 90; 
                x += 2; 
            }
            else{
                number += 10; 
                x++; 
            }

        }else if (s[x] == 'C') {
            if(s[x + 1] == 'D'){
                number += 400; 
                x += 2;
            }
            else if(s[x + 1] == 'M'){
                number += 900; 
                x += 2;
            }
            else { 
                number += 100; 
                x++; 
            }
        } 

        else if(s[x] == 'V'){
            number += 5; x++; 
        }
        else if(s[x] == 'L'){ 
            number += 50; x++; 
        }
        else if(s[x] == 'D'){
            number += 500; x++; 
        }
        else if(s[x] == 'M'){
             number += 1000; x++;
        }
    }

    return number;
}