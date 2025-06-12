#include "tp_thash.h"
#include "menu.h"



/**
4. Desarrollar un algoritmo que dado un archivo que contendrá los datos de alumnos  (legajo, apellido, nombres, domicilio, TE) 
   genere una tabla hash donde la clave será el legajo y se guardará como dato la posición física 
   del registro para realizar accesos directos.  
   Hacer un ABM para poder cargar manualmente el archivo.  El “legajo" es un valor de 6 dígitos. 
*/

int funcion_hash_mod(int clave){
    return clave % 997;
}

int cargarTabla(TablaHash tabla, FILE* archivo){   //retorna el indice de la ultima posicion a cargar
    Alumnos alumno;
    int contador = 0; //indice inicial
    while(fread(&alumno, sizeof(Alumnos), 1, archivo) != 0){
        int* contador2 = (int*)malloc(sizeof(int));
        *contador2 = contador;  //actualiza el indice en un puntero para que coincida con los parametros de th_insetar
        th_insertar(tabla, te_crear_con_valor(alumno.legajo, contador2));
        contador++;
    }
    return contador;
}
void alta_alumno(TablaHash tabla, FILE* archivo, int legajo, int* indice){
    int* indice2 = (int*)malloc(sizeof(int));
    Alumnos alumno;
    cargando_alumno(&alumno);
    *indice2 = *indice;
    alumno.legajo = legajo;
    
    th_insertar(tabla, te_crear_con_valor(alumno.legajo,indice2));

    //if(fseek(archivo, sizeof(Alumnos) * (*indice), SEEK_SET) != 0){ //posiciona para escribir

    if(fseek(archivo, sizeof(Alumnos) * *indice, SEEK_SET) != 0){
        printf("error al posicionar para escritura");
        system("pause");
        return;
    }
    if(fwrite(&alumno, sizeof(Alumnos), 1, archivo) != 1){ //escribre el archivo
        printf("error al escribir en el archivo");
        system("pause");
        return;
    }
    *indice = *indice + 1;
}

void alta_logica(int indice, FILE* archivo){
    Alumnos alumno;

    if(fseek(archivo, sizeof(Alumnos) * indice, SEEK_SET) != 0){   //se posiciona en el archivo
        printf("error al posicionar para escritura");
        system("pause");
        return;
    }

    fread(&alumno, sizeof(Alumnos), 1, archivo);    //leemos el archivo para ver el estado del alumno (si se encuentra o no)
    
    if(alumno.Estado == false){
        alumno.Estado = true;
        fseek(archivo, -(long)sizeof(Alumnos), SEEK_CUR);  //retrocede en el archivo, dejandolo en la posicion que lo leyo antes 
        if(fwrite(&alumno, sizeof(Alumnos), 1, archivo) != 1){ //escribre el archivo
        printf("error al escribir en el archivo");
        system("pause");
        return;
        }

        printf("El alumno ya fue dado de alta\n");
    }
    else{
        printf("\nEl alumno ya se encuentra dado de alta en el archivo\n\n");
    }

}  

