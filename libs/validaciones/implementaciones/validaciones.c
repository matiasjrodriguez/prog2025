#include "../headers/validaciones.h"
static const int TAMANIO_MAXIMO = 100;
bool esDigito(const char *c){
    if( strlen(c)>1 && (c[0] == '-') ) {
        c++;
    }
    for (int i = 0; c[i] != '\0'; i++) {
        if (!isdigit(c[i])) {
            return false; 
        }
    }
    return true;
}

bool esDigito_positivo(const char *c){
    if( strlen(c)>1 && c[0] == '-' ) {
        return false;
    }
    for (int i = 0; c[i] != '\0'; i++) {
        if(!isdigit(c[i])) {
            return false; 
        }
    }
    return true;
}

bool noEsCero(const char *c){
    bool esCero = false;
    while(c[0]!='\0' && !esCero){
        if(c[0] != '0'){
            esCero = true;
        }
        c++;
    }
    return esCero;
}

bool esFlotante(const char *c){
    bool puntoEncontrado = false;

    if( strlen(c)>1 && (c[0] == '-') ) {
        c++;
    }
    for (int i = 0; c[i] != '\0'; i++) {
        if(c[i] == '.'){
            if(puntoEncontrado){
                return false;
            }
            puntoEncontrado = true;
        }
        else if (!isdigit(c[i])) {
            return false; 
        }
    }
    return true;
}

bool esFlotantePositivo(const char *c){
    bool puntoEncontrado = false;

    if( strlen(c)>1 && (c[0] == '-') ) {
        return false;
    }
    for (int i = 0; c[i] != '\0'; i++) {
        if(c[i] == '.'){
            if(puntoEncontrado){
                return false;
            }
            puntoEncontrado = true;
        }
        else if (!isdigit(c[i])) {
            return false; 
        }
    }
    return true;
}

bool esAlfabetico(const char *c) {
    for (int i = 0; c[i] != '\0'; i++) {
        if(!isalpha(c[i])) {
            return false; 
        }
    }
    return true;
}

bool soloEspacios(char* string){
    int i = 0;
    bool encontro_caracter = false;
    while (encontro_caracter == false && *(string + i) != '\0'){
        if(*(string + i) != ' '){
            encontro_caracter = true;
        }
        i++;
    }
    return encontro_caracter;
}

bool masDeUnCaracter(char* string){
    bool resultado = true;
    if(strlen(string) <= 1){
        resultado = false;
        return resultado;
    }
    return resultado;
}

bool contieneEspacios(const char *c){
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i]==' ') {
            return false; 
        }
    }
    return true;
}

bool soloHyL(char senial[]){    //si la señal solo contiene h o l retorna verdadero
    bool bandera = true, resultado = true;
    int i = 0;
    while(bandera == true && senial[i] != '\0'){
        if(senial[i] == 'L' || senial[i] == 'l'){
            i++;
        }
        else if(senial[i] == 'H' || senial[i] == 'h'){
            i++;
        }
        else{
            resultado = false;
            bandera = false;
        }
    }
    return resultado;  
}

bool verificandoSenial(char senial[]){  //si la señal es valida, retorna true
    bool resultado = true;
    
    if(soloEspacios(senial) == false){
        printf("Ingreso unicamente espacios. Solo debe ingresar letras H y L...:\n");
        resultado = false;
    }
    else if(soloHyL(senial) == false){
        printf("Solo debe ingresar letras H y L...:\n");
        system("pause");
        resultado = false;
    }
    return resultado;
}

char* ingresa_palabra(char* mensaje){
    char palabra[100];
    printf("%s", mensaje);
    
    fgets(palabra,100, stdin);
    int l = strlen(palabra);
    palabra[l-1]=0;

    char* pp = (char*)malloc(l * sizeof(char));
    if(pp == NULL){
        printf("error al solicitar memoria...");
    }
    strcpy(pp, palabra);

    return pp;
}

// Permite ingresar un entero o un punto "." (como string). Si se ingresa un entero, lo guarda en *num y retorna true.
// Si se ingresa un punto ".", retorna false y no modifica *num. Si se ingresa cualquier otro valor, retorna false.
bool ingresoDatosNumericosEnter(const char *mensaje_error, int *num) {
    char *c = ingresa_palabra("");
    if (strlen(c) == 0) {
        free(c);
        return false;
    }

    while (!esDigito(c)) {
        printf("%s\n-> ", mensaje_error);
        free(c);
        c = ingresa_palabra("");
        if (strlen(c) == 0) {
            free(c);
            return false;
        }
    }
    *num = atoi(c);
    free(c);
    return true;
}

