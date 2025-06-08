#include "tp_1_recursividad.h"

void menuPunto5(){
    char *numero;
    char *numeroConPuntos;
    int seguir = 1;

    while(seguir == 1){
        bool chequeo = false;

        while (!chequeo) {
            numero = ingresa_palabra("Ingrese un numero entero sin puntos:\t");
            chequeo = (esDigito(numero) && soloEspacios(numero));
            if (!chequeo) {
                system("cls");
                printf(">> Entrada no valida, ingrese un entero!\n ACLARACION!! numeros positivos sin el '+' al principio.\n\n");
                free(numero);
            }
        }

        numeroConPuntos = agregarSeparadorMiles(numero);
        printf("El numero con puntos es: %s\n", numeroConPuntos);

        printf(".\n.\n.\n>>>> Desea ingresar otro valor?\n");
        seguir = preguntarContinuar();

        free(numero);
        free(numeroConPuntos);
        system("cls");
    }

}
int main(){
    menuPunto5();
    return 0;
}