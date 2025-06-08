#include "tp_1_recursividad.h"

void menuPunto3(){
    int respuesta;
    char *entrada;
    int seguir = 1;
    
    while(seguir == 1){
        bool chequeo = false;

        while (!chequeo) {
            entrada = ingresa_palabra("Ingrese un numero 'k' para calcular el k-esimo numero de la serie Fibonacci:\n-> ");
            chequeo = (esDigito_positivo(entrada) && soloEspacios(entrada));
            if (!chequeo) {
                system("cls");
                printf(">> Entrada no valida, ingrese un entero.\n ACLARACION!! numeros positivos sin el '+' al principio.\n\n");
                free(entrada);
            }
        }

        respuesta = terminoSeridFibonacci(atoi(entrada));
        printf("\nFibonacci(%d) = %d\n", atoi(entrada), respuesta);
        
        printf(".\n.\n.\n>>>> Quiere calcular otro valor de la serie Fibonacci?\n");
        seguir = preguntarContinuar();

        free(entrada); 
        system("cls");
    }
}

int main(){
    menuPunto3();
    return 0;
}