#include "menu.h"

void menuPunto2(){
    Lista list1, list2;
    Lista resp = l_crear();
    ResultadoValorMinimo min;
    float l_promedio = 0;
    int cantidad, seguir = 1;

    while(seguir == 1){
    printf("Ingrese la cantidad de elementos a ingresar en la lista 1\n-> ");
    cantidad = ingresoDatosNumericosNoCero("Ingrese un numero valido!");
    list1 = l_cargar_azar(cantidad);

    printf("\nIngrese la cantidad de elementos a ingresar en la lista 2: ");
    cantidad = ingresoDatosNumericosNoCero("Ingrese un numero valido!");
    list2 = l_cargar_azar(cantidad);

    printf("\nLISTA 1: \n");
    l_mostrar(list1);
    printf("\nLISTA 2: \n");
    l_mostrar(list2);
    system("pause");

    printf("|\n|__ A: VALORES DE LISTA_1 QUE NO ESTAN EN LISTA_2:\n");
    resp = verElementosQueNoSeRepiten(list1, list2);
    l_mostrar(resp);
    printf("|\n|__ B: VALORES DE LISTA_2 QUE NO ESTAN EN LISTA_1:\n");
    resp = verElementosQueNoSeRepiten(list2, list1);
    l_mostrar(resp);

    printf("|\n|__ C: VALORES COMUNES ENTRE LAS LISTAS:\n");
    resp = verElementosRepetidos(list2, list1);
    l_mostrar(resp);

    printf("|\n|__ D: PROMEDIO DE VALORES DE LAS LISTAS:\n");
    l_promedio = promedio(list1);
    printf("Promedio lista 1: %lf", l_promedio);
    l_promedio = promedio(list2);
    printf("\nPromedio lista 2: %lf\n", l_promedio);

    printf("|\n|__ E: VALORES MINIMOS DE CADA LISTA:\n");
    min = valorMinimo(list1, list2);
    printf("Lista 1: valor %d en la posicion %d\n", min.valor, min.pos);
    printf("Lista 2: valor %d en la posicion %d", min.valor_2, min.pos_2);
    
    seguir = preguntarContinuar();
    system("cls");
    }
    system("pause");    
}

void menuPunto3(){
    ResultadosMul resp;
    Lista list1, list2;
    int cantidad, seguir = 1;

    while(seguir == 1){
        printf("Ingrese la cantidad de elementos a ingresar en las listas\n-> ");
        cantidad= ingresoDatosNumericosNoCero("Ingrese un numero valido!");


        printf("\nCargamos lista 1:\n");
        list1 = l_cargar(cantidad);
        printf("\nCargamos lista 2:\n");
        list2 = l_cargar(cantidad);

        printf("\nLISTA 1: \n");
        l_mostrar(list1);
        printf("\nLISTA 2: \n");
        l_mostrar(list2);

        printf("|\n|\n|__RESULTADOS DE LOS ANALISIS (si son multiplos, si hay un escalar y cual):\n");
        resp = multiplo(list1, list2);
        printf(resp.esMultiplo? "\nLista 2 es multiplo de Lista 1":"\nLista 2 NO es multiplo de Lista 1");
        printf(resp.escalar? "\nExiste un numero escalar: %d":"\nNO existe un numero escalar", resp.numEscalar);

        seguir = preguntarContinuar();
        system("cls");
    }
}

void menuPunto4(){
    Lista lista1, lista2;
    int cantidad, seguir = 1, resultado;
    while(seguir == 1){
        printf("Ingrese la cantidad de elementos que queres ingresar en las listas\n-> ");
        cantidad = ingresoDatosNumericosNoCero("Ingrese un numero valido!");
        printf("Ingrese los elementos de lista 1->\n ");
        lista1 = l_cargar(cantidad);
        printf("Ingrese los elementos de lista 2->\n ");
        lista2 = l_cargar(cantidad);
    
        printf("\nLISTA 1: \n");
        l_mostrar(lista1);
        printf("\nLISTA 2: \n");
        l_mostrar(lista2);
        printf("\n");
        resultado = CompararListas(lista1, lista2);
        mostrarComparacion(resultado);

        printf("\n\nLa complejidad de la resolucion es lineal O(n) = n\n");
        printf("\n");
        seguir = preguntarContinuar();
        system("cls");
    }
}

void menuPunto5(){
    Lista polinomio = l_crear();
    Lista resultado;
    double desde, hasta, intervalo;
    bool seguir = 1;

    while(seguir == 1){
        printf("Ingrese desde que valor de X: ");
        desde = ingresoDatosFloat("Ingrese un valor adecuado!");
        printf("\nIngrese hasta que valor de X: ");
        hasta = ingresoDatosFloat("Ingrese un valor adecuado!");
        printf("\nIngrese el intervalo: ");
        intervalo = ingresoDatosFloatPositivos("Ingrese un valor adecuado! Positivos sin el '+'.");

        hacerPolinomio(polinomio);
        resultado = calcularRango(polinomio, desde, hasta, intervalo);
        printf("\n\n>>> RESULTADOS DE F(X):\n");
        l_mostrar(resultado);

        seguir = preguntarContinuar();
        system("cls");
    }
}

void menuPunto6(){
    Lista list1, list2;
    int cantidad, seguir = 1;
    bool resultado;
    while(seguir == 1){
        printf("Ingrese la cantidad de elementos a ingresar en la lista 1\n-> ");
        cantidad = ingresoDatosNumericosNoCero("Ingrese un numero valido!");
        list1 = l_cargar(cantidad);

        printf("\nIngrese la cantidad de elementos a ingresar en la lista 2: ");
        cantidad = ingresoDatosNumericosNoCero("Ingrese un numero valido!");
        list2 = l_cargar(cantidad);

        printf("\nLISTA 1: \n");
        l_mostrar(list1);
        printf("\nLISTA 2: \n");
        l_mostrar(list2);
        resultado = esSublista(list1, list2);
        printf(resultado ? "|\n|\n|__La 'lista 2' es una sublista de la 'lista 1'\n":"|\n|\n|__La 'lista 2' NO es una sublista de la 'lista 1'\n");

        printf("\nCOMPLEJIDAD ALGORITMICA: O(n * m),\n'n' es el tamanio de la lista l2 y 'm' es el tamanio de la lista l1.\nPara cada elemento de l2, se realiza una busqueda lineal en l1.\n");
        seguir = preguntarContinuar();
        system("cls");
    }
}