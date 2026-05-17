int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* output = (int*)malloc(numsSize * sizeof(int));
    if (!output) {
        printf("erro no malloc");
        exit(1);
    }
    
    for (int i = 0; i < numsSize; i++) {
        output[i] = -1;
    }

    int* stack = (int*)malloc(numsSize * sizeof(int));  
    int top = -1; // top vazio = -1 e nao 0 porque é usado com indice, portanto 0 é uma posiçao valida da pilha

    for (int i = 0; i < 2 * numsSize; i++) {
        int indice_atual = i % numsSize; // faz percorrer o array duas vezes,  
             
        while (top != -1 && nums[stack[top]] < nums[indice_atual]) {
            // cond 1: previne acessar memoria invalida 
            // cond 2: verifica se numero analisado é maior que o do topo da pilha


            output[stack[top]] = nums[indice_atual];
            top--; // pop
        }

        if (i < numsSize) { // entra todos na primeira iteração 
            stack[++top] = indice_atual; // push
        }
    }

    free(stack); 
    return output;
}