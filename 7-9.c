#include <stdio.h>
#include <ctype.h>

/*
En un negocio trabajan 12 vendedores. Cada vez que se realiza una venta durante el día, se emite una factura
donde se indican los siguientes datos:
• Número de Factura (entero, mayor que cero).
• Código de vendedor (entero de 1 a 12).
• Importe de la venta (real, mayor que cero).
La información termina con un número de Factura igual a cero. Al principio del ingreso, se debe solicitar la
fecha del día de procesamiento. Se pide informar con las leyendas aclaratorias:
• Importe total de facturación por cada vendedor y Cantidad de facturas emitidas por vendedor, ,
con el siguiente formato:
Venta del Día: XX/XX/XXXX
Nro. de
Vendedor   Importe vendido    Cantidad de facturas emitidas
xx              xxxx                xx
xx              xxxx                xx

total          xxxxx                xxx

*/

int main() {
    int vendedores[12]={0},numfactura[12]={0},facturas,dia,mes,anio,totalfacturas=0,i,vendedor;
    float importe[12]={0},totalimp=0,imp;

    printf("ingrese la fecha del dia de la venta\n");
    printf("dia: ");
    scanf("%d",&dia);
    printf("mes: ");
    scanf("%d",&mes);
    printf("año: ");
    scanf("%d",&anio);

    for(i=0;i<12;i++){
        do{
            printf("ingrese la cantidad de facturas emitidas: ");
            scanf("%d",&facturas);

        }while(!(facturas>=0));
        if(facturas==0){
            break;
        }
        numfactura[i]=facturas;
        totalfacturas+=facturas;

        do{
            printf("ingrese el numero de vendedor: ");
            scanf("%d",&vendedor);

        }while(!(vendedor>=1&&vendedor<=12));
        vendedores[i] = vendedor;

        do{
            printf("ingrese el importe vendido: ");
            scanf("%f",&imp);
        }while(!(imp>0));
        totalimp+=imp;
        importe[i] = imp;


    }

    printf("Venta del dia: %d/%d/%d\n",dia,mes,anio);
    printf("Vendedor    importe vendido    Cantidad de facturas emitidas   \n");

    for(i=0;i<12;i++){
        if(vendedores[i]!=0){
            printf("%d              %.2f                        %d \n",vendedores[i],importe[i],numfactura[i]);
        }
    }
    printf("\n");
    printf("Total:    %.2f     %d",totalimp,totalfacturas);

    return 0;
}
7