int ingresoDatosNumericos(char * mensaje_error){
    bool chequeo = false;
    char * c;
    int num;
    while (!chequeo){
        c = ingresa_palabra("");
        chequeo = (esDigito(c) && soloEspacios(c));
        if(!chequeo){
            printf("%s\n-> ", mensaje_error);
            free(c);
            c = NULL;
        }
    }
    chequeo = false;
    num = atoi(c);
    free(c);
    return num;
}

int ingresoDatosNumericosPositivos(char * mensaje_error){
    bool chequeo = false;
    char * c;
    int num;
    while (!chequeo){
        c = ingresa_palabra("");
        chequeo = (esDigito_positivo(c) && soloEspacios(c));
        if(!chequeo){
            printf("%s", mensaje_error);
            free(c);
            c = NULL;
        }
    }
    chequeo = false;
    num = atoi(c);
    return num;
}

int ingresoDatosNumericosNoCero(char * mensaje_error){
    bool chequeo = false;
    char * c;
    int num;
    while (!chequeo){
        c = ingresa_palabra("");
        chequeo = (esDigito_positivo(c) && soloEspacios(c) && noEsCero(c));
        if(!chequeo){
            system("cls");
            printf("%s\n-> ", mensaje_error);
            free(c);
            c = NULL;
        }
    }
    chequeo = false;
    num = atoi(c);
    return num;
}

int ingresoIntLimitado(char * mensaje_error, int minimo, int maximo){
    bool chequeo = false;
    char * c;
    int num;

    while (!chequeo){
        c = ingresa_palabra("");
        chequeo = (esDigito(c) && soloEspacios(c));
        if (chequeo) {
            num = atoi(c);
            if (num < minimo || num > maximo) {
                chequeo = false;
            }
        }
        if(!chequeo){
            printf("%s\n-> ", mensaje_error);
            free(c);
            c = NULL;
        }
    }
    chequeo = false;
    free(c);

    return num;
}

double ingresoDatosFloat(char *mensaje_error) {
    bool chequeo = false;
    char *c;
    double num;

    while (!chequeo) {
        c = ingresa_palabra("");
        reemplazarComasPorPuntos(c);
        chequeo = esFlotante(c) && soloEspacios(c);
        if (!chequeo) {
            system("cls");
            printf("%s", mensaje_error);
            free(c);
        }
    }

    num = atof(c);
    free(c);
    return num;
}

double ingresoDatosFloatPositivos(char *mensaje_error) {
    bool chequeo = false;
    char *c;
    double num;

    while (!chequeo) {
        c = ingresa_palabra("");
        reemplazarComasPorPuntos(c);
        chequeo = esFlotantePositivo(c) && soloEspacios(c);
        if (!chequeo) {
            system("cls");
            printf("%s", mensaje_error);
            free(c);
        }
    }

    num = atof(c);
    free(c);
    return num;
}

char* sacarEspacios(char* string){
    int i = 0, f = strlen(string) - 1;      //i = posicion primer elemento || f = posicion ultimo elemento
    while (*(string + i) == ' '){   
        i++;
    }                                   //i = posicion del primer caracter distinto a un espacio || f = posicion del ultimo caracter distinto a un espacio
    while (*(string + f) == ' '){
        f--;
    }
    
    char* string_aux = (char*)malloc((f - i) + 2 * sizeof(char));   
    
    for(int j = 0; j <= (f - i);j++){
        *(string_aux + j) = *(string + (i + j));    //i+j sirve para copiar a partir del primer caracter != ' ' de la cadena
    }
    *(string_aux + (f - i + 1)) = '\0';
    
    string = (char*)realloc(string_aux,((f - i) + 1) * sizeof(char));
    *(string + (f - i + 1)) = '\0';
    //free(string_aux);
    return string;
}

void todoAMayusculas(char* string){
    
    while (*string) //se ejecuta mientras este apuntando al string
    {
        *string = toupper(*string);
        string++;   //avanza en memoria
    }
}

int preguntarContinuar() {
    int continuar;
    char buffer[10];

    while (1) {
        printf("\n\nIngresa 1 para SEGUIR, 0 para NO SEGUIR: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &continuar) == 1 && (continuar == 0 || continuar == 1)) {
                return continuar;
            } else {
                printf("Entrada no valida. Por favor, ingresa 1 para continuar o 0 para salir.\n");
            }
        }
    }
}

int leerEnteroPositivo(const char* mensaje) {
    char buffer[100];
    int valor;
    while (1) {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            buffer[strcspn(buffer, "\n")] = '\0';  
            if (esDigito_positivo(buffer)) {
                valor = atoi(buffer);
                if (valor > 0) {
                    return valor;
                } else {
                    printf("Entrada no valida. Solo se permiten numeros enteros positivos.\n");
                }
            } else {
                printf("Entrada no valida. Solo se permiten numeros enteros positivos.\n");
            }
        } else {
            printf("Error en la lectura. Intenta de nuevo.\n");
            while (getchar() != '\n');  
        }
    }
}

