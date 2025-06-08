#include "tp_1_recursividad.h"

void menuPunto2(){
    char *m, *n;
    int resultado;
    int seguir = 1;
    
    while(seguir == 1){
        bool chequeo = false;

        while (!chequeo){
            m = ingresa_palabra("Ingrese el multiplicando 'm':\n-> ");
            chequeo = (esDigito(m) && soloEspacios(m));
            if(!chequeo){
                system("cls");
                printf(">> Entrada no valida, ingrese un entero!\n ACLARACION!! numeros positivos sin el '+' al principio.\n\n");
                free(m);
            }
        }

        system("cls");
        chequeo = false;

        while (!chequeo){
            n = ingresa_palabra("Ingrese el multiplicador 'n':\n-> ");
            chequeo = (esDigito(n) && soloEspacios(n));
            if(!chequeo){
                system("cls");
                printf(">> Entrada no valida, ingrese un entero!\n-> ");
                free(n);
            }
        }

        resultado = producto(atoi(m), atoi(n));
        printf("\n%s * %s = %d\n", m, n, resultado);

        printf(".\n.\n.\n>>>> Desea realizar otra multiplicacion?\n");
        seguir = preguntarContinuar();

        free(n);
        free(m);
        system("cls");
    }

}
int main(){
    menuPunto2();
    return 0;

}