#include "tp_1_recursividad.h"

void menuPunto9(){
    bool resultado;
    char *numero=NULL;
    bool seguir = true;
    while (seguir){
        bool chequeo=false;
        while(!chequeo){
            numero=ingresa_palabra("Ingrese el posible 'N' divisible por 7:\n-> ");
            chequeo = (esDigito_positivo(numero) && soloEspacios(numero) && noEsCero(numero));
            if(!chequeo){
                system("cls");
                printf(">> Entrada no valida, ingrese un entero!\n");
                free(numero);
                numero=NULL;
            }
        }
        int n_int=atoi(numero);
        resultado=divisiblePor7(n_int);
        if(resultado==true){
            printf("El numero %d es divisible por 7",n_int);
        }
        else{
            printf("El numero %d no es divisible por 7",n_int);
        }
        free(numero);
        printf("\n\n>>>> Desea realizar otra division? SI = 1, NO = 0: ");
        while(scanf("%d", &seguir) !=1 || (seguir !=0 && seguir !=1)){
            printf("Ingrese 1 para SI o 0 para NO: ");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');
        printf("\n\n");
    }
}

int main(){
    menuPunto9();
    return 0;
}