void reemplazarComasPorPuntos(char *c) {
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] == ',') {
            c[i] = '.';
        }
    }
}

void mostrarComparacion(int respuesta){
    if(respuesta == 1){
        printf("por lo cual la lista 1 es MAYOR a la lista 2\n");
    }
    else if(respuesta == 2){
        printf("por lo cual la lista 1 es MENOR a la lista 2\n");
    }
    else{
        printf("ambas listas son iguales\n");
    }
}

// mostrar polinomio (tiene errores)
int intersarEspacios(char* poli, int pos){
    poli[++pos] = ' ';
    poli[++pos] = '+';
    poli[++pos] = ' ';

    return ++pos;
}
void mostrarPolinomio(Lista list){
    char polinomio[100] = "F(x) = "; 
    int tamanio = l_longitud(list), guia=1, i=7;
    int grado = tamanio-1;
    Iterador recorrer = iterador(list);

    while (hay_siguiente(recorrer) && guia<=tamanio){
        int num = siguiente(recorrer)->clave;

        if((guia+1) != tamanio && num!=0 && grado >1){

            polinomio[i] = num + '0';
            polinomio[++i] = 'X';
            polinomio[++i] = '^';
            polinomio[++i] = grado + '0';
            int space = intersarEspacios(polinomio, i);
            i=space;
        }
        else if(num!=0){
            
            if(guia==tamanio){
                int space = intersarEspacios(polinomio, i);
                i=space;   
                polinomio[i] = num + '0';
            }
            else{
                polinomio[i] = num + '0';
                polinomio[++i] = 'X';
            }
        }
        guia++;
        grado--;
    }
    polinomio[++i] = '\0';

    printf("\nPOLINOMIO ------ ");
    for(int i = 0; i<=strlen(polinomio); i++){
        printf("%c", polinomio[i]);
    }
}

Lista l_cargar(int cantidad){
    Lista list = l_crear();
    int num, guia = 0;
    TipoElemento nodo;

    while(!l_es_llena(list) && guia<cantidad){
        printf("  | CLAVE NODO %d | ->\t", guia+1);
        num = ingresoDatosNumericos("Ingrese una clave valida!");
        nodo = te_crear(num);
        l_agregar(list, nodo);
        guia++;
    }

    return list;
}

Lista l_cargar_azar(int cantidad){
    Lista list = l_crear();
    int num, guia = 0;
    TipoElemento nodo;
    srand(time(NULL));

    while(!l_es_llena(list) && guia<cantidad){
        num = rand() % 151;
        nodo = te_crear(num);
        l_agregar(list, nodo);
        guia++;
    }
    return list;
}

Lista l_cargar_azar_limitada(int cantidad, int maximo, int minimo){
    Lista list = l_crear();
    int num, guia = 0;
    TipoElemento nodo;
    srand(time(NULL));

    if (minimo > maximo) {
        int temp = minimo;
        minimo = maximo;
        maximo = temp;
    }
    while(!l_es_llena(list) && guia<cantidad){
        num = minimo + rand() % (maximo - minimo + 1);
        nodo = te_crear(num);
        l_agregar(list, nodo);
        guia++;
    }

    return list;
}

Pila p_cargar(int cantidad){
    Pila pilon = p_crear();
    int num, guia = 0;
    TipoElemento nodo;
    if(cantidad == 0){
        return pilon;
    }
    while(!p_es_llena(pilon) && guia<cantidad){
        printf("  | CLAVE NODO %d | ->\t", guia+1);
        num = ingresoDatosNumericos("Ingrese una clave valida!");
        nodo = te_crear(num);
        p_apilar(pilon, nodo);
        guia++;
    }

    return pilon;
}

Pila p_cargar_azar(int cantidad){
    Pila pilon = p_crear();
    int num, guia = 0;
    TipoElemento nodo;
    srand(time(NULL));

    while(!p_es_llena(pilon) && guia<cantidad){
        num = rand() % 151;
        nodo = te_crear(num);
        p_apilar(pilon, nodo);
        guia++;
    }
    return pilon;
}

Pila p_cargar_azar_limitada(int cantidad, int maximo, int minimo){
    Pila pilon = p_crear();
    int num, guia = 0;
    TipoElemento nodo;
    srand(time(NULL));

    if (minimo > maximo) {
        int temp = minimo;
        minimo = maximo;
        maximo = temp;
    }
    while(!p_es_llena(pilon) && guia<cantidad){
        num = minimo + rand() % (maximo - minimo + 1);
        nodo = te_crear(num);
        p_apilar(pilon, nodo);
        guia++;
    }
    return pilon;
}

