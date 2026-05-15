#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool lemonadeChange(int* bills, int billsSize);

int main(){
}

bool lemonadeChange(int* bills, int billsSize) {
    int fives = 0, twentys = 0, tens = 0;

    for(int i =0; i < billsSize; i++){
        if(bills[i] == 5){
            fives++;
        }

        if(bills[i] == 10){
            if(fives < 1){
                return false;
            }else{
                fives--;
                tens++;
            }
        }

        if(bills[i] == 20){
            if(tens < 1){
                if(fives < 3){
                    return false;
                } else{
                    fives -= 3;
                }
            }else if(fives < 1){ // tenho 10 mas nao tenho 5
                return false;
            }else{ // tenho 10 e tenho 5
                tens--;
                fives--;
            }
        }
    }
    return true;
}
