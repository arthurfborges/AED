bool isValid(char* s) {
    char pilha[strlen(s)];
    int topo =0;

    if(s[0] == '}' || s[0] == ']' || s[0] == ')'){return false;}

    for(int i = 0; i < strlen(s) ; i++){

        if(s[i] == '{' || s[i] == '[' || s[i] == '('){
            //push 
            pilha[topo] = s[i];
            topo++; printf("aqui");
        } else {
            if(topo != 0 && ((pilha[topo - 1] == '{' && s[i] == '}') || 
                            (pilha[topo - 1] == '[' && s[i] == ']') || 
                            (pilha[topo - 1] == '(' && s[i] == ')') 
                            ) 
            ) {
                // pop

                pilha[topo -1] = '\0';
                topo--; printf(" e aqui");
            } else {return false;}
        }
    }

    if( topo == 0 ) { return true; } else { printf("%s", pilha); return false;}
}
//{[()]}