Pila p_intercambio(Pila auxiliar, Pila p_original){
    TipoElemento nodo,nodo1;
    if(p_es_vacia(auxiliar)){
        return NULL;
    }
    while(p_es_vacia(auxiliar)!=true){
        nodo=p_desapilar(auxiliar);
        nodo1=te_crear(nodo->clave);
        p_apilar(p_original,nodo1);
    }
    return p_original;
}

Pila p_copiar(Pila original){
    Pila copia = p_crear();
    Pila auxiliar = p_crear();
    TipoElemento nodo;

    while (!p_es_vacia(original)) {
        nodo = p_desapilar(original);
        p_apilar(auxiliar, nodo);
    }

    while (!p_es_vacia(auxiliar)) {
        nodo = p_desapilar(auxiliar);
        p_apilar(original, nodo);
        p_apilar(copia, te_crear(nodo->clave));
    }

    return copia;
}

Cola c_cargar(int cantidad){
    Cola colaza = c_crear();
    int num, guia = 0;
    TipoElemento nodo;

    while(!c_es_llena(colaza) && guia<cantidad){
        printf("  | CLAVE NODO %d | ->\t", guia+1);
        num = ingresoDatosNumericos("Ingrese una clave valida!");
        nodo = te_crear(num);
        c_encolar(colaza, nodo);
        guia++;
    }

    return colaza;
}

Cola c_cargar_cantidad(){
    int cola_cantidad;
    Cola colaza;

    printf("Ingrese la cantidad de elementos a cargar en la cola 1 (max %i)\n-> ", TAMANIO_MAXIMO);
    cola_cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 1, TAMANIO_MAXIMO);   
    colaza = c_cargar(cola_cantidad);

    return colaza;
}

bool c_buscar(Cola cola, int clave)
{
    TipoElemento dato;
    bool encontre = false;
    Cola aux;
    aux = c_crear();

    while(!c_es_vacia(cola))
    {
        dato = c_desencolar(cola);
        if(dato->clave == clave)
        {
            encontre = true;
        }

        c_encolar(aux,dato);
    }

    while(!c_es_vacia(aux))
    {
        c_encolar(cola,c_desencolar(aux));
    }
    return encontre;
}

Cola c_intercambiar(Cola cola){
    TipoElemento nodo;
    Cola nueva=c_crear();
    Cola aux=c_crear();
    while(!c_es_vacia(cola)){
        nodo=c_desencolar(cola);
        c_encolar(aux,nodo);
    }
    while(!c_es_vacia(aux)){
        nodo=c_desencolar(aux);
        c_encolar(cola,nodo);
        c_encolar(nueva,te_crear(nodo->clave));
    }
    return nueva;
}

int c_longitud(Cola cola)
{
    Cola aux = c_intercambiar(cola);
    int cantidad = 0;
    while(!c_es_vacia(aux))
    {
        c_desencolar(aux);
        cantidad++;
    }
    return cantidad;
}

void c_mostrar_con_valor(Cola cola)
{
    Cola aux = c_crear();
    TipoElemento dato;

    while(!c_es_vacia(cola))
    {
        dato = c_desencolar(cola);
        printf("Clave: %i\tValor: %s\n",dato->clave, *(bool*)(dato->valor) ? "Verdadero" : "Falso");
        c_encolar(aux,dato);
    }
    while(!c_es_vacia(aux))
    {
        dato = c_desencolar(aux);
        c_encolar(cola,dato);
    }
}

void c_liberar_memoria(Cola cola)
{
    while(!c_es_vacia(cola))
    {
        TipoElemento nodo = c_desencolar(cola);
        free(nodo->valor);
    }
}

int a_cargar(ArbolBinario arbol, NodoArbol padre, int opcion){
    TipoElemento te;
    NodoArbol nodo;
    int num, guia = 0;
    int continuar;

    if(!a_es_lleno(arbol)){
        printf("  | CLAVE NODO | ->\t");
        num = ingresoDatosNumericos("Ingrese una clave valida!");
        te = te_crear(num);
        
        if(opcion == -1) nodo = a_conectar_hi(arbol, padre, te);
        else if (opcion == 1) nodo = a_conectar_hd(arbol, padre, te);
        else nodo = a_establecer_raiz(arbol, te);

        printf("Desea continuar cargando el arbol?");
        continuar = preguntarContinuar();
        if(!continuar){
            return 1;
        }
        a_cargar(arbol, nodo, -1);
        a_cargar(arbol, nodo, 1);
    }
}

