#include "tp_arboles.h"

// EJERCICIO 2
// a
void buscar_hojas(NodoArbol nodo, Lista l_hojas){
    TipoElemento te;
    
    if(a_es_rama_nula(nodo)){
        return;
    }

    if(n_hijoizquierdo(nodo) == NULL && n_hijoderecho(nodo) == NULL){
        te = te_crear(n_recuperar(nodo)->clave);
        l_agregar(l_hojas, te);
    }

    buscar_hojas(n_hijoizquierdo(nodo), l_hojas);
    buscar_hojas(n_hijoderecho(nodo), l_hojas);
}

Lista a_ej2_hojas(ArbolBinario A){
    NodoArbol raiz = a_raiz(A);
    Lista l_resultado = l_crear();
    buscar_hojas(raiz, l_resultado);

    return l_resultado;
    }

// b
void a_no_hojas(NodoArbol nodo1, Lista l_resultado){
    if(a_es_rama_nula(nodo1)){
        return;
    }
    // con que haya al menos un hijo te asegura que no es hoja
    if(!a_es_rama_nula(n_hijoizquierdo(nodo1)) || !a_es_rama_nula(n_hijoderecho(nodo1))){
        TipoElemento te = te_crear(n_recuperar(nodo1)->clave);
        l_agregar(l_resultado, te);
    }
    a_no_hojas(n_hijoizquierdo(nodo1), l_resultado);
    a_no_hojas(n_hijoderecho(nodo1), l_resultado);
}

Lista a_ej2_interiores(ArbolBinario A){
    NodoArbol raiz = a_raiz(A);
    Lista l_resultado = l_crear();

    if(!a_es_rama_nula(raiz)){
        
        if(!a_es_rama_nula(n_hijoizquierdo(raiz))){
            a_no_hojas(n_hijoizquierdo(raiz), l_resultado);
        }
        if(!a_es_rama_nula(n_hijoderecho(raiz))){
            a_no_hojas(n_hijoderecho(raiz), l_resultado);
        }
    }
    return l_resultado;
}

// c
void a_encontrar_clave(NodoArbol nodo1, int clave, Lista l_res){
    if(a_es_rama_nula(nodo1)){
        return;
    }
    // nodo1->datos->clave sirve tambien pero por abstraccion no se usa
    if(clave == n_recuperar(nodo1)->clave){
        l_agregar(l_res, te_crear_con_valor(0, nodo1));
    }
    a_encontrar_clave(n_hijoizquierdo(nodo1), clave, l_res);
    a_encontrar_clave(n_hijoderecho(nodo1), clave, l_res);
}

Lista a_ej2_buscarclave(ArbolBinario A, int clave){
    Lista l_resultado = l_crear();
    NodoArbol raiz = a_raiz(A);

    if(!a_es_rama_nula(raiz)){
        a_encontrar_clave(raiz, clave, l_resultado);
    }
    return l_resultado;
}

//  EJERCICIO 3
//  A
NodoArbol buscarpadre(NodoArbol nodo, int clavehijo){
    if(a_es_rama_nula(nodo)){
        return NULL;
    }
    NodoArbol nhi = n_hijoizquierdo(nodo);
    NodoArbol nhd = n_hijoderecho(nodo);

    if((!a_es_rama_nula(nhi) && n_recuperar(nhi)->clave == clavehijo)
    || (!a_es_rama_nula(nhd) && n_recuperar(nhd)->clave == clavehijo)){
        return nodo;
    } // si alguna de las claves de los hijo del nodo es la clavehijo, retorno el nodo

    NodoArbol padre = buscarpadre(nhi, clavehijo);                      // busco al padre por los hijos izquierdos,
    return a_es_rama_nula(padre) ? buscarpadre(nhd, clavehijo) : padre; // si padre == NULL, por los hijos derechos.
}                                                                       // y padre se encontró (!=NULL), lo retorno

