bool isPalindrome(int x) {
    int numero, inverso=0;
    bool zeroum;
    numero= x;
    
    do{
        numero = numero/10;
        inverso = inverso + numero *10;
    }while(numero !=0);


    if(inverso = x && x <! inverso){
        zeroum = true;
    } else {
        zeroum = false;
    }
    
    return zeroum;
    
}