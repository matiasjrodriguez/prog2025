#include "menu.h"
static const int TAMANIO_MAXIMO = 100;
// EJERCICIO 2
void menuPunto2(){
    int cantidad, num, opcion, posicion, clave, claveEliminar, cantidadElementos;
    bool seguir = 1;
    bool resultado;
    TipoElemento x, nuevo;
    Cola cola_tp, nuevaCola, copiaCola, colaInvertida;

    cola_tp = c_cargar_cantidad();
    c_mostrar(cola_tp);

    while (seguir == 1) {
        printf("\n=== MENU DEL PUNTO 2 ===\n");
        printf("1. Ejercicio A \n");
        printf("2. Ejercicio B \n");
        printf("3. Ejercicio C \n");
        printf("4. Ejercicio D \n");
        printf("5. Ejercicio E \n");
        printf("6. Ejercicio F \n");
        printf("> Seleccione una opcion: ");
        opcion = ingresoIntLimitado("Ingrese un valor adecuado!", 1, 6);

        switch (opcion) {
            case 1:
                c_mostrar(cola_tp);
                printf("\n|\n|__ CLAVE DEL NODO A VERIFICAR SU EXISTENCIA: ");
                num = ingresoDatosNumericos("Ingrese un valor adecuado!");
                resultado = c_ej2_existeclave(cola_tp, num);
                printf(resultado ? "\nSe encuentra '%d' en la cola\n" : "\nNO se encuentra '%d' en la cola\n", num);
                break;

            case 2:
                c_mostrar(cola_tp);
                cantidad = c_ej2_contarelementos(cola_tp);
                printf("\n|\n|__ POSICION DONDE INSERTAR EL NUEVO ELEMENTO (entre 1 y %d): ", cantidad);
                posicion = ingresoIntLimitado("Posicion invalida!", 1, cantidad + 1);

                printf("|__ CLAVE DEL NUEVO ELEMENTO A INSERTAR: ");
                clave = ingresoDatosNumericos("Ingrese un valor adecuado!");
                nuevo = te_crear(clave);

                nuevaCola = c_ej2_colarelemento(cola_tp, posicion, nuevo);
                printf("\nElemento con clave '%d' insertado en posicion %d.\n", clave, posicion);
                c_mostrar(nuevaCola);
                break;

            case 3:
            // error al querer eliminar ultimo elemento en la cola
                c_mostrar(cola_tp);
                printf("\n|\n|__ CLAVE DEL ELEMENTO A ELIMINAR DE LA COLA: ");
                claveEliminar = ingresoDatosNumericos("Ingrese un valor adecuado!");
                nuevaCola = c_ej2_sacarelemento(cola_tp, claveEliminar);
                printf("COLA RESULTANTE:\n");
                c_mostrar(nuevaCola);
                break;

            case 4:
                c_mostrar(cola_tp);
                cantidadElementos = c_ej2_contarelementos(cola_tp);
                printf("\nLa cantidad de elementos en la cola es: %d\n", cantidadElementos);
                break;

            case 5:
                c_mostrar(cola_tp);
                copiaCola = c_ej2_copiar(cola_tp);
                printf("\nSe ha realizado una copia de la cola.\n");
                c_mostrar(copiaCola);
                break;

            case 6:
                c_mostrar(cola_tp);
                printf("\nInvirtiendo el contenido de la cola...\n");
                colaInvertida = c_ej2_invertir(cola_tp);
                printf("Cola invertida:\n");
                c_mostrar(colaInvertida);
                break;
        }

        seguir = preguntarContinuar();
        system("cls");
    }
}

// EJERCICIO 3
void menuPunto3(){
    Cola cola1, cola2;
    int cola_cantidad;
    bool seguir = true;

    while(seguir == 1){
        cola1 = c_cargar_cantidad();
        c_mostrar(cola1);
        printf("\n");
        cola2 = c_cargar_cantidad();
        c_mostrar(cola2);
        
        bool resultado = c_ej3_iguales(cola1, cola2);
        printf("\n\nRESULTADO:\n");
        printf(resultado? "Las colas son iguales\n":"Las colas no son iguales\n");

        seguir = preguntarContinuar();
        system("cls");
    }
}

// EJERCICIO 4
void menuPunto4(){
    int cantidad;
    bool seguir = 1;
    Cola cola, cola_resultado;

    while(seguir == 1){
        cola = c_cargar_cantidad();
        c_mostrar(cola);
        cola_resultado = c_ej4_colanorepetidos(cola);
        printf("\nELEMENTOS NO REPETIDOS:\n");
        c_mostrar(cola_resultado);

        seguir = preguntarContinuar();
        system("cls");
    }    
}