int a_ej3_clavepadre(ArbolBinario A, int clavehijo){
    NodoArbol raiz = a_raiz(A);
    if(a_es_vacio(A)){
        return -1;
    }
    if(n_recuperar(raiz)->clave == clavehijo){
        return -1;
    }else{
        NodoArbol res = buscarpadre(raiz, clavehijo);
    // si res = NULL porque no encontró la clave retorna la clave hijo y sino la clave padre
        return a_es_rama_nula(res) ? clavehijo : n_recuperar(res)->clave;
    }
    
}

//  B
void buscarhijos(NodoArbol nodo, int clave, Lista l_hijos){
    if(a_es_rama_nula(nodo)){
        return;
    }
    if(n_recuperar(nodo)->clave == clave){
        if(n_recuperar(n_hijoizquierdo(nodo)) != NULL){
            l_agregar(l_hijos, n_recuperar(n_hijoizquierdo(nodo)));
        }
        if(n_recuperar(n_hijoderecho(nodo)) != NULL){
            l_agregar(l_hijos, n_recuperar(n_hijoderecho(nodo)));
        }
        
    }
    else{
        buscarhijos(n_hijoizquierdo(nodo), clave, l_hijos);
        buscarhijos(n_hijoderecho(nodo), clave, l_hijos);
    }
}

Lista a_ej3_hijos(ArbolBinario A, int clavepadre){
    Lista l_resultados = l_crear();
    NodoArbol raiz = a_raiz(A);
    buscarhijos(raiz, clavepadre, l_resultados);
    return l_resultados;
}

//  C   Listar el hermano (solo la clave)

void buscarhermano(NodoArbol nodo, int clave, int* hermano){
    TipoElemento te;
    if(a_es_rama_nula(nodo)){
        return;    //NULL
    }
    te = n_recuperar(n_hijoizquierdo(nodo));
    if(te != NULL){
        if(te->clave == clave){ //error
            te = n_recuperar(n_hijoderecho(nodo));
            if(te != NULL){
                *hermano = te->clave;
            }
        }
    }
    te = n_recuperar(n_hijoderecho(nodo));
    if(te != NULL){
        if(te->clave == clave){ 
            te = n_recuperar(n_hijoizquierdo(nodo));
            if(te != NULL){
                *hermano = te->clave;
            }
        }
    }
    buscarhermano(n_hijoizquierdo(nodo),clave, hermano); 
    buscarhermano(n_hijoderecho(nodo),clave, hermano);
    
}
int a_ej3_hermano(ArbolBinario A, int clave){
    NodoArbol nodo = a_raiz(A);
    int hermano = -1;
    buscarhermano(nodo, clave, &hermano);
    return hermano;
}

//  D  
int calcularnivel(NodoArbol nodo, int clave, int nivel){
    if(a_es_rama_nula(nodo)){
        return -1;  //ojo aca
    }
    if(n_recuperar(nodo)->clave == clave){
        return nivel;
    }
    int resp = calcularnivel(n_hijoizquierdo(nodo), clave, (nivel+1)); // busco al padre por los hijos izquierdos,
    return (resp != -1) ? resp : calcularnivel(n_hijoderecho(nodo), clave, (nivel+1));
}
int a_ej3_nivel(ArbolBinario A, int clave){
    NodoArbol raiz = a_raiz(A);
    return calcularnivel(raiz, clave, 0);
}

//  E 

void nodoABuscar(NodoArbol nodo, int clave, NodoArbol *resultado){  //busca un nodo por la clave
    TipoElemento te;

    if(!a_es_rama_nula(nodo)){
        te = n_recuperar(nodo);
        if(te->clave == clave){
            *resultado = nodo;
        }

        nodoABuscar(n_hijoizquierdo(nodo), clave, resultado);
        nodoABuscar(n_hijoderecho(nodo), clave, resultado);
    }
}

