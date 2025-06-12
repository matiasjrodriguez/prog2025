#include "menu.h"
#include "tp_thash.h"

void main() {
    int opcion;

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("4. Ejercicio 4 \n");
        printf("5. Ejercicio 5 \n");
        printf("6. Ejercicio 6 \n");
        printf("0. Salir\n");
        printf("> Seleccione una opcion: ");
        opcion = ingresoDatosNumericosPositivos("\nEntrada erronea.\n-> ");
        system("cls");

        switch (opcion) {
            case 4:
                th_ej4_abm();
                break;
            case 5:
                menuPunto5();
                break;
            case 6:
                th_ej6_covid();
                //menuPunto6_v2();
                break;
            case 0:
                printf("Saliendo...\n");
                system("pause");
                break;
            default:
                printf("AVISO: Ingrese un numero parte de las opciones.\n");
                break;
        }

    } while (opcion != 0);

}