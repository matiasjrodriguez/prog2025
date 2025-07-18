#include "../headers/arbol-binario-busqueda.h"
#include "../headers/nodo.h"

static const int TAMANIO_MAXIMO = 100;


struct ArbolBinarioBusquedaRep {
    NodoArbol raiz;
    int cantidad_elementos;
};


ArbolBinarioBusqueda abb_crear() {
    ArbolBinarioBusqueda nuevo_arbol = (ArbolBinarioBusqueda) malloc(sizeof(struct ArbolBinarioBusquedaRep));
    nuevo_arbol->raiz = NULL;
    nuevo_arbol->cantidad_elementos = 0;
    return nuevo_arbol;
}


bool abb_es_vacio(ArbolBinarioBusqueda a) {
    return (a->raiz == NULL);
}


bool abb_es_lleno(ArbolBinarioBusqueda a){
    return (a->cantidad_elementos == TAMANIO_MAXIMO);

};


int abb_cantidad_elementos(ArbolBinarioBusqueda a) {
    return a->cantidad_elementos;
}


bool abb_es_rama_nula(NodoArbol pa) {
    return pa == NULL;
}


NodoArbol abb_raiz(ArbolBinarioBusqueda a) {
    return a->raiz;
}



NodoArbol abb_insertar_recursivo(ArbolBinarioBusqueda a, NodoArbol pa, TipoElemento te, bool *inserto) {
    if (pa == NULL) {
	*inserto = true;
        a->cantidad_elementos++;
        NodoArbol nuevo_nodo = n_crear(te);
        if (a->cantidad_elementos == 1) {
            a->raiz = nuevo_nodo;
        }
        return nuevo_nodo;
    } else if (te->clave > pa->datos->clave) {
        pa->hd = abb_insertar_recursivo(a, pa->hd, te, inserto);
    } else if (te->clave < pa->datos->clave) {
        pa->hi = abb_insertar_recursivo(a, pa->hi, te, inserto);
    }
    return pa;
}

bool abb_insertar(ArbolBinarioBusqueda a, TipoElemento te) {
    bool inserto = false;

    if (abb_es_lleno(a)) {
        return false;
    }

    if (abb_es_vacio(a)) {
        a->raiz = n_crear(te);
        a->cantidad_elementos++;
        inserto = true;
    } else {
        NodoArbol p, q;
        q = abb_raiz(a);
        while (q != NULL) {
            p = q;
            if (te->clave < q->datos->clave) {
                q = q->hi;
            } else if (te->clave > q->datos->clave) {
                q = q->hd;
            } else {
                break;
            }
        }
        if (q == NULL) {
            inserto = true;
            NodoArbol na = n_crear(te);
            a->cantidad_elementos++;
            if (p->datos->clave > te->clave) {
                p->hi = na;
            } else {
                p->hd = na;
            }
        } else {
            printf("Clave Duplicada: %d \n", te->clave);
        }
    }
    return inserto;
}


NodoArbol abb_buscar_minimo(NodoArbol nodoArbol) {
    NodoArbol actual = nodoArbol;

    while (actual && actual->hi != NULL)
        actual = actual->hi;

    return actual;
}

NodoArbol abb_eliminar_recursivo(NodoArbol root, int claveABorrar, bool *borre) {
    if (root == NULL) {
        return root;
    }

    if (claveABorrar < root->datos->clave)
        root->hi = abb_eliminar_recursivo(root->hi, claveABorrar, borre);
    else if (claveABorrar > root->datos->clave)
        root->hd = abb_eliminar_recursivo(root->hd, claveABorrar, borre);
    else {
        *borre = true;
        if (root->hi == NULL) {
            NodoArbol temp = root->hd;
            free(root);
            return temp;
        } else if (root->hd == NULL) {
            NodoArbol temp = root->hi;
            free(root);
            return temp;
        }

        NodoArbol temp = abb_buscar_minimo(root->hd);
        root->datos->clave = temp->datos->clave;
        root->datos->valor = temp->datos->valor;

        root->hd = abb_eliminar_recursivo(root->hd, temp->datos->clave, borre);
    }
    return root;
}


bool abb_eliminar(ArbolBinarioBusqueda a, int claveABorrar) {
    bool borre = false;
    TipoElemento te;
    NodoArbol N;
    te = n_recuperar(abb_raiz(a));

    // cotemplo que si borra la raiz y no tiene hijos por la derecha el hijo izquierdo se convierte en raiz
    N = n_hijoderecho(abb_raiz(a));
    if ((N == NULL) && (te->clave == claveABorrar)) {
        printf("Hijo Derecho NULO \n");
        N = abb_raiz(a);
        a->raiz = n_hijoizquierdo(abb_raiz(a));
        free(N);
        return true;
    }

    // cotemplo que si borra la raiz y no tiene hijos por la izquierda el hijo derecho se convierte en raiz
    N = n_hijoizquierdo(abb_raiz(a));
    if ((N == NULL) && (te->clave == claveABorrar)) {
        printf("Hijo Izquierdo NULO \n");
        N = abb_raiz(a);
        a->raiz = n_hijoderecho(abb_raiz(a));
        free(N);
        return true;
    }

    // Cualquier otro caso
    // Sino llamo al proceso recursivo
    abb_eliminar_recursivo(abb_raiz(a), claveABorrar, &borre);
    return borre;
}


TipoElemento abb_buscar_recursivo(NodoArbol nodoArbol, int clave) {
    if (nodoArbol == NULL)
        return NULL;
    else if (clave < nodoArbol->datos->clave)
        return abb_buscar_recursivo(nodoArbol->hi, clave);
    else if (clave > nodoArbol->datos->clave)
        return abb_buscar_recursivo(nodoArbol->hd, clave);
    else
        return nodoArbol->datos;

}

TipoElemento abb_buscar(ArbolBinarioBusqueda a, int clave) {
    return abb_buscar_recursivo(abb_raiz(a), clave);
}