void calcularRama(NodoArbol nodo, int *altura, int nivel){
    if (a_es_rama_nula(nodo)) {
        if (nivel > *altura){
            *altura = nivel;
        }
    }
    else{
        calcularRama(n_hijoizquierdo(nodo), altura, nivel+1);
        calcularRama(n_hijoderecho(nodo), altura, nivel+1);
    }
}

int a_ej3_alturarama(ArbolBinario A, int clave){
    int resultado = 0;
    NodoArbol nodoActual = NULL;

    nodoABuscar(a_raiz(A), clave, &nodoActual);
    if(nodoActual == NULL){
        return -1;
    }
    else{
        calcularRama(nodoActual, &resultado, 0);
    }
    
    return resultado;
}

// F Listar todos los nodos que están en el mismo nivel (solo la clave).
void mismonivel(NodoArbol nodo, int nivel, int nivelactual, Lista l_resultado){
    if(a_es_rama_nula(nodo) || nivelactual > nivel){
        return;
    }   //ojo con este
    if(nivel == nivelactual){
        l_agregar(l_resultado, n_recuperar(nodo));
    }
    mismonivel(n_hijoizquierdo(nodo), nivel, nivelactual+1,l_resultado);
    mismonivel(n_hijoderecho(nodo), nivel, nivelactual+1,l_resultado);
}


Lista a_ej3_clavesmismonivel(ArbolBinario A, int nivel){
    Lista l_resultados = l_crear();
    NodoArbol raiz = a_raiz(A);
    mismonivel(raiz, nivel, 0, l_resultados);
    return l_resultados;

}


// EJERCICIO 4
//A
Lista a_ej4_anchura(ArbolBinario A) {
    Lista lista_resultado = l_crear();
    NodoArbol nodo_actual = a_raiz(A);
    Cola cola_nodos = c_crear();
    TipoElemento elemento_cola;

    if (nodo_actual != NULL) {
        elemento_cola = te_crear_con_valor(0, nodo_actual);  // Encolar la raiz
        c_encolar(cola_nodos, elemento_cola);
    }

    while (!c_es_vacia(cola_nodos)) {
        NodoArbol nodo_procesado = (NodoArbol) c_desencolar(cola_nodos)->valor;
        TipoElemento elemento_nodo = n_recuperar(nodo_procesado);
        l_agregar(lista_resultado, elemento_nodo);  // Agregar la clave al resultado

        NodoArbol hijo_actual = n_hijoizquierdo(nodo_procesado);
        while (hijo_actual != NULL) {
            elemento_cola = te_crear_con_valor(0, hijo_actual);
            c_encolar(cola_nodos, elemento_cola);
            hijo_actual = n_hijoderecho(hijo_actual);  // Avanzar al siguiente hijo (hermano derecho)
        }
    }

    return lista_resultado;
}

//B
int a_ej4_q_hojas(ArbolBinario A) {
    if (a_es_vacio(A)) return 0;

    Cola cola = c_crear();
    TipoElemento elem;
    NodoArbol nodo_actual;
    int hojas = 0;

    // Encolar la raíz
    NodoArbol raiz = a_raiz(A);
    if (raiz == NULL) return 0;

    elem = te_crear_con_valor(0, raiz);
    c_encolar(cola, elem);

    while (!c_es_vacia(cola)) {
        elem = c_desencolar(cola);
        nodo_actual = (NodoArbol) elem->valor;

        NodoArbol hijo_izq = n_hijoizquierdo(nodo_actual);

        if (hijo_izq == NULL) {  
            // No tiene hijos -> hoja
            hojas++;
        } else {
            // Encolar todos los hijos no nulos
            NodoArbol hijo = hijo_izq;
            while (hijo != NULL) {
                elem = te_crear_con_valor(0, hijo);
                c_encolar(cola, elem);
                hijo = n_hijoderecho(hijo);
            }
        }
    }

    return hojas;
}

