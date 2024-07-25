#include <stdio.h>
#include <ctype.h>


/*
una empresa de capacitacion online dispone de 20 cursos distintos numerados del 1 al 20. Cada curso tiene una capacidad de alumnos distinta que debe solicitarse al inicio del programa (15 a 20)
Luego se cargan las inscripciones ingresando por cada inscripcion, numero de curso(1 a 20), numero de promotor(100 a 109) y cantidad de inscriptos (mayor que 0). Si algun caso no hay
capacidad para las inscripciones ,se deben inscribir los posibles e indicar con un mensaje la falta de cupo. La carga de inscripciones finaliza con un codigo de curso igual a 99.
Mostrar:
a) La cantidad de inscriptos de cada curso
b) listar los numeros de curso en lso cuales hubo gente que no pudo anotarse por falta de cupo.
c) cantidad de alumnos inscriptos por cada promotor.
*Se deben realizar las siguientes funciones:
* una funcion que reciba los limites inferior y superior de un rango y un valor adicional y retorne un numero entero dentro del rango enviado o el valor adicional. Este debe usarse para codigo de curso,
 promotor y capacidad.
*üna funcion para ingresar la capacidad de 20 cursos. esta funcion debe invocar la anterior
*una funcion para el ingreso de la cantidad  de inscriptos.

*/
//prototipos de funcion
int leeYvalida(int ,int ,int);
void capacidadCursos(int[],int,int,int);
void cantidadInscriptos(int[],int[],int[],int[]);

//main
int main(){
    int cantPorcursos[20]={0},capacidadPorCurso[20]={0},promotor[10]={0},cursosSinCupo[20]={0};
    int liminf =15, limsup= 20, dif=99;
    printf("capacidad por curso: ");

    capacidadCursos(capacidadPorCurso,liminf,limsup,dif);
    cantidadInscriptos(cantPorcursos,capacidadPorCurso,promotor,cursosSinCupo);

    for(int i=0;i<20;i++){
        int j= i+1;
        printf("la cantidad de personas en el curso %d es %d\n",j,cantPorcursos[i]);
    }
    printf("los cursos que no se pudieron anotar por falta de cupo fue: \n");
    for(int i=0;i<20;i++){
        if(cursosSinCupo[i]!=0){
            printf("el curso %d no tenia cupo\n",cursosSinCupo[i]);
        }
    }
    printf("los alumnos por cada promotor son: \n");
    int promotornum=100;
    for(int i=0; i<10;i++){

        printf("el promotor %d tiene %d alumnos inscriptos\n",promotornum,promotor[i]);
        promotornum++;
    }

}

//funciones

int leeYvalida(int liminf,int limsup, int dif){
    int num,band=0;
    do{
        if(band==0){
            printf("ingrese el numero: ");
            scanf("%d",&num);
            band=1;
        }else{
            printf("error, numero no admitido, vuelva a ingresar: ");
            scanf("%d",&num);
        }

    }while(!((num>=liminf && num<=limsup)||num == dif));

    return num;
}

void capacidadCursos(int capacidad[],int liminf, int limsup, int dif){
    int numcurso,i,capacidadC;
    numcurso = leeYvalida(1,20,dif);

    while(numcurso!=99){
    printf("ingrese la capacidad del curso: ");
    capacidadC = leeYvalida(liminf,limsup,20); // al no haber condicion de corte, ponemos que el dif sea cualqueir numero dentro del rango.
    capacidad[numcurso-1] = capacidadC;
    numcurso = leeYvalida(1,20,dif);
    }

}

void cantidadInscriptos(int cantporCurso[], int MaxCapacidad[],int promotor[],int sinCupo[]){
    int i, num,cantcurso,promotornum,indicePromotor=0;
    printf("ingrese el curso a cargar alumno: ");
    num= leeYvalida(1,20,99);
    while(num !=99){

        if(MaxCapacidad[num-1]!=0){
            cantporCurso[num-1]++;
            printf("ingrese promotor: ");
            promotornum= leeYvalida(100,109,109);
            switch(promotornum){
                case 100:
                    promotor[0]++;
                    indicePromotor=0;
                    break;
                case 101:
                    promotor[1]++;
                    indicePromotor=1;
                    break;
                case 102:
                    promotor[2]++;
                    indicePromotor=2;
                    break;
                case 103:
                    promotor[3]++;
                    indicePromotor=3;
                    break;
                case 104:
                    promotor[4]++;
                    indicePromotor=4;
                    break;
                case 105:
                    promotor[5]++;
                    indicePromotor=5;
                    break;
                case 106:
                    promotor[6]++;
                    indicePromotor=6;
                    break;
                case 107:
                    promotor[7]++;
                    indicePromotor=7;
                    break;
                case 108:
                    promotor[8]++;
                    indicePromotor=8;
                    break;
                case 109:
                    promotor[9]++;
                    indicePromotor=9;
                    break;

            }
        }else{
            printf("error, no se ha registrado la capacidad de alumnos para ese curso");

        }

        //sumamos siempre 1 al curso, pero en caso de que esto exceda la capacidad maxima, volvemos a restarle 1 y mostramos con un mensaje aclaratorio.
        if(cantporCurso[num-1]>MaxCapacidad[num-1]){
            sinCupo[num-1]= num;
            cantporCurso[num-1]--;
            promotor[indicePromotor]--;
            printf("el curso de numero %d ya ha completado su capacidad maxima.", num);
        }

    printf("vuelva a ingresar el curso al que quiere cargarle un alumno: ");
    num= leeYvalida(1,20,99);
    }



}
