#include "tp_1_recursividad.h"

void menuPunto6(){
    char* senial;
    int n, seguir = 1;

    while(seguir == 1){
        bool bandera = false;
        while (!bandera)    //hasta que la palabra ingresada no sea valida, no sale del while
        {   
            senial = ingresa_palabra("Ingrese una senial: ");
            bandera = verificandoSenial(senial);
            if(!bandera){   //si no es valido el ingreso del string, libera la memoria utilizada
                printf("\nIngrese una senial valida! Que no contenga espacios y sean solo H y/o L.\n");
                free(senial);
            }
        }

        todoAMayusculas(senial);
        printf("\nLas ondas digitales en formato L y H: %s\n", senial);
        ondaDigital(senial);

        printf("\nDesea volver a formatear ondas digitales?\n");
        free(senial);
        seguir = preguntarContinuar();
        system("cls");
    }
    printf("Presione ENTER para continuar...");
    getchar();
}

int main(){
    menuPunto6();

    return 0;
}