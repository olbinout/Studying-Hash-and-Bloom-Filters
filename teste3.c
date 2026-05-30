#include <stdio.h>

// Este arquivo trata-se sobre o Filtro de Bloom 


/*

    Contextos que o Filtro de Bloom é bom:
        - Verificar se um item existe em uma estrutura de dados.
        - Extremamente eficiente em espaço, consumindo pouca memória
        - Garante consultas ultra-ráidas


    * Ele serve para responder a pergunta: "O item X existe na estrutura de dados?"

    * Existem dois tipos de respostas possíveis:
        - "Não": Você tem a certeza absoluta de que o elemento não está lá. O filtro nunca vai gerar um Falso Negativo. 
        - "Sim": O elemento provavelmente está presente, mas existe a chance de ser um Falso Positivo. Ou seja, ele diz que está lá, mas na verdade não está.

    * Este vídeo ajudará a entender como o Filtro de Bloom funciona de foram visual: https://www.youtube.com/watch?v=kfFacplFY4Y

        - A lógica básica é essa: joga o dado no Hash, marca o bit no vetor, e depois checa se os bits daquele dado estão marcados.

*/
int main (){



    return 0;
}