NodoArbol a_buscar(NodoArbol raiz, int clave){
    if(raiz == NULL){
        return NULL;
    }
    if(raiz->datos->clave != clave){
        NodoArbol resultado = a_buscar(n_hijoizquierdo(raiz), clave);
        if (resultado != NULL) {
            return resultado;
        }
        resultado = a_buscar(n_hijoderecho(raiz), clave);
        if (resultado != NULL) {
            return resultado;
        }
    }
    else{
        return raiz;
    }
}
NodoArbol a_buscar_nodo(ArbolBinario arbol, int clave){
    NodoArbol raiz = a_raiz(arbol);
    NodoArbol nodo = a_buscar(raiz, clave);

    return nodo;
}

ArbolBinario a_cargar_anchura(){
    ArbolBinario arbol = a_crear();
    int clave, clave_hi, clave_hd;
    char buffer[32];

    printf("Ingrese la clave de la raiz (enter para arbol vacio): ");
    if(!ingresoDatosNumericosEnter("Ingrese un valor adecuado!", &clave)){
        return arbol;
    }
    NodoArbol raiz = a_establecer_raiz(arbol, te_crear(clave));

    Cola cola = c_crear();
    c_encolar(cola, (TipoElemento)raiz);

    while (!c_es_vacia(cola)) {
        NodoArbol actual = (NodoArbol)c_desencolar(cola);
        printf("\nNodo %d:\n", actual->datos->clave);

        // Hijo izquierdo
        printf("  Clave hijo izquierdo de %d (enter para NULL): ", actual->datos->clave);
        if (ingresoDatosNumericosEnter("Ingrese un valor adecuado!", &clave_hi)) {
            NodoArbol hi = a_conectar_hi(arbol, actual, te_crear(clave_hi));
            c_encolar(cola, (TipoElemento)hi);
        }

        // Hijo derecho
        printf("  Clave hijo derecho de %d (enter para NULL): ", actual->datos->clave);
        if (ingresoDatosNumericosEnter("Ingrese un valor adecuado!", &clave_hd)) {
            NodoArbol hd = a_conectar_hd(arbol, actual, te_crear(clave_hd));
            c_encolar(cola, (TipoElemento)hd);
        }
        printf("\n\n");
        a_mostrar_normal(arbol);
        printf("\n\n");
    }
    system("cls");
    return arbol;
}

ArbolBinario nArio_cargar_anchura(){
    ArbolBinario arbol = a_crear();
    int clave, clave_hi, clave_hd;
    char buffer[32];

    printf("Ingrese la clave de la raiz (enter para arbol vacio): ");
    if(!ingresoDatosNumericosEnter("Ingrese un valor adecuado!", &clave)){
        return arbol;
    }
    NodoArbol raiz = a_establecer_raiz(arbol, te_crear(clave));

    Cola cola = c_crear();
    c_encolar(cola, (TipoElemento)raiz);

    NodoArbol actual = (NodoArbol)c_desencolar(cola);
    printf("\nNodo %d:\n", actual->datos->clave);

    // Hijo izquierdo
    printf("  Clave hijo izquierdo de %d (enter para NULL): ", actual->datos->clave);
    if (ingresoDatosNumericosEnter("Ingrese un valor adecuado!", &clave_hi)) {
        NodoArbol hi = a_conectar_hi(arbol, actual, te_crear(clave_hi));
        c_encolar(cola, (TipoElemento)hi);
    }
    
    while (!c_es_vacia(cola)) {
        NodoArbol actual = (NodoArbol)c_desencolar(cola);
        printf("\nNodo %d:\n", actual->datos->clave);

        // Hijo izquierdo
        printf("  Clave hijo izquierdo de %d (enter para NULL): ", actual->datos->clave);
        if (ingresoDatosNumericosEnter("Ingrese un valor adecuado!", &clave_hi)) {
            NodoArbol hi = a_conectar_hi(arbol, actual, te_crear(clave_hi));
            c_encolar(cola, (TipoElemento)hi);
        }

        // Hijo derecho
        printf("  Clave hijo derecho de %d (enter para NULL): ", actual->datos->clave);
        if (ingresoDatosNumericosEnter("Ingrese un valor adecuado!", &clave_hd)) {
            NodoArbol hd = a_conectar_hd(arbol, actual, te_crear(clave_hd));
            c_encolar(cola, (TipoElemento)hd);
        }
        printf("\n\n");
        a_mostrar_normal(arbol);
        printf("\n\n");
    }
    system("cls");
    return arbol;
}

