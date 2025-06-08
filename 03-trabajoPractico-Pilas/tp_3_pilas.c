#include "tp_3_pilas.h"

// EJERCICIO 2
//a.
bool p_ej2_existeclave(Pila p, int clave){
    Pila p_aux = p_crear();
    TipoElemento nodo;
    bool resultado = false;

    while (p_es_vacia(p) != true) {
        nodo = p_desapilar(p);
        if(nodo->clave == clave){
            resultado = true;
        }
        if(!p_apilar(p_aux, nodo)){
            printf("hubo un error al apilar...\n");
        }
    }

    while (p_es_vacia(p_aux) != true) {
        nodo = p_desapilar(p_aux);
        if(!p_apilar(p, nodo)){
            printf("hubo un error al apilar...\n");
        }
    }

    return resultado;
}
//  b.	
Pila p_ej2_colocarelemento(Pila p, int posicionordinal, TipoElemento x){
    TipoElemento nodo, nodo1;
    Pila p_aux = p_crear(), p_resultado = p_crear();
    int posicion = 1;
    
    if(!p_es_llena(p)){
        while(!p_es_vacia(p)){
            nodo = p_desapilar(p);
            nodo1 = te_crear(nodo->clave);
            if(posicion == posicionordinal){
                p_apilar(p_aux, x);
            }
            p_apilar(p_aux, nodo1);
            p_apilar(p_resultado, nodo);
            posicion++;
        }
        if(posicion == posicionordinal){
            p_apilar(p_aux, x);
        }
        while(!p_es_vacia(p_resultado)){
            nodo = p_desapilar(p_resultado);
            p_apilar(p, nodo);
        }
        while(!p_es_vacia(p_aux)){
            nodo = p_desapilar(p_aux);
            p_apilar(p_resultado, nodo);
        }
    }
    else{
        printf("\nLa pila se encontraba llena por lo que no se realizaron los cambios!\n");
        return p;
    }

    return p_resultado;
}
//  c.
Pila p_ej2_eliminarclave(Pila p, int clave){
    Pila pila_aux = p_crear();
    Pila p_resultado = p_crear();
    TipoElemento x1, x2;
    bool encontro = false;

    while(!p_es_vacia(p)){ 
        p_apilar(pila_aux, p_desapilar(p));
    }

    while (!p_es_vacia(pila_aux)){
        x1 = p_desapilar(pila_aux);
        if(x1->clave != clave){
            x2 = te_crear(x1->clave);
            p_apilar(p_resultado, x2);
        }
        else{
            encontro = true;
        }
        p_apilar(p, x1);
    }
    if(!encontro){
        printf("No se encontraba en la pila la clave a eliminar.\n\n");
    }
    return p_resultado;   
}
    
//  d.	
Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2){
    Pila p_copia = p_copiar(p);
    Pila p_aux = p_crear();
    TipoElemento x, xp1, xp2;
    int cant_ele = 0;
    bool apilo;
    while (p_es_vacia(p_copia) != true){
        cant_ele ++;
        x = p_desapilar(p_copia);
        if(cant_ele == pos1){
            xp1 = te_crear(x->clave);
            apilo = p_apilar(p_aux,x);
        }
        else if(cant_ele == pos2){
            xp2 = te_crear(x->clave);
            apilo = p_apilar(p_aux, x);
        }
        else{
            
            apilo = p_apilar(p_aux, x);
        }
    }
    if(cant_ele < pos2 || cant_ele < pos1){ //el cambio esta fuera de las cantidad de posiciones que tiene la pila 
        return p_aux;
    }
    
    while (p_es_vacia(p_aux) != true){
        
        x = p_desapilar(p_aux);
        
        if(cant_ele == pos1){
            apilo = p_apilar(p_copia,xp2);    //elemento posicion 2
        }
        else if(cant_ele == pos2){
            apilo = p_apilar(p_copia, xp1);
        }
        else{
            apilo = p_apilar(p_copia,x);
        }
        cant_ele--;
    }
    if(apilo == false){
        printf("hubo un error al apilar...\n");
        return p_crear();
    }
    return p_copia;
}
//  e.
Pila p_ej2_duplicar(Pila p){
    Pila p_aux = p_crear();
    TipoElemento x, x2;
    bool apilo;
    if(p_es_vacia(p) == true){
        return p;
    }
    while (p_es_vacia(p) != true){
        x = p_desapilar(p);
        x2 = te_crear(x->clave);
        apilo = p_apilar(p_aux, x2);
        apilo = p_apilar(p_aux, x2);
    }
    while (p_es_vacia(p_aux) != true){
        x = p_desapilar(p_aux);
        x2 = te_crear(x->clave);
        apilo = p_apilar(p, x2);
        apilo = p_apilar(p, x2);
    }
    if(apilo == false){
        printf("hubo un error al apilar...\n");
        return p_crear();
    }
    return p;
    
}

