#include <stdio.h>


int main(){
    int a,b,c,d,e,capicuatriple=0,capicuaquintuple=0;

    printf("ingrese numero: ");
    scanf("%d",&a);
    printf("ingrese numero: ");
    scanf("%d",&b);
    printf("ingrese numero: ");
    scanf("%d",&c);
    printf("ingrese numero: ");
    scanf("%d",&d);
    printf("ingrese numero: ");
    scanf("%d",&e);

    while(1){
        if(a==0 && b==0 &&c==0 && d==0 &&e==0){
            break;
        }

        if(b==a&&c==a&& d==a&& e==a){

         //ej 55555
            capicuaquintuple++;

        }else if(a==c && b ==d && e==a){

         //ej 13131
            capicuaquintuple++;
            capicuatriple++;
        } else if(a==d && b==d) //ej 23432
            capicuaquintuple++;

        if(a==c) //ej 12122 o 22131 o 21314  22515
            capicuatriple++;
        if(c==e)
            capicuatriple++;
        if(b==d)
            capicuatriple++;



        printf("ingrese numero: ");
        scanf("%d",&a);
        printf("ingrese numero: ");
        scanf("%d",&b);
        printf("ingrese numero: ");
        scanf("%d",&c);
        printf("ingrese numero: ");
        scanf("%d",&d);
        printf("ingrese numero: ");
        scanf("%d",&e);
    }

    if(capicuatriple>0)
        printf("capicuas triples: %d \n",capicuatriple);
    if(capicuaquintuple>0)
        printf("capicuas quintuples: %d\n",capicuaquintuple);

}