//C
bool son_similares(NodoArbol n1, NodoArbol n2) {
    if (a_es_rama_nula(n1) && a_es_rama_nula(n2)) {
        return true; // ambos vacíos
    }

    if (a_es_rama_nula(n1) || a_es_rama_nula(n2)) {
        return false; // uno vacío y otro no
    }

    NodoArbol hijo1 = n_hijoizquierdo(n1);
    NodoArbol hijo2 = n_hijoizquierdo(n2);
    while (!a_es_rama_nula(hijo1) && !a_es_rama_nula(hijo2)) {
        if (!son_similares(hijo1, hijo2)) {
            return false;
        }
        hijo1 = n_hijoderecho(hijo1);
        hijo2 = n_hijoderecho(hijo2);
    }

    // Si la cantidad de hijos no es la misma
    if (!a_es_rama_nula(hijo1) || !a_es_rama_nula(hijo2)) {
        return false;
    }

    return true;
}

bool a_ej4_similares(ArbolBinario A, ArbolBinario B) {
    return son_similares(a_raiz(A), a_raiz(B));
}

//D
NodoArbol nArio_buscarPadre(NodoArbol nodo, int clave){
    if(a_es_rama_nula(nodo)) return NULL;

    NodoArbol hijo = n_hijoizquierdo(nodo);
    while(!a_es_rama_nula(hijo)){
        if(n_recuperar(hijo)->clave == clave){
            return nodo;
        }
        NodoArbol res = nArio_buscarPadre(hijo, clave);
        if(res != NULL) return res;
        hijo = n_hijoderecho(hijo); // va por los hermanos 
    }
    return NULL;
}

TipoElemento a_ej4_padre(ArbolBinario A, int clave){
    if(a_es_vacio(A)){
        return NULL;
    }

    NodoArbol raiz = a_raiz(A);
    if(n_recuperar(raiz)->clave == clave){
        return te_crear(-1); // La raíz no tiene padre
    }

    NodoArbol nodo_padre = nArio_buscarPadre(raiz, clave);
    if(a_es_rama_nula(nodo_padre)){
        return te_crear(-1); // No se encontró el padre
    }

    return n_recuperar(nodo_padre); 
}

//E
void encontrar_y_agregar_hermanos(NodoArbol nodo, int clave, Lista l_hermanos) {
    if (a_es_rama_nula(nodo)) return;

    NodoArbol hijo = n_hijoizquierdo(nodo);
    
    while (!a_es_rama_nula(hijo)) {
        if (n_recuperar(hijo)->clave == clave) {
            // El nodo actual (padre) tiene como hijo al nodo buscado.
            NodoArbol hermano = n_hijoizquierdo(nodo);
            while (!a_es_rama_nula(hermano)) {
                if (n_recuperar(hermano)->clave != clave) {
                    l_agregar(l_hermanos, n_recuperar(hermano));
                }
                hermano = n_hijoderecho(hermano);
            }
            return; // Ya encontramos y agregamos los hermanos, salimos.
        }
        hijo = n_hijoderecho(hijo);
    }

    // Buscar en los hijos recursivamente
    NodoArbol sub = n_hijoizquierdo(nodo);
    while (!a_es_rama_nula(sub)) {
        encontrar_y_agregar_hermanos(sub, clave, l_hermanos);
        sub = n_hijoderecho(sub);
    }
}

Lista a_ej4_hermanos(ArbolBinario A, int clave) {
    Lista l_hermanos = l_crear();
    NodoArbol raiz = a_raiz(A);

    if (a_es_rama_nula(raiz)) return l_hermanos;

    // La raíz no tiene hermanos
    if (n_recuperar(raiz)->clave == clave) return l_hermanos;

    encontrar_y_agregar_hermanos(raiz, clave, l_hermanos);
    return l_hermanos;
}