ArbolBinario nArio_cargar_azar(int cantidad_nodos){
    if (cantidad_nodos <= 0) return a_crear();

    ArbolBinario arbol = a_crear();
    NodoArbol* nodos = malloc(sizeof(NodoArbol) * cantidad_nodos);
    int claves[cantidad_nodos];
    int usados = 0;
    srand((unsigned int)time(NULL));

    // Generar claves únicas aleatorias
    for (int i = 0; i < cantidad_nodos; ++i) {
        int clave, unico;
        do {
            clave = 1 + rand() % (100 - 1 + 1);
            unico = 1;
            for (int j = 0; j < i; ++j) {
                if (claves[j] == clave) {
                    unico = 0;
                    break;
                }
            }
        } while (!unico);
        claves[i] = clave;
    }

    // Insertar la raíz
    nodos[0] = a_establecer_raiz(arbol, te_crear(claves[0]));
    usados = 1;

    int insertados = 1;
    while (insertados < cantidad_nodos) {
        // Elegir nodo padre al azar entre los ya insertados
        int padre_idx = rand() % usados;
        NodoArbol padre = nodos[padre_idx];

        // Insertar como hijo izquierdo si no tiene, sino como hermano derecho del último hijo
        if (n_hijoizquierdo(padre) == NULL) {
            nodos[usados++] = a_conectar_hi(arbol, padre, te_crear(claves[insertados]));
        } else {
            NodoArbol ultimo = n_hijoizquierdo(padre);
            // Buscar el último hermano derecho del hijo izquierdo
            while (n_hijoderecho(ultimo) != NULL) {
                ultimo = n_hijoderecho(ultimo);
            }
            nodos[usados++] = a_conectar_hd(arbol, ultimo, te_crear(claves[insertados]));
        }
        insertados++;
    }

    free(nodos);
    return arbol;
}

ArbolBinario nArio_cargar_azar_rep(int cantidad_nodos){
    if (cantidad_nodos <= 0) return a_crear();

    ArbolBinario arbol = a_crear();
    NodoArbol* nodos = malloc(sizeof(NodoArbol) * cantidad_nodos);
    int claves[cantidad_nodos];
    int usados = 0;
    srand((unsigned int)time(NULL));

    // Generar claves aleatorias
    for (int i = 0; i < cantidad_nodos; ++i) {
        int clave = 1 + rand() % (100 - 1 + 1);
        claves[i] = clave;
    }

    // Insertar la raíz
    nodos[0] = a_establecer_raiz(arbol, te_crear(claves[0]));
    usados = 1;

    int insertados = 1;
    while (insertados < cantidad_nodos) {
        // Elegir nodo padre al azar entre los ya insertados
        int padre_idx = rand() % usados;
        NodoArbol padre = nodos[padre_idx];

        // Insertar como hijo izquierdo si no tiene, sino como hermano derecho del último hijo
        if (n_hijoizquierdo(padre) == NULL) {
            nodos[usados++] = a_conectar_hi(arbol, padre, te_crear(claves[insertados]));
        } else {
            NodoArbol ultimo = n_hijoizquierdo(padre);
            // Buscar el último hermano derecho del hijo izquierdo
            while (n_hijoderecho(ultimo) != NULL) {
                ultimo = n_hijoderecho(ultimo);
            }
            nodos[usados++] = a_conectar_hd(arbol, ultimo, te_crear(claves[insertados]));
        }
        insertados++;
    }

    free(nodos);
    return arbol;
}

ArbolBinario a_cargar_azar(int cantidad_nodos) {
    if (cantidad_nodos <= 0) return a_crear();

    ArbolBinario arbol = a_crear();
    NodoArbol* nodos = malloc(sizeof(NodoArbol) * cantidad_nodos);
    int claves[cantidad_nodos];
    int usados = 0;
    srand(time(NULL));

    // Generar claves únicas aleatorias
    for (int i = 0; i < cantidad_nodos; ++i) {
        int clave;
        int unico;
        do {
            clave = 1 + rand() % (100 - 1 + 1);
            unico = 1;
            for (int j = 0; j < i; ++j) {
                if (claves[j] == clave) {
                    unico = 0;
                    break;
                }
            }
        } while (!unico);
        claves[i] = clave;
    }

    // Insertar la raíz
    nodos[0] = a_establecer_raiz(arbol, te_crear(claves[0]));
    usados = 1;

    int insertados = 1;
    while (insertados < cantidad_nodos) {
        // Elegir nodo padre al azar entre los ya insertados
        int padre_idx = rand() % usados;
        NodoArbol padre = nodos[padre_idx];

        // Decidir aleatoriamente si insertar hijo izquierdo o derecho
        int lado = rand() % 2 ? 1 : -1; // 1: derecho, -1: izquierdo

        // Si ambos hijos están ocupados, buscar otro padre
        if (n_hijoizquierdo(padre) != NULL && n_hijoderecho(padre) != NULL) {
            continue;
        }

        // Si el lado elegido está ocupado, usar el otro si está libre
        if (lado == -1 && n_hijoizquierdo(padre) != NULL) lado = 1;
        if (lado == 1 && n_hijoderecho(padre) != NULL) lado = -1;

        NodoArbol nuevo = NULL;
        if (lado == -1 && n_hijoizquierdo(padre) == NULL) {
            nuevo = a_conectar_hi(arbol, padre, te_crear(claves[insertados]));
        } else if (lado == 1 && n_hijoderecho(padre) == NULL) {
            nuevo = a_conectar_hd(arbol, padre, te_crear(claves[insertados]));
        }
        if (nuevo != NULL) {
            nodos[usados++] = nuevo;
            insertados++;
        }
    }

    free(nodos);
    return arbol;
}

