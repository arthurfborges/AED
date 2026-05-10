// ordem dos dados fixos no inicio de pbuffer
// [int*select][int* numCont][int* usedBytes][char* temp]
// sizeof(int) [int*select] - fixo no inicio de pBuffer, usado para seleção no menu
// sizeof(int) [int* numCont] - fixo no inicio de pBuffer, contem o numero de pessoas na agenda
// sizeof(int) [int* usedBytes] - fixo no inicio de pbuffer, contem o numero de bytes usados pelo programa
// 350 bytes   [char* temp] - fixo no inicio de pBuffer, temp para o scanf 

// ordem dos dados variaveis por pessoa:
//     [int* age][int* Sname][char* name][int* Semail][char* email]
//     Sname - tamanho da string name
//     Semail - tamanho da string email

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STATIC_STR_SIZE 350
#define INITIAL_SIZE ( 3*sizeof( int ) + STATIC_STR_SIZE )

void Add    ( void **pbuffer );
/*
====================
Add
 a função Add, adiciona novos contatos à agenda, contendo idade, nome e email.
====================
*/

void Remova ( void **pbuffer );
/*
====================
Remova
 a função Remova, remove um contato da agenda, liberando o espaço anteriormente usado
 e move os dados que estao a direita dos dados removidos para a esquerda,
 desta forma a memoria nao tem furos
====================
*/

void Search ( void **pbuffer );
/*
====================
Search
 a função Search, pergunta ao usuario um nome e busca dentro da agenda dados daquele contato.
====================
*/

void List   ( void **pbuffer );
/*
====================
List
 a função List, lista todos os contatos atualmente armazenados dentro da agenda.
====================
*/


void *pbuffer;
int* numCont;
int* usedBytes;
char* temp;
int main(  ) {
    
    pbuffer = malloc( INITIAL_SIZE );
    if ( !pbuffer ) {
        printf ( "erro ao alocar 1" );
        exit ( 1 );
    }
    int* select = ( int* ) pbuffer;

    numCont = ( int* ) pbuffer + 1;
    *numCont = 0;
    
    usedBytes = ( int* ) pbuffer + 2;
    ( *usedBytes ) = 0;
    
    temp = ( char* )( pbuffer ) + 3* sizeof ( int ); 

    do{
        printf ( "escolha uma opção: \n1- Adicionar Pessoa (Nome, Idade, email)\n2- Remover Pessoa\n3- Buscar Pessoa\n4- Listar todos\n5- Sair \n" );
        scanf ( "%d", select );
        getchar (  );
        
        switch ( *select )
        {
            case 1:
                Add ( &pbuffer );
                    ( *numCont )++;
                break;
            case 2:
                Remova ( &pbuffer ); 
                    ( *numCont )--;           
                break;
            case 3:
                Search ( &pbuffer );
                break;
            case 4:
                List ( &pbuffer );
                break;
            case 5:
                printf ( "saindo... \n" );
                free ( pbuffer );
                break;
            default:
                printf ( "numero que digitou nao esta nas opçoes de menu, tente novamente\n" );
            break;
        }
    } while ( *select != 5 );
}

void Add  ( void **pbuffer ){ // complexidade pior caso O(N) - inserção no final de pbuffer

    //IDADE

    *pbuffer = realloc( ( *pbuffer ), INITIAL_SIZE + ( *usedBytes ) + sizeof ( int ) );
        if( !pbuffer ){
            printf ( "erro ao alocar 2" );
            exit ( 1 );
        }
    temp = ( char* )( *pbuffer ) + 3*sizeof( int ); // pra nao perder o lugar, pode apontar para endereço invalido
    int* age = ( int* )( ( char* )( *pbuffer ) + INITIAL_SIZE + ( *usedBytes )) ;
    
    printf ( "Digite a idade do contato que deseja adicionar: \n\t" );
    scanf ( "%d", age );
    getchar (  );
    
    ( *usedBytes ) += sizeof ( int );

    // NOME

    printf ( "Digite o nome do contato que deseja adicionar: \n\t" );
        fgets ( temp, 349, stdin );

        *pbuffer = realloc ( ( *pbuffer ), INITIAL_SIZE + ( *usedBytes ) + sizeof ( int ));
            if( !pbuffer ) {
            printf( "erro ao alocar 3" );
            exit ( 1 );
        }
        temp = ( char* )( *pbuffer ) + 3*sizeof ( int );
        int* Sname = ( int* )( ( char* )( *pbuffer ) + INITIAL_SIZE + ( *usedBytes ) );

        *Sname = strlen ( temp ) + 1;

        ( *usedBytes ) += sizeof ( int );

        *pbuffer = realloc( ( *pbuffer ), INITIAL_SIZE + ( *usedBytes ) + ( *Sname ) );
            if ( !pbuffer ){
            printf ( "erro ao alocar 4" );
            exit ( 1 );
        }
        temp = ( char* )( *pbuffer ) + 3*sizeof ( int );
        char* name = ( char* )( *pbuffer ) + INITIAL_SIZE + ( *usedBytes );
 
        strcpy ( name, temp );
       
        ( *usedBytes ) += *Sname;

    // EMAIL

    printf ( "Digite o email do contato que deseja adicionar:\n\t" );
        fgets( temp, 349, stdin );

        *pbuffer = realloc ( ( *pbuffer ),  INITIAL_SIZE + ( *usedBytes ) + sizeof ( int ) );
            if(!pbuffer){
            printf( "erro ao alocar 5" );
            exit ( 1 );
        }
        temp = ( char* )( *pbuffer ) + 3*sizeof ( int );
        int* Semail = ( int* )( ( char* )( *pbuffer ) + INITIAL_SIZE + ( *usedBytes ) );

        *Semail = strlen ( temp ) +1;

        ( *usedBytes ) += sizeof ( int );

        *pbuffer = realloc ( ( *pbuffer ),  INITIAL_SIZE + ( *usedBytes ) + ( *Semail ) );
            if( !pbuffer ){
            printf( "erro ao alocar 6" );
            exit ( 1 );
        }
        temp = ( char* )( *pbuffer ) + 3*sizeof( int );
        char* email = ( char* )( *pbuffer ) + INITIAL_SIZE + ( *usedBytes );
        
        strcpy ( email, temp );
        
        ( *usedBytes ) += *Semail;
}

