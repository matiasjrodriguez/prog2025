#include "tp_4_colas.h"

// EJERCICIO 2
//A
bool c_ej2_existeclave(Cola c, int clave){
    Cola c_aux = c_crear();
    TipoElemento nodo;
    bool resultado = false;

    while (!c_es_vacia(c)){
        nodo = c_desencolar(c);
        if(!resultado && nodo->clave == clave){
            resultado = true;
        }
        if(!c_encolar(c_aux, nodo)){
            printf("hubo un error al encolar...\n");
        }
    }

    while (!c_es_vacia(c_aux)) {
        nodo = c_desencolar(c_aux);
        if(!c_encolar(c, nodo)){
            printf("hubo un error al encolar...\n");
        }
    }

    return resultado;
}


//B
Cola c_ej2_colarelemento(Cola c, int posicionordinal, TipoElemento X) {
    Cola cola_auxiliar = c_crear();
    Cola cola_resultado = c_crear();
    TipoElemento nodo, nodo1;
    int longitud = 0;
    int posicion = 1;

    while (!c_es_vacia(c)) {
        nodo = c_desencolar(c);
        nodo1 = te_crear(nodo->clave);
        c_encolar(cola_resultado, nodo);
        c_encolar(cola_auxiliar, nodo1);
        longitud++;
    }

    while (!c_es_vacia(cola_resultado)) {
        nodo = c_desencolar(cola_resultado);
        c_encolar(c, nodo);
    }
    
    if (posicionordinal < 1 || posicionordinal > longitud + 1 || longitud == 10) {
        return c; 
    }

    while (!c_es_vacia(cola_auxiliar)) {
        if (posicion == posicionordinal) {
            c_encolar(cola_resultado, X);
        }
        nodo = c_desencolar(cola_auxiliar);
        c_encolar(cola_resultado, nodo);
        posicion++;
    }

    if (posicion == posicionordinal) {
        c_encolar(cola_resultado, X);
    }

    return cola_resultado;
}

//C
Cola c_ej2_sacarelemento(Cola c, int clave) {
    Cola cola_auxiliar = c_crear();
    Cola cola_resultados = c_crear();
    TipoElemento nodo, copia;

    while (!c_es_vacia(c)) {
        nodo = c_desencolar(c);
        copia = te_crear(nodo->clave);
        c_encolar(cola_auxiliar, copia);
        c_encolar(cola_resultados, nodo); 
    }

    
    while (!c_es_vacia(cola_resultados)) {
        nodo = c_desencolar(cola_resultados);
        c_encolar(c, nodo);
    }

    
    while (!c_es_vacia(cola_auxiliar)) {
        nodo = c_desencolar(cola_auxiliar);
        if (nodo->clave != clave) {
            c_encolar(cola_resultados, nodo);
        }
    }

    return cola_resultados;
}


//D
int c_ej2_contarelementos(Cola c) {
    if (c_es_vacia(c)) {
        return 0;
    }

    Cola c_aux = c_crear();
    TipoElemento nodo;
    int contador = 0;

    while (!c_es_vacia(c)) {
        nodo = c_desencolar(c);
        c_encolar(c_aux, nodo);
        contador++;
    }

    while (!c_es_vacia(c_aux)) {
        nodo = c_desencolar(c_aux);
        c_encolar(c, nodo);
    }

    return contador;
}


//E
Cola c_ej2_copiar(Cola c) {
    Cola cola_auxiliar = c_crear();   
    Cola copia = c_crear();  
    TipoElemento nodo;

    while (!c_es_vacia(c)) {
        nodo = c_desencolar(c);
        c_encolar(cola_auxiliar, nodo);                
        TipoElemento copiaNodo = te_crear(nodo->clave);  
        c_encolar(copia, copiaNodo);          
    }
    while (!c_es_vacia(cola_auxiliar)) {
        nodo = c_desencolar(cola_auxiliar);
        c_encolar(c, nodo);
    }
    return copia;
}



