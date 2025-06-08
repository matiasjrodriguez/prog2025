#ifndef TP_ARBOLES_H
#define TP_ARBOLES_H

#include <stdbool.h>
#include <stdio.h>
#include "../libs/listas/headers/listas.h"
#include "../libs/tablashash/headers/tabla_hash.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/validaciones.h"
#include "../libs/arboles/headers/arbol-binario.h"
#include "../libs/arboles/headers/arbol-avl.h"
#include "../libs/arboles/headers/arbol-binario-busqueda.h"
#include "../libs/listas/headers/listas.h"

struct AlumnosRep{   
int legajo;   
char apellido[20];   
char nombre[20];   
char domicilio[20];   
char TE[15];    //telefono
bool Estado; 
};
typedef struct AlumnosRep Alumnos;

/**
4. Desarrollar un algoritmo que dado un archivo que contendrá los datos de alumnos  (legajo, apellido, nombres, domicilio, TE) 
   genere una tabla hash donde la clave será el legajo y se guardará como dato la posición física 
   del registro para realizar accesos directos.  
   Hacer un ABM para poder cargar manualmente el archivo.  El “legajo" es un valor de 6 dígitos. 
*/
void th_ej4_abm();


/**
5. Realizar una comparación de los tiempos de accesos a las claves entre un árbol AVL y una Tabla Hash. 
   El operador debe poder indicarle cuantas claves se deben generar (entre 1 y 2000), cuantas repeticiones 
   se realizaran y cuál es el rango de las claves a generar.   
   Luego se tomarán claves al azar dentro del mismo rango y se buscaran en ambas estructuras.  
   El proceso se repetirá “n” veces (repeticiones a ingresar por el operador).  
   Documentar la conclusión final respecto a los tiempos de accesos de ambas estructuras. 
*/
void th_ej5_comparacion(int q_claves, int q_repeticiones, int rango_desde, int rango_hasta);


/**
6. Se desea poder implementar una solución para encontrar de forma rápida los datos de las personas que a una fecha
   determinada se presentaron a vacunar contra el COVID.  
   Es decir dada una fecha determinada debería obtener quienes se vacunaron. 
   De cada persona se guarda básicamente el DNI, Apellido y Nombre.  
   Se debe además hacer una pantalla de carga donde se pueda especificar la fecha y los datos de las personas 
   que se vacunaron en esa fecha. 
*/
int th_ej6_covid();

#endif // TP_ARBOLES_H
