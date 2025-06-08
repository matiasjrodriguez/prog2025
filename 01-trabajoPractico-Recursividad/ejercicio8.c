#include "tp_1_recursividad.h"

void menuPunto8(){
    int tamano, n, continuar;

    do {
        tamano = leerEnteroPositivo("Numero de elementos en el conjunto: ");
        int* conjunto = (int*)malloc(tamano * sizeof(int));

        if (conjunto == NULL) {
            printf("Error al asignar memoria.\n");
            return;
        }

        printf("Por favor ingrese %d numeros enteros positivos:\n", tamano);

        
        for (int i = 0; i < tamano; i++) {
            conjunto[i] = leerEnteroPositivo("Ingrese un numero: ");
        }

        n = leerEnteroPositivo("Ingrese un valor objetivo a alcanzar: ");
        
        
        char *output[100] = {NULL};
        
        
        subconjuntosQueSumanN(conjunto, tamano, n, output);

        
        printf("Subconjuntos que suman %d:\n", n);
        int i = 0;

        
        if (output[0] == NULL) {
            printf("No se encontraron subconjuntos que sumen %d.\n", n);
        } else {
            
            while (i < 100 && output[i] != NULL) {
                printf("{ %s }\n", output[i]);
                free(output[i]);  
                output[i] = NULL;  
                i++;
            }
        }

        free(conjunto);  

        continuar = preguntarContinuar();

    } while (continuar == 1); 

}
int main(){
    menuPunto8();
    return 0;

}