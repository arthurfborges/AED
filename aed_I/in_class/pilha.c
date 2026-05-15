// PILHA
#include<stdbool.h>
#include <stdio.h>

const int MAX = 10;

typedef struct  {
    int ra;
    char nome[50];
}Aluno;

typedef struct  {
    Aluno alunos[MAX];
    int topo;
    int base;
    int limite;
}Pilha; 

int main (){

}

void Reset(Pilha *pilha) {
    pilha->topo = 0;
    pilha->base = 0;
    pilha->limite = MAX;
} 

bool Empty(Pilha *pilha) {
    return pilha->topo == 0;
}

bool Full(Pilha *pilha) {
    return pilha->topo == MAX;
}

bool PUSH(Pilha *pilha, Aluno *item) {
    if (!Full(pilha)) {
        pilha->alunos[pilha->topo] = *item;
        pilha->topo++;
        return true;
    } else {
        return false;
    }
}

void POP(Pilha *pilha, Aluno *aluno)
{
    if (pilha->topo == 0){return;}
    
    pilha->topo--;
    *aluno = pilha->alunos[pilha->topo];
}
void Listar(Pilha *pilha){
    if(Empty(pilha)){
        return;
    } else{
        

        for(int i = pilha->base; i< pilha->topo; i++ ){
            printf("Aluno %d: %s", i +1,pilha->alunos[i].nome);
        }
        
    }
}