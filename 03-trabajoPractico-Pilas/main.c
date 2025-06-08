#include "menu.h"

void main() {
    int opcion;

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("2. Ejercicio 2 \n");
        printf("3. Ejercicio 3 \n");
        printf("4. Ejercicio 4 \n");
        printf("5. Ejercicio 5 \n");
        printf("6. Ejercicio 6 \n");
        printf("7. Ejercicio 7 \n");
        printf("8. Ejercicio 8 \n");
        printf("0. Salir\n");
        printf("> Seleccione una opcion: ");
        opcion = ingresoDatosNumericosPositivos("\nEntrada erronea.\n-> ");
        system("cls");

        switch (opcion) {
            case 2:
                menuPunto2();
                break;
            case 3:
                menuPunto3();
                break;
            case 4:
                menuPunto4();
                break;
            case 5:
                menuPunto5();
                break;
            case 6:
                menuPunto6();
                break;
            case 7:
                menuPunto7();
                break;
            case 8:
                menuPunto8();
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