//F
Cola c_ej2_invertir(Cola c) {
    if (c_es_vacia(c)) {
        return c;
    }

    Cola copia = c_ej2_copiar(c);  
    Pila pila = p_crear();         
    TipoElemento nodo;
    
    while (!c_es_vacia(copia)) {
        nodo = c_desencolar(copia);
        p_apilar(pila, nodo);
    }

    Cola cola_invertida = c_crear();

    while (!p_es_vacia(pila)) {
        nodo = p_desapilar(pila);
        c_encolar(cola_invertida, nodo);
    }

    return cola_invertida;
}



// EJERCICIO 3
bool c_ej3_iguales(Cola c1, Cola c2){
    TipoElemento nodo1,nodo2;
    Cola c_aux = c_crear();
    bool resultado = true;
    int e_c1 = c_ej2_contarelementos(c1);
    int e_c2 = c_ej2_contarelementos(c2);
    if(e_c1 != e_c2){
        resultado = false;
        return resultado;
    }
    else{
        while(!c_es_vacia(c1)){
            nodo1 = c_desencolar(c1);
            nodo2 = c_desencolar(c2);
            if(nodo1->clave != nodo2->clave){
                resultado = false;
            }
            c_encolar(c_aux, nodo1);
            c_encolar(c2, nodo2);
        }
        while(!c_es_vacia(c_aux)){
            nodo1 = c_desencolar(c_aux);
            c_encolar(c1, nodo1);
        }
    }
    
    return resultado;
}

// EJERCICIO 4
/**
4.	Dada una cola de números enteros, no ordenada,
	construir un algoritmo que permita pasar a otra cola todos los elementos que no se repiten en la primera,
	sin destruir el contenido de la cola original y dejándola en su estado inicial.
 */
// Retorna la cola con las claves que no tienen repeticiones, caso contrario si todas se repiten retorna cola vacia.

Cola  c_ej4_colanorepetidos(Cola c){
    TipoElemento elemento1, elemento2;
    Cola c_aux = c_crear();
    Cola c_resultado = c_crear();
    Cola c_copia = c_ej2_copiar(c);
    bool seguir = true, repite = false;

    if(c_es_vacia(c)){
        return c_resultado;
    }

    while(seguir == true){  
        elemento1 = c_desencolar(c_copia);

        while(c_es_vacia(c_copia) == false){
            elemento2 = c_desencolar(c_copia);
            
            if(elemento1->clave != elemento2->clave){   //si son distintos los agrega a la cola auxiliar
                c_encolar(c_aux,elemento2);
            }
            else{
                repite = true;
            }
        }
        if(repite != true){ //si el elemento a comparar no se repite, lo agrega a la cola de resultado
            c_encolar(c_resultado,elemento1);   
        }
        else{
            repite = false;
        }
        
        
        if(c_es_vacia(c_aux)){  //si no se agrega ningun elemento, es porque todos los elementos fueron distintos y sale del while
            seguir = false; 
        }
        else{
            c_copia = c_ej2_copiar(c_aux);
            c_aux = c_crear(); // cola auxiliar vuelve a 0
        }
    }
    
    return c_resultado;
}
// EJERCICIO 5
/**
5.	Dada una cola de valores enteros no repetidos y mayores o iguales a 2,
	obtener todos los valores que son Divisores Totales o parciales.
	Se dice que un valor es Divisor Total si permite dividir a todos los demás valores de la cola en forma exacta.
	Se dice que un divisor es parcial si al menos puede dividir en forma exacta al menos al 50% de la cola (es decir a la mitad de los elementos).
 */
// retorna una cola con el/los divisor/es total/es o parcial/es.   Si no hay ni divisor total ni parcial retornar cola vacia.
// Usar el atributo valor para indicar cuando el divisor es total(true) o parcial.  Indicar con true cuando es total, caso contrario false.

