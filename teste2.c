#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno{
    char nome[100];
    int matricula;
} Aluno;

typedef struct No{
    Aluno estudante;
    struct No *prox;
} No;

typedef struct Hashmap{
    No *discentes[10];
} Hashmap;


// Functions
int hashFunction (Aluno X);
void inserir(Hashmap *ht, Aluno X);

int main (){

    Aluno A1 = {"Otavio", 2025010165};
    Aluno A2 = {"Francisco", 2025010225};
    Hashmap *ht = malloc(sizeof(Hashmap));

    for (int i = 0; i < 10; i++){
        ht->discentes[i] = NULL;
    }

    inserir(ht, A1);
    inserir(ht, A2);

    printf("Índice da tabela Hash de %s: %d\n", A1.nome, hashFunction(A1));
    printf("Índice da tabela Hash de %s: %d\n", A2.nome, hashFunction(A2));

    printf("Depois de %s é %s\n", A1.nome, ht->discentes[hashFunction(A1)]->prox->estudante.nome);

    return 0;
}

int hashFunction (Aluno X){
    int hash = X.matricula % 10;
    return hash;
}

void inserir(Hashmap *ht, Aluno X){
    int indice = hashFunction(X);
    No *novoNo = malloc(sizeof(No));
    novoNo->estudante = X;
    novoNo->prox = NULL;
    if (ht->discentes[indice] == NULL){
        ht->discentes[indice] = novoNo;
    }

    else {
        No *atual = ht->discentes[indice];
        while (atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = novoNo;
    }
}