void baja_alumno(int clave, TablaHash tabla, FILE* archivo){
    Alumnos alumno;
    TipoElemento te = th_recuperar(tabla, clave);   //buscamos el alumno en la tabla
    int indice = *((int*)te->valor);

    if(fseek(archivo, sizeof(Alumnos) * indice, SEEK_SET) != 0){
        printf("error al posicionar al posicionarse en el archivo\n");
        system("pause");
        return;
    }
    fread(&alumno, sizeof(Alumnos), 1, archivo);   

    if(alumno.Estado == true){
        alumno.Estado = false;
        fseek(archivo, -(long)sizeof(Alumnos), SEEK_CUR);  //retrocede en el archivo, dejandolo en la posicion que lo leyo antes
        
        if(fwrite(&alumno, sizeof(Alumnos), 1, archivo) != 1){
            printf("error al escribir en el archivo");
            system("pause");
            return;
        }
        printf("\nSe dio de baja al alumno con legajo %d\n", alumno.legajo);
    }
    else{
        printf("\nNo se pudo realizar la baja, porque el alumno ya estaba dado de baja\n");
    }
}
void buscar_alumno(int indice, FILE* archivo){
    Alumnos alumno;
    if(fseek(archivo, sizeof(Alumnos) * indice, SEEK_SET) != 0){
        printf("error al posicionar al posicionarse en el archivo\n");
        system("pause");
        return;
    }
    fread(&alumno, sizeof(Alumnos), 1, archivo);

    if(alumno.Estado == false){
        printf("no se encontro el alumno dentro del archivo\n");
        system("pause");
        return;
    }
    else{
        printf("\n\n=========== informacion del alumno ===========\n");
        printf("Legajo %d\n",alumno.legajo);
        printf("Apellido %s\n",alumno.apellido);
        printf("Nombre %s\n",alumno.nombre);
        printf("Domicilio %s\n",alumno.domicilio);
        printf("Telefono %s\n", alumno.TE);
    }
}
void modoficar_alumno(int legajo,TablaHash tabla,FILE* archivo){
    Alumnos alumno;
    bool seguir = true;
    int opcion;
    TipoElemento te = th_recuperar(tabla, legajo);
    while(seguir){
        printf("=========== Modificaciones ===========\n");
        printf("Seleccione el campo a modificar\n");
        printf("1. Modificar nombre\n");
        printf("2. Modificar apellido\n");
        printf("3. Modificar telefono\n");
        printf("4. Modificar direccion\n");
        printf("0. Salir\n");
        opcion = ingresoDatosNumericosPositivos("\nEntrada erronea.\n-> ");
        system("cls");
        switch(opcion) {
            case 0:
                seguir = false;
                break;
            case 1:
                modificar_alumno_nombre(archivo, *((int*)te->valor));
                break;
            case 2:
                modificar_alumno_apellido(archivo,*((int*)te->valor));
                break;
            case 3:
                modificar_alumno_telefono(archivo,*((int*)te->valor));
                break;
            case 4:
                modificar_alumno_direccion(archivo,*((int*)te->valor));
                break;
            default:
                printf("AVISO: Ingrese un numero parte de las opciones.\n");
                break;
        }
    }
}

void modificar_alumno_nombre(FILE* archivo, int indice){
    Alumnos alumno;
    char* nombre_nuevo = (char*)malloc(21 * sizeof(char));
    ingresarString_noEspaciado("Ingrese el nuevo nombre del alumno\n",nombre_nuevo,20);
    
    if(fseek(archivo, sizeof(Alumnos) * indice, SEEK_SET) != 0){
        printf("error al posicionar al posicionarse en el archivo\n");
        system("pause");
        return;
    }
    fread(&alumno, sizeof(Alumnos), 1, archivo);
    strcpy(alumno.nombre, nombre_nuevo);  //copiamos el nuevo telefono

    fseek(archivo, -(long)sizeof(Alumnos), SEEK_CUR);  //retrocede en el archivo, dejandolo en la posicion que lo leyo antes 
    if(fwrite(&alumno, sizeof(Alumnos), 1, archivo) != 1){ //escribre el archivo
        printf("error al escribir en el archivo");
        system("pause");
        return;
    }
    printf("Ahora el nombre del alumno es %s\n", alumno.nombre);
    system("pause");
}

void modificar_alumno_apellido(FILE* archivo, int indice){
    Alumnos alumno;
    char* apellido_nuevo = (char*)malloc(21 * sizeof(char));
    ingresarString_noEspaciado("Ingrese el nuevo nombre del alumno\n",apellido_nuevo,20);
    
    if(fseek(archivo, sizeof(Alumnos) * indice, SEEK_SET) != 0){
        printf("error al posicionar al posicionarse en el archivo\n");
        system("pause");
        return;
    }
    fread(&alumno, sizeof(Alumnos), 1, archivo);
    strcpy(alumno.apellido, apellido_nuevo);  //copiamos el nuevo telefono

    fseek(archivo, -(long)sizeof(Alumnos),SEEK_CUR);  //retrocede en el archivo, dejandolo en la posicion que lo leyo antes 
    if(fwrite(&alumno, sizeof(Alumnos), 1, archivo) != 1){ //escribre el archivo
        printf("error al escribir en el archivo");
        system("pause");
        return;
    }
    printf("Ahora el nombre del alumno es %s\n", alumno.apellido);
    system("pause");
}

