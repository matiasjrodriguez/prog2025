#include "tp_2_listas.h"

// EJERCICIO 2
// a. y b.
Lista verElementosQueNoSeRepiten(Lista l1, Lista l2){
    Lista resultado = l_crear();
    TipoElemento nodo1, nuevo_nodo; 
    Iterador recorrer = iterador(l1);

    while(hay_siguiente(recorrer)){
        nodo1 = siguiente(recorrer);
        if(l_buscar(l2, nodo1->clave) == NULL && l_buscar(resultado, nodo1->clave) == NULL){    
            nuevo_nodo = te_crear(nodo1->clave);
            l_agregar(resultado, nuevo_nodo);
        }
    }
    return resultado;
}

// c.
Lista verElementosRepetidos(Lista l1, Lista l2){
    Lista resultado = l_crear();
    TipoElemento nodo1, nuevo_nodo; 
    Iterador recorrer = iterador(l1);

    while(hay_siguiente(recorrer)){
        nodo1 = siguiente(recorrer);
        if(l_buscar(l2, nodo1->clave) != NULL && l_buscar(resultado, nodo1->clave) == NULL){
            nuevo_nodo = te_crear(nodo1->clave);
            l_agregar(resultado, nuevo_nodo);
        }
    }
    return resultado;
}

// d.
float promedio(Lista l1){
    float resultado = 0;
    TipoElemento nodo;
    Iterador ite = iterador(l1);

    while(hay_siguiente(ite)){
        nodo = siguiente(ite);
        resultado += nodo->clave;
    }
    resultado = (resultado/l_longitud(l1));

    return resultado;
}

// e.
ResultadoValorMinimo valorMinimo(Lista l1, Lista l2){
    ResultadoValorMinimo resultado;
    int i=1;
    TipoElemento valorL1= l_recuperar(l1,i);
    TipoElemento valorL2= l_recuperar(l2,i);
    resultado.valor = valorL1->clave, resultado.pos = i;// inicio el valor minimo
    resultado.valor_2 = valorL2->clave, resultado.pos_2 = i;// inicio el valor minimo
    Iterador ite=iterador(l1);
    Iterador ite2=iterador(l2);
    while(hay_siguiente(ite)){
        valorL1=siguiente(ite);
        
        if(valorL1->clave < resultado.valor){
            resultado.pos = i, resultado.valor = valorL1->clave;
        }
        i++;
    }
    i = 1;
    while(hay_siguiente(ite2)){
        valorL2=siguiente(ite2);
        
        if(valorL2->clave < resultado.valor_2){
            resultado.pos_2 = i, resultado.valor_2 = valorL2->clave;    //ite2->posicionActual
        }
        i++;
    }
    return resultado;
}

//EJERCICIO 3
ResultadosMul multiplo(Lista l1, Lista l2){
    TipoElemento nodo1 = l_recuperar(l1,1), nodo2 = l_recuperar(l2,1);
    int x=nodo2->clave/nodo1->clave;
    ResultadosMul multiplo_resultado = { .esMultiplo = true, .escalar = true, .numEscalar = x };
    Iterador ite =iterador(l1), ite2 =iterador(l2);
    while(hay_siguiente(ite)){
        nodo1=siguiente(ite);
        nodo2=siguiente(ite2);
        if ((nodo2->clave%nodo1->clave) != 0){
            multiplo_resultado.esMultiplo = false, multiplo_resultado.escalar = false, multiplo_resultado.numEscalar = 0;
            return multiplo_resultado;
        }
        if (nodo2->clave/nodo1->clave != x){
            multiplo_resultado.escalar = false;
        }
    }
    return multiplo_resultado;
}

// EJERCICIO 4
int CompararListas(Lista l1, Lista l2){
    TipoElemento valor1, valor2;
    Iterador iter1 = iterador(l1);
    Iterador iter2 = iterador(l2);
    int contador1 = 0, contador2 = 0;
    
    while(hay_siguiente(iter1)){    //considera que ambas listas sean iguales
        valor1 = siguiente(iter1);
        valor2 = siguiente(iter2);
        if(valor1->clave > valor2->clave){
            contador1++;
        }
        else if(valor1->clave < valor2->clave){
            contador2++;
        }
    }
    printf("La lista 1 cuenta con %d claves mayores, mientras que la lista 2 cuenta con %d claves mayores\n", contador1, contador2);
    
    if(contador1 > contador2){
        return 1;
    }
    else if(contador1 < contador2){
        return 2;
    }
    else{
        return 0;
    }
}

// EJERCICIO 5
void hacerPolinomio(Lista list) {
    int grado, coeficiente;
    printf("\nIngrese el grado del polinomio: ");
    grado = ingresoDatosNumericosPositivos("Ingrese un grado valido.");
    for (int i = grado; i>=0; i--) {
        printf("Coeficiente de x^%d: ", i);
        coeficiente = ingresoDatosNumericos("Ingrese un coeficiente valido.");
        l_agregar(list, te_crear(coeficiente));
    }
}

float evaluarPolinomio(Lista list, float X){
    float resultado = 0, potencia = 0, exponente = l_longitud(list)-1;
    Iterador iteList = iterador(list);
    TipoElemento coeficiente;

    while(hay_siguiente(iteList)){
        coeficiente = siguiente(iteList);
        if(hay_siguiente(iteList)){
            potencia = pow(X, exponente);
            resultado += coeficiente->clave * potencia;
        }
        else{
            resultado += coeficiente->clave;
        }
        exponente--;
    }

    return resultado;
}

Lista calcularRango(Lista list, double x, double y, double sumando){
    Lista resultado = l_crear();
    Iterador iteList = iterador(list);
    float valorX = 0;
    TipoElemento coeficiente; 
    float flx = x;

    while(x<=y){
        valorX = evaluarPolinomio(list, flx);
        coeficiente = te_crear(valorX);
        l_agregar(resultado, coeficiente);
        printf("\nF(%.1lf) = %.1lf", flx, valorX);
        x+= sumando;
        flx = x;
    }
    
    return resultado;
}

//EJERCICIO 6
bool esSublista(Lista l1, Lista l2){
    TipoElemento nodo_l1, nodo_l2;
    bool resultado = true;
    Iterador ite = iterador(l2);
    
    while(hay_siguiente(ite) && resultado){
        nodo_l2 = siguiente(ite);
        nodo_l1 = l_buscar(l1 ,nodo_l2->clave);
        
        if(nodo_l1 == NULL){
            resultado = false;
        }
    }
    return resultado;
}