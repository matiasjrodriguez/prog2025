#include "tp_thash.h"


/**
4. Desarrollar un algoritmo que dado un archivo que contendrá los datos de alumnos  (legajo, apellido, nombres, domicilio, TE) 
   genere una tabla hash donde la clave será el legajo y se guardará como dato la posición física 
   del registro para realizar accesos directos.  
   Hacer un ABM para poder cargar manualmente el archivo.  El “legajo" es un valor de 6 dígitos. 
*/

int funcion_hash_mod(int clave){
    return clave % 997;
}

void cargando_alumno(Alumnos* alumno){
    char *nombre, *apellido, *domicilio, *telefono;
    int legajo;

    nombre = ingresando_Nombre_Alumno();
    apellido = ingresando_Nombre_Alumno();
    domicilio = ingresando_Domicilio_Alumno();
    telefono = ingresando_Telefono_Alumno();
    alumno->legajo = ingresando_Legajo_alumno();

    strcpy(alumno->nombre, nombre);
    strcpy(alumno->apellido, apellido);
    strcpy(alumno->domicilio, domicilio);
    strcpy(alumno->TE, telefono);
}

void carga_archivo(Alumnos* alumno){
    int clave = funcion_hash_mod(alumno->legajo);
    alumno->Estado=true;
    FILE* archivo=fopen("Alumnos.dat","rb+"); //abre el archivo, lo crea en caso de que no exista
    fseek(archivo,clave * sizeof(alumno),SEEK_SET); //pos 0, hasta la pos de la clave
    fwrite(alumno,sizeof(alumno),1,archivo);    //escribe la linea
    fclose(archivo);
}
void th_ej4_abm(){
    
}


/**
5. Realizar una comparación de los tiempos de accesos a las claves entre un árbol AVL y una Tabla Hash. 
   El operador debe poder indicarle cuantas claves se deben generar (entre 1 y 2000), cuantas repeticiones 
   se realizaran y cuál es el rango de las claves a generar.   
   Luego se tomarán claves al azar dentro del mismo rango y se buscaran en ambas estructuras.  
   El proceso se repetirá “n” veces (repeticiones a ingresar por el operador).  
   Documentar la conclusión final respecto a los tiempos de accesos de ambas estructuras. 
*/
void th_ej5_comparacion(int q_claves, int q_repeticiones, int rango_desde, int rango_hasta){

}


/**
6. Se desea poder implementar una solución para encontrar de forma rápida los datos de las personas que a una fecha
   determinada se presentaron a vacunar contra el COVID.  
   Es decir dada una fecha determinada debería obtener quienes se vacunaron. 
   De cada persona se guarda básicamente el DNI, Apellido y Nombre.  
   Se debe además hacer una pantalla de carga donde se pueda especificar la fecha y los datos de las personas 
   que se vacunaron en esa fecha. 
*/
int th_ej6_covid(){

}