void modificar_alumno_direccion(FILE* archivo, int indice){
    Alumnos alumno;
    char* domicilio_nuevo = (char*)malloc(21 * sizeof(char));
    ingresarString_char_y_numeros("Ingrese la nueva direccion del alumno\n",domicilio_nuevo,20);
    
    if(fseek(archivo, sizeof(Alumnos) * indice, SEEK_SET) != 0){
        printf("error al posicionar al posicionarse en el archivo\n");
        system("pause");
        return;
    }
    fread(&alumno, sizeof(Alumnos), 1, archivo);
    strcpy(alumno.domicilio, domicilio_nuevo);  //copiamos el nuevo telefono

    fseek(archivo, -(long)sizeof(Alumnos),SEEK_CUR);  //retrocede en el archivo, dejandolo en la posicion que lo leyo antes 
    if(fwrite(&alumno, sizeof(Alumnos), 1, archivo) != 1){ //escribre el archivo
        printf("error al escribir en el archivo");
        system("pause");
        return;
    }
    printf("Ahora el domicilio del alumno es %s\n", alumno.domicilio);
    system("pause");
}

void modificar_alumno_telefono(FILE* archivo, int indice){
    Alumnos alumno;
    char* telefono_nuevo = (char*)malloc(21 * sizeof(char));
    ingresarEnteros_char("Ingrese la nueva direccion del alumno\n",telefono_nuevo,20);
    
    if(fseek(archivo, sizeof(Alumnos) * indice, SEEK_SET) != 0){
        printf("error al posicionar al posicionarse en el archivo\n");
        system("pause");
        return;
    }
    fread(&alumno, sizeof(Alumnos), 1, archivo);
    strcpy(alumno.TE, telefono_nuevo);  //copiamos el nuevo telefono

    fseek(archivo, -(long)sizeof(Alumnos),SEEK_CUR);  //retrocede en el archivo, dejandolo en la posicion que lo leyo antes 
    if(fwrite(&alumno, sizeof(Alumnos), 1, archivo) != 1){ //escribre el archivo
        printf("error al escribir en el archivo");
        system("pause");
        return;
    }
    printf("Ahora el telefono del alumno es %s\n", alumno.TE);
    system("pause");
}

void cargando_alumno(Alumnos* alumno){
    char *nombre, *apellido, *domicilio, *telefono;
    
    ingresarString_noEspaciado("\nIngrese el nombre del alumno: ", alumno->nombre,20);

    ingresarString_noEspaciado("\nIngrese el apellido del alumno: ", alumno->apellido,20);

    ingresarString_Espaciado("\nIngrese el domicilio del alumno (no altura): ", alumno->domicilio,20);
    ingresarEnteros_char("\nIngrese la altura del domicilio: ",alumno->TE,15);
    
    ingresarEnteros_char("\nIngrese el numero de telefono: ",alumno->TE,15);

    alumno->Estado = true;
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
    menuPunto4();
}


/**
5. Realizar una comparación de los tiempos de accesos a las claves entre un árbol AVL y una Tabla Hash. 
   El operador debe poder indicarle cuantas claves se deben generar (entre 1 y 2000), cuantas repeticiones 
   se realizaran y cuál es el rango de las claves a generar.   
   Luego se tomarán claves al azar dentro del mismo rango y se buscaran en ambas estructuras.  
   El proceso se repetirá “n” veces (repeticiones a ingresar por el operador).  
   Documentar la conclusión final respecto a los tiempos de accesos de ambas estructuras. 
*/

int funcion_hash_mod2003(int clave){
    return clave % 2003;
}

int cargarHashAVL(int q_claves, int rango_desde, int rango_hasta, ArbolAVL arvl, TablaHash thash){
    int i = 0;
    while(i < q_claves){
        int random = rand() % (rango_hasta - rango_desde + 1) + rango_desde;

        if(avl_buscar(arvl, random) == NULL){ 
            avl_insertar(arvl, te_crear(random));
            th_insertar(thash, te_crear(random));
            i++;
        }
    }
    return i;
}

