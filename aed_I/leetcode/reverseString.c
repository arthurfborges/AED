#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char* s, int sSize);

int main () {
    char string[] = "hello";
    int tam = 6;

    reverseString(string, tam);

    printf("string: %s", string);

}


void reverseString(char* s, int sSize) {
    char temp;
    
    for(int i=0; i<sSize/2; i++){
        temp = s[i];
        
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = temp;
    }
    
}
    