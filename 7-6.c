#include <stdio.h>
#include <ctype.h>


/*

 Se ingresan DNI, código de sector (1 a 5) y sueldo de los empleados de una empresa. Se sabe que como
máximo la empresa tiene 100 empleados. Se desea:
a. Cargar los datos de los empleados mediante la función CargaEmpleados. La carga finaliza con un
empleado con DNI 99.
b. Generar un vector con la cantidad de empleados en cada sector mediante la función
CuentaPorSector y mostrarlo en forma de listado.
c. Determinar el importe total a pagar de sueldos mediante la función TotalAPagar.

*/

void cargaEmpl(int[],int[],float[],int);
void cuentaPorSector(int[],int,int[]);
float totalAPagar(float[],int);

int main(){

    int i,j,empleados[100]={0},sector[100]={0},tamanio=100,totalesSector[5];
    float sueldo[100]={0};
    float sueldoTotal;

    cargaEmpl(empleados,sector,sueldo,tamanio);

    cuentaPorSector(sector,tamanio,totalesSector);
    printf("----Sector----\n");
    for(i=0;i<5;i++){
        j=i+1;
        printf("Sector %d : %d\n",j,totalesSector[i]);
    }


    sueldoTotal= totalAPagar(sueldo,tamanio);

    printf("el sueldo total a pagar es %.2f",sueldoTotal);





}

void cargaEmpl(int empleados[],int sector[],float sueldo[],int tamanio){
    int i,dni,sectornum;
    float sueldonum;
    for(i = 0;i<tamanio;i++){
        printf("ingrese dni: ");
        scanf("%d",&dni);
        if(dni ==99){
            break;
        }
        else{
            empleados[i] = dni;
        }

        do{
            printf("ingrese sector: ");
            scanf("%d",&sectornum);
        }while(!(sectornum>=1 && sectornum <=5));

        sector[i] = sectornum;

        printf("ingrese su sueldo: ");
        scanf("%f",&sueldonum);
        sueldo[i] = sueldonum;

    }

}

void cuentaPorSector(int sector[],int tamanio,int sectoresTotal[]){
    int i,j,sector1=0,sector2=0,sector3=0,sector4=0,sector5=0;
    for(i=0;i<tamanio;i++){
        switch(sector[i]){
            case 1:
                sector1++;
                break;
            case 2:
                sector2++;
                break;
            case 3:
                sector3++;
                break;
            case 4:
                sector4++;
                break;
            case 5:
                sector5++;
                break;

        }
    }
    sectoresTotal[0]=sector1;
    sectoresTotal[1]=sector2;
    sectoresTotal[2]=sector3;
    sectoresTotal[3]=sector4;
    sectoresTotal[4]=sector5;


}

float totalAPagar(float sueldo[], int tamanio){

    float sumaSueldo=0;
    int i;
    for(i=0;i<tamanio;i++){
        sumaSueldo+= sueldo[i];
    }

    if(sumaSueldo>0)
        return sumaSueldo;
    else
        return 0;
}

