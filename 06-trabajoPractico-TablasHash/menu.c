#include "menu.h"
#include "tp_thash.h"
static int const TAMANO = 997;

void menuPunto4(){
    int opcion, clave, cant_nodo, indice, legajo;
    bool seguir = true;
    TipoElemento te;
    TablaHash tabla = th_crear(TAMANO, &funcion_hash_mod);
    FILE* archivo = fopen("Alumnos.dat","r+b"); //Abre o crea un archivo binario para lectura / escritura
    
    if(archivo == NULL){
        archivo = fopen("Alumnos.dat", "w+b");  //Crea un archivo binario para lectura / escritura
        fclose(archivo);
        archivo = fopen("Alumnos.dat","r+b");
    }
    //ESCRIBIR TABLA
    indice = cargarTabla(tabla, archivo);
    th_mostrar(tabla);
    fclose(archivo);


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
            case 1: 
                //ABRIR ARCHIVO
                archivo = fopen("Alumnos.dat","r+b");
                legajo = ingresando_Legajo_alumno();
                te = th_recuperar(tabla,legajo);
                //VERIFICAR QUE EL LEGAJO SE ENCUENTRE EN LA TABLA
                if(te == NULL){
                    //SI NO ESTA, DAR DE ALTA EN LA TABLA
                    alta_alumno(tabla, archivo, legajo, &indice);
                }
                else{
                    alta_logica(*((int*)te->valor), archivo);     //te->valor es un puntero int
                }
                //CERRAR ARCHIVO
                printf("\n\n");
                th_mostrar_solo_ocupados(tabla);
                fclose(archivo);
                break;
            case 2: 
                //ABRIR ARCHIVO
                archivo = fopen("Alumnos.dat","r+b");
                legajo = ingresando_Legajo_alumno();
                te = th_recuperar(tabla,legajo);
                //VERIFICAR QUE EL LEGAJO SE ENCUENTRE EN LA TABLA
                if(te != NULL){
                    //SI ESTA, DAR DE BAJA DE LA TABLA
                    baja_alumno(te->clave, tabla, archivo);
                }
                else{
                    printf("\nEl alumno no se encuentra dentro del archivo\n");
                }
                //CERRAR ARCHIVO
                printf("\n\n");
                th_mostrar_solo_ocupados(tabla);
                fclose(archivo);       
                break;
            case 3: 
                archivo = fopen("Alumnos.dat","r+b");
                legajo = ingresando_Legajo_alumno();
                te = th_recuperar(tabla,legajo);
                //VERIFICAR QUE EL LEGAJO SE ENCUENTRE EN LA TABLA
                if(te != NULL){
                    modoficar_alumno(te->clave, tabla, archivo);
                    //modoficar_alumno(legajo, tabla, archivo);
                }
                else{
                    printf("\nEl legajo no pertenece a un alumno\n");
                }
                printf("\n\n");
                th_mostrar_solo_ocupados(tabla);
                fclose(archivo);
                break;
            case 4:
                //ABRIR ARCHIVO
                archivo = fopen("Alumnos.dat","r+b");
                //PEDIR LEGAJO
                legajo = ingresando_Legajo_alumno();
                te = th_recuperar(tabla,legajo);
                //VERIFICAR QUE EL LEGAJO SE ENCUENTRE EN LA TABLA
                if(te != NULL){
                    buscar_alumno(*(int*)te->valor, archivo);
                }
                else{
                    printf("\nEl legajo no pertenece a un alumno\n");
                }
                //CERRAR ARCHIVO
                printf("\n\n");
                th_mostrar_solo_ocupados(tabla);
                fclose(archivo);
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
    int opcion, clave, cant_nodo;
    int cant_claves, cant_rep, min, max;    
    bool seguir = true;

    while (seguir == 1){
        printf("\n=== MENU DE PUNTO 5 ===\n");
    
        printf("Ingrese la cantidad de claves a generar (1-2000): ");//preguntar cuantas claves (entre 1 y 2000)
        cant_claves = ingresoIntLimitado("Ingrese un valor adecuado!", 1, 2000);

        printf("\nIngrese el valor minimo para generar claves\n-> ");//rango minimo
        min = ingresoDatosNumericosPositivos("Ingrese un valor adecuado!");

        printf("\nIngrese el valor maximo para generar claves a partir de %d : \n-> ",(min + (cant_claves-1)));//rango maximo
        max = ingresoIntMinimo("Ingrese un valor adecuado!", (min + (cant_claves-1)));

        printf("\nIngrese la cantidad de repeticiones a realizar: ");//cuantas repeticiones
        cant_rep = ingresoDatosNumericosNoCero("Ingrese un valor adecuado!");
                    
        th_ej5_comparacion(cant_claves, cant_rep, min, max);
            
        seguir = preguntarContinuar();
        printf("\n\n");
        system("pause");
        system("cls");    
    }
        
}
void menuPunto6_v2(){

    TablaHash tabla = th_crear(TAMANO, &funcion_hash_mod);
    int opcion, clave, cant_nodo,indice, dni;
    bool seguir = true;
    ArbolAVL avl1, avl2;
    FichaVacunados *ficha = (FichaVacunados*)malloc(sizeof(FichaVacunados));;
    TipoElemento te, te2;

    while (seguir == 1){
        printf("\n=== MENU DE PUNTO 6 ===\n");
        printf("1. Cargar persona en ficha de vacunacion\n");
        printf("2. Eliminar persona de ficha de vacunacion. datos necesario: fecha y dni\n");
        printf("3. Modificar datos de una persona de vacunacion por fecha. datos necesario: fecha y dni\n");
        printf("4. Mostrar ficha de vacunacion por fecha\n");
        printf("0. Salir \n");
        printf("> Seleccione una opcion: ");
        opcion = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 4);
        system("cls");

        switch (opcion){
            case 0:
                printf("Seguro que desea salir?");
                seguir = !preguntarContinuar();   
                break;

            case 1:  
                cargar_vacunados(tabla);    
                break;
            case 2:  

                //INGRESAR fecha
                ficha->fecha = ingresando_fecha();
                //cargar archivo
                te = th_recuperar(tabla, ficha->fecha);
                
                if(te != NULL){ //si se encuentra en la tabla
                    avl2 = (ArbolAVL)te->valor;
                    ficha->DNI = ingresando_dni();
                    if((te2 = avl_buscar(avl2, ficha->DNI)) == NULL){   //si no existe el dni en determinada fecha, nadie se vacuno ese dia //ficha->DNI  //te->clave
                        //PRINTF NO SE ENCUENTRA                        
                        printf("\nNo hubo personas vacunadas en dicha fecha con dicho DNI\n");
                        system("pause");
                    }
                    else{//si hay personas vacunadas en esa fecha
                        //ingresan el dni
                        //dni = ingresando_dni();
                        //verifico que el dni sea corrercto
                        //te2 = th_recuperar(tabla, ficha->DNI);
                        
                        if(te2 != NULL){    //si se encuentra en la tabla
                            avl1 = (ArbolAVL)te->valor;
                            //borro en arbol
                            if(!avl_eliminar(avl1, te2->clave)){//eliminamos la clave del arbol
                                printf("\nHubo un error al eliminar la clave del arbol\n");
                                system("pause");
                            }  
                             //borro en th
                            else if(th_eliminar(tabla,ficha->DNI)){//eliminamos la clave de la tabla
                                printf("\nHubo un error al eliminar la persona de la tabla\n");
                                system("pause");
                            }
                            else{
                                printf("\nLa persona fue eliminada con exito\n");
                            }
                        }
                        else{
                            printf("\nEl dni ingresado no coincide con uno existente en dicha fecha\n");
                            printf("Por favor vuelva a intentarlo\n");
                            system("pause");
                        }

                    }
                    
                }
                else{   //caso contrario
                    printf("No hubo personas vacunadas en dicha fecha\n");
                    printf("Por favor vuelva a intentarlo\n");
                    system("pause");
                }
                
                break;
            case 3:  
                               
                //INGRESAR fecha
                ficha->fecha = ingresando_fecha();
                //cargar archivo
                te = th_recuperar(tabla, ficha->fecha);
                
                if(te != NULL){ //si se encuentra en la tabla
                    avl2 = (ArbolAVL)te->valor;
                    ficha->DNI = ingresando_dni();
                    if((te2 = avl_buscar(avl2, ficha->DNI)) == NULL){   //si no existe el dni en determinada fecha, nadie se vacuno ese dia
                        //PRINTF NO SE ENCUENTRA                        
                        printf("No hubo personas vacunadas en dicha fecha con dicho DNI\n");
                        system("pause");
                    }
                    else{//si hay personas vacunadas en esa fecha
                        //ingresan el dni
                        //dni = ingresando_dni();
                        //verifico que el dni sea corrercto
                        //te2 = th_recuperar(tabla, dni);
                        
                        if(te2 != NULL){    //si se encuentra en la tabla
                            avl1 = (ArbolAVL)te->valor;
                            //borro en arbol
                            if(!avl_eliminar(avl1, te2->clave)){//eliminamos la clave del arbol
                                printf("Hubo un error al modificar la clave del arbol\n");
                                system("pause");
                            }  
                             //borro en th
                            else if(th_eliminar(tabla,dni)){//eliminamos la clave de la tabla
                                printf("Hubo un error al modificar la persona de la tabla\n");
                                system("pause");
                            }
                            else{
                                cargar_vacunados(tabla);
                            }
                        }
                        else{
                            printf("El dni ingresado no coincide con uno existente en dicha fecha\n");
                            printf("Por favor vuelva a intentarlo\n");
                            system("pause");
                        }

                    }
                }
                else{   //caso contrario
                    printf("No hubo personas vacunadas en dicha fecha\n");
                    printf("Por favor vuelva a intentarlo\n");
                    system("pause");
                }
                
                break;
            case 4: 
                mostrar_vacunados(tabla);
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