void th_ej5_comparacion(int q_claves, int q_repeticiones, int rango_desde, int rango_hasta){
    double totalavl = 0, totalhash = 0;
    clock_t inicioavl, iniciohash, finavl, finhash;

    double* tiempo_avl = (double*)malloc(sizeof(double) * q_repeticiones);
    double* hash_tiempo = (double*)malloc(sizeof(double) * q_repeticiones);
/*  |
    |__ Arreglos para almacenar el tiempo usado de las estructuras en cada repetición   */

    // Lista l_avl_tiempo = l_crear();  
    // Lista l_hash_tiempo = l_crear();

    ArbolAVL arvl = avl_crear();// --------> CREO ARBOL AVL
    TablaHash thash = th_crear(2003, funcion_hash_mod2003);// --------> CREO TABLA HASH

    int claves_cargadas = cargarHashAVL(q_claves, rango_desde, rango_hasta, arvl, thash);
/*  |                                                                                  | 
    |__ función que carga tanto el avl como la hash con las mismas claves aleatorias __|   */
    printf("\nClaves cargadas: %d\n", claves_cargadas);
    printf("\n\n");  

    a_mostrar_normal_AVL(arvl);      // ===========
    printf("\n\n");                  //   Muestro
    th_mostrar(thash);               // ===========

    printf("Cuantas claves desea buscar?\n-> ");
    int cant_claves = ingresoIntMinimo("Ingrese un valor adecuado!", 1);

    // Se crea urreglo de claves aleatorias a buscar, para que ambas estructuras busquen las mismas claves
    int* claves_busqueda = (int*)malloc(sizeof(int) * cant_claves);
    for (int i = 0; i < cant_claves; i++) {
        claves_busqueda[i] = rand() % (rango_hasta - rango_desde + 1) + rango_desde;
    }

    for(int j = 0; j < q_repeticiones; j++){
        /* -------------------------------------------------------------------------------
            ACLARACION: La función clock mide el tiempo de CPU utilizado por el programa.
        -------------------------------------------------------------------------------- */
        // -------------------
        //      ARBOL AVL     
        // -------------------
        inicioavl = clock(); // inicio contador de tiempo del arbol avl
        for(int i = 0; i < cant_claves; i++) {
            avl_buscar(arvl, claves_busqueda[i]);
        }
        finavl = clock(); // finalizo
        double *tiempousadoavl = (double*)malloc(sizeof(double));
        *tiempousadoavl = (double)(finavl - inicioavl) / CLOCKS_PER_SEC;
        totalavl += *tiempousadoavl;
        // l_agregar(l_avl_tiempo, te_crear_con_valor(j, tiempousadoavl));
        tiempo_avl[j] = *tiempousadoavl;

        // -------------------
        //    TABLA HASH
        // -------------------
        iniciohash = clock(); // inicio contador de tiempo de la tabla hash
        for(int i = 0; i < cant_claves; i++) {
            th_recuperar(thash, claves_busqueda[i]);
        }
        finhash = clock(); // finalizo
        double *tiempousadohash = (double*)malloc(sizeof(double));
        *tiempousadohash = (double)(finhash - iniciohash) / CLOCKS_PER_SEC;
        totalhash += *tiempousadohash;
        // l_agregar(l_hash_tiempo, te_crear_con_valor(j, tiempousadohash));
        hash_tiempo[j] = *tiempousadohash;
    }
    free(claves_busqueda);

    printf("\n\nLISTADO DE TIEMPOS DE BUSQUEDA DEL ARBOL AVL POR CADA REPETICION:\n");
    for(int i = 0; i<q_repeticiones; i++){
        double tiempo1 = tiempo_avl[i];
        printf("%f ", tiempo1);
    }
    // Iterador iteavl = iterador(l_avl_tiempo);
    // while(hay_siguiente(iteavl)){
    //     double tiempo1 = *(double*)(siguiente(iteavl)->valor);
    //     printf("%f ", tiempo1);
    // }

    printf("\n\nLISTADO DE TIEMPOS DE BUSQUEDA DE LA TABLA HASH POR CADA REPETICION:\n");
    for(int i = 0; i<q_repeticiones; i++){
        double tiempo2 = hash_tiempo[i];
        printf("%f ", tiempo2);
    }
    // Iterador itehash = iterador(l_hash_tiempo);
    // while(hay_siguiente(itehash)){
    //     double tiempo2 = *(double*)(siguiente(itehash)->valor);
    //     printf("%f ", tiempo2);
    // }

    printf("\n\n");
    printf("\nTiempo promedio AVL: %f segundos\n", totalavl / q_repeticiones);
    printf("Tiempo total AVL: %f segundos\n", totalavl);
    printf("\nTiempo promedio Hash: %f segundos\n", totalhash / q_repeticiones);
    printf("Tiempo total Hash: %f segundos\n", totalhash);

    printf("\n\n====== CONCLUSION ======\n\n");
    printf("Luego de muchas pruebas con distintos rangos de repeticiones para ambas implementaciones,\n");
    printf("se evidencio que la TABLA HASH con lista de colisiones tenia tiempos de acceso mas eficaces a comparacion que los del arbolAVL.\n");
    printf("sin embargo, en la implementacion de zona de overflow, sucedia lo contrario, el ArbolAVL fue mas eficaz que la tabla hash.");
    // lista_colisiones = tablas hash + rapido
    // zona overflow = arbol avl + rapido
    free(tiempo_avl);
    free(hash_tiempo);
}