// EJERCICIO 7
bool determinarEquivalencia(NodoArbol nodo1, NodoArbol nodo2){

    TipoElemento te1= n_recuperar(nodo1), te2= n_recuperar(nodo2);

    if(te1->clave == te2->clave){
        if(n_hijoizquierdo(nodo1) != NULL && n_hijoizquierdo(nodo2) != NULL){
            //tienen un hijo izquierdo para seguir comparando y son iguales en la clave
            determinarEquivalencia(n_hijoizquierdo(nodo1), n_hijoizquierdo(nodo2));
        }
        else if(n_hijoizquierdo(nodo1) == NULL && n_hijoizquierdo(nodo2) == NULL);
        else{
            return false;   //NO COMPARTEN ESTRUCTURA
        }        
        if(n_hijoderecho(nodo1) != NULL && n_hijoderecho(nodo2) != NULL){
            determinarEquivalencia(n_hijoderecho(nodo1), n_hijoderecho(nodo2));
        }
        else if(n_hijoderecho(nodo1) == NULL && n_hijoderecho(nodo2) == NULL);
        else{
            return false;
        }
    }
    else{
        return false;
    }
    return true;
}

bool a_ej7_equivalente(ArbolBinario A, ArbolBinario B){

    if(a_es_vacio(A) || a_es_vacio(B)){
        return (a_es_vacio(A) && a_es_vacio(B));
    }

    NodoArbol raiz1 = a_raiz(A), raiz2 = a_raiz(B);
    bool equivalencia;
    equivalencia = determinarEquivalencia(raiz1, raiz2);

    return equivalencia;
}

// EJERCICIO 8
// A
void alturaN_ario(NodoArbol nodo, int *altura, int *contador){
    if(a_es_rama_nula(nodo)) return;

    NodoArbol nhi = n_hijoizquierdo(nodo);
    NodoArbol nhd = n_hijoderecho(nodo);
    if(!a_es_rama_nula(nhi)){
        (*contador)++;
        alturaN_ario(nhi, altura, contador);
    }
    else if((*contador) > (*altura) && a_es_rama_nula(nhd)){
        *altura = (*contador);
        *contador = 2; // raiz + hijo extremo izquierdo
    }
    
    alturaN_ario(nhd, altura, contador);
}
int a_ej8_altura(ArbolBinario A){
    NodoArbol raiz = a_raiz(A);
    int altura = 0; // preguntar cómo se van a cargar los n-arios. 
    int contador = 1; // raiz

    alturaN_ario(raiz, &altura, &contador);

    return altura;
}

// B
int nivelN_ario(NodoArbol nodo, int clave, int nivel_actual){
    if(a_es_rama_nula(nodo)) return -1; // no se encontró
    
    if(n_recuperar(nodo)->clave == clave) return nivel_actual;
    
    int nivel = nivelN_ario(n_hijoizquierdo(nodo), clave, nivel_actual+1);
    if (nivel != -1) return nivel;
    
    return nivelN_ario(n_hijoderecho(nodo), clave, nivel_actual);
}
int a_ej8_nivel(ArbolBinario A, int clave){
    NodoArbol raiz = a_raiz(A);
    return nivelN_ario(raiz, clave, 0);
}

// C
void internosN_ario(NodoArbol nodo1, Lista l_res){
    if(a_es_rama_nula(nodo1)) return;

    if(!a_es_rama_nula(n_hijoizquierdo(nodo1))){
        TipoElemento te = te_crear(n_recuperar(nodo1)->clave);
        l_agregar(l_res, te);
    }
    internosN_ario(n_hijoizquierdo(nodo1), l_res);
    internosN_ario(n_hijoderecho(nodo1), l_res);
}
Lista a_ej8_internos(ArbolBinario A){
    NodoArbol raiz = a_raiz(A);
    NodoArbol nhi = n_hijoizquierdo(raiz);
    Lista l_resultado = l_crear();
    internosN_ario(nhi, l_resultado);

    if(l_es_vacia(l_resultado)){
        printf("\nEl arbol no tiene nodos interiores...\n");
    }
    return l_resultado;
}