Cola c_ej5_divisortotal(Cola c)
{
    Cola copia = c_intercambiar(c);
    Cola aux = c_crear();
    Cola candidatos = c_crear();
    Cola resultado = c_crear();

    TipoElemento dato1,dato2;
    int contador_div;
    int longitud = c_longitud(c);

    if(longitud == 1)
    {
        dato1 = c_desencolar(copia);
        bool* v = malloc(sizeof(bool));
        *v = true;
        dato2 = te_crear_con_valor(dato1->clave,v);
        c_encolar(resultado,dato2);
    }
    else if(longitud == 2)
    {
        int i,j;
        for (i=0; i<2 ;i++)
        {
            dato1 = c_desencolar(copia);
            c_encolar(candidatos,dato1);
        }
        for (i=0; i<2; i++)
        {
            copia = c_intercambiar(c);
            dato1 = c_desencolar(candidatos);
            contador_div = 0;
            for (j=0; j<2; j++)
            {
                dato2 = c_desencolar(copia);
                if(dato2->clave % dato1->clave == 0)
                {
                    contador_div++;
                }
            }
            bool* v = malloc(sizeof(bool));
            *v = (contador_div == longitud);
            TipoElemento divisor = te_crear_con_valor(dato1->clave,v);
            c_encolar(resultado,divisor);
        }
    }
    else
    {
        int mayor = 2;
        int mitad_elementos = (longitud+1)/2;

        while(!c_es_vacia(copia))
        {
            dato1 = c_desencolar(copia);
            if(dato1->clave > mayor)
            {
                mayor = dato1->clave;
            }
            c_encolar(aux,dato1);
        }

        if(mayor % 2 != 0)  //si es impar, se le suma 1 para hacer division entera
        {
            mayor++;
        }

        while(!c_es_vacia(aux))
        {
            dato1 = c_desencolar(aux);
            if(dato1->clave <= mayor/2)
            {
                bool* v = malloc(sizeof(bool));
                *v = 0;
                dato2 = te_crear_con_valor(dato1->clave,v);
                c_encolar(candidatos,dato2);
            }
        }

        while(!c_es_vacia(candidatos))
        {
            copia = c_intercambiar(c);
            dato1 = c_desencolar(candidatos);
            contador_div = 0;
            while(!c_es_vacia(copia))
            {
                dato2 = c_desencolar(copia);
                if(dato2->clave % dato1->clave == 0)
                {
                    contador_div++;
                }
            }
            if(contador_div >= mitad_elementos) 
            {
                bool* v = malloc(sizeof(bool));
                *v = (contador_div == longitud);
                TipoElemento divisor = te_crear_con_valor(dato1->clave,v);
                c_encolar(resultado,divisor);
            }
        }
    }
    return resultado;
}

// EJERCICIO 6
/**
6.	Dada una pila y una cola generada con valores al azar retornar en una lista todos los valores comunes a ambas
    y en qué posición ordinal se encontró cada uno en su estructura.  Si existe mas de una vez la primer posicion encontrada.
    No se deben destruir las estructuras originales.
 */
// retornar una lista con los valores comunes segun las especificaciones del ejercicio.
// Si no existen valores comunes retornar la lista vacia. 
// Usar el atributo valor para enviar las 2 posiciones como un *char.
// Ejemplo: si “P” = (2,5,8,19,3,4) y “C” = (4, 18, 12, 5, 6) la lista tendría L = (5:2:4, 4:6:5). 2 y 4 deben venir en el valor.
// "2:4" indicara que el "5" esta en la segunda posicion de "P" y en la cuarta de "C".
Lista c_ej6_comunesapilaycola(Pila p, Cola c){
    Lista lista_resultado = l_crear();
    Pila p_copia = p_copiar(p);
    Cola c_copia = c_ej2_copiar(c);
    TipoElemento nodo_p, nodo_c, nuevo_elemento;
    int pos_pila = 1, pos_cola;

    while (!p_es_vacia(p_copia)){
        nodo_p = p_desapilar(p_copia);
        pos_cola = 1;
    
        while (!c_es_vacia(c_copia)){
            nodo_c = c_desencolar(c_copia);

            if (nodo_p->clave == nodo_c->clave && l_buscar(lista_resultado, nodo_c->clave)==NULL){
                char *posiciones = malloc(6 * sizeof(char));
                sprintf(posiciones, "%d:%d", pos_pila, pos_cola);
                nuevo_elemento = te_crear_con_valor(nodo_p->clave, posiciones);
                
                l_agregar(lista_resultado, nuevo_elemento);
            }
            pos_cola++;
        }
        c_copia = c_ej2_copiar(c);
        pos_pila++;
    }
    return lista_resultado;
}

