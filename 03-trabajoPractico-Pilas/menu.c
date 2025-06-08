#include "menu.h"

// EJERCICIO 2
void menuPunto2(){
    int cantidad, maximo, minimo, num, posicionOrdinal, clave, pos1, pos2;
    bool seguir = 1;
    TipoElemento x;
    Pila pilon, pilon_resultado;

    while(seguir == 1){
        printf("Ingrese la cantidad de elementos a cargar en la pila (max 10)\n-> ");
        cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 10);
        pilon = p_cargar(cantidad);
        p_mostrar(pilon);

        // 2_A
        printf("\n|\n|__ CLAVE DEL NODO A VERIFICAR SU EXISTENCIA: ");
        num = ingresoDatosNumericos("Ingrese un valor adecuado!");
        bool resultado = p_ej2_existeclave(pilon, num);
        printf(resultado ? "\nSe encuentra '%d' en la pila\n":"\nNO se encuentra '%d' en la pila\n", num);
        
        //ejercicio 2 B
        printf("\n|\n|__ POSICION ORDINAL DONDE DESEA INSERTAR UN ELEMENTO: ");
        posicionOrdinal = ingresoIntLimitado("Ingrese una posicion ordinal adecuada!", 1, cantidad+1);
        printf("\nCLAVE DE REEMPLAZO: ");
        x = te_crear(ingresoDatosNumericos("Ingrese una clave adecuada!"));
        pilon_resultado = p_ej2_colocarelemento(pilon, posicionOrdinal,x);
        printf("PILA RESULTANTE:\n");
        p_mostrar(pilon_resultado);    
        printf("PILA ORIGINAL:\n");
        p_mostrar(pilon); 
        
        //ejercicio 2 C   
        printf("\n|\n|__ CLAVE A ELIMINAR: ");
        clave = ingresoDatosNumericos("Ingrese una clave adecuada!");
        pilon_resultado = p_ej2_eliminarclave(pilon, clave);
        printf("PILA RESULTANTE:\n");
        p_mostrar(pilon_resultado);
        printf("PILA ORIGINAL:\n");
        p_mostrar(pilon);      

        //ejercicio 2 D
        printf("\n|\n|__ INTERCAMBIO DE POSICIONES\nPOSICION 1: ");
        pos1 = ingresoIntLimitado("Ingrese una posicion adecuada!", 1, cantidad);
        printf("\nPOSICION 2: ");
        pos2 = ingresoIntLimitado("Ingrese una posicion adecuada!", 1, cantidad);
        pilon_resultado = p_ej2_intercambiarposiciones(pilon, pos1, pos2);
        printf("PILA RESULTANTE:\n");
        p_mostrar(pilon_resultado);
        printf("PILA ORIGINAL:\n");
        p_mostrar(pilon);

        seguir = preguntarContinuar();
        system("cls");
    }
}

// EJERCICIO 3
void menuPunto3(){
    Pila pilon1, pilon2;
    int cantidad;
    bool seguir = 1;

    while(seguir == 1){
        printf("Ingrese la cantidad de elementos a cargar en las pilas (max 10)\n-> ");
        cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 10);
        
        printf("\nCargamos pila 1:\n");
        pilon1 = p_cargar(cantidad);
        printf("\nCargamos pila 2:\n");
        pilon2 = p_cargar(cantidad);

        printf("\nPILA 1: \n");
        p_mostrar(pilon1);
        printf("\nPILA 2: \n");
        p_mostrar(pilon2);

        bool resultado = p_ej3_iguales(pilon1, pilon2);
        printf(resultado ? "\nLas pilas son IGUALES\n":"\nLas pilas NO SON IGUALES\n");

        printf("\n\nCOMPLEJIDAD ALGORITMICA:\nEsta funcion es de orden lineal: O(n), donde n es la cantidad de elementos en las pilas.");
        seguir = preguntarContinuar();
        system("cls");
    }
}

// EJERCICIO 4
void menuPunto4(){
    int decimal, base;
    char *resultado;
    bool seguir = 1;

    while(seguir == 1){
        printf("Ingrese el decimal a convertir\n-> ");
        decimal = ingresoDatosNumericos("Ingrese un valor adecuado!");

        printf("Ingrese la base a convertir el decimal\n-> ");
        base = ingresoIntLimitado("Ingrese una base adecuada!", 2, 16);

        resultado = p_ej4_cambiarbase(decimal, base);
        printf("%s", resultado);

        printf("\n\nCOMPLEJIDAD ALGORITMICA:\nEsta funcion es de orden logaritmico: O(log n), donde n es el valor del numero decimal original.");
        seguir = preguntarContinuar();
        system("cls");
    }
}