// D
bool mismo_nivelhojasN_ario(ArbolBinario A, NodoArbol nodo, int *nivel_primera_hoja){
    if(a_es_rama_nula(nodo)) return true;

    // Si es hoja
    if(a_es_rama_nula(n_hijoizquierdo(nodo))){
        int nivel_actual = a_ej8_nivel(A, n_recuperar(nodo)->clave);
        if(*nivel_primera_hoja == -1){
            *nivel_primera_hoja = nivel_actual;
        }
        else if(nivel_actual != *nivel_primera_hoja){
            return false;
        }
        return true;
    }

    // Recorrer hijos y hermanos
    if(!mismo_nivelhojasN_ario(A, n_hijoizquierdo(nodo), nivel_primera_hoja)) return false;
    if(!mismo_nivelhojasN_ario(A, n_hijoderecho(nodo), nivel_primera_hoja)) return false;

    return true; // Ensure a return value for all paths
}

bool a_ej8_hojasmismonivel(ArbolBinario A){
    int mismo_nivel = -1;
    NodoArbol raiz = a_raiz(A);

    return mismo_nivelhojasN_ario(A, raiz, &mismo_nivel);
}

// EJERCICIO 9
void construirArbolAVL(NodoArbol nodo, ArbolAVL arbol){
    TipoElemento te;
    if(a_es_rama_nula(nodo)){   //caso base
        return;
    }
    te = te_crear(n_recuperar(nodo)->clave);
    avl_insertar(arbol, te);
    construirArbolAVL(n_hijoizquierdo(nodo), arbol);
    construirArbolAVL(n_hijoderecho(nodo), arbol);
}
ArbolAVL a_ej9_construiravl(ArbolBinario A){
    int diferencia_alturas = 0;
    NodoArbol raiz = a_raiz(A);
    ArbolAVL arbolbalanceado = avl_crear();
    if(a_es_vacio(A)){
        printf("\nla diferencia de alturas de 0. porque ambos arboles estan vacios\n");
        return arbolbalanceado;
    }
    else{
        construirArbolAVL(raiz, arbolbalanceado);
        diferencia_alturas = a_ej9_diferenciaalturas(A, arbolbalanceado); 
        printf("\nla diferencia de alturas de %d\n",diferencia_alturas);
    }
    
    return arbolbalanceado;
}

void calculandoAlturaAVL(NodoArbol nodo, int* altura, int nivel){
    if(a_es_rama_nula(nodo)){
        if(nivel > *altura){
            *altura = nivel;
        }
    }
    else{
        calculandoAlturaAVL(n_hijoizquierdo(nodo), altura, nivel+1);
        calculandoAlturaAVL(n_hijoderecho(nodo), altura, nivel+1);
    }
}

int a_ej9_diferenciaalturas(ArbolBinario A, ArbolAVL AVL){
    int altura_arbol, alturaAVL = 0;
    NodoArbol raiz = a_raiz(A);
    NodoArbol raizAVL = avl_raiz(AVL);
    altura_arbol = a_ej3_alturarama(A, n_recuperar(raiz)->clave);
    calculandoAlturaAVL(raizAVL, &alturaAVL,0);
    printf("\nla altura del arbol binario es de %d",altura_arbol);
    printf("\nla altura del arbol AVL es de %d", alturaAVL);
    return altura_arbol - alturaAVL;
}
// EJERCICIO 10
/*Dada una serie de números generados al azar, cargar la misma serie en un árbol binario de búsqueda y en un árbol binario balanceado “AVL”.  
	Comparar la altura de ambos árboles.  
	Repetir el proceso “n” veces. 
	¿Qué puede concluir al respecto?
 */