// EJERCICIO 5
void menuPunto5(){
    Cola cola;
    int cantidad;
    int num, guia;
    TipoElemento nodo;

    bool seguir = 1;
    while(seguir == 1)
    {
        cola = c_crear();
        printf("Ingrese la cantidad de elementos de la cola: ");
        do{
            cantidad = ingresoDatosNumericosPositivos("Ingrese una cantidad valida! -> ");
            if(cantidad < 1 || cantidad > TAMANIO_MAXIMO)
            {
                printf("La cola debe tener entre 1 y %i elementos! -> ",TAMANIO_MAXIMO);
            }
        }while(cantidad < 1 || cantidad > TAMANIO_MAXIMO);

        guia = 0;
        while(!c_es_llena(cola) && guia<cantidad){
            do{
                printf("  | CLAVE NODO %d | ->\t", guia+1);
                num = ingresoDatosNumericos("Ingrese una clave valida! -> ");
                if((num<2 || num>1000000) || c_buscar(cola,num))
                {
                    printf("Ingrese una clave igual o mayor a 2 que no este ya en la cola! -> ");
                }
            }while((num<2 || num>1000000) || c_buscar(cola,num));
            nodo = te_crear(num);
            c_encolar(cola, nodo);
            guia++;
        }

        printf("\nImprimiendo cola con divisores totales (verdadero) y parciales (falso)...\n");
        printf("Valor del elemento // Es divisor total/parcial\n");
        Cola divisores = c_ej5_divisortotal(cola);
        c_mostrar_con_valor(divisores);
        if (c_longitud(divisores) == 0)
        {
            printf("\nLa cola esta vacia! No hay divisores totales ni parciales!\n");
        }
        c_liberar_memoria(cola);

        seguir = preguntarContinuar();
        system("cls");
    }
}

// EJERCICIO 6
void menuPunto6(){
    Lista lista_resultado;
    TipoElemento nodo;
    Cola cola_tp;
    Pila pilon;
    int pila_cantidad, cola_cantidad;
    bool seguir = true;

    while(seguir == 1){
        printf("Ingrese la cantidad de elementos a cargar en la pila (max %i)\n-> ", TAMANIO_MAXIMO);
        pila_cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 1, TAMANIO_MAXIMO);
        pilon = p_cargar(pila_cantidad);
        p_mostrar(pilon);
        printf("\n\n");
        cola_tp = c_cargar_cantidad();
        c_mostrar(cola_tp);
        
        lista_resultado = c_ej6_comunesapilaycola(pilon, cola_tp);
        Iterador recorrer_lista = iterador(lista_resultado);
        printf("|\n|__ LISTA DE COMUNES ENTRE LA PILA Y COLA: ");
        while(hay_siguiente(recorrer_lista)){
            nodo = siguiente(recorrer_lista);
            printf("(%d:%s) ", nodo->clave, (char*)nodo->valor);
        }

        seguir = preguntarContinuar();
        system("cls");
    }
}

// EJERCICIO 7
void menuPunto7(){
    Cola cola1 = c_crear(), cola2 = c_crear(), cola3 = c_crear(), cola_resultado = c_crear();
    TipoElemento nodo;
    int cola1_cantidad, cola2_cantidad, cola3_cantidad, tiempoatencion;
    bool seguir = true;
    
    while(seguir == 1){
    
        printf("Ingrese la cantidad de elementos a cargar en la cola 1 (max %i)\n-> ", (TAMANIO_MAXIMO - 2));
        cola1_cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 1, (TAMANIO_MAXIMO - 2));
        cola1 = c_cargar(cola1_cantidad);
        system("cls");
        
        printf("Ingrese la cantidad de elementos a cargar en la cola 2 (max %i)\n-> ", (TAMANIO_MAXIMO - 1 - cola1_cantidad));
        cola2_cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 1, (TAMANIO_MAXIMO - 1 - cola1_cantidad));
        cola2 = c_cargar(cola2_cantidad);
        system("cls");
        
        printf("Ingrese la cantidad de elementos a cargar en la cola 3 (max %i)\n-> ", (TAMANIO_MAXIMO - cola1_cantidad - cola2_cantidad));
        cola3_cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 1, (TAMANIO_MAXIMO - cola1_cantidad - cola2_cantidad));
        cola3 = c_cargar(cola3_cantidad);
        system("cls");
        printf("Cola 1:\n");
        c_mostrar(cola1);
        printf("Cola 2:\n");
        c_mostrar(cola2);
        printf("Cola 3:\n");
        c_mostrar(cola3);
        system("pause");
        printf("ingrese el tiempo de atencion:\n");
        tiempoatencion = ingresoDatosNumericosPositivos("Ingrese un valor adecuado!");
        cola_resultado = c_ej7_atenderclientes(cola1, cola2, cola3, tiempoatencion);
       
        printf("\n__ CLIENTES __\n");
        if(!c_es_vacia(cola_resultado)){
            while(!c_es_vacia(cola_resultado)){
                nodo = c_desencolar(cola_resultado);
                printf("%s\n", (char*)nodo->valor);
            }
        }
        else{
            printf("COLA VACIA !!! \n");
        }
        c_mostrar(cola1);
        c_mostrar(cola2);
        c_mostrar(cola3);
        seguir = preguntarContinuar();
        system("cls");
    }
}