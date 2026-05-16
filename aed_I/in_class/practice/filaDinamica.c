#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox;
}No;

typedef struct{
    No *inicio;
    No *fim;
}Fila;

/* IMPLEMENTAR */
void inicializar(Fila *f){
    f->inicio = NULL;
    f->fim = NULL;
}

/* IMPLEMENTAR */
int empty(Fila *f){
    if (f->inicio == NULL ){
        return 1;
    }
    return 0;
}

/* IMPLEMENTAR */
void push(Fila *f, int valor){

    
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (f->inicio == NULL){
        f->inicio = novo;
        f->fim = novo;
        return;
    }

    f->fim->prox = novo;
    f->fim = novo;
    return;


    
}

/* IMPLEMENTAR */
int pop(Fila *f){

    if(f->inicio == NULL){
        printf(" A fila esta vazia nao da pra remover");
        return -1;
    }

    No *aux;
    aux = f->inicio;
    int resultado;
    resultado = aux->valor;
    f->inicio = f->inicio->prox;

      if(f->inicio == NULL){
        f->fim = NULL;
    }

    free(aux);
    return resultado;

}

/* IMPLEMENTAR */
void listar(Fila *f){

    No *aux = f->inicio;

    while(aux != NULL){
        printf("%d\n",aux->valor);
        aux = aux->prox;

    }
    return;

}

int main(){

    Fila f;

    int opcao;
    int valor;

    inicializar(&f);

    do{

        printf("\n===== FILA DINAMICA =====\n");
        printf("1 - Enqueue\n");
        printf("2 - Dequeue\n");
        printf("3 - Mostrar fila\n");
        printf("4 - Verificar se vazia\n");
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

                listar(&f);

                break;

            case 4:

                if(empty(&f))
                    printf("Fila vazia!\n");
                else
                    printf("Fila nao esta vazia!\n");

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