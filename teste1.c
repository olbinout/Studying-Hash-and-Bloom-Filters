#include <stdio.h>

// Structs
typedef struct {
    char nome[100];
    int matricula;
} Aluno;

typedef struct {
    Aluno tabela[100];
} Hashtable;


// Functions
int hashFunction (Aluno X);
void inserir(Hashtable *ht, Aluno X); 



// Main code
int main (){

    Aluno A1 = {"Joao", 12345};
    Aluno A2 = {"Maria", 67890};
    Hashtable ht; // Uma tabela com 100 posições (começando de 0 até 99), onde cada posição armazena um dado do tipo "Aluno".


    for (int i = 0; i < 100; i++) {
        ht.tabela[i].matricula = -1; // O "-1" é para simbolizar que não tem nada naquele determinado espaço da tabela hash.
    }

    inserir(&ht, A1);
    inserir(&ht, A2);

    printf("Índice da tabela Hash de %s: %d\n", A1.nome, hashFunction(A1));
    printf("Índice da tabela Hash de %s: %d\n", A2.nome, hashFunction(A2));
    // O hash de "Joao" e "Maria" serão diferentes, mesmo que as matrículas sejam iguais, porque o hash é calculado com base no nome do aluno (cada caracter representa um número inteiro, segundo a tabela ASCII), este nome será convertido em um número inteiro e acumulado dentro de "hash", no final, é só pegar o resto da divisão de hash por 100, ou seja, hash % 100.

    return 0;
}

// Functions codes  
int hashFunction (Aluno X) {
    int hash = 0 ;
    for (int i = 0 ; X.nome[i] != '\0'; i++) {
        hash += X.nome[i];
    }

    // Digamos que a tabela de hash tem 100 posições, então, vamos usar % "100".
    // Por estarmos dividindo o hash por 100, o resultado será um número entre 0 e 99, que é o tamanho da tabela hash.

    return hash % 100;
}

void inserir(Hashtable *ht, Aluno X){
    int indice = hashFunction(X);
    int origem = indice;
    while (ht->tabela[indice].matricula != -1) {
        indice = (indice + 1) % 100; // Serve para que o indice volte para o início da tabela, caso ele chegue no final, ou seja, na posição 99, ele volta para a posição 0. Criando um loop circular.

        if (indice == origem) {
            return; // Serve para evitar um loop infinito, caso a tabela esteja cheia. O programa não vai guardar o hash do aluno na tabela. Mas, vai continuar rodando o programa.
        }
    }

    ht->tabela[indice] = X;
}