// EJERCICIO 7
// 7.	Un negocio tiene 3 ventanillas para atender a sus clientes. Los clientes forman cola en cada ventanilla.
// 	Un día, dos de los tres empleados que atienden las ventanillas no pueden asistir al trabajo,
// 	quedando uno solo para atender a las tres colas. Este empleado decide que, a medida que lleguen los clientes,
// 	atenderá por cierta cantidad de minutos (que denominaremos Q) a cada cola, paseándose por todas las colas equitativamente.
// 	Se pide que implemente un algoritmo que modele esta situación y dé como resultado el orden en que fueron atendidos los clientes.
//  */
// retornar la cola con los resultados de la atenciones de los clientes.  Ver el ejemplo en el PDF del TP.
// retornar en la clave el nro de cola que lo atendio y en el void* de cada elemento los textos "Cliente 1 Cola 3", Cliente 1 Cola 2, etc.
// Segun el ejemplo el primer item de la cola seria clave: 3, void* "Cliente 1 Cola 3".
// Si las colas estan vacias, retornar cola vacia.
Cola c_ej7_atenderclientes(Cola c1, Cola c2, Cola c3, int tiempoatencion){
    TipoElemento nodo = te_crear(0), nodo2 = te_crear(0), nodo3 = te_crear(0), nodoaux; //crea la clave en 0, para desencolar despues
    Cola resultado = c_crear();
    int cont = 1, cont2 = 1, cont3 = 1;
    Cola c1_aux = c_crear(); Cola c2_aux = c_crear(); Cola c3_aux = c_crear();//se crean las colas auxiliares 
    c1_aux = c_ej2_copiar(c1); c2_aux = c_ej2_copiar(c2); c3_aux = c_ej2_copiar(c3);//se COPIAN las colas originales por las auxiliares para no perder el contenido
    bool termino1 = false, termino2 = false, termino3 = false;
    
    while ((termino1 == false || termino2 == false || termino3 == false)){
   
        if(nodo == NULL){
            termino1 = true;
        }
        else if(nodo->clave == 0){  //desencola el primer elemento
            nodo = c_desencolar(c1_aux);
        }
        else if((nodo->clave -= tiempoatencion)<=0){
            char *posiciones = malloc(10 * sizeof(char));
            sprintf(posiciones, "Cliente %d Cola 1", cont);     //almecenar string en la nueva cola
            nodoaux = te_crear_con_valor(1, posiciones);
            if(!c_encolar(resultado,nodoaux)){
                printf("hubo un error al encolar...\n");
            }
            nodo = c_desencolar(c1_aux);
            cont++;
        }

        if(nodo2 == NULL){
            termino2 = true;
        }
        else if(nodo2->clave == 0){
            nodo2 = c_desencolar(c2_aux);
        }
        else if((nodo2->clave -= tiempoatencion)<=0){

            char *posiciones = malloc(10 * sizeof(char));
            sprintf(posiciones, "Cliente %d Cola 2", cont2);
            nodoaux = te_crear_con_valor(2, posiciones);
            if(!c_encolar(resultado,nodoaux)){
                printf("hubo un error al encolar...\n");
            }
            nodo2=c_desencolar(c2_aux);
            cont2++;
        }

        if(nodo3 == NULL){
            termino3 = true;
        }
        else if(nodo3->clave == 0){
            nodo3 = c_desencolar(c3_aux);
        }
        else if((nodo3->clave -= tiempoatencion)<=0){
            char *posiciones = malloc(10 * sizeof(char));
            sprintf(posiciones, "Cliente %d Cola 3", cont3);
            nodoaux = te_crear_con_valor(3, posiciones);
            if(!c_encolar(resultado,nodoaux)){
                printf("hubo un error al encolar...\n");
            }
            nodo3=c_desencolar(c3_aux);
            cont3++;
        }
    }
    return resultado;
}