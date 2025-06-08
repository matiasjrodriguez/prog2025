#include "menu.h"

// EJERCICIO 2
void menuPunto2(){
    NodoArbol nodo;
    Lista l_resultado;
    int opcion, clave, cant_nodo;
    bool seguir = true;

    ArbolBinario arbolito = a_modo_carga();
    system("cls");
    printf("\n|| GRAFICO DEL ARBOL ||\n\n");
    a_mostrar_normal(arbolito);
    if(a_es_vacio(arbolito)) printf("\n\n");
    
    while (seguir == 1){
        printf("\n=== MENU DEL PUNTO 2 ===\n");
        printf("1. Ejercicio A - Retornar una lista con todos los nodos terminales u hojas\n");
        printf("2. Ejercicio B - Retornar en una estructura todos los nodos interiores\n");
        printf("3. Ejercicio C - Buscar todas las ocurrencias de una clave dentro del árbol.\n");
        printf("4. Complejidad ejercicios A, B y C\n");
        printf("0. Salir \n");
        printf("-1. Cargar nuevo arbol \n");
        printf("> Seleccione una opcion: ");
        opcion = ingresoIntLimitado("Ingrese un valor adecuado!", -1, 4);
        system("cls");

        switch (opcion){
            case -1:
                arbolito = a_modo_carga();
                system("cls");
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");
                break;

            case 0:
                printf("Seguro que desea salir?");
                seguir = !preguntarContinuar();   
                break;

            case 1: // ejercicio a
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");
                l_resultado = a_ej2_hojas(arbolito);
                printf("\nHOJAS DEL ARBOL:\n");
                if(l_es_vacia(l_resultado)){
                    printf("\n>>> Lista vacia! <<<");
                }
                else{
                    l_mostrar(l_resultado);
                }
                break;
            
            case 2: // ejercicio b
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");
                l_resultado = a_ej2_interiores(arbolito);
                printf("\nNODOS INTERIORES DEL ARBOL:\n");
                if(l_es_vacia(l_resultado)){
                    printf("\n>>> Lista vacia! <<<");
                }
                else{
                    l_mostrar(l_resultado);
                }
                break;
                
            case 3: // ejercicio c
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");

                printf("\nCual es la clave que desea buscar? ");
                clave = ingresoDatosNumericos("Ingrese un valor adecuado!");

                l_resultado = a_ej2_buscarclave(arbolito, clave);
                if(a_es_vacio(arbolito)){
                    printf("\nEl arbol estaba vacio...");
                }
                else{
                    printf("\nNODOS CON CLAVE COMUN EN EL ARBOL:\n");
                }

                if(l_es_vacia(l_resultado)){
                    printf("\n>>> Lista vacia! <<<");
                }
                else{
                    // lo hago de esta manera complicada para entender el uso de valor y nodos.
                    Iterador ite = iterador(l_resultado);
                    while(hay_siguiente(ite)){
                        TipoElemento nodo = siguiente(ite);
                        NodoArbol clave = (NodoArbol)nodo->valor;
                        printf("%d ", n_recuperar(clave)->clave);
                    }
                }
                break;
            case 4:
                printf("La complejidad algoritmica de la solucion de los ejercicios va a variar segun la implementacion de listas utilizada.\n El recorrido completo del arbol es obligatorio, por lo cual esto va ser de es de orden lineal.\n");
                printf("Luego si se utiliza para listas la implementacion de arreglos, la complejidad final va a ser de orden lineal.\n");
                printf("Pero si se utilizan las implementaciones de cursores o punteros, la complejidad no necesariamente es lineal, por ejemplo \n");
                printf("si se hacen búsquedas o inserciones dentro de la lista en cada paso. Por ejemplo: para cada nodo recorrer la lista para evitar duplicados");
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

// EJERCICIO 3
void menuPunto3(){
    int opcion, cant_nodo;
    bool seguir = true;
    int clave1, clave2;
    Lista l;
    Iterador iter;
    TipoElemento te;

    ArbolBinario arbolito = a_modo_carga();
    system("cls");
    printf("\n|| GRAFICO DEL ARBOL ||\n\n");
    a_mostrar_normal(arbolito);
    if(a_es_vacio(arbolito)) printf("\n\n");
    
    while (seguir == 1){
        printf("\n=== MENU DEL PUNTO 3 ===\n");
        printf("1. Ejercicio A  (Indicar el nombre del nodo padre (clave))\n");
        printf("2. Ejercicio B (Listar los hijos (solo las clave/s)) \n");
        printf("3. Ejercicio C (Listar el hermano (solo la clave)) \n");
        printf("4. Ejercicio D (Calcular el nivel en el que se encuentra.) \n");
        printf("5. Ejercicio E (Calcular la altura de su rama (Altura del Subárbol)) \n");
        printf("6. Ejercicio F (Listar todos los nodos que estan en el mismo nivel (solo la clave)) \n");
        printf("0. Salir \n");
        printf("-1. Cargar nuevo arbol \n");
        printf("> Seleccione una opcion: ");
        opcion = ingresoIntLimitado("Ingrese un valor adecuado!", -1, 6);
        system("cls");
        
        l = l_crear();
        switch (opcion){
            case -1:
                arbolito = a_modo_carga();
                system("cls");
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n"); 
                break;

            case 0:
                printf("Seguro que desea salir?");
                seguir = !preguntarContinuar();   
                break;

            case 1: // ejercicio a
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");
                printf("\nIngrese un nodo que desee averiguar su padre... ");
                clave1 = ingresoDatosNumericos("Ingrese un valor adecuado!");
                clave2 = a_ej3_clavepadre(arbolito, clave1);
                if(clave2 == -1){
                    printf("\nLa raiz no tiene padre o el arbol estaba vacio");
                }
                else if(clave2 == clave1){
                    printf("\nNo se encontro la clave esperada...");
                }
                else{
                    printf("\nEL NODO %d ES PADRE DE %d\n", clave2, clave1);
                }
                break;

            case 2:
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");
                printf("\nIngrese un nodo que desee averiguar sus hijos... ");
                clave2 = ingresoDatosNumericos("Ingrese un valor adecuado!");
                l = a_ej3_hijos(arbolito, clave2);
                if(l_es_vacia(l)){
                    printf("\nNo se encontraron hijos de la clave...");
                }
                else{
                    l_mostrar(l);
                }
                break;

            case 3:
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");
                printf("\nIngrese un nodo que desee averiguar su hermano... ");
                clave1 = ingresoDatosNumericos("Ingrese un valor adecuado!");
                clave2 = a_ej3_hermano(arbolito, clave1);
                if(clave2 == -1){
                     printf("\nEste nodo no tiene hermano\n");
                }
                else{
                    printf("\nEl hermano de %d es %d\n", clave1, clave2);
                }
                break;

            case 4:
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");
                printf("\nIngrese un nodo al que desee averiguar el nivel al que se encuentra... ");
                clave1 = ingresoDatosNumericos("Ingrese un valor adecuado!");
                clave2 = a_ej3_nivel(arbolito, clave1);
                if(clave2 == -1){
                    printf("\nNo se encontro la clave...\n"); 
                }
                else{
                    printf("\nEl nivel del nodo %d es %d\n", clave1, clave2);
                }
                break;

            case 5:
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");
                printf("\nIngrese un nodo el cual desee averiguar la altura de su rama... ");
                clave1 = ingresoDatosNumericos("Ingrese un valor adecuado!");
                clave2 = a_ej3_alturarama(arbolito, clave1);
                if(clave2 == -1){
                    printf("\nNo se encontro la clave...\n"); 
                }
                else{
                    printf("\nLa altura de la rama del nodo %d es %d\n", clave1, clave2);
                }
                break;

            case 6:
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");
                printf("\nIngrese el nivel que desee averiguar todo los nodos... ");
                clave1 = ingresoDatosNumericos("Ingrese un valor adecuado!");
                l = a_ej3_clavesmismonivel(arbolito, clave1);
                if(l_es_vacia(l)){
                    printf("\n\nNo se encontraron nodos en ese nivel o el arbol estaba vacio");
                }
                else{
                    printf("\nLos nodos en el nivel %d son...", clave1);
                    l_mostrar(l);
                }
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

// EJERCICIO 4
void menuPunto4() {
    int opcion, clave, resultado_int;
    bool seguir = true;
    TipoElemento te_resultado;
    Lista lista_resultado;
    ArbolBinario arbol1, arbol2;

    arbol1 = nArio_modo_carga();
    system("cls");
    printf("\n|| ARBOL PRINCIPAL ||\n\n");
    a_mostrar_normal(arbol1);
    if(a_es_vacio(arbol1)) printf("\n\n"); 

    while (seguir == true) {
        printf("\n=== MENU DEL PUNTO 4 ===\n");
        printf("1. EJERCICIO A  (lista con el resultado del recorrido en anchura del arbol n-ario) \n");
        printf("2. EJERCICIO B  (cantidad de hojas de dicho arbol n-ario) \n");
        printf("3. EJERCICIO C  (dados dos arboles generales determine si tienen la misma estructura, sin importar los datos del mismo) \n");
        printf("4. EJERCICIO D  (retornar el padre de un nodo del arbol) \n");
        printf("5. EJERCICIO E  (retornar los hermanos de un nodo del arbol) \n");
        printf("0. Salir \n");
        printf("-1. Cargar nuevo arbol \n");
        printf("Seleccione una opcion: ");
        opcion = ingresoIntLimitado("Ingrese un valor entre 1 y 5", -1, 5);
        system("cls");

        printf("\n|| ARBOL PRINCIPAL ||\n\n");
        a_mostrar_normal(arbol1);

        switch(opcion){
            case -1:
                arbol1 = nArio_modo_carga();
                system("cls");
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbol1);
                if(a_es_vacio(arbol1)) printf("\n\n"); 
                break;

            case 0:
                printf("Seguro que desea salir?");
                seguir = !preguntarContinuar();   
                break;

            case 1:
                lista_resultado = a_ej4_anchura(arbol1);
                printf("\n\nRecorrido en anchura:\n");
                l_es_vacia(lista_resultado) ? printf("La lista esta vacia") : l_mostrar(lista_resultado);
                break;

            case 2:
                resultado_int = a_ej4_q_hojas(arbol1);
                printf("\nCantidad de hojas: %d\n", resultado_int);
                break;

            case 3:
                printf("\n\n\nCARGAR EL SEGUNDO ARBOL:\n");
                arbol2 = nArio_modo_carga();
                printf("\n|| SEGUNDO ARBOL ||\n\n");
                a_mostrar_normal(arbol2);
                if(a_es_vacio(arbol2)) printf("\n\n");
                if (a_ej4_similares(arbol1, arbol2)){
                    if(a_es_vacio(arbol1) && a_es_vacio(arbol2)){
                        printf("\nAmbos arboles estaban vacios por lo que son estructuralmente similares");
                    }
                    else{
                        printf("\nLos arboles son estructuralmente similares.\n");
                    }
                } else {
                    printf("\nLos arboles no son estructuralmente similares.\n");
                }
                break;

            case 4:
                printf("\nIngrese la clave del nodo para obtener su padre:\n-> ");
                clave = ingresoDatosNumericos("Ingrese un valor valido");
                te_resultado = a_ej4_padre(arbol1, clave);
                if(te_resultado == NULL){
                    printf("\nEl arbol estaba vacio, por lo que no existe un nodo padre");
                }
                else if (te_resultado->clave == -1){
                    printf("El nodo no tiene padre (es la raiz o no se encontro).\n");
                } else {
                    printf("El padre del nodo %d es: %d\n", clave, te_resultado->clave);
                }
                break;

            case 5:
                printf("\nIngrese la clave del nodo para obtener sus hermanos:\n-> ");
                clave = ingresoDatosNumericos("Ingrese un valor valido");
                lista_resultado = a_ej4_hermanos(arbol1, clave);
                if(l_es_vacia(lista_resultado)){
                    printf("El nodo no tiene ningun hermano!");
                }
                else{
                    printf("Hermanos del nodo %d:\n", clave);
                    l_mostrar(lista_resultado);
                }
                break;

            default:
                printf("Opcion invalida.\n");
                break;
        }
        printf("\n\n");
        system("pause");
        system("cls");
    }
}

// EJERCICIO 7
void menuPunto7(){
    int opcion, cant_nodo;
    bool seguir = true, resultado;
    while (seguir == 1){
        printf("\n=== PUNTO 7 ===\n");

        printf("\nCargamos primer arbol\n\n");
        ArbolBinario arbolito1 = a_modo_carga();
        system("cls");
        printf("\n|| GRAFICO DEL ARBOL 1 ||\n\n");
        a_mostrar_normal(arbolito1);
        if(a_es_vacio(arbolito1)) printf("\n\n"); 

        printf("\nCargamos segundo arbol\n\n");
        ArbolBinario arbolito2 = a_modo_carga();
        system("cls");
        printf("\n|| GRAFICO DEL ARBOL 2 ||\n\n");
        a_mostrar_normal(arbolito2);
        if(a_es_vacio(arbolito2)) printf("\n\n"); 
        
        system("cls");
        printf("\n|| GRAFICO DEL ARBOL 1 ||\n\n");
        a_mostrar_normal(arbolito1);
        if(a_es_vacio(arbolito1)) printf("\n\n"); 
        printf("\n\n\n|| GRAFICO DEL ARBOL 2 ||\n\n");
        a_mostrar_normal(arbolito2);
        if(a_es_vacio(arbolito2)) printf("\n\n"); 

        resultado = a_ej7_equivalente(arbolito1, arbolito2);
        if(resultado == true){
            if(a_es_vacio(arbolito1) && a_es_vacio(arbolito2)){
                printf("\n\nLos dos arboles estaban vacios\n");
            }
            printf("\n=== LOS ARBOLES SON EQUIVALENTES ===\n");
        }
        else{
            printf("\n=== LOS ARBOLES NO SON EQUIVALENTES ===\n");
        }
        seguir = preguntarContinuar();
        system("cls");
    }
}

// EJERCICIO 8
void menuPunto8(){
    int opcion, cant_nodo, altura, nivel, clave;
    Lista l_res;
    bool seguir = true;

    ArbolBinario arbolito = nArio_modo_carga();
    system("cls");
    printf("\n|| GRAFICO DEL ARBOL ||\n\n");
    a_mostrar_normal(arbolito);
    if(a_es_vacio(arbolito)) printf("\n\n"); 

    while (seguir == 1){
        printf("\n=== MENU DEL PUNTO 8 ===\n");
        printf("1. Ejercicio A (Determinar la altura del n-ario)\n");
        printf("2. Ejercicio B (Determinar el nivel de un nodo)\n");
        printf("3. Ejercicio C (Listar todos los nodos internos (solo las claves))\n");
        printf("4. Ejercicio D (Determinar si todas las hojas estan al mismo nivel)\n");
        printf("0. Salir \n");
        printf("-1. Cargar nuevo arbol \n");
        printf("> Seleccione una opcion: ");
        opcion = ingresoIntLimitado("Ingrese un valor adecuado!", -1, 4);
        system("cls");

        switch (opcion){
            case 1: // ejercicio a
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");
                altura = a_ej8_altura(arbolito);
                if(altura == 0){
                    printf("\n\nEl arbol ingresado estaba vacio...");
                }
                else if(altura == 1){
                    printf("\n\nEl arbol ingresado solo tenia la raiz...");
                }
                printf("\nALTURA DEL ARBOL N-ARIO: %d\n", altura);
                break;
            
            case 2: // ejercicio b
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");

                printf("\n\nIngrese la clave del nodo que desea saber su nivel\n-> ");
                clave = ingresoDatosNumericos("Ingrese un valor adecuado!");

                nivel = a_ej8_nivel(arbolito, clave);
                if(nivel == -1){
                    printf("\n\nNo se encontro el nodo...");
                }
                else{
                    if(nivel == 0){
                        printf("\n\nEl nodo era la raiz...");
                    }
                    printf("\nNIVEL DEL NODO %d EN EL ARBOL N-ARIO: %d\n", clave, nivel);
                }
                break;

            case 3: // ejercicio c
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");

                l_res = a_ej8_internos(arbolito);
                if(l_es_vacia(l_res)){
                    printf("\nNODOS INTERIORES DEL N-ARIO:\n");
                    printf("\nLa lista esta vacia...");
                }
                else{
                    printf("\nNODOS INTERIORES DEL N-ARIO:\n");
                    l_mostrar(l_res);
                } 

                break;

            case 4: // ejercicio d
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");

                bool res = a_ej8_hojasmismonivel(arbolito);
                if(!a_es_vacio(arbolito)){
                    printf(res ? "\nLas hojas son del mismo nivel" : "\nLas hojas NO son del mismo nivel");
                }
                else{
                    printf("\nEl arbol ingresado estaba vacio...");
                }

                break;
            
            case 0:
                printf("Seguro que desea salir?");
                seguir = !preguntarContinuar();   
                break;

            case -1:
                arbolito = nArio_modo_carga();
                system("cls");
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n"); 
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

// EJERCICIO 9
void menuPunto9(){
    int opcion, cant_nodo;
    bool seguir = true, resultado;
    ArbolBinario arbolito1;
    ArbolAVL arbol_avl;
    while (seguir == 1){
        arbolito1 = a_modo_carga();
        system("cls");
        printf("\n|| GRAFICO DEL ARBOL ||\n\n");
        a_mostrar_normal(arbolito1);
        if(a_es_vacio(arbolito1)) printf("\n\n"); 
        system("cls");
        printf("\n=== PUNTO 9 ===\n");
        printf("\n|| GRAFICO DEL ARBOL ||\n\n");
        a_mostrar_normal(arbolito1);
        if(a_es_vacio(arbolito1)) printf("\n\n");
       
        printf("\n|| GRAFICO DEL ARBOL AVL ||\n\n");
        arbol_avl = a_ej9_construiravl(arbolito1);
        a_mostrar_normal_AVL(arbol_avl);
        if(avl_es_vacio(arbol_avl)) printf("\n\n");
        printf("\n\nla complejidad algoritmica de la solucion es de orden lineal\n\n");
        seguir = preguntarContinuar();
        system("cls");
    }
}

// EJERCICIO 10
void menuPunto10(){
    int opcion, cant_nodos, valorminimo, valormaximo,N_repeticiones;
    bool seguir = true, rango = true, resultado;
    Lista l_resultado = l_crear();
    ArbolAVL arbol_AVL = avl_crear();
    ArbolBinarioBusqueda arbolBB = abb_crear();
    while (seguir == 1){
        
        while(rango == true){      
            printf("Ingrese la cantidad de nodos que desea cargar en los arboles\n-> ");
            cant_nodos = ingresoDatosNumericosPositivos("Ingrese un valor adecuado!");
            printf("Ingrese el valor minimo generado al azar\n-> ");
            valorminimo = ingresoDatosNumericos("Ingrese un valor adecuado!");
            printf("Ingrese el valor maximo generado al azar\n-> ");                    
            valormaximo = ingresoDatosNumericos("Ingrese un valor adecuado!");
            printf("Ingrese la cantidad de veces que quiere repetir este proceso \n-> ");
            N_repeticiones = ingresoDatosNumericosPositivos("Ingrese un valor adecuado!");
            
            if (N_repeticiones <= 0) {
            printf("\nLa cantidad de repeticiones debe ser mayor a 0...\n");
            }
            else if (valormaximo <= valorminimo) {
                printf("\nEl máximo no puede ser menor o igual al mínimo.\n");
            }
            else if ((valormaximo - valorminimo + 1) < cant_nodos) {
                printf("\nEl rango de números es menor a la cantidad de nodos a crear. Ingrese un rango mayor o igual.\n");
            }
            else {
                rango = false;
            }
        }
        
        system("cls");
        l_resultado =  a_ej10_comparacionarboles(N_repeticiones,valorminimo,valormaximo, cant_nodos);
        printf("La diferencia de alturas fueron");
        l_mostrar(l_resultado);
        printf("La conclusion a la que llegamos es que el arbol BB tiende a tener mas niveles que un arbol AVL. Debido a que este ultimo, al tener un autobalanceo crece menos en profundidad.\n");
        seguir = preguntarContinuar();
        rango = true;
        system("cls");
    }
}