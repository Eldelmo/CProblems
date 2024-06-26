#include <stdio.h>
#include <ctype.h>

/*
Confeccionar un programa para:
a. Generar los vectores necesarios para guardar la información ingresada por teclado. Se ingresa los
datos de 300 artículos diferentes. De cada artículo se ingresa los siguientes datos:
• Código de artículo (int, entre 1 y 500).
• Clase de artículo (char, ‘A’ o ‘B’ o ‘C’ o ‘D’).
• Número de depósito donde se encuentra el artículo (int, entre 1 y 100).
• Stock (int, entre o y 2000).
• Punto de reposición (int, entre 500 y 1000).
b. Generar e informar el vector VB, que contenga los códigos de artículos de aquellos que hayan
quedado con el stock igual a cero.
c. Generar e informar el vector VC, que contengo a los códigos de artículos de aquellos que hayan
quedado con stock por debajo del punto de reposición.
d. Generar e informar el vector VD, que contengo los códigos de artículos de aquellos que están en los
depósitos entre el 15 y 50.
FUNCIONES:
I. Para generar los vectores del punto a).
II. Para generar el vector VB.
III. Para generar el vector VC.
IV. Para generar el vector VD.


*/
void cargaVectores(int[],char[],int[],int[],int[],int);
void sinStock(int[],int[],int[],int);//recibe articulo y stock
void debajoReposicion(int[],int[],int[],int[],int); //recibe stock, codigo y reposicion
void depositos15y30(int[],int[],int[],int); //recibe codigos y depositos;

int main(){
    int art[300]={0},deposito[300]={0},stock[300],reposicion[300]={0},i;
    char claseArt[300]={0},tamanio =300;
    int stockcero[300]={0},sinReposicion[300]={0},depositosentre1530[300]={0};

    cargaVectores(art,claseArt,deposito,stock,reposicion,tamanio);

    sinStock(art,stock,stockcero,tamanio);
    printf("mostrando articulos sin stock: \n");
    for(i =0;i<tamanio;i++){
        if(stockcero[i]!=0)
            printf("articulo: %d   ",stockcero[i]);
    }
    printf("\n");
    debajoReposicion(art,stock,reposicion,sinReposicion,tamanio);
    printf("mostrando articulos debajo de reposicion: \n");
    for(i=0;i<tamanio;i++){
        if(sinReposicion[i]!=0)
            printf("articulo: %d    ",sinReposicion[i]);
    }
    printf("\n");

    depositos15y30(art,deposito,depositosentre1530,tamanio);
    printf("mostrando los articulos que estan entre el deposito 15 y 30: \n");
    for(i=0;i<tamanio;i++){
        if(depositosentre1530[i]!=0)
            printf("articulo: %d   ",depositosentre1530[i]);
    }



    return 0;

}


void cargaVectores(int art[],char claseArt[],int deposito[],int stock[],int reposicion[],int tamanio){
    int stockart,codigo,depositoart,reposicionart,i;
    char clasearticulo;

    printf("ingresando datos de cada articulo\n");
    for(i=0;i<tamanio;i++){

        do{
            printf("ingrese el codigo del articulo: ");
            scanf("%d",&codigo);
        }while(!((codigo>=1 && codigo<=500)||codigo==999));
        if(codigo==999){
            break;
        }
        art[i] = codigo;

        do{
            printf("ingrese la clase de articulo: ");
            scanf(" %c",&clasearticulo);
            getchar();
            clasearticulo= toupper(clasearticulo);

        }while(!(clasearticulo=='A'||clasearticulo=='B'||clasearticulo=='C'||clasearticulo=='D'));
        claseArt[i] = clasearticulo;

        do{
            printf("ingrese el numero de deposito: ");
            scanf("%d",&depositoart);

        }while(!(depositoart>=1 &&depositoart<=100));

        deposito[i]= depositoart;

        do{
            printf("ingrese el stock del articulo: ");
            scanf("%d",&stockart);

        }while(!(stockart>=0 &&stockart<=2000));

        stock[i] = stockart;

        do{
            printf("Ingrese la cantidad de reposicion: ");
            scanf("%d",&reposicionart);
        }while(!(reposicionart>=500&&reposicionart<=1000));

        reposicion[i]= reposicionart;



    }


}

void sinStock(int art[],int stock[],int stockcero[],int tamanio){
    int i;
    for(i=0;i<tamanio;i++){
        if(stock[i]==0){
            stockcero[i] = art[i];
        }
    }

}

void debajoReposicion(int art[],int stock[],int reposicion[],int sinReposicion[],int tamanio){
    int i;
    for(i=0;i<tamanio;i++){
        if(stock[i]<reposicion[i]){
            sinReposicion[i] = art[i];
        }
    }

}

void depositos15y30(int art[], int deposito[],int depositos1530[],int tamanio){
    int i;
    for(i=0;i<tamanio;i++){
        if(deposito[i]>=15 && deposito[i]<=30){
            depositos1530[i] = art[i];
        }
    }

}