/**
6. Se desea poder implementar una solución para encontrar de forma rápida los datos de las personas que a una fecha
   determinada se presentaron a vacunar contra el COVID.  
   Es decir dada una fecha determinada debería obtener quienes se vacunaron. 
   De cada persona se guarda básicamente el DNI, Apellido y Nombre.  
   Se debe además hacer una pantalla de carga donde se pueda especificar la fecha y los datos de las personas 
   que se vacunaron en esa fecha. 
*/

void cargar_vacunados(TablaHash tabla){ //RECIBA EL ARCHIVO
    int fecha_final;
    bool seguir = true;
    ArbolAVL avl1, avl2;
    FichaVacunados *ficha = (FichaVacunados*)malloc(sizeof(FichaVacunados));;
    TipoElemento te;

    //ingresando_vacunado(ficha);
    ficha->fecha = ingresando_fecha();
    //cargar archivo
    ingresando_vacunado(ficha);
    ficha->DNI = ingresando_dni();
    te = th_recuperar(tabla, ficha->fecha);
    
    if(te != NULL){ //si se encuentra en la tabla
        
        avl2 = (ArbolAVL)te->valor; //el arbol ya existe por lo que no lo creamos 
        if(avl_buscar(avl2, ficha->DNI) == NULL){   //si no existe el dni en determinada fecha

            //ingresando_vacunado(ficha);   //permite ingresar los datos restantes una vez chequeado que no este

            avl_insertar(avl2, te_crear_con_valor(ficha->DNI,ficha));    
            printf("\nLa persona se cargo correctamente y habian otras personas vacunadas en la misma fecha\n");
        }
        else{
            printf("\nLa persona ya se encontraba cargada en la misma fecha\n");
            printf("Vuelva a intentarlo");
            cargar_vacunados(tabla);
        }
          
    }
    else{   //caso contrario
        //ingresando_vacunado(ficha); //permite ingresar los datos restantes
        avl1 = avl_crear(); //creo el arbol avl para determinada fecha
        avl_insertar(avl1, te_crear_con_valor(ficha->DNI, ficha));  //insertamos en el arbol, el tipoelemento con el dni como clave(ordena el arbol) y el puntero a la ficha
        th_insertar(tabla, te_crear_con_valor(ficha->fecha, avl1)); //"guardamos" el avl en la ficha
        printf("\nLa persona se cargo correctamente y fue la primera cargada en esta fecha\n");
    }
    
    //esta en tabla hash
}

void ingresando_vacunado(FichaVacunados *ficha){
    char *nombre = (char*)malloc(21 * sizeof(char)),*apellido = (char*)malloc(21 * sizeof(char)),*dni = (char*)malloc(10 * sizeof(char));
    int dni_num;
    //ingresarString_solo_char("Ingrese el nombre de la persona\n", ficha->nombre ,20);
    ingresarString_noEspaciado("\nIngrese el nuevo nombre del vacunado: ",nombre,20);
    ingresarString_noEspaciado("\nIngrese el apellido de la persona: ", apellido ,20);
    // ingresarEnteros_char("Ingrese el DNI de la persona\n", dni ,10);
    // dni_num = atoi(dni);
    //ficha->DNI = dni_num;
    strcpy(ficha->nombre,nombre);
    strcpy(ficha->apellido,apellido);
    
}