ArbolBinario a_cargar_azar_rep(int cantidad_nodos){
    if (cantidad_nodos <= 0) return a_crear();

    ArbolBinario arbol = a_crear();
    NodoArbol* nodos = malloc(sizeof(NodoArbol) * cantidad_nodos);
    int claves[cantidad_nodos];
    int usados = 0;
    srand(time(NULL));

    // Generar claves aleatorias
    for (int i = 0; i < cantidad_nodos; ++i) {
        int clave = 1 + rand() % (100 - 1 + 1);
        claves[i] = clave;
    }

    // Insertar la raíz
    nodos[0] = a_establecer_raiz(arbol, te_crear(claves[0]));
    usados = 1;

    int insertados = 1;
    while (insertados < cantidad_nodos) {
        // Elegir nodo padre al azar entre los ya insertados
        int padre_idx = rand() % usados;
        NodoArbol padre = nodos[padre_idx];

        // Decidir aleatoriamente si insertar hijo izquierdo o derecho
        int lado = rand() % 2 ? 1 : -1; // 1: derecho, -1: izquierdo

        // Si ambos hijos están ocupados, buscar otro padre
        if (n_hijoizquierdo(padre) != NULL && n_hijoderecho(padre) != NULL) {
            continue;
        }

        // Si el lado elegido está ocupado, usar el otro si está libre
        if (lado == -1 && n_hijoizquierdo(padre) != NULL) lado = 1;
        if (lado == 1 && n_hijoderecho(padre) != NULL) lado = -1;

        NodoArbol nuevo = NULL;
        if (lado == -1 && n_hijoizquierdo(padre) == NULL) {
            nuevo = a_conectar_hi(arbol, padre, te_crear(claves[insertados]));
        } else if (lado == 1 && n_hijoderecho(padre) == NULL) {
            nuevo = a_conectar_hd(arbol, padre, te_crear(claves[insertados]));
        }
        if (nuevo != NULL) {
            nodos[usados++] = nuevo;
            insertados++;
        }
    }

    free(nodos);
    return arbol;
}

ArbolBinario a_modo_carga(){
    int opcion, cant_nodo;
    ArbolBinario arbolito;

    printf("Seleccione el modo de carga del arbol binario:\n");
    printf("  1. Carga manual por anchura\n");
    printf("  2. Carga al azar con valores unicos\n");
    printf("  3. Carga al azar con valores que pueden repetirse\n");
    printf("> Seleccione una opcion: ");
    opcion = ingresoIntLimitado("Ingrese 1, 2 o 3", 1, 3);
    if (opcion == 1){
        printf("\n\n");
        arbolito = a_cargar_anchura();
        system("cls");
    }
    else if (opcion == 2){
        printf("\n\n");
        printf("Ingrese la cantidad de nodos que desea cargar en el arbol o <=0 para cargarlo vacio\n-> ");
        cant_nodo = ingresoDatosNumericosPositivos("Ingrese un valor adecuado!");
        printf("\n\n");
        arbolito = a_cargar_azar(cant_nodo);
    }
    else{
        printf("\n\n");
        printf("Ingrese la cantidad de nodos que desea cargar en el arbol o <=0 para cargarlo vacio\n-> ");
        cant_nodo = ingresoDatosNumericosPositivos("Ingrese un valor adecuado!");
        printf("\n\n");
        arbolito = a_cargar_azar_rep(cant_nodo);
    }
    
    return arbolito;
}

ArbolBinario nArio_modo_carga(){
    int opcion, cant_nodo;
    ArbolBinario arbolito;

    printf("Seleccione el modo de carga del arbol binario transformado:\n");
    printf("  1. Carga manual por anchura\n");
    printf("  2. Carga al azar con valores unicos\n");
    printf("  3. Carga al azar con valores que pueden repetirse\n");
    printf("> Seleccione una opcion: ");
    opcion = ingresoIntLimitado("Ingrese 1, 2 o 3", 1, 3);
    if (opcion == 1){
        printf("\n\n");
        arbolito = nArio_cargar_anchura();
        system("cls");
    }
    else if (opcion == 2){
        printf("\n\n");
        printf("Ingrese la cantidad de nodos que desea cargar en el arbol o <=0 para cargarlo vacio\n-> ");
        cant_nodo = ingresoDatosNumericosPositivos("Ingrese un valor adecuado!");
        printf("\n\n");
        arbolito = nArio_cargar_azar(cant_nodo);
    }
    else{
        printf("\n\n");
        printf("Ingrese la cantidad de nodos que desea cargar en el arbol o <=0 para cargarlo vacio\n-> ");
        cant_nodo = ingresoDatosNumericosPositivos("Ingrese un valor adecuado!");
        printf("\n\n");
        arbolito = nArio_cargar_azar_rep(cant_nodo);
    }
    
    return arbolito;
}

