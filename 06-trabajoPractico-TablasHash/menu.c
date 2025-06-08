#include "menu.h"
#include "tp_thash.h"
static int const TAMANO = 997;

//cargar nombre, apellido, legajo(no puede tener mas de 6 digitos), domicilio ,telefono
//actualizar estado cuando entra en la tabla
void menuPunto4(){
    //TablaHash tabla = th_crear(TAMANO, &funcion_hash_mod);  //verificar parametros
    //FILE* archivo;
    char nombre[] = "Alumnos.dat";
    Alumnos alumno;
    
    int opcion, clave, cant_nodo;
    bool seguir = true;

    while (seguir == 1){
        printf("\n=== MENU DE PUNTO 4 ===\n");
        printf("1. dar de alta un alumno\n");
        printf("2. dar de baja un alumno\n");
        printf("3. modificar datos de un alumno\n");
        printf("4. buscar un alumno\n");
        printf("0. Salir \n");
        printf("> Seleccione una opcion: ");
        opcion = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 4);
        system("cls");

        switch (opcion){
    
            case 0:
                printf("Seguro que desea salir?");
                seguir = !preguntarContinuar();   
                break;

            case 1: // ejercicio a
                cargando_alumno(&alumno);
                // printf("%s\n",alumno->nombre);
                // printf("%s\n",alumno->apellido);
                // printf("%s\n",alumno->domicilio);
                // printf("%s\n",alumno->TE);
                // printf("%d\n",alumno->legajo);
                break;
            
            case 2: // ejercicio b
         
                break;
                
            case 3: // ejercicio c

                break;
            case 4:
                
                break;

            default:
                printf("AVISO: Ingrese un numero parte de las opciones.\n");
                break;
        }
        printf("\n\n");
        system("pause");
        system("cls");
    }
    

}

void menuPunto5(){
    printf("sin realizar...\n");
    system("pause");
}

void menuPunto6(){
    printf("sin realizar...\n");
    system("pause");
}