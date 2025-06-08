#include "tp_1_recursividad.h"

void menuPunto1(){
    char* palabra = NULL;
    int seguir = 1;

    while(seguir == 1){
        bool bandera = false;
        while (!bandera)    //hasta que la palabra ingresada no sea valida, no sale del while
        {   
            palabra = ingresa_palabra("Ingrese un palindromo: \n");
            bandera = (esAlfabetico(palabra) && soloEspacios(palabra) && masDeUnCaracter(palabra) && contieneEspacios(palabra));
            if(!bandera){   //si no es valido el ingreso del string, libera la memoria utilizada
                printf("\nIngrese una palabra valida! Que no contenga espacios, sea mas de un caracter y no sean numeros.\n");
                free(palabra);
                palabra = NULL;
            }
        }
        
        todoAMayusculas(palabra);
        bandera = palindromo(palabra);  
        
        if(bandera == true){
            printf("La palabra %s, es un palindromo\n",palabra);
        }

        else if(bandera == false){
            printf("La palabra %s, NO es un palindromo\n",palabra);
        }

        free(palabra);
        printf(".\n.\n.\n>>>> Desea ingresar otro valor?\n");
        seguir = preguntarContinuar();
        system("cls");
    
    }
}
int main(){
    menuPunto1();
    return 0;
}
                                                                                                                                    