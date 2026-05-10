#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STATIC_STR_SIZE 350
#define INITIAL_SIZE (3*sizeof(int) + STATIC_STR_SIZE)
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// ajustar mensagens de err9o de malloc e realloc antes de entr3egar o trabalho


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



// organizaçao pBuffer
// sizeof(int) [int*select] - fixo no inicio de pBuffer, usado para seleção no menu
// sizeof(int) [int* numCont] - fixo no inicio de pBuffer, contem o numero de pessoas na agenda
// 350 bytes  [char* temp] - fixo no inicio de pBuffer, temp para o scanf 



// ordem dos dados variaveis por pessoa

// [int* age][int* Sname][char* name][int* Semail][char* email]


// Sname - tamanho da string name
// Semail - tamanho da string email

// ponteiros do tipo char* sao autoexplicativos





void add    (void **pbuffer);
void remova (void **pbuffer);            
void search (void **pbuffer);
void list   (void **pbuffer);

void *pbuffer;
int* numCont;
int* usedBytes;
char* temp;
int main() {
    
    pbuffer = malloc(INITIAL_SIZE);
    int* select = ( int* )pbuffer;

    numCont = (int*)pbuffer + 1;
    *numCont = 0;
    
    usedBytes = (int*)pbuffer + 2;
    (*usedBytes) = 0;
    
    temp = (char*)(pbuffer) + 3* sizeof(int); // ?????????????

    do{
        printf("escolha uma opção: \n1- Adicionar Pessoa (Nome, Idade, email)\n2- Remover Pessoa\n3- Buscar Pessoa\n4- Listar todos\n5- Sair");
        scanf("%d", select);
        getchar();
        
        switch (*select)
        {
            case 1:
                add(&pbuffer);
                    (*numCont)++;
                break;
            case 2:
                remova(&pbuffer); 
                    (*numCont)--;           
                break;
            case 3:
                search(&pbuffer);
                break;
            case 4:
                list(&pbuffer);
                break;
            case 5:
                printf("saindo...");
                free(pbuffer);
                break;
            default:
                printf("numero que digitou nao esta nas opçoes de menu, tente novamente");
            break;
        }

    }while(*select != 5);
        

}



void add  (void **pbuffer){

    
    //IDADE

    *pbuffer = realloc((*pbuffer), INITIAL_SIZE + (*usedBytes) + sizeof(int));
    temp = (char*)(*pbuffer) + 3*sizeof(int); // pra nao perder o lugar
    int* age = (int*)((char*)(*pbuffer) + INITIAL_SIZE + (*usedBytes)) ;

    
    printf("digite a idade do contato que deseja adicionar");
    scanf("%d", age);
    getchar();
    
    (*usedBytes) += sizeof(int);
    // NOME

    printf("digite o nome do contato que deseja adicionar");
        fgets(temp, 349, stdin);

        *pbuffer = realloc((*pbuffer), INITIAL_SIZE + (*usedBytes) + sizeof(int));
        temp = (char*)(*pbuffer) + 3*sizeof(int);
        int* Sname = (int*)((char*)(*pbuffer) + INITIAL_SIZE + (*usedBytes));

        *Sname = strlen(temp) + 1;

        (*usedBytes) += sizeof(int);

        *pbuffer = realloc((*pbuffer), INITIAL_SIZE + (*usedBytes) + (*Sname));
        temp = (char*)(*pbuffer) + 3*sizeof(int);
        char* name = (char*)(*pbuffer) + INITIAL_SIZE + (*usedBytes);
 
        strcpy(name, temp);
       
        (*usedBytes) += *Sname;

    // EMAIL

    printf("digite o email do contato que deseja adicionar");
        fgets(temp, 349, stdin);

        *pbuffer = realloc((*pbuffer),  INITIAL_SIZE + (*usedBytes) + sizeof(int));
        temp = (char*)(*pbuffer) + 3*sizeof(int);
        int* Semail = (int*)((char*)(*pbuffer) + INITIAL_SIZE + (*usedBytes));

        *Semail = strlen(temp) +1;

        (*usedBytes) += sizeof(int);

        *pbuffer = realloc((*pbuffer),  INITIAL_SIZE + (*usedBytes) + (*Semail));
        temp = (char*)(*pbuffer) + 3*sizeof(int);
        char* email = (char*)(*pbuffer) + INITIAL_SIZE + (*usedBytes);
        
        strcpy(email, temp);
        
        (*usedBytes) += *Semail;
}

void remova (void **pbuffer){
    // busca
    printf("digite o nome do contato que deseja deletar:");
        fgets(temp, 349, stdin);

    char*totalSearched = (char*)(*pbuffer) + INITIAL_SIZE;
    char*final= (char*)(*pbuffer) + INITIAL_SIZE + (*usedBytes);
    char *current = (char*)(*pbuffer);


    while(totalSearched < final){


        int* age =  (int*)totalSearched;
        int* Sname = (int*)((char*)totalSearched + sizeof(int));
        int* Semail = (int*)((char*)totalSearched + 2*sizeof(int) + *Sname);
        char* name = (char*)totalSearched + 2*sizeof(int);
        char* email = (char*)totalSearched +  3*sizeof(int) + *Sname ;
        
        // processo de remoção
        if(strcmp(temp, name) == 0){
            
            memmove(
                totalSearched, 
                totalSearched + (3 * sizeof(int) + *Sname + *Semail),
                final - (totalSearched + 3 * sizeof(int) + *Sname + *Semail)
            );
            
            (*usedBytes) -= (3*sizeof(int) + *Sname + *Semail);
            (*numCont)--;

            printf("removido com sucesso!");
            return;  
        }
        
        totalSearched = totalSearched +  3*sizeof(int) + *Sname + *Semail;
        
    }

    printf("Contato nao encontrado.");

}           

void search (void **pbuffer){
    printf("digite o nome que deseja procurar:");
        fgets(temp, 349, stdin);

    char*current = (char*)(*pbuffer) + INITIAL_SIZE;
    char*final= (char*)(*pbuffer) + INITIAL_SIZE + (*usedBytes);

    while(current < final){
        int* age =  (int*)current;
        int* Sname = (int*)((char*)current + sizeof(int));
        int* Semail = (int*)((char*)current + 2*sizeof(int) + *Sname);
        char* name = (char*)current + 2*sizeof(int);
        char* email = (char*)current +  3*sizeof(int) + *Sname ;


        if(strcmp(temp, name) == 0){
            printf("@@@@@  BUSCA  @@@@@\n");
            printf("Nome: %s \n", name);
            printf("Idade: %d \n", *age);
            printf("E-mail: %s \n", email);
            printf("@@@@@@@@@@@@@@@@@@@\n");
            return;  
        }

        current = current +  3*sizeof(int) + *Sname + *Semail;
        
    }

    printf("Contato nao encontrado.");
    

}

void list (void **pbuffer){
    char*current = (char*)(*pbuffer) + INITIAL_SIZE;
    char*final= (char*)(*pbuffer) + INITIAL_SIZE + (*usedBytes);

    printf("##################\n");
    while(current < final){
        int* age =  (int*)current;
        int* Sname = (int*)((char*)current + sizeof(int));
        char* name = (char*)current + 2*sizeof(int);
        int* Semail = (int*)((char*)current + 2*sizeof(int) + *Sname);
        char* email = (char*)current +  3*sizeof(int) + *Sname ;

        current = current +  3*sizeof(int) + *Sname + *Semail;
        
        printf("Nome: %s \n", name);
        printf("Idade: %d \n", *age);
        printf("E-mail: %s \n", email);
        printf("##################\n");
        
        
    }


}