void mostrarArbolBinRec(NodoArbol nodo, char cad[]){
    printf("%d\n", nodo->datos->clave);

    //Para el hijo derecho
    if (nodo->hd!=NULL){
        char cad2 [1000]; 
        strcpy(cad2,cad);
        if (nodo->hi!=NULL){
            printf("%s%c%c%c%c%c", cad, 195, 196, 196, 196,196);
            char simb = 179, aux [2];
            aux[0] = simb; aux[1]= '\0'; strcat(cad2, aux);
            strcat(cad2,"    "); 
            mostrarArbolBinRec (nodo->hd, cad2);
        }
        else{
            printf("%s%c%c%c%c%c%c", cad, 192, 196,68, 196,196,196); 
            strcat(cad2,"    ");
            mostrarArbolBinRec (nodo->hd, cad2);
        }
    }
    //Para el hijo izquierdo
    if (nodo->hi != NULL){
        char cad3[1000];
        strcpy(cad3, cad);
        printf("%s%c%c%c%c%c", cad, 192, 196, 73, 196,196); 
        strcat(cad3,"     ");
        mostrarArbolBinRec (nodo->hi, cad3);
    }
}
void a_mostrar_normal(ArbolBinario arb){
    if (a_raiz(arb) == NULL) printf("El arbol esta vacio.");
    else{
        mostrarArbolBinRec(a_raiz(arb),"");
    }
}
void a_mostrar_normal_ABB(ArbolBinarioBusqueda arb){
    if (abb_raiz(arb) == NULL) printf("El arbol esta vacio.");
    else{
        mostrarArbolBinRec(abb_raiz(arb),"");
    }
}
void a_mostrar_normal_AVL(ArbolAVL arb){
    if (avl_raiz(arb) == NULL) printf("El arbol esta vacio.");
    else{
        mostrarArbolBinRec(avl_raiz(arb),"");
    }
}
void in_ordenAVL(ArbolAVL a){
    NodoArbol N = avl_raiz(a);
    in_orden(N);
}
void in_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        in_orden(n_hijoizquierdo(N));
        x = n_recuperar(N);
        printf(" %d", x->clave);
        in_orden(n_hijoderecho(N));
    }
}

bool esBinarioTransformado(NodoArbol raiz){
    return (n_hijoderecho(raiz) == NULL);
}



//hash

char* ingresando_Telefono_Alumno(){
    bool seguir = true;
    char* telefono;
    while (seguir){
        telefono = ingresa_palabra("Ingrese el telefono del alumno...\n"); 
        if(masDeUnCaracter(telefono) && soloEspacios(telefono) && strlen(telefono) <= 16){
            seguir = false;
        }
       else{
        printf("Error al ingresar telefono\nVuelva a intentarlo\n");
        system("pause");
       }
    }
    return telefono;
}

char* ingresando_Domicilio_Alumno(){
    bool seguir = true;
    char* domicilio;
    while (seguir){
        domicilio = ingresa_palabra("Ingrese el domicilio del alumno...\n");  
        if(masDeUnCaracter(domicilio) && soloEspacios(domicilio) && strlen(domicilio) <= 21){
            seguir = false;
        }
       else{
        printf("Error al ingresar domicilio\nVuelva a intentarlo\n");
        system("pause");
       }
    }
    return domicilio;
}
int ingresando_Legajo_alumno(){
    bool seguir = true;
    int legajo;
    while (seguir){
        legajo = ingresoDatosNumericosPositivos("Ingrese el legajo del alumno (maximo 6 digitos)");
        if(legajo <= 999999){
            seguir = false;
        }
       else{
        printf("Error al ingresar legajo\nVuelva a intentarlo\n");
        system("pause");
       }
    }
    return legajo;
}

char* ingresando_Nombre_Alumno(){    
    bool seguir = true;
    char* nombre;
    while(seguir){
        nombre = ingresa_palabra("Ingrese el nombre del alumno...\n"); 
        if(masDeUnCaracter(nombre) && soloEspacios(nombre) && esAlfabetico(nombre) && strlen(nombre) <= 21){
            seguir = false;
        }
       else{
        printf("Error al ingresar nombre\nVuelva a intentarlo\n");
        system("pause");
       }
    }
    return nombre;
}