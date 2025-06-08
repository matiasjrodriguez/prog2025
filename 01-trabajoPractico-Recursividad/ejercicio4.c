#include "tp_1_recursividad.h"

void menuPunto4(){
    char *m = NULL, *n = NULL;
    float resultado;
    int seguir = 1;

    while(seguir == 1){
        bool chequeo = false;

        while (!chequeo){
            m = ingresa_palabra("Ingrese un dividendo 'm':\n-> ");
            chequeo = (esDigito(m) && soloEspacios(m));
            if(!chequeo){
                system("cls");
                printf(">> Entrada no valida, ingrese un entero!\n ACLARACION!! numeros positivos sin el '+' al principio.\n\n");
                free(m);
                m = NULL;
            }
        }

        system("cls");
        chequeo = false;

        while (!chequeo){
            n = ingresa_palabra("Ingrese un divisor 'n':\n-> ");
            chequeo = (esDigito(n) && soloEspacios(n) && noEsCero(n));
            if(!chequeo){
                system("cls");
                printf(">> Entrada no valida, ingrese un entero!\n");
                free(n);
                n = NULL;
            }
        }

        resultado = division(atoi(m), atoi(n));
        printf("\n%d / %d = %f\n", atoi(m), atoi(n), resultado);

        printf(".\n.\n.\n.\n>>>> Desea calcular otra division?\n");
        seguir = preguntarContinuar();

        free(m);
        free(n);
        system("cls");
    }
}

int main(){
    menuPunto4();
    return 0;
}