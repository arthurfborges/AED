#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct trieNode{
    struct trieNode *child[ALPHABET_SIZE];
    bool fimDaPalavra;
}trieNode;

trieNode* createNode( void );
bool findWord( char* word, trieNode *rootNode );
void insertWord ( char* word, trieNode *rootNode );
void trie_busca_prefixo(trieNode *root, char *prefixo, char **palavras);

int main(){

    char* word = "batata";

    trieNode *root = createNode();
    insertWord("batman", root);

    bool isWordFound = findWord(word, root);
    printf("Real ou faike: %d\n", isWordFound);

}

trieNode* createNode( void ){
    trieNode *node = (trieNode *)malloc(sizeof(trieNode));
    for (int i = 0; i < ALPHABET_SIZE; i++){
        node->child[i] = NULL;
    } 
    node->fimDaPalavra = false;
    return node;
}

bool findWord( char* word, trieNode *rootNode ) {
    int len_word = strlen( word );
    
    if ( len_word == 0 ) {
        return false;
    }

    trieNode *aux = rootNode;
    int i = 0;

    while ( i < len_word ) {
        int j = (int) word[i] - 'a';
        if ( !aux->child[j] )
            return false;

        aux = aux->child[j];
        i++;
    }

    return true;
}

void insertWord ( char* word, trieNode *rootNode ){
    trieNode *current = rootNode;

    for ( int i = 0; word[i] != '\0'; i++ ){
        int index = word[i] - 'a';
        if ( !current->child[index] ) {
            current->child[index] = createNode();
        }
        current = current->child[index];
    }
    current->fimDaPalavra = true;
}

void trie_busca_prefixo(trieNode *rootNode, char *prefixo, char **palavras){
    
    int len_prefixo = strlen( prefixo );
    
    if ( len_prefixo == 0 ) {
        return false;
    }

    trieNode *aux = rootNode;
    int i = 0;

    while ( i < len_prefixo ) {
        int j = (int) prefixo[i] - 'a';
        if ( !aux->child[j] )
            return;

        aux = aux->child[j];
        i++;
    }

    if (findWord(prefixo, rootNode)){
        
    }
    
    // aux =  ultima letra do prefixo

    // bat
    
    // batman
    // bater
    // batida
    // batatao

    while( !aux->fimDaPalavra && palavraListada(palavras)){


}

bool palavraListada(){
    
}


