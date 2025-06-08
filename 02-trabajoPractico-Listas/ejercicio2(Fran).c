#include "tp_2_listas.h"

Lista posicionesClaveResolucion(Iterador iter, int clave, int pos, Lista L_resultado);
//Lista edadesRecu(Lista L_edades,Lista l_resultado, Iterador iter);
Lista edadesRecu(Lista L_edades, Iterador iter);
Lista edades_en_posiciones(Lista L_edades, Lista L_posiciones);
Cola colaCopia(Cola c);
Cola existeClaveRecursiva(Cola c_respuesta, int clave, Cola c_copia);
//ejercicio recursivo listas
float promedioRecursivo(int promedio, int i, Iterador iter){
    
    if(hay_siguiente(iter) == false){
        return promedio/i;
    }
    else{
        TipoElemento elemento = siguiente(iter);
        return promedioRecursivo((promedio + elemento->clave), i+1, iter);
    }
}
float promedioLista(Lista L){
    int i = 0;
    int promedio = 0;
    Iterador iter = iterador(L);
    promedio = promedioRecursivo(promedio, i, iter);
    return promedio;
}


// ejercicio recursivo pilas

TipoElemento clave_pila_recursivo(Pila pila, int clave){
    TipoElemento elemento;
    if(p_es_vacia(pila)){
        return NULL;
    }
    elemento = p_desapilar(pila);
    if(elemento->clave == clave){
        return elemento;
    }
    else{    
        return clave_pila_recursivo(pila, clave);
    }
}
Cola copia_pila(Pila p){
    TipoElemento elemento1, elemento2;
    Pila p_auxiliar = p_crear(), p_copia = p_crear();

    while(p_es_vacia(p)){
        elemento1 = p_desapilar(p);
        elemento2 = te_crear(elemento1->clave);
        p_apilar(p_copia, elemento2);
        p_apilar(p_auxiliar, elemento1);
    }
    while (p_es_vacia(p_auxiliar)){
        elemento1 = p_desapilar(p_auxiliar);
        p_apilar(p, elemento1);
    }
    return p_copia;
}

TipoElemento clave_pila(Pila p,int clave){
    TipoElemento elemento;
    elemento = clave_pila_recursivo(p, clave);
    
}

// void main(){
//     Pila pilon1;
//     int cantidad, clave;

//     printf("Ingrese la cantidad de elementos a cargar en las pilas (max 10)\n-> ");
//     cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 1, 10);
//     printf("\nCargamos pila 1:\n");        
//     pilon1 = p_cargar(cantidad);      
//     printf("\nPILA 1: \n");
//     p_mostrar(pilon1);
//     printf("\ningrese clave:\n");   
//     scanf("%d",&clave);
//     TipoElemento elemento;
//     elemento = clave_pila(pilon1, clave);
    
//     if(elemento == NULL){
//         printf("\nno existe la clave\n");
//     }
//     else{
//         printf("\nla clave es: %d\n",elemento->clave);
//     }
//     system("pause");
// }

// bool esSublista(Lista l1, Lista l2){    //la complejidad algoritmica es cuadratica 
//     bool resultado = true, encontro = false;
//     TipoElemento v1, v2;
//     Iterador iter1 = iterador(l1);
//     Iterador iter2 = iterador(l2);

//     while ((hay_siguiente(iter2) && resultado == true)){
//         v2 = siguiente(iter2);
        
//         while ((hay_siguiente(iter1) && encontro == false)){
                
//             v1 = siguiente(iter1);
//             if(v2->clave == v1->clave){
//                 encontro = true;
//             }
//         }
//         if(encontro == false){  //si no encontro ninguna coincidencia es porque no es sublista
//             resultado = false;
//         }else{
//             iter1 = iterador(l1);//vuelve el iterador al inicio
//             encontro = false;
//         }  
//     }
//     return resultado;
// }

// Cola c_ej2_colarelemento(Cola c, int posicionordinal, TipoElemento X){
//     int contador = 0;
//     TipoElemento elemento;
//     Cola c_aux = c_crear();

//     if(c_es_llena(c)){
//         printf("la cola esta llena, por lo que no es posible encolar el elemento");
//         return c;
//     }

//     while (c_es_vacia(c) == false){
//         contador++;
//         if(contador == posicionordinal){
//             if(!c_encolar(c_aux, X)){
//                 printf("error al encolar");
//             }
//         }
//         else{
//             elemento = c_desencolar(c);
//             if(!c_encolar(c_aux, elemento)){
//                 printf("error al encolar");
//             }
//         }
//     }
//     return c_aux;}
    