// EJERCICIO 5
void menuPunto5(){
    Pila pilon1, p_resultado;
    int cantidad;
    bool seguir = 1;

    while(seguir == 1){
        printf("Ingrese la cantidad de elementos a cargar en la pila (max 10)\n-> ");
        cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 10);
        
        printf("\nCargamos pila:\n");
        pilon1 = p_cargar(cantidad);
        printf("\nPILA: \n");
        p_mostrar(pilon1);

        printf("\nPILA INVERTIDA: \n");
        p_resultado = p_ej5_invertir(pilon1);
        p_mostrar(p_resultado);

        printf("\n\nCOMPLEJIDAD ALGORITMICA:\nEsta funcion es de orden lineal: O(n), donde n es la cantidad de elementos en la pila original.");
        seguir = preguntarContinuar();
        system("cls");
    }
}

// EJERCICIO 6
void menuPunto6(){
    Pila pilon1, p_resultado;
    int cantidad, opcion, clave;
    bool seguir = 1;

    while(seguir == 1){
        printf("Ingrese la cantidad de elementos a cargar en la pila (max 10)\n-> ");
        cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 10);
        
        printf("\nCargamos pila:\n");
        pilon1 = p_cargar(cantidad);
        printf("\nPILA: \n");
        p_mostrar(pilon1);

        printf("\n\nRESOLUCION RECURSIVA -- 1\nRESOLUCION ITERATIVA -- 2\n-> ");
        opcion = ingresoIntLimitado("Ingrese un valor adecuado!", 1, 2);
        printf("\nCLAVE A ELIMINAR: ");
        clave = ingresoDatosNumericos("Ingrese una clave adecuada!");
        if(opcion == 1){
            p_resultado = p_ej6_eliminarclave_r(pilon1, clave);
        }
        else{
            p_resultado = p_ej6_eliminarclave(pilon1, clave);
        }
        p_mostrar(p_resultado);

        printf("\n\nCOMPLEJIDAD ALGORITMICA: \nEsta funcion es de orden lineal: O(n), donde n es la cantidad de elementos en la pila original.");
        seguir = preguntarContinuar();
        system("cls");
    }
}
// EJERCICIO 7
void menuPunto7(){
    Pila pilon1, pilon2, p_resultado;
    int cantidad;
    bool seguir = 1;

    while(seguir == 1){
        printf("Ingrese la cantidad de elementos a cargar en las pilas (max 10)\n-> ");
        cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 10);
        
        printf("\nCargamos pila 1:\n");
        pilon1 = p_cargar(cantidad);
        printf("\nCargamos pila 2:\n");
        pilon2 = p_cargar(cantidad);

        printf("\nPILA 1: \n");
        p_mostrar(pilon1);
        printf("\nPILA 2: \n");
        p_mostrar(pilon2);

        p_resultado = p_ej7_elementoscomunes(pilon1, pilon2);
        printf("\nELEMENTOS EN COMUN: \n");
        p_mostrar(p_resultado);

        printf("\n\nCOMPLEJIDAD ALGORITMICA:\nEsta funcion es de orden cuadratico: O(n * m) donde n es el tamanio de la pila 1, \ny m es el tamanio de la pila 2.");
        seguir = preguntarContinuar();
        system("cls");
    }
}
// EJERCICIO 8
void menuPunto8(){
    Pila pilon1, p_resultado, p_aux = p_crear();
    int cantidad;
    bool seguir = 1;

    while(seguir == 1){
        printf("Ingrese la cantidad de elementos a cargar en la pila (max 10)\n-> ");
        cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 10);
        
        if(cantidad != 0){
            printf("\nCargamos la pila:\n");
        }
        pilon1 = p_cargar(cantidad);

        printf("\nPILA:\n");
        p_mostrar(pilon1);

        p_resultado = p_ej8_sacarrepetidos(pilon1);
        
        while(!p_es_vacia(p_resultado)){
            TipoElemento x = p_desapilar(p_resultado);
            //int puntero = *((int*)x->valor);
            printf("\n%d:%d", x->clave, *((int*)x->valor));
            p_apilar(p_aux, x);
        }
        while(!p_es_vacia(p_aux)){
            p_apilar(p_resultado, p_desapilar(p_aux));
        }
        printf("\n\nCOMPLEJIDAD ALGORITMICA:\nTiene una complejidad algoritmica de O(n^2) debido al doble bucle que compara\ncada elemento de la pila con todos los demas.");
        seguir = preguntarContinuar();
        system("cls");
    }
}