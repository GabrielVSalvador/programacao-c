#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

#define ARROZ 1
#define FEIJAO 2
#define MACARRAO 3

#define INSERIR 1
#define REMOVER 2
#define BUSCAR 3
#define LISTAR 4
#define DELETAR 5

int main()
{
    lista lista_compras;
    int produto, opicao, posicao, quantidade_itens;

    printf("Quantos elementos deseja colocar na sua lista? ");
    scanf("%d", &quantidade_itens);
    lista_criar(&lista_compras, quantidade_itens);

    printf("Menu\n");
    printf("[1] INSERIR ITEM\n");
    printf("[2] REMOVER ITEM\n");
    printf("[3] BUSCAR ITEM\n");
    printf("[4] LISTAR ITENS\n");
    printf("[5] DELETAR LISTA\n");
    printf("Qual a opção desejada? ");
    scanf("%d", &opicao);

    if(opicao == INSERIR || opicao == REMOVER || opicao == BUSCAR){
        printf("Qual o código do item desejado?\n");
        printf("[1] ARROZ\n");
        printf("[2] FEIJAO\n");
        printf("[3] MACARRAO\n");
        scanf("%d", &produto);
    }

    switch(opicao){
        case INSERIR : lista_inserir_elemento(produto, &lista_compras); break;
        case REMOVER : lista_remover_elemento(produto, &lista_compras); break;
        case BUSCAR :
        {
            posicao = lista_posicao_elemento(produto, lista_compras);
            if(posicao != ELEMENTO_NAO_EXISTENTE){
                printf("O item esta na posição %d.", posicao);
            } else {
                printf("O item não esta na lista.");
            }
            break;
        }
        case LISTAR : lista_exibir(lista_compras);break;
        case DELETAR : lista_deletar(&lista_compras);
    }
}
