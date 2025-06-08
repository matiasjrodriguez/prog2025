#include "tp_1_recursividad.h"


void menuPunto7(){
    char *n;
    int seguir = 1;

    while(seguir == 1){
        bool chequeo = false;
        chequeo = false;
        while (!chequeo){
            n = ingresa_palabra("Ingrese el nivel del grupo de la mafia china (1 - 10.000):\n-> ");
            chequeo = (esDigito_positivo(n) && soloEspacios(n));
            if(chequeo){
               if(atoi(n) == 0 || atoi(n) > 10000){
                system("cls");
                printf(">> Entrada no valida, ingrese un entero!\nACLARACION!! numeros positivos sin el '+' al principio.\n\n");
                chequeo = false;
               }
            }
            else{
                system("cls");
                printf(">> Entrada no valida, ingrese un entero!\nACLARACION!! numeros positivos sin el '+' al principio.\n\n");
                free(n);
            }
        }
    
        char *grupo = reunionMafia(atoi(n));
        printf("%s\n",grupo);
        free(grupo);
        printf("\n");
        seguir = preguntarContinuar();

        free(n);
        system("cls");
    }
}

int main(){
    menuPunto7();
    return 0;
}