// void main(){    //listas
//     Lista list1 = l_crear(), list2 = l_crear();
//     Lista resp = l_crear();
//     float promedio;
//     int cantidad, seguir = 1;


//     Lista l_prueba;
//     TipoElemento x = te_crear(1);
//     //l_agregar(l_prueba, x);
//     //Iterador iter = iterador(l_prueba);

    
    
//     printf("Ingrese la cantidad de elementos a ingresar en la lista 1\n-> ");
//     cantidad = ingresoDatosNumericosNoCero("Ingrese un numero valido!");
//     l_prueba = l_cargar(cantidad);
//     Iterador iter = iterador(l_prueba);

//     while ((x = siguiente(iter)) != NULL){
//         printf("entro %d\n", x->clave);
//     }
//     printf("salio");

//     printf("\nLISTA 1: \n");
//     l_mostrar(list1);
   
//     promedio = promedioLista(l_prueba);
//     printf("el promedio de la lista 1 es %f",promedio);
//     system("pause");
// }


                                        //PARCIAL 1

// 1.Dada una lista se desea retornar la misma lista de forma inversa. 
// La función "Lista Listalnvertida(Lista L)” recibe la lista y retorna otra de forma invertida. 
// No debe perderse la lista original. La función debe ser genérica (debe funcionar para cualquiera de las implementaciones).
// Se pide:
// a) Hacer la función Listalnvertida.
// b) Indicar la complejidad algorítmica de la función desarrollada. Fundamentar.


//PSEUCODIGO

//  1           1.2.3.4. ----> 4.3.2.1
//          
//         
//         ciclo    (hasta que el contador sea 1)
//              
//              recuperamos elemento de la lista
//              creamos nuevo TE
//              insertar lista_invertida 
//              contador--
//         
//         retornamos lista_invertida
//
 
// 2. Dada una lista, se pide retornar el/los elemento/s de la/las claves de mayor valor (no necesariamente única). 
// El proceso será genérico e iterativo y deberá funcionar para cualquiera de las implementaciones de listas vistas (arreglos, apuntadores y cursores).
// NO se puede destruir la lista. La función recibirá la lista. El resultado debe ser devuelto (no se puede mostrar en la misma función)
// Ejemplo: Es la lista "L" contiene (1, 9, 5, 1. 8, 9, 7, 1, 9) el resultado esperado será (9,9,9) 
// Se pide 
// a) Hacer la función correspondiente 
// b) Indicar la complejidad algorítmica de la función. Fundamentar. 


//
//
//          recorrer
//          comparar si es mayor e igual ---> agregar a la nueva lista
//          retornar
//
//
//
//
//
//
//
//
//
//
//



















Lista listaInvertida(Lista L){
    TipoElemento elemento;
    Lista lista_invertida = l_crear();
    int pos = l_longitud(L);
    while (pos!=0){
        elemento = l_recuperar(L,pos);
        if(!l_agregar(lista_invertida,elemento)){
            printf("error al insertar...");
            system("pause");
        }
        pos--;
    }
    
    return lista_invertida;
}

Lista listaInvertidaRecursiva(Iterador iter, Lista l_invertida, int pos){
    TipoElemento elemento;
    if(hay_siguiente(iter) == false){
        return l_invertida;
    }
    else{
        elemento = siguiente(iter);
        l_insertar(l_invertida, elemento, pos);
        return listaInvertidaRecursiva(iter,l_invertida,pos++);
    }
}
Lista listaInvertidaR(Lista l){
    Iterador iter = iterador(l);
    Lista l_invertida = l_crear();
    l_invertida = listaInvertidaRecursiva( iter, l_invertida, 1);
    return l_invertida;
}

/*
                                        PARCIAL 2

1) Dada una pila, se pide retornar el/los elemento/s de una clave que se desea buscar (no necesariamente única). 
El proceso será iterativo y deberá funcionar para cualquiera de las implementaciones de pilas vistas (arreglos y apuntadores). 
NO se puede destruir la pila. La función recibirá la pila y la clave que se desea buscar. 
El resultado debe ser devuelto (no se puede mostrar en la misma función). 

Ejemplo: si la pila "P" contiene: (1,4,5,1,8,9,7,1,3) y se pide buscar la clave "1", el resultado esperado será (1,1,1).
Se pide: 
Hacer la función correspondiente. 
Indicar la complejidad algorítmica de la función sin tener en cuenta la TAD. Fundamentar.













2) Dada una lista se desea retornar la/s posición/es ordinales de una clave dada (la lista no está ordenada y pueden existir claves repetidas). 
La función debe ser recursiva, recibe la lista y la clave a buscar. 
No debe perderse la lista original. 
La función debe funcionar para cualquier implementación de lista.
Se pide: 
Hacer la función correspondiente. 
Indicar la complejidad algorítmica de la función teniendo en cuenta la TAD. Fundamentar.
*/

