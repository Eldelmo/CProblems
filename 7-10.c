#include <stdio.h>
#include <ctype.h>

/*
Se procesan los datos de los casi 90 alumnos de un turno de la materia Elementos de Programación. Por
cada alumno se ingresan:
• DNI (entero, mayor que cero y menor que 99.999.999).
• Nota del Parcial 1 (entero, de 0 a 10).
• Nota del Parcial 2 (entero, de 0 a 10).
• Porcentaje de asistencia (real, mayor o igual a cero).
Para finalizar, se ingresa un DNI igual a cero.
Se pide informar con las leyendas aclaratorias y/o títulos:
a. Según los parciales si promocionó, aprobó, reprobó o estuvo ausente (uno o ambos parciales igual a cero).
b. Listar los alumnos que no cumplen con la asistencia (mayor o igual a 75%).
c. Informar cuántos alumnos que promocionaron NO cumplen en la asistencia.
d. Informar los alumnos que sacaron 10 en el parcial 2.
e. Al finalizar, informar el promedio total de notas de cada parcial y de asistencia.

*/

int main() {

    int i,dnialumno,dni[90]={0},notas1[90]={0},notas2[90]={0},nota,totalnota1=0,totalnota2=0,contador1=0,contador2=0,contadorasis=0;
    float asistencia, porcentajeAsistencia[90]={0},totalasistencia=0,promedio;

    for(i=0;i<90;i++){
        do{
            printf("ingrese dni: ");
            scanf("%d",&dnialumno);
        }while(!(dnialumno>=0 && dnialumno<=99999999));
        if(dnialumno==0){
            break;
        }
        dni[i]= dnialumno;
        do{
            printf("ingrese la nota del primer parcial: ");
            scanf("%d",&nota);
        }while(!(nota>=0 &&nota<=10));
        notas1[i]=nota;
        totalnota1+=nota;
        contador1++;
        do{
            printf("ingrese la nota del segudno parcial: ");
            scanf("%d",&nota);
        }while(!(nota>=0 &&nota<=10));
        notas2[i] = nota;
        totalnota2+=nota;
        contador2++;
        do{
            printf("ingrese porcentaje de asistencia: ");
            scanf("%f",&asistencia);
        }while(!(asistencia>=0));
        totalasistencia+=asistencia;
        contadorasis++;
        porcentajeAsistencia[i] = asistencia;
    }

    printf("Condicion de cada alumno: \n");
    for(i=0;i<90;i++){
        if(dni[i]>0){
                if(notas1[i]==0 || notas2[i]==0 )
                    printf("el alumno de dni %d se ausento a un parcial\n",dni[i]);
                if((notas1[i]>=4 && notas1[i]<7)&& notas2[i]>4){
                    printf("el alumno de dni %d aprobo, pero debe rendir final\n",dni[i]);
                }

                if(notas1[i]>=7 && notas2[i]>=7){
                    if(porcentajeAsistencia[i]<75){
                        printf("el alumno de dni %d promociono, pero no cumple con la asistencia\n",dni[i]);
                    }else
                        printf("el alumno de dni %d promociono\n",dni[i]);
                }

                if(notas1[i]<4 || notas2[i]<4)
                    printf("el alumno de dni %d debe recursar\n",dni[i]);
                if(notas1[i]>4 && (notas2[i]>=4 && notas2[i]<7))
                    printf("el alumno de dni %d aprobo, pero debe rendir final\n",dni[i]);


                if(notas2[i]==10){
                    printf("el alumno de dni %d saco 10 en el segundo parcial\n",dni[i]);
                }

        }


    }

    printf("Alumnos que no cumplen la asistencia: \n");
    for(i=0;i<90;i++){
        if(dni[i]>0 && porcentajeAsistencia[i]<75)
            printf("el alumno de dni %d no cumple con la asistencia\n",dni[i]);
    }

    if(totalnota1>0){
        printf("el promedio de las notas del primer parcial es %f \n",totalnota1/(float)contador1);
    }
    if(totalnota2>0){
        printf("el promedio de las notas del segundo parcial es %f \n",totalnota2/(float)contador2);
    }
    if(contadorasis>0){
        printf("el promedio de las asistencias es %f \n",totalasistencia/(float)contadorasis);
    }
}
