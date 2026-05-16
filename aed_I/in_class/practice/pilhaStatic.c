#include <stdio.h>
#include <string.h>

#define TAM 10

typedef struct {
    char dados[TAM];
    int topo;
} Pilha;

/* FUNÇÕES */
void inicializar(Pilha *p){
    p->topo = -1;
}

void push(Pilha *p, char valor){
    if(p->topo== TAM - 1){
        printf("A pilha esta cheia");
        return '\0';
    }
    p->topo++;
    p->dados[p->topo] = valor;
}

char pop(Pilha *p){
    if (p->topo == -1){
        printf(" a pilha esta vazia");
        return;
    }
    char valor = p->dados[p->topo];
    p->topo--;
    return valor;
}

void listar(Pilha *p){
    for( int x = p->topo; x>= 0; x--){
        printf("%c\n",p->dados[x]);
    }
}

int main() {

    Pilha p;

    int opcao;

    char valor;
    char removido;

    inicializar(&p);

    do {

        printf("\n===== PILHA =====\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Imprimir pilha\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        scanf("%d", &opcao);

        getchar();

        switch(opcao) {

            case 1:

                printf("Caractere: ");
                scanf("%c", &valor);

                push(&p, valor);

                getchar();

                break;

            case 2:

                removido = pop(&p);

                printf("Removido: %c\n", removido);

                break;

            case 3:

                listar(&p);

                break;

            case 0:

                printf("Encerrando...\n");

                break;

            default:

                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}