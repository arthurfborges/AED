#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

typedef struct No {
    Pessoa pessoa;
    struct No *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

/* FUNÇÕES */
void inicializar(Pilha *p);

void push(Pilha *p, Pessoa pessoa);

Pessoa pop(Pilha *p);

void listar(Pilha *p);

int main() {

    Pilha p;

    Pessoa pessoa;
    Pessoa removido;
    p.topo = NULL;

    int opcao;

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

                printf("Nome: ");
                fgets(pessoa.nome, 50, stdin);

                printf("Idade: ");
                scanf("%d", &pessoa.idade);

                push(&p, pessoa);

                break;

            case 2:

                removido = desempilhar(&p);

                printf("\nPessoa removida:\n");
                printf("Nome: %s", removido.nome);
                printf("Idade: %d\n", removido.idade);

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
void inicializar(Pilha *p){
    p->topo = -1;
}

void push(Pilha *p, Pessoa pessoa){
    No *novo=malloc(sizeof(No));
    novo->prox = NULL;
    novo->pessoa.idade = pessoa.idade;
    strcpy(novo->pessoa.nome,pessoa.nome);

    novo->prox = p->topo;
    p->topo = novo;

}
Pessoa pop(Pilha *p){ //pop bota o topo pro proximo e retorna o que foi removido
    Pessoa vazio = {"", 0};
    if (p->topo == NULL){
        return vazio;
    }
    No *tmp = p->topo;
    Pessoa removido = tmp->pessoa;
    p->topo = tmp->prox;
    free(tmp);
    return removido;

}
void imprimirPilha(Pilha *p){
    No *aux;
    aux = p->topo;

    while(aux!= NULL){
        printf("%s \n %d\n",aux->pessoa.nome,aux->pessoa.idade);
        aux=aux->prox;
    }
}