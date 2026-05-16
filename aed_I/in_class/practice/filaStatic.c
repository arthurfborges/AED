#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct{
    int itens[TAM];
    int inicio;
    int fim;
}Fila;

/* IMPLEMENTAR */
void inicializar(Fila *f){
    f->inicio = 0;
    f->fim = -1;
}

/* IMPLEMENTAR */
int empty(Fila *f){
    if(f->inicio > f->fim){
        return 0;
    }
    return 1;
}

/* IMPLEMENTAR */
int full(Fila *f){
    if (f->fim== TAM - 1){
        return 1;
    }
    return 0;
}

/* IMPLEMENTAR */
void push(Fila *f, int valor){
    if (f->fim == TAM - 1){
        printf(" a fila está lotada");
    }
    for( int x = f->inicio; x<=f->fim + 1; x++){
        if ( x == f->fim + 1){
            f->itens[x] = valor;
        }
    }
    f->fim++;
}

/* IMPLEMENTAR */
int push(Fila *f){
    if (f->inicio>f->fim){
        printf("a fila esta vazia");
        return -1;
    }
   int removido = f->itens[f->inicio];
   f->inicio++;
   return removido;
}

/* IMPLEMENTAR */
void listar(Fila *f){

     if(empty(f)){
        printf("Fila vazia!\n");
        return;
    }

    for (int x = f->inicio; x<= f->fim; x++ ){
        printf("%d\n",f->itens[x]);
    }
}

int main(){

    Fila f;
    int opcao;
    int valor;

    inicializar(&f);

    do{

        printf("\n===== FILA =====\n");
        printf("1 - Enqueue\n");
        printf("2 - Dequeue\n");
        printf("3 - Mostrar fila\n");
        printf("4 - Verificar se vazia\n");
        printf("5 - Verificar se cheia\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao){

            case 1:

                printf("Valor: ");
                scanf("%d", &valor);

                push(&f, valor);

                break;

            case 2:

                valor = pop(&f);

                if(valor != -1)
                    printf("Removido: %d\n", valor);

                break;

            case 3:

                listar(&f);

                break;

            case 4:

                if(empty(&f))
                    printf("Fila vazia!\n");
                else
                    printf("Fila nao esta vazia!\n");

                break;

            case 5:

                if(full(&f))
                    printf("Fila cheia!\n");
                else
                    printf("Fila nao esta cheia!\n");

                break;

            case 0:

                printf("Encerrando...\n");

                break;

            default:

                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}