// Generamos una lista con la serie de numeros (unicos no repetidos)
// Las claves se deben generar entre "valorminimo" y "valormaximo".

Lista a_ej10_generarlistaclaves(int cantidadclavesagenerar, int valorminimo, int valormaximo){
    Lista l_al_azar = l_crear(); 
    int i = 0, clave;
    while(i < cantidadclavesagenerar){
        //generar claves al azar y agregar a la lista
        clave = rand() % (valormaximo - valorminimo + 1) + valorminimo;
        //printf("%d \n", clave);
        if(l_buscar(l_al_azar, clave) == NULL){//no existe la clave en la lista
            l_agregar(l_al_azar, te_crear(clave));
            i++;
        }
    }
    return l_al_azar;
}

// Ahora se la paso a la funcion que crea los 2 arboles
void construirArbolBB(Iterador iter, ArbolBinarioBusqueda A){
    TipoElemento te;
    if(hay_siguiente(iter) == false){
        return;
    }
    te = siguiente(iter);
    abb_insertar(A, te_crear(te->clave));
    construirArbolBB(iter, A);
}
ArbolBinarioBusqueda a_ej10_crearABB(Lista L){
    Iterador iter = iterador(L);
    ArbolBinarioBusqueda arbolBB = abb_crear();
    construirArbolBB(iter, arbolBB);
    return arbolBB;
}

void construirArbolAVL_Iterador(Iterador iter, ArbolAVL arbol){
    TipoElemento te;
    if(hay_siguiente(iter) == false){   //caso base
        return;
    }
    te = siguiente(iter);
    avl_insertar(arbol, te);
    construirArbolAVL_Iterador(iter, arbol);
}
ArbolAVL a_ej10_crearAVL(Lista L){
    Iterador iter = iterador(L);
    ArbolAVL arbol = avl_crear();
    construirArbolAVL_Iterador(iter, arbol);
    return arbol;
}

// Ahora llamos a la funcion que compara las alturas.  La comparacion es Altura(ABB) - Altura(AVL).
int a_ej10_difalturas(ArbolBinarioBusqueda ABB, ArbolAVL AVL){
    int alturaAVL = 0, alturaABB = 0, diferencia = 0;
    NodoArbol raizAVL = avl_raiz(AVL);
    NodoArbol raizABB = abb_raiz(ABB);
    calculandoAlturaAVL(raizAVL, &alturaAVL,0);
    calcularRama(raizABB, &alturaABB, 0); 
    diferencia = alturaABB - alturaAVL;

    return diferencia;
}

// Este proceso se debera repetir N veces  (N se debera poder tomar por teclado).

// LLamada general del proceso.  retorna una lista con todas las diferencias de las comparaciones.
Lista a_ej10_comparacionarboles(int N_repeticiones, int valorminimo, int valormaximo, int cantidaclavesagenerar){
    Lista l_diferencias_altura = l_crear();
    Lista l_al_azar;
    ArbolAVL arbol_AVL = avl_crear();
    ArbolBinarioBusqueda arbolBB = abb_crear();
    int i = 0, altura;
    
    

    while(i < N_repeticiones){
        l_al_azar =  a_ej10_generarlistaclaves(cantidaclavesagenerar, valorminimo, valormaximo);
        printf("\n\nrepeticion numero: %d\n\n",i+1);
        arbol_AVL = a_ej10_crearAVL(l_al_azar);
        printf("\n|| GRAFICO DEL ARBOL AVL ||\n\n");
        a_mostrar_normal_AVL(arbol_AVL);
        arbolBB = a_ej10_crearABB(l_al_azar);
        printf("\n|| GRAFICO DEL ARBOL BB ||\n\n");
        a_mostrar_normal_ABB(arbolBB);

        altura = a_ej10_difalturas(arbolBB, arbol_AVL);
        l_agregar(l_diferencias_altura, te_crear(altura));
        i++;
    }

    return l_diferencias_altura;
}

