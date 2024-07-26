#include <stdio.h>
#include <ctype.h>

/*
Una competencia de gimnasia esta formada por 5 disciplinas diferentes. Por cada disciplina se registra el puntaje de cada uno de los 20 deportistas(numerados de 1000 a 1019). Los puntajes se ingresan de la siguiente
manera: primero los 20 puntajes para la disciplina 1, luego los 20 de la disciplina 2 y asi hasta completar las 5. Los puntajes  siempre se cargan en orden comenzando por el deportista numero 1000 al 1019. Por cadada
disciplina/deportista se ingresan 3 puntajes de cada uno de los jurados y se debe guardar el promedio de dichos puntajes. en caso de que un deportista no tenga puntaje para esa disciplina se cargara un 0 en el
puntaje del primer jurado y no se pediran los  otros 2.
Luego de la carga mostrar (usar una funcion para cada punto)
1. un listado con la suma de puntos totales de cada deportista sumando las 5 disciplinas para cada uno, mostrano numero deportista y puntaje total obtenido.
2. la cantidad de deportistas que no tuvieron puntaje en almenos 1 disciplina.
para el ingreso de datos validados realizar una funcion que permita ingresar el puntaje que es un numero real que va de 0 a 10.
*/
//prototipo
float leeYvalida(int,int,int);
void mostrarPuntaje(float[],float[],float[],float[],float[]);
void cargaPuntaje(float[]);
void deportistasSinpuntaje(float[],float[],float[],float[],float[]);


//main
int main(){
    float disciplina1[20], disciplina2[20], disciplina3[20],disciplina4[20],disciplina5[20],promedioDeportista=0,sumapuntajesDeportista=0;

    //carga de datos
    printf("carga disciplina 1: \n");
    cargaPuntaje(disciplina1);
    printf("carga disciplina 2: \n");
    cargaPuntaje(disciplina2);
    printf("carga disciplina 3: \n");
    cargaPuntaje(disciplina3);
    printf("carga disciplina 4: \n");
    cargaPuntaje(disciplina4);
    printf("carga disciplina 5: \n");
    cargaPuntaje(disciplina5);

    //mostrar puntos de cada deportista
    mostrarPuntaje(disciplina1,disciplina2,disciplina3,disciplina4,disciplina5);


    //mostrar cantidad de deportistas que tuvieron 0 en alguna disciplina
    deportistasSinpuntaje(disciplina1,disciplina2,disciplina3,disciplina4,disciplina5);
    return 0;
}


//funciones
float leeYvalida(int liminf,int limsup,int dif){
    // al no haber condicion de corte , dif puede ser cualquier valor dentro del rango
    int band=0;
    float num;
    do{
        if(band==0){
            band=1;
            printf("ingrese el numero: ");
            scanf("%f",&num);
        }else{
            printf("Error, vuelva a cargar el numero: ");
            scanf("%f",&num);
        }

    }while(!((num>=liminf && num<=limsup)||num==dif));

    return num;

}
void cargaPuntaje(float disciplina[]){
    float promedio, sumaPuntajes=0,puntaje1,puntaje2,puntaje3;
    int i,j,cantpuntajes=3,participante=1000;
    for(i=0;i<20;i++){

        printf("Ingrese los 3 puntajes del participante %d: \n",participante);
        printf("Puntaje 1: ");
        puntaje1=leeYvalida(0,10,8);
        if(puntaje1==0){
            puntaje2=0;
            puntaje3=0;
            }else if(puntaje1!=0){
                printf("puntaje 2: ");
                puntaje2 =leeYvalida(0,10,8);
                printf("puntaje 3: ");
                puntaje3=leeYvalida(0,10,8);
            }
        sumaPuntajes=puntaje1+puntaje2+puntaje3;
        promedio= sumaPuntajes/3;
        disciplina[i] = promedio;

        participante++;
    }

}

void mostrarPuntaje(float disciplina1[],float disciplina2[],float disciplina3[],float disciplina4[],float disciplina5[]){
    int i,num,participante=1000;
    float sumapuntajes;
    for(i=0;i<20;i++){
        printf("para el participante %d: ",participante);
        participante++;
        sumapuntajes= disciplina1[i]+disciplina2[i]+disciplina3[i]+disciplina4[i]+disciplina5[i];

    }

}
void deportistasSinpuntaje(float disciplina1[],float disciplina2[],float disciplina3[],float disciplina4[],float disciplina5[]){
    int i, contador=0;
    for(i=0;i<20;i++){
        if(disciplina1[i]==0)
            contador++;
        else if (disciplina2[i]==0)
            contador++;
        else if (disciplina3[i]==0)
            contador++;
        else if (disciplina4[i]==0)
            contador++;
        else if (disciplina5[i]==0)
            contador++;

    }
    printf("La cantidad de deportistas que tuvieron 0 en alguna disciplina fueron %d \n",contador);
}
