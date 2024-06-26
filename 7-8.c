#include <stdio.h>
#include <ctype.h>

/*
Para una carrera de automóviles, se toman los tiempos de clasificación (real, mayor que 0 en segundos) de
como máximo 60 autos de carrera inscriptos para la competencia.
Los autos se identifican con números correlativos del 1 al 60, quedando sin información aquellos que no
participan de la presente carrera.
Cuando ya no hay más tiempos de clasificación para cargar, se ingresa un auto con número negativo.
Se solicita determinar:
a. El número de auto que clasificó en primer lugar.
b. El número de auto que obtuvo el peor tiempo de clasificación.
c. La cantidad de autos que superaron el promedio de tiempo de clasificación.
d. El o los números de autos que no participan de la carrera actual.


*/

int primerlugar(float[]);
int ultimolugar(float[]);

int main(){

    float tiempos[60]={0};
    int i,j=0,numauto,mejorespromedio=0;
    float tiempo,sumatiempos=0,promedio;
    for(i=0;i<60;i++){
        do{
            printf("ingrese el numero de auto: ");
            scanf("%d",&numauto);
        }while(!((numauto>=1&&numauto<=60)||numauto<0));

        if(numauto<0){
            break;
        }

        do{
            printf("ingrese el tiempo de clasificacion: ");
            scanf("%f",&tiempo);
        }while(!(tiempo>0));
        sumatiempos+=tiempo;
        tiempos[numauto-1] = tiempo;
        j++;

    }
    int pl = primerlugar(tiempos);
    int ul = ultimolugar(tiempos);
    promedio = sumatiempos/j;
    printf("los autos que no participaron fueron : \n");
    for(i=0;i<60;i++){
        if((tiempos[i]<promedio)&& tiempos[i]!=0){
            mejorespromedio++;
        }
        if(tiempos[i]==0){
            printf("numero: %d , ",i+1);
        }
    }
    printf("\n");
    printf("el primer lugar fue: %d \n",pl);
    printf("el ultimo lugar fue: %d\n",ul);
    printf("el promedio de tiempo fue de %.2f, y la cantidad de autos que lo superaron fue de %d\n",promedio,mejorespromedio);


    return 0;

}

int primerlugar(float tiempo[]){
    int i,band=0,numerofinal;
    float menortiempo;
    for(i=0;i<60;i++){
        if((band==0|| tiempo[i]<menortiempo) && tiempo[i]!=0){
            band =1;
            menortiempo = tiempo[i];
            numerofinal=i+1;
        }
    }
    return numerofinal;
}


int ultimolugar(float tiempo[]){
    int i, numerofinal;
    float mayor=0;
    for(i=0;i<60;i++){
        if((tiempo[i]>mayor)&& tiempo[i]!=0){
            mayor=tiempo[i];
            numerofinal=i+1;
        }
    }
    return numerofinal;

}
