#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu();
void adicionar(char **nomes, int *tamanho);
void remover(char **nomes, int *tamanho);
void listar(char *nomes);

int main(){

    char *nomes = NULL;
    int tamanho = 0;
    int op;

    do{
        op = menu();

        switch( op ){

            case 1:
                adicionar(&nomes, &tamanho);
                break;

            case 2:
                remover(&nomes, &tamanho);
                break;

            case 3:
                listar(nomes);
                break;

        }

    }while( op != 4 );

    free( nomes );

    return 0;
}

int menu(){

    int select;

    printf( "\n1) Adicionar nome" );
    printf( "\n2) Remover nome" );
    printf( "\n3) Listar" );
    printf( "\n4) Sair\n" );

    scanf( "%d",&select );
    getchar();

    return select;
}

void adicionar( char **nomes, int *tamanho ){

    char temp[100];

    printf( "Digite o nome: " );
    fgets( temp,100,stdin );

    int len = strlen( temp );

    *nomes = realloc( *nomes, *tamanho + len + 1 );

    memcpy( *nomes + *tamanho, temp, len );

    *tamanho += len;

    ( *nomes )[ *tamanho ] = '\0';
}

void remover(char **nomes, int *tamanho){

    char temp[100];
    char *pos;

    printf("Nome para remover: ");
    fgets(temp,100,stdin);

    pos = strstr(*nomes,temp);

    if(!pos){
        printf("Nome nao encontrado\n");
        return;

    }   

    int len = strlen(temp);

    temp[len+1]= '\n';

    memmove(pos, pos + len, *tamanho - ( *nomes - pos ) - len);

    *tamanho -= len;

    *nomes = realloc(*nomes, *tamanho + 1);
}

void listar(char *nomes){

    if(!nomes){
        printf("Lista vazia\n");
        return;
    }

    printf("\nNomes:\n%s",nomes);
}