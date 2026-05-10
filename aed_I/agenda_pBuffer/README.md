#### **Arthur Ferreira Borges - AED I - M1 - 25101666**

#### **Agenda**

Faça uma agenda com o seguinte menu:

1- Adicionar Pessoa (Nome, Idade, email)

2- Remover Pessoa

3- Buscar Pessoa

4- Listar todos

5- Sair

O desafio é não poder criar variáveis e sim um buffer de memória (void *pBuffer). Nisso vocês terão que fazer o trabalho que o Sistema Operacional faz para vocês ao organizar a memória.

Regras:

1. **Nenhuma variável pode ser declarada em todo o programa, somente ponteiros** . Todos os dados do programa devem ser guardados dentro do pBuffer.
2. Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.
   1. Exemplo: int *ptr = (int *)pBuffer
3. Exemplo do que não pode: int c; char a; int v[10];  void Funcao( **int parametro** )
4. Todas as strings que ficarem dentro do pBuffer deve ter somente o tamanho necessário, somente um buffer para receber o que o usuário digita no scanf pode ter um tamanho fixo.
5. Não pode usar struct em todo o programa.

**Motivação** para fazer o trabalho: **Desempenho** e **entender o hardware** onde programamos.

-------------------------------------------//----------------------------------------

Organização para pBuffer comentada no inicio do codigo.
