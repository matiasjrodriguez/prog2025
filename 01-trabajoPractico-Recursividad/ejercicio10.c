#include "tp_1_recursividad.h"
void menuPunto10(){
    char *n=NULL, *b=NULL;
    int * resultado=NULL;
    bool seguir = true;

    while(seguir){
        bool chequeo = false;

        while (!chequeo){
            n = ingresa_palabra("Ingrese un numero 'N':\n-> ");
            chequeo = (esDigito_positivo(n) && soloEspacios(n) && noEsCero(n));
            if(!chequeo){
                system("cls");
                printf(">> Entrada no valida, ingrese un entero!\n");
                free(n);
                n=NULL;
            }
        }

        system("cls");
        chequeo = false;

        while (!chequeo){
            b = ingresa_palabra("Ingrese una bomba 'B':\n-> ");
            chequeo = (esDigito_positivo(b) && soloEspacios(b) && noEsCero(b));
            if(!chequeo){
                system("cls");
                printf(">> Entrada no valida, ingrese un entero!\n");
                free(b);
                b=NULL;
            }
        }
        int n_int=atoi(n);
        int b_int=atoi(b);
        if (b_int>=n_int){
            printf("La bomba debe ser menor al Numero explosivo.\n");
        }
        else{
            resultado = explosion(n_int, b_int);
        }
        free(n);
        free(b);
        free(resultado);

        printf(".\n.\n.\n.\n>>>> Desea hacer otro intento? SI = 1, NO = 0: ");
        while (scanf("%d", &seguir) != 1 || (seguir != 0 && seguir != 1)) {
            printf("Ingrese 1 para SI o 0 para NO: ");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');
        system("cls");
    }
}
int main(){
    menuPunto10();
    return 0;
}