int ingresando_dni(){
    char *dni = (char*)malloc(10 * sizeof(char));
    int dni_num;
    ingresarEnteros_char("\nIngrese el DNI de la persona: ", dni ,10);
    dni_num = atoi(dni);

    return dni_num;
}

int ingresando_fecha(){
    int dia, mes, anio;
    bool seguir = true;
    printf("\nIngrese la fecha en formato ddmmaaaa (primero el dia, luego el mes, luego el anio)");
    printf("\nDia: ");
    dia = ingresoIntLimitado("Ingrese un dia adecuado!", 1, 31);
    printf("\nMes: ");
    mes = ingresoIntLimitado("Ingrese un mes adecuado!", 1, 12);
    printf("\nAnio: ");
    anio = ingresoIntLimitado("Ingrese un anio adecuado! Que sea desde el covid y no exceda el presente", 2020, 2025);

    // Unifica la fecha en formato ddmmaaaa como un solo int
    int fecha = dia * 1000000 + mes * 10000 + anio;
    return fecha;
}

// int ingresando_fecha(){
//     char* fecha = (char*)malloc(10 * sizeof(char));
//     bool seguir = true;
//     while(seguir){
//         ingresarEnteros_char("Ingrese la fecha en formato ddmmaaaa (ej: 27122001): ",fecha ,10);
//         if (strlen(fecha) != 8) {
//             printf("Error, la fecha debe tener 8 numeros.\n");
//             continue;
//         }
//         // Validación básica de día y mes
//         int dia = (fecha[0] - '0') * 10 + (fecha[1] - '0');
//         int mes = (fecha[2] - '0') * 10 + (fecha[3] - '0');
//         int anio = (fecha[4] - '0') * 1000 + (fecha[5] - '0') * 100 + (fecha[6] - '0') * 10 + (fecha[7] - '0');
//         if (dia < 1 || dia > 31 || mes < 1 || mes > 12) {
//             printf("Error, día o mes inválido.\n");
//             system("pause");
//             continue;
//         }
//         if (anio < 2020 || anio > 2023) {
//             printf("Error, el año debe estar entre 2020 y 2023 (periodo COVID en Argentina).\n");
//             system("pause");
//             continue;
//         }
//         break;
//     }
//     return atoi(fecha); 
// }

void mostrar_vacunados(TablaHash tabla){
    TipoElemento te;
    FichaVacunados *ficha = (FichaVacunados*)malloc(sizeof(FichaVacunados));
    ArbolAVL avl;
    NodoArbol raiz;
    ficha->fecha = ingresando_fecha();
    te = th_recuperar(tabla, ficha->fecha); //recuperamos los datos de la fecha ingresada
    if(te != NULL){
        avl = (ArbolAVL)te->valor;
        raiz = avl_raiz(avl);
        if(avl_es_vacio(avl)){
            printf("\nNo se encontraron resultados para la fecha ingresada\n");
        }
        else{
            imprimir_listado_vacunados(raiz, ficha);   
        }
        
    }
    else{
        printf("\nNo se encontraron resultados para la fecha ingresada\n");
    }
}




//hasta aca
void imprimir_listado_vacunados(NodoArbol nodo, FichaVacunados *ficha){
    TipoElemento te;
    if(a_es_rama_nula(nodo)){
        return;
    }
    te = n_recuperar(nodo);
    ficha = ((FichaVacunados*)te->valor);
    printf("\n=========== Vacunado ===========\n");
    printf("Apellido: %s\n",ficha->apellido);
    printf("nombre:   %s\n",ficha->nombre);
    printf("DNI:      %d\n",ficha->DNI);        
    printf("fecha:    %d\n",ficha->fecha);
    
    imprimir_listado_vacunados(n_hijoizquierdo(nodo),ficha);
    imprimir_listado_vacunados(n_hijoderecho(nodo),ficha);

}




int th_ej6_covid(){
    menuPunto6_v2();
    return 0;
}
