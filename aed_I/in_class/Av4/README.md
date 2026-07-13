# Arthur Borges - M1 - 25101666

## 18. 4Sum

Given an array `nums` of `n` integers, return *an array of all the **unique** quadruplets* `[nums[a], nums[b], nums[c], nums[d]]` such that:

* `0 <= a, b, c, d < n`
* `a`, `b`, `c`, and `d` are  **distinct** .
* `nums[a] + nums[b] + nums[c] + nums[d] == target`

You may return the answer in  **any order** .

Exemplo 1:

    Entrada:`nums = [1,0,-1,0,-2,2], target = 0`

    Saida:`[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]`

Exemplo 2:

    Entrada:`nums = [2,2,2,2,2], target = 8`

    Saida:`[[ 2,2,2,2 ]]`

Exemplo 3:

    Entrada:`nums = [1000000000, 1000000000, 1000000000, 1000000000], target = -294967296`

    Saida: NULL

![1783900930257](image/README/1783900930257.png)


ISSUE 1: nao sabia implementar o quicksort entao gastei tempo fazendo mergesort, e errei uma parte

ISSUE 2: usei a logica certa da maneira errada, somava 2 depois 3 depois 4 ao inves de somar 4 direto e depois andar ponteiros

ISSUE 3: tive problemas com a sintaxe ao ter que retornar uma matriz e ao colocar a resposta na variavel, 

ISSUE 4: demorei para resolver o testcase 4.
