#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include "../../listas/headers/listas.h"
#include "../../pilas/headers/pilas.h"
#include "../../colas/headers/colas.h"
#include "../../tipoElemento/headers/tipo_elemento.h"
#include "../../arboles/headers/arbol-binario.h"
#include "../../arboles/headers/arbol-binario-busqueda.h"
#include "../../arboles/headers/arbol-avl.h"

#ifndef VALIDACIONES_H
#define VALIDACIONES_H


/* >>>>> VALIDACIONES DE STRINGS DE NUMEROS <<<<< */

bool esDigito(const char * cadena); // Retorna TRUE si el string representa solo números enteros.

bool esDigito_positivo(const char * cadena); // Retorna TRUE si el string representa solo números enteros positivos.

bool noEsCero(const char * cadena); // Retorna TRUE si el string representa un numero distinto de cero.

bool esFlotante(const char *c);

bool esFlotantePositivo(const char *c);


/* >>>>> VALIDACIONES DE STRINGS <<<<< */

bool esAlfabetico(const char *c); // Retorna TRUE si el string representa solo valores alfabeticos.

bool soloEspacios(char* ); // Retorna TRUE si el string contiene al menos un caracter.

bool masDeUnCaracter(char*); // Retorna TRUE si el string contiene mas de a un caracter.

bool contieneEspacios(const char *);    //Retorna TRUE si el string NO contiene espacios.

bool soloHyL(char senial[]);    //si la señal solo contiene h o l retorna verdadero.

bool verificandoSenial(char senial[]);  //si la señal solo contiene h o l retorna verdadero.


/* >>>>> INGRESOS <<<<< */

char* ingresa_palabra(char* );  // Facilita el ingreso de un string. 

bool ingresoDatosNumericosEnter(const char *mensaje_error, int *num);

int ingresoDatosNumericos(char * mensaje_error); // Facilita el ingreso y la validacion de valores numericos.

int ingresoDatosNumericosPositivos(char * mensaje_error); // Facilita el ingreso y la validacion de valores numericos positivos >= 0.

int ingresoDatosNumericosNoCero(char * mensaje_error); // Facilita el ingreso y la validacion de valores numericos positivos > 0.

int ingresoIntLimitado(char * mensaje_error, int minimo, int maximo); // Ingreso de valores 'int' estableciento un rango.

double ingresoDatosFloat(char *mensaje_error); // Facilita el ingreso y la validacion de valores float.

double ingresoDatosFloatPositivos(char *mensaje_error); // Facilita el ingreso y la validacion de valores float positivos >= 0.


/* >>>>> HERRAMIENTAS <<<<< */

char* sacarEspacios(char* ); // Elimina los espacios de un string.

void todoAMayusculas(char* string); // Convierte un string a mayusculas.

int preguntarContinuar(); // Pregunta si se desea continuar

int leerEnteroPositivo(const char* mensaje);

void reemplazarComasPorPuntos(char *c);

void mostrarComparacion(int respuesta); 

void mostrarPolinomio(Lista list);


/*-----------------------------------------------------------
  >>>>>>>>>>>>>>>>>>>>>>     LISTAS    <<<<<<<<<<<<<<<<<<<<<
-----------------------------------------------------------*/

Lista l_cargar(int nodos); // Carga por teclado la lista según la cantidad recibida.

Lista l_cargar_azar(int cantidad); // Genera valores aleatorios entre 0 y 150.

Lista l_cargar_azar_limitada(int cantidad, int maximo, int minimo); // Genera valores aleatorios de manera controlada.


/*-----------------------------------------------------------
  >>>>>>>>>>>>>>>>>>>>>>     PILAS    <<<<<<<<<<<<<<<<<<<<<<
-----------------------------------------------------------*/

Pila p_cargar(int cantidad); // Carga por teclado la pila según la cantidad recibida.

Pila p_cargar_azar(int cantidad); // Genera valores aleatorios entre 0 y 150.

Pila p_cargar_azar_limitada(int cantidad, int maximo, int minimo); // Genera valores aleatorios de manera controlada.

Pila p_intercambio(Pila auxiliar, Pila p_original); // recibe pila auxiliar, devuelve pila original.

Pila p_copiar(Pila original); // Retorna una copia de la pila recibida.


/*-----------------------------------------------------------
  >>>>>>>>>>>>>>>>>>>>>>     colas    <<<<<<<<<<<<<<<<<<<<<<
-----------------------------------------------------------*/

Cola c_cargar(int cantidad); // Carga por teclado la cola según la cantidad recibida.

Cola c_cargar_cantidad(); 

bool c_buscar(Cola cola, int clave);

Cola c_intercambiar(Cola cola); // hacemos una nueva cola sin perder la original

int c_longitud(Cola cola);

void c_mostrar_con_valor(Cola cola);

void c_liberar_memoria(Cola cola);


/*-----------------------------------------------------------
  >>>>>>>>>>>>>>>>>>>>>     arboles    <<<<<<<<<<<<<<<<<<<<<
-----------------------------------------------------------*/

int a_cargar(ArbolBinario arbol, NodoArbol padre, int opcion);

NodoArbol a_buscar_nodo(ArbolBinario arbol, int clave);

ArbolBinario a_cargar_anchura();

ArbolBinario a_cargar_azar(int cantidad_nodos); // carga un arbol con valores 'X' UNICOS, NO REPETIDOS X=[1-100]

ArbolBinario a_cargar_azar_rep(int cantidad_nodos); // carga un arbol con valores 'X' que PUEDEN SER REPETIDOS X=[1-100]

ArbolBinario nArio_cargar_anchura();

ArbolBinario nArio_cargar_azar(int cantidad_nodos);

ArbolBinario nArio_cargar_azar_rep(int cantidad_nodos);

ArbolBinario a_modo_carga();

ArbolBinario nArio_modo_carga();

void a_mostrar_normal(ArbolBinario arbol);

void a_mostrar_normal_AVL(ArbolAVL arb);

void a_mostrar_normal_ABB(ArbolBinarioBusqueda arb);

void in_orden(NodoArbol N);

bool esBinarioTransformado(NodoArbol raiz);



//tablas hash

char* ingresando_Nombre_Alumno();

int ingresando_Legajo_alumno();

char* ingresando_Domicilio_Alumno();

char* ingresando_Telefono_Alumno();



#endif // VALIDACIONES_H