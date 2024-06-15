#include <stdio.h>
#include <ctype.h>

/*
6.9 (de donde sale la funcion) 
Realizar una función que reciba 3 números enteros correspondientes al día, mes y año de una fecha y valide
si la misma es correcta. En caso de que la fecha es correcta debe retornar un 1 y si es incorrecta debe
retornar un 0. Para la validación usar la función del punto 8 que retorna la cantidad de días de un mes.

6.14
Realizar un programa que ingrese la fecha actual y la fecha de nacimiento de una persona y calcule su edad.
Para validar las fechas utilizar la función del punto 9. Para el cálculo realizar una función que reciba las dos
fechas y retorne la edad de la persona.

*/
int calcularEdad(int,int,int,int,int,int);
int restar1dia(int);
int sumarvariosdias(int,int);
int cantidaddias(int,int);
int validarFecha(int,int,int);
int sumar1dia(int);
int restarVariosDias(int,int);

int main() {
    int anio, mes,dia,opc,diasAsumar,diasArestar;
    printf("ingrese su fecha de nacimiento: ");
    do{
        printf("ingrese un año y un mes: ");
        scanf("%d %d",&anio,&mes);
    }while(mes<0 || mes>12);

    printf("ingrese dia: ");
    scanf("%d",&dia);




    if(validarFecha(dia,mes,anio)==1){
        printf("fecha valida \n");
        printf("su edad es %d \n", calcularEdad(dia,mes,anio,13,6,2024));
    }
    else
        printf("fecha no valida \n");


}


int cantidaddias(int anio, int mes){
    int en=31,feb,mar=31,abr=30,may=31,jun=30,jul=31,agos=31,sept=30,oct=31,nov=30,dic=31;
    if(anio%4==0 || anio%400==0){
        feb=29;
    }else
        feb=28;

    switch(mes){
        case 1:
            return en;
            break;
        case 2:
            return feb;
            break;
        case 3:
            return mar;
            break;
        case 4:
            return abr;
            break;
        case 5:
            return may;
            break;
        case 6:
            return jun;
            break;
        case 7:
            return jul;
            break;
        case 8:
            return agos;
            break;
        case 9:
            return sept;
            break;
        case 10:
            return oct;
            break;
        case 11:
            return nov;
            break;
        case 12:
            return dic;
            break;
    }

}

int validarFecha(int dia,int mes,int anio){
    int diasmes= cantidaddias(anio,mes);

    if(dia>=1 &&dia<=diasmes)
        return 1;
    else
        return 0;


}

int sumar1dia(int dia){

    return dia+1;

}
int sumarvariosdias(int dia, int aSumar){

    return dia+aSumar;
}

restar1dia(int dia){

    return dia-1;
}
int restarVariosDias(int dia, int diasArestar){
    return dia - diasArestar;
}

int calcularEdad(int dia, int mes, int anio,int diaHoy, int mesHoy, int anioHoy){

    int edad = anioHoy - anio;
    int mesfinal= mes - mesHoy;
    int diafinal = dia - diaHoy;

    if(mesfinal>0){
        edad=edad-1;
    }
    if(mesfinal==0){
        if(diafinal>0)
            edad=edad-1;
    }
    return edad;


}