Lista posicionesClave(Lista l, int clave){
    Iterador iter = iterador(l);
    Lista L_resultado = l_crear();
    int pos = 1;
    L_resultado = posicionesClaveResolucion(iter, clave, pos, L_resultado);
    return L_resultado;

}

Lista posicionesClaveResolucion(Iterador iter, int clave, int pos, Lista L_resultado){
    TipoElemento elemento,elemento2;

    if(hay_siguiente(iter) == false){
        return L_resultado;
    }
    else{
        elemento = siguiente(iter);
        if(elemento->clave == clave){
            elemento2 = te_crear(pos);
            l_agregar(L_resultado, elemento2);
        }
        return posicionesClaveResolucion(iter, clave, (pos+1), L_resultado);
    }
}
//                                      ejercicio racker

Lista edades_en_posiciones(Lista L_edades, Lista L_posiciones){
    Lista l_resultado = l_crear();
    Iterador iter = iterador(L_posiciones);
    l_resultado = edadesRecu(L_edades, l_resultado, iter);
    return l_resultado;
    
}

 Lista edadesRecu(Lista L_edades,Lista l_resultado, Iterador iter){
     TipoElemento nodo1, nodo2;
     if(hay_siguiente(iter) == false){
         return l_resultado;
     }
     nodo1 = siguiente(iter);
     nodo2 = l_recuperar(L_edades, nodo1->clave);
     l_agregar(l_resultado, te_crear(nodo2->clave));
     return edadesRecu(L_edades, l_resultado, iter);
 }
// version bian
Lista edadesRecu(Lista L_edades, Iterador iter){
    TipoElemento nodo1, nodo2;
    
    if(hay_siguiente(iter) == false){
        return l_crear();
    }
    
    nodo1 = siguiente(iter);
    Lista lista_resultado = edadesRecu(L_edades, iter);
    
    nodo2 = l_recuperar(L_edades, nodo1->clave);
    l_agregar(lista_resultado, te_crear(nodo2->clave));
    
    return lista_resultado;

}
int main(){
    //          PARCIAL 1
    /*Lista l = l_crear(), l_resultado = l_crear();
    l = l_cargar(5);
    l_mostrar(l);
    l_resultado = listaInvertida(l);
    l_mostrar(l_resultado);
    printf("lista recursiva...\n");
    l_resultado = listaInvertidaR(l);
    l_mostrar(l_resultado);
    system("pause");
    */
   
    //            PARCIAL 2
    Lista l1 = l_crear(), l2 = l_crear(), l_resultado = l_crear();
    int clave;
    l1 = l_cargar(10);
    l_mostrar(l1);
    l2 = l_cargar(5);
    l_mostrar(l2);
    l_resultado = edades_en_posiciones(l1, l2);
    printf("las edades de las posiciones son:\n");
    l_mostrar(l_resultado);
    l_mostrar(l1);
    system("pause");
    return 0;
}


Cola existeClave(Cola C, int clave){
    Cola c_respuesta = c_crear(), c_copia = c_crear();
    c_copia = colaCopia(C);
    return existeClaveRecursiva(c_respuesta, clave, c_copia);
}

Cola existeClaveRecursiva(Cola c_respuesta, int clave, Cola c_copia){
    TipoElemento elemento1, elemento2;

    if(c_es_vacia(c_copia)){
        return c_respuesta;
    }
    elemento1 = c_desencolar(c_copia);
    if(elemento1->clave == clave){
        elemento2 = te_crear(clave);
        c_encolar(c_respuesta, elemento2);
        return existeClaveRecursiva(c_respuesta, clave, c_copia);
    }
}
Cola colaCopia(Cola c){
    TipoElemento nodo,nodoaux;
    Cola aux=c_crear();
    Cola nueva=c_crear();
    while(!c_es_vacia(c)){
        nodo=c_desencolar(c);
        c_encolar(aux,nodo);
        nodoaux=te_crear(nodo->clave);
        c_encolar(nueva,nodoaux);
    }
    while(!c_es_vacia(aux)){
        nodo=c_desencolar(aux);
        c_encolar(c,nodo);
    }
    return nueva;
}