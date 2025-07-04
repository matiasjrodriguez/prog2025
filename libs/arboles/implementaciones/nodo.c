#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/nodo.h"

// retorna el hijo izquierdo
NodoArbol n_hijoizquierdo(NodoArbol N){
    if (N == NULL) {
        return NULL;
    }
    else {
        return N->hi;
    }
};

// retorna el hijo derecho
NodoArbol n_hijoderecho(NodoArbol N){
    if (N == NULL) {
        return NULL;
    }
    else {
        return N->hd;
    }
};

// Crea el Nodo y lo retorna
NodoArbol n_crear(TipoElemento te) {
    NodoArbol na = (NodoArbol) malloc(sizeof(struct NodoArbolRep));
    na->datos = te;
    na->hi = NULL;
    na->hd = NULL;
    na->FE = 0;
    return na;
};

// retorno el tipo elemento de un nodo o NULL si no existe
TipoElemento n_recuperar(NodoArbol N) {
    if (N == NULL) {
        return NULL;
    }
    else {
        TipoElemento x = N->datos;
        return x;
    }
};
