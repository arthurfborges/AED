#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int daysBetweenDates(char* date1, char* date2);

int main(){
    char data1[] = "2020-01-15" , data2[] = "2019-12-31" ;

    int days = daysBetweenDates(data1, data2);

    printf("dias: %d", days);

}

int daysBetweenDates(char* date1, char* date2) {
    char temp[4];

    // conversao int data 1
    int ano1;
    ano1 = atoi(date1);

    int mes1;
    for(int i = 0; i< 2 ; i++){
        temp[i] = date1[5+i];
    }
    mes1 = atoi(temp);

    int dia1;
    for(int i = 0; i< 2 ; i++){
        temp[i] = date1[8+i];
    }
    dia1 = atoi(temp);



    // conversao int data 2
    int ano2;
    ano2 = atoi(date2);

    int mes2;
    for(int i = 0; i< 2 ; i++){
        temp[i] = date2[5+i];
    }
    mes2 = atoi(temp);

    int dia2;
    for(int i = 0; i< 2 ; i++){
        temp[i] = date2[8+i];
    }
    dia2 = atoi(temp);


    // calculo
    int number, tot1 = 0;

    int difAno = (ano2 - ano1);
    
    ano1 ++; // pra nao contar o proprio ano
    for (int i = 0; i < difAno; i++){

        if((ano1 + i) % 100 ==0){
            if((ano1 + i) % 400 == 0){
                tot1 += 366;
            }
        }else if ((ano1 + i) % 4 == 0){
            tot1 += 366;
        }else{
            tot1 += 365;
        }

    }

    int difMes =    (mes2 - mes1);

    mes1 ++; // pra nao contar o proprio mes
    for(int i = 0; i < difMes; i++){
        if(mes1+ i == 2){
            tot1 += 28;
        }else if(mes1 + i == 4 || mes1 + i == 6 || mes1 + i == 9 || mes1 + i == 11){
                tot1 += 30;
        }else {
            tot1 += 31;
        }
    }

    tot1 += (dia2 - dia1);

    return tot1;
}