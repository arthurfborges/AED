#include <stdbool.h>

int mySqrt(int x) {
long long int resposta = 0;
long long int mid;
long long int right = x;
long long int left = 1;



while(left <= right){
    // starting from left, move half the distsnce
    mid = left + (right-left)/2;

    if(mid * mid == x){
        return mid;
    }

    if(mid * mid < x){
        resposta = mid;
        left = mid + 1;
    }else{
        right = mid -1;
    }
}

    return resposta;
}  