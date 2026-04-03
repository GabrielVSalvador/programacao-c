#ifndef LISTA_SEQUENCIAL
#define LISTA_SEQUENCIAL

#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define ELEMENTO_NAO_EXISTENTE -1
#define ELEMENTO_EXISTENTE -2
#define LISTA_CHEIA -3
#define LISTA_VAZIA -4
#define SUCESSO -5


typedef struct{
    int *elemento;
    int *usado, tamanho;
}lista;

void lista_criar(lista* l ,int tam)
{
    l-> elemento = malloc(sizeof(int[tam]));
    l-> usado = calloc(tam, sizeof(int [tam]));
    l-> tamanho = tam;
}

int lista_numero_elementos (lista l){
    int i, num_elementos = 0;
    for ( i =0; i < l.tamanho;i++){
        if(l.usado[i] == TRUE){
            num_elementos++;
        }
    }
    return num_elementos;

}

int lista_posicao_elemento ( int elemento, lista l){
    int i;
    for(i=0; i<l.tamanho;i++){
        if(l.usado[i] == TRUE){
            if(l.elemento[i] == elemento){
                return i;
            }
        }
    }
    return ELEMENTO_NAO_EXISTENTE;
}

int lista_inserir_elemento (int elemento, lista* l){
    int i, num_elementos;
    num_elementos = lista_numero_elementos(*l);
    if(num_elementos >=  l->tamanho)
        return LISTA_CHEIA;
    if(lista_posicao_elemento(elemento,*l) != ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_EXISTENTE;
    for(i=0 ; i< l ->tamanho; i++){
        if(l->usado[i] == FALSE){
            l->elemento = elemento;
            l->usado = TRUE;
            break;
        }

    }
    return SUCESSO;
}

int lista_remover_elemento(int elemento, lista* l){
    int num_elementos = lista_numero_elementos(*l);
    int posicao = lista_posicao_elemento(elemento,*l);
    if(num_elementos <= 0)
        return LISTA_VAZIA;
    if(posicao == ELEMENTO_NAO_EXISTENTE)
        return ELEMENTO_NAO_EXISTENTE;
    l->usado[posicao] = FALSE;
}

void lista_exibir (lista l){
    int i;
    for(i=0 ; i <l.tamanho; i++){
        if(l.usado[i] == TRUE){
            return printf("%d", l.elemento[i]);
        }
        printf("\n");
    }
}

void lista_ler (lista* l){
    int i, elemento;
    int num_elementos;
    printf("Informe o numero de elementos que deseja inserir");
    scanf("%d", &num_elementos);
    for(i=0; i<num_elementos;i++ && i < l->tamanho, i++){
        printf("Lista[%d] = ", i);
        scanf("%d", &elemento);
        lista_inserir_elemento(elemento, l);
    }
}

void lista_deletar(lista* l){
    free(l->elemento);
    free(l->usado);
    free(l->tamanho);
    l->elemento = l->tamanho = l->usado = NULL;
}

#endif // LISTA_SEQUENCIAL
