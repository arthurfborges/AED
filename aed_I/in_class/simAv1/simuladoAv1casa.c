#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool lemonadeChange ( int* bills, int billsSize );
/*
====================
LemonadeChange
 Given an integer array bills where bills[i] is the bill the ith 
 customer pays, return true if you can provide every customer
 with the correct change, or false otherwise.
 Example:
    Input: bills = [5,5,5,10,20]
    Output: true
====================
*/

int main ( ) {
    int case1[] = {5,5,5,10,20}, size1 = 5;
        lemonadeChange(case1, size1);

    int case2[] = {5,5,10,10,20}, size2 = 5;
        lemonadeChange(case2, size2);

    int case3[] = {5,5,10,20}, size3 = 5;
        lemonadeChange(case3, size3);
}

bool lemonadeChange ( int* bills, int billsSize ) { 
    // de acordo com o doc de doom, deveria mudar o nome da função pra ficar com a 
    // primeira letra maiúscula, mas ela assim nao funciona no leet.
    // tambem poderia ter usado const na variavel int* bills -> const int* bills
    // mas nao mudei, pois tambem nao funcionaria no leet.   
    
    int fives = 0, tens = 0;

    for ( int i = 0 ; i < billsSize ; i++ ) {
        if ( bills[i] == 5 ) {
            fives++;
        }

        if ( bills[i] == 10 ) {
            if ( fives < 1 ) {
                return false;
            } else {
                fives--;
                tens++;
            }
        }

        if ( bills[i] == 20 ) {
            if ( tens < 1 ) {
                if ( fives < 3 ) {
                    return false;
                } else {
                    fives -= 3;
                }
            }else if ( fives < 1 ) { // tenho 10 mas nao tenho 5
                return false;
            } else { // tenho 10 e tenho 5
                tens--;
                fives--;
            }
        }
    }
    return true;
}