//  f.
int p_ej2_cantidadelementos(Pila p){
    int cantidad = 0;
    Pila p_aux = p_crear();
    TipoElemento x, x2;
    bool apilo;

    if(p_es_vacia(p) == true){
        return 0;
    }
    while (p_es_vacia(p) != true){
        x = p_desapilar(p);
        x2 = te_crear(x->clave);
        apilo = p_apilar(p_aux, x2);
        cantidad++;
    }
    while (p_es_vacia(p_aux) != true) {
        x = p_desapilar(p_aux);
        x2 = te_crear(x->clave);
        apilo = p_apilar(p, x2);
    }
    if(apilo == false){
        printf("hubo un error al apilar...\n");
        return 0;
    }
    
    return cantidad;
}
// 3.
bool p_ej3_iguales(Pila p1, Pila p2){
    bool resultado = true ;
    TipoElemento nodo,nodo1,nodo2;
    Pila aux=p_crear();
    int j=p_ej2_cantidadelementos(p1);
    int g=p_ej2_cantidadelementos(p2);
    if (j!=g){
        resultado=false;
        return resultado;
    }
    while(p_es_vacia(p1)!=true){
        nodo=p_desapilar(p1);
        nodo1=te_crear(nodo->clave);
        nodo=p_desapilar(p2);
        nodo2=te_crear(nodo->clave);
        if(nodo1->clave != nodo2->clave){
            resultado = false;
        }
        p_apilar(aux,nodo1);
        p_apilar(aux,nodo2);
    }
    while(p_es_vacia(aux)!=true){
        nodo=p_desapilar(aux);
        nodo2=te_crear(nodo->clave);
        nodo=p_desapilar(aux);
        nodo1=te_crear(nodo->clave);
        p_apilar(p1,nodo1);
        p_apilar(p2,nodo2);
    }
    return resultado;// complejidad lineal
}
//4.
char*  p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase){ 
    Pila p_restos = p_crear();
    TipoElemento resto;
    char* resultado = malloc(33 * sizeof(char)); // Suficiente para un número binario de 32 bits + '\0'
    int index = 0;

    while (nrobasedecimal>=1){
        resto = te_crear(nrobasedecimal % nrootrabase);
        p_apilar(p_restos, resto);
        nrobasedecimal /= nrootrabase;
    }

    while (!p_es_vacia(p_restos)) {
        resto = p_desapilar(p_restos);
        if (resto->clave < 10) {
            resultado[index++] = '0' + resto->clave; // Convertir a carácter numérico
        } else {
            resultado[index++] = 'A' + (resto->clave - 10); // Convertir a carácter hexadecimal
        }
    }

    resultado[index] = '\0'; // Terminar el string
    return resultado;//complejidad lineal
}

