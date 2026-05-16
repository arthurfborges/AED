#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct{
    int itens[TAM];
    int inicio;
    int fim;
    int qtd;
}Fila;

/* IMPLEMENTAR */
void inicializar(Fila *f){
    f->qtd = 0;
    f->inicio = 0;
    f->fim = 0;
}

/* IMPLEMENTAR */
int empty(Fila *f){
    if( f->qtd == 0){
        return 1;
    }
    return 0;
}

/* IMPLEMENTAR */
int full(Fila *f){
    if (f->qtd == TAM ){
        return 1;
    }
    return 0;
}

void push(Fila *f, int valor){
    if ( full(f)==1){
        return;
    }
    f->qtd++;
    f->itens[f->fim] = valor;
    f->fim = (f->fim + 1) % TAM;
}

int pop(Fila *f){
        if (empty(f)==1){
            return;
        }
        // tu caminha o inicio
        // o fim nao
        int retorno = f->itens[f->inicio];

        f->inicio = (f->inicio + 1) % TAM;
        f->qtd--;
        return retorno;
}

/* IMPLEMENTAR */
void listar(Fila *f){
    
}

int main(){

    Fila f;

    int opcao;
    int valor;

    inicializar(&f);

    do{

        printf("\n===== FILA CIRCULAR =====\n");
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

                printf("Digite um valor: ");
                scanf("%d", &valor);

                push(&f, valor);

                break;

            case 2:

                valor = pop(&f);

                if(valor != -1)
                    printf("Removido: %d\n", valor);

                break;

            case 3:

                mostrar(&f);

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