
# Arthur Borges - M1 - 25101666

## 775 - Global and Local Inversions

Voce recebe um array de inteiros nums de comprimento n que representa

    uma permutacao de todos os inteiros no intervalo [0, n - 1].



    O numero de inversoes GLOBAIS e o numero de pares ( i, j ) diferentes

    onde:

    0 <= i < j < n  e  nums[i] > nums[j]

    O numero de inversoes LOCAIS e o numero de indices i onde:

    0 <= i < n - 1  e  nums[i] > nums[i + 1]

    Retorne true se o numero de inversoes globais for igual ao numero de

    inversoes locais.

    Exemplo 1:

    Entrada: nums = [1,0,2]

    Saida: true

    Explicacao: ha 1 inversao global e 1 inversao local.

    Exemplo 2:

    Entrada: nums = [1,2,0]

    Saida: false

    Explicacao: ha 2 inversoes globais e 1 inversao local.

    Exemplo 3:

    Entrada: nums = [3,0,1,2]

    Saida: false

    Explicacao: ha 3 globais e uma local


ISSUE 1: tive dificuldade em entender o que o problema pedia pois li mal a descrição da função isIdealPermutation, e perdi muito tempo tentando achar um jeito de calcular as locais com base na arvore.

ISSUE 2: nao vi que rebalancear de dentro da função inserir ja chamava o atualizar e botei ele ali porque, ao meu ver, ele nao seria chamado caso eu nao o  colocasse.

ISSUE 3: achei que a logica do problema seria ligada ao numero de rotações e como uma ultima esperança botei aquele if xulo pra aumentar o numero de casos aceitos.