void Remova ( void **pbuffer ){  // complexidade O(N) 
    // busca
    printf ( "Digite o nome do contato que deseja deletar: \n\t" );
        fgets ( temp, 349, stdin );

    char*totalSearched = ( char* )( *pbuffer ) + INITIAL_SIZE;
    char*final= ( char* )( *pbuffer ) + INITIAL_SIZE + ( *usedBytes );
    char *current = ( char* )( *pbuffer );

    while( totalSearched < final ){

        int* age =  ( int* )totalSearched;
        int* Sname = ( int* )( ( char* )totalSearched + sizeof( int ) );
        int* Semail = ( int* )( ( char* ) totalSearched + 2*sizeof ( int ) + *Sname );
        char* name = ( char* )totalSearched + 2*sizeof ( int );
        char* email = ( char* )totalSearched +  3*sizeof ( int ) + *Sname ;
        
        // processo de remoção
        if ( strcmp ( temp, name ) == 0 ){
            
            memmove (
                totalSearched, 
                totalSearched + ( 3 * sizeof ( int ) + *Sname + *Semail ),
                final - ( totalSearched + 3 * sizeof ( int ) + *Sname + *Semail )
            );
            
            ( *usedBytes ) -= ( 3*sizeof ( int ) + *Sname + *Semail );
            ( *numCont )--;

            printf ( "Removido com sucesso! \n" );
            return;  
        }
        
        totalSearched = totalSearched +  3*sizeof ( int ) + *Sname + *Semail;
        
    }

    printf ( "Contato nao encontrado." );

}           

void Search ( void **pbuffer ) {  // complexidade O(N) 
    printf ( "Digite o nome que deseja procurar: \n\t" );
        fgets ( temp, 349, stdin );

    char*current = ( char* )( *pbuffer ) + INITIAL_SIZE;
    char*final= ( char* )( *pbuffer ) + INITIAL_SIZE + ( *usedBytes );

    while( current < final ){
        int* age =  ( int* )current;
        int* Sname = ( int* )( ( char* )current + sizeof ( int ) );
        int* Semail = ( int* )( ( char* )current + 2 * sizeof ( int ) + *Sname );
        char* name = ( char* )current + 2*sizeof ( int );
        char* email = ( char* )current +  3*sizeof ( int ) + *Sname ;

        if ( strcmp ( temp, name ) == 0 ) {
            printf ( "@@@@@  BUSCA  @@@@@\n" );
            printf ( "Nome: %s ", name );
            printf ( "Idade: %d \n", *age );
            printf ( "E-mail: %s ", email );
            printf ( "@@@@@@@@@@@@@@@@@@@\n" );
            return;  
        }

        current = current +  3*sizeof ( int ) + *Sname + *Semail;
        
    }

    printf ( "Contato nao encontrado. \n" );

}

void List ( void **pbuffer ) {  // complexidade O(N) 
    char*current = ( char* )( *pbuffer ) + INITIAL_SIZE;
    char*final= ( char* )(*pbuffer ) + INITIAL_SIZE + ( *usedBytes );

    printf( "##################\n" );
    while ( current < final ) {
        int* age =  ( int* )current;
        int* Sname = ( int* )( ( char* )current + sizeof ( int ) );
        char* name = ( char* )current + 2*sizeof ( int );
        int* Semail = ( int* )( ( char* )current + 2*sizeof( int ) + *Sname );
        char* email = ( char* )current +  3*sizeof ( int ) + *Sname ;

        current = current +  3*sizeof ( int ) + *Sname + *Semail;
        
        printf ( "Nome: %s ", name );
        printf ( "Idade: %d \n", *age );
        printf ( "E-mail: %s ", email );
        printf ( "##################\n" );
    }
}

// complexidade geral O(N) - N = numero de contatos