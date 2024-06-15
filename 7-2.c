#include <stdio.h>
#include <ctype.h>
#include <math.h>

/*
Realizar los siguientes vectores con 10 valores reales. Confeccionar un programa para:
a. Generar el vector VA con la información ingresada por teclado.
b. Generar el vector VB, donde cada elemento es la raíz cuadrada del respectivo elemento de VA.
(para el cálculo de la raíz cuadrada utilizar la función sqrt disponible en la biblioteca math.h). Si el
número es negativo poner un 0 ya que no se puede calcular la raíz
c. Calcular el vector VC como VA+VB.
d. Copiar el vector VC en orden inverso en otro vector llamado VD.
e. Hallar el valor máximo del vector VA y en qué posición se halló (el mayor es único).
f. Generar un vector VE con aquellos valores negativos que se encuentran en el vector VA.
g. Mostrar el contenido de todos los vectores.
FUNCIONES:
I. Para el ingreso del vector AA, del punto a.
II. Para generar el vector CC, del punto c.
III. Para generar el vector VE del punto f.
IV. Para mostrar los valores de todos los vectores del punto g.

*/

void cargarVector(float[]);
void juntarVector(float[],float[],float[]);
void negativosVector(float[],float[]);
void mostrarVectores(float[],float[],float[],float[],float[]);

int main() {
    int i,j, valor;
    float VA[10]={0},VD[10]={0},VE[10]={0}, VB[10]={0},VC[10]={0};
    int maximoVA=0,posicionMaxVA,valordeVector;

    printf("cargando VA: \n");
    cargarVector(VA);

    printf("\n cargando VB: ");
    for(i= 0; i<10;i++){
        valor = VA[i];
        if(valor>0){
            VB[i] = sqrtf(valor);
        }else{
            VB[i] = 0;
        }
    }

    printf("\n Cargando VC");
    juntarVector(VA,VB,VC);

    printf("\n Cargando VD");
    for(i=9,j=0;i>=0;i--){
        VD[j] = VC[i];
        j++;
    }

    printf("\nHallando Maximo y posicion maxima de VA: ");

    for(i=0;i<10;i++){
        if(VA[i]>maximoVA){
            maximoVA= VA[i];
            posicionMaxVA=i;
        }
    }

    printf("\n Cargando VE: ");
    negativosVector(VA,VE);

    printf("\n Mostrando vectores");
    mostrarVectores(VA,VC,VD,VE,VB);


}

void cargarVector(float v1[]){
    float valor;
    int i;
    for(i=0;i<10;i++){
        printf("ingrese un valor REAL: ");
        scanf("%f",&valor);
        v1[i]=valor;

    }
}
void juntarVector(float v1[],float v2[],float vfinal[]){
    int i;
    float valor1,valor2;
    for(i=0; i<10;i++){
        valor1 = v1[i];
        valor2= v2[i];
        vfinal[i] = valor1 + valor2;
    }
}
void negativosVector(float v1[],float vfinal[]){
    int i, j;
    for(i =0,j=0;i<10;i++){
        if(v1[i]<0){
            vfinal[j] = v1[i];
            j++;
        }
    }
}
void mostrarVectores(float v1[],float v2[],float v3[],float v4[],float v5[]){
    int i;
    printf("\nprimer vector:\n");
    for(i=0;i<10;i++){
        printf("%.2f ",v1[i]);
    }
    printf("\nsegundo vector:\n");
    for(i=0;i<10;i++){
        printf("%.2f ",v2[i]);
    }
    printf("\ntercer vector:\n");
    for(i=0;i<10;i++){
        printf("%.2f ",v3[i]);
    }
    printf("\ncuarto vector:\n");
    for(i=0;i<10;i++){
        printf("%.2f ",v4[i]);
    }
    printf("\nquinto vector:\n");
    for(i=0;i<10;i++){
        printf("%.2f ",v5[i]);
    }
}