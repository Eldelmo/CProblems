#include <stdio.h>

/*

5.1.21 Tomando como base el ejercicio anterior ingresar un número entero mayor a 0 y dibujar un rombo con
*. Por ejemplo, si se ingresa el número 5 dibuja la pirámide de 5 filas y luego completa el rombo al ir
decrementando la cantidad de asteriscos.
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *

*/

int main(){

    int n, i, j, k;
    printf("Escriba el numero de filas: \n");
    scanf("%d",&n);

    for(i = 1; i<=n;i++){

        for(j = 0; j<n-i; j++){
            printf(" ");
        }
        for(k = 0; k <i*2-1; k++){
            printf("*");
        }


        printf("\n");

    }


    for(i=n-1;i>0; i--){
        for(j=0;j<n-i;j++){
            printf(" ");
        }

        for(k=0;k<i*2-1;k++){
            printf("*");
        }

        printf("\n");
    }


}