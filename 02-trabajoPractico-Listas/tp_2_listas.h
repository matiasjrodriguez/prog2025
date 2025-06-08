#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include "../libs/validaciones/headers/validaciones.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"

#ifndef TP_2_Listas
#define TP_2_Listas

// P2
/*
    Dada una 2 listas (L1 y L2) cargadas con valores al azar (en la clave) realizar los siguientes
    ejercicios:
        a. Que retorne una lista con los valores de L1 que no están en L2.
        b. Que retorne una lista con los valores de L2 que no están en L1.
        c. Que retorne una lista con todos los valores comunes a ambas listas (L1 y L2).
        d. Que retorne los promedios de ambas listas.
        e. Que retorne el valor mínimo de ambas listas y su posición ordinal.
*/
typedef struct
{
    float resultado1;
    float resultado2;
} Resultados;

typedef struct resultadoStruct
{
    int pos;
    int valor;
    int pos_2;
    int valor_2;
} ResultadoValorMinimo;

// Punto 2 a y b
Lista verElementosQueNoSeRepiten(Lista l1, Lista l2);
// Punto 2 C
Lista verElementosRepetidos(Lista l1, Lista l2);
// Punto 2 D
float promedio(Lista l1);
// Punto 2 E
ResultadoValorMinimo valorMinimo(Lista l1, Lista l2);

// P3
/*
Dadas 2 listas (L1 y L2) determinar si L2 es múltiplo de L1. Se considera múltiplo si cada
elemento de L2 se divide en forma exacta por el valor L1 de la misma posición. Usar la
clave como campo de datos solamente.
    Ejemplo:
    si L1 = (2, 5, 7, 3) y L2 = (8, 20, 28, 12) entonces L2 es múltiplo por L1 porque
    cada posición de L2 se divide por el valor de L1 de la misma posición en forma exacta
    (sin decimales). Si el resultado de la división retorna el mismo valor para cada posición
    se dice que “L2” es múltiplo de “L1” por un “escalar”. Para este caso “4” es el escalar
    de L1. El algoritmo debe contemplar esta situación.
*/
typedef struct
{
    bool esMultiplo;
    bool escalar;
    int numEscalar;
} ResultadosMul;
ResultadosMul multiplo(Lista l1, Lista l2);

// P4 Retorna 1 si L1 > L2, 2 si L2 > 1, 0 si son iguales.
/*
Dadas dos listas L1 y L2, se pide compararlas siempre en el sentido L1L2. Por lo tanto
puede suceder que: L1 > L2, L1 = L2 o L1 < L2. La forma de obtener la comparación es por
la clave, posición a posición, donde si L1 tiene más cantidad de claves mayores que L2 se
considera L1 > L2, por el contrario se considera L1 < L2, o de lo contrario L1 será igual a L2.
Determinar la complejidad algorítmica de la solución empleada.
*/
int CompararListas(Lista l1, Lista L2);

// P5
/*
Generar un algoritmo que guarde en una lista enlazada los coeficientes de un polinomio.
Realizar una función que dada la lista de coeficientes y un cierto valor de “X” nos devuelva
el valor del polinomio para ese punto.

Luego realizar un proceso que dado un rango de valores de “X” y un valor de intervalo
“I”, retorne una lista con los valores de “Y” o “F(x)”.
    Ejemplo:
    si el polinomio es F(x) = 2x + 1. Se pide retornar los valores de F(x) entre los “X” -1 y 1 de a “0,5”.
    Es decir se deberían retornar los valores de F(-1), F(-0,5), F(0), F(0,5) y F(1).
*/
void hacerPolinomio(Lista list);
float evaluarPolinomio(Lista list, float x);
Lista calcularRango(Lista list, double x, double y, double sumando);

// P6
/*
Generar un algoritmo que determine si una lista es sublista de otra. Se considera que es
una sublista si todos los valores de la segunda se encuentran dentro de la primera sin
importar el orden o posición de cada elemento. La comparación es solo por la clave. Se
pide además determinar la complejidad algorítmica de la solución.
    Ejemplo:
    si “L1” contiene los elementos (7, 3, 4, 5, 9, 2) y “L2” contiene los elementos
    (4, 7, 2) se dice que “L2” es sublista de “L1”. 
*/
bool esSublista(Lista l1, Lista l2);

// Utilidades
Lista rellenarLista(int elementos);

#endif // TP_2_Listas