//5.
Pila  p_ej5_invertir(Pila p){
    TipoElemento nodo, nodo1;
    Pila p_aux = p_crear();
    Pila p_invertida = p_crear();
    while(p_es_vacia(p)!=true){
        nodo=p_desapilar(p);
        nodo1=te_crear(nodo->clave);
        p_apilar(p_aux, nodo);
        p_apilar(p_invertida, nodo1);
    }
    while(p_es_vacia(p_aux)!=true){
        nodo=p_desapilar(p_aux);
        p_apilar(p, nodo);
    }
    return p_invertida;//complejidad lineal
}

//6.
// iterativo.
Pila p_ej6_eliminarclave(Pila p, int clave){
    TipoElemento nodo,nodo2;
    Pila aux = p_crear(), p_eliminadas = p_crear();
    while(p_es_vacia(p)!=true){
        nodo=p_desapilar(p);
        p_apilar(aux,nodo);
    }
    while(p_es_vacia(aux)!=true){
        nodo = p_desapilar(aux);
        if(nodo->clave!=clave){
            nodo2 = te_crear(nodo->clave);
            p_apilar(p_eliminadas, nodo2);
        }
        p_apilar(p,nodo);
    }
    return p_eliminadas;//complejidad lineal
}
//recursivo.
Pila p_ej6_eliminarclave_r(Pila p, int clave) {
    TipoElemento nodo,nodo1;
    Pila p_nueva=p_crear();
    if (p_es_vacia(p)) {
        return p_nueva;
    }
    nodo= p_desapilar(p);
    p_nueva= p_ej6_eliminarclave_r(p, clave);
    p_apilar(p, nodo);
    if (nodo->clave != clave) {
        nodo1=te_crear(nodo->clave);
        p_apilar(p_nueva,nodo1);
    }
    return p_nueva;//complejidad lineal
}

// 7.
Pila p_ej7_elementoscomunes(Pila p1, Pila p2){
    TipoElemento nodo1, nodo2, nodoaux2;
    Pila aux1=p_crear(), aux2=p_crear(), en_comun=p_crear();
    bool encontrado=false;
    while(!p_es_vacia(p1)){
        nodo1=p_desapilar(p1);
        while(!p_es_vacia(p2)){
            nodo2=p_desapilar(p2);
            if (nodo1->clave==nodo2->clave && !encontrado){
                nodoaux2 = te_crear(nodo2->clave);
                encontrado = p_apilar(en_comun, nodoaux2);
            }
            p_apilar(aux2, nodo2);
        }
        p_intercambio(aux2, p2);
        p_apilar(aux1, nodo1);
        encontrado=false;
    }
    p_intercambio(aux1,p1);
    return en_comun;//complejidad cuadratica
}

// EJERCICIO 8
Pila p_ej8_sacarrepetidos(Pila p){
    Pila p_copia = p_copiar(p), p_pendiente = p_crear(), p_resultado = p_crear();
    TipoElemento nodo1, nodo2, x;
    int* contador = malloc(sizeof(int));
    bool seguir = true;

    if(p_es_vacia(p_copia)){
        printf("\nLa pila ingresada estaba vacia");
        return p_copia;
    }
    while(seguir){
        *contador = 1;
        nodo1 = p_desapilar(p_copia);

        if(p_es_vacia(p_copia)){
            x = te_crear_con_valor(nodo1->clave, contador);
            p_apilar(p_resultado, x);
            return p_resultado;
        }

        while(!p_es_vacia(p_copia)){ 
            nodo2 = p_desapilar(p_copia);
    
            if(nodo1->clave == nodo2->clave){
                ++(*contador);
            }
            else if(nodo1->clave != nodo2->clave){
                p_apilar(p_pendiente, nodo2);
            }
        }
        x = te_crear_con_valor(nodo1->clave, contador);
        p_apilar(p_resultado, x);
        contador++;

        if(p_es_vacia(p_pendiente)){
            seguir = false;
        }
        else{
            p_copia = p_intercambio(p_pendiente, p_copia);
        }
    }
    return p_resultado;//complejidad cuadratica
}