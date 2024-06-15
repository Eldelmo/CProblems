#include <stdio.h>
 
 /*
 6.3. Se realizó un concurso de tiro al blanco. Por cada participante se ingresa un número que lo identifica y el
resultado de los disparos efectuados. El ingreso finaliza con un número de participante negativo.
Cada participante efectúa 5 disparos, registrándose las coordenadas X-Y de cada disparo. 
 • No considere disparos sobre los ejes, pero sí en el centro (si es sobre los ejes las coordenadas
deberán volver a ingresarse).
• Para determinar el cuadrante utilizar la función CUADRANTE que reciba las dos coordenadas y
retorne el cuadrante al cual pertenece (1 a 4) y 0 para indicar un tiro en el centro.
Para calcular el puntaje utilizar la función PUNTAJE que reciba 5 parámetros que representan la cantidad
disparos en cada cuadrante y en el centro. La función debe retornar el puntaje obtenido según la siguiente
escala:
✓ Cuadrantes 1 y 2: 50 puntos
✓ Cuadrantes 3 y 4: 40 puntos
✓ Centro: 100 puntos
Determinar:
a. El puntaje obtenido por cada participante, detallando cuantos disparos realizó en cada cuadrante.
b. Mostrar el número del participante ganador y el puntaje obtenido.
c. Calcular y mostrar la cantidad total de disparos en el centro (de todos los participantes)
 */
int CUADRANTE(int x, int y);
int PUNTAJE(int c1, int c2, int c3, int c4, int centro);
 
 
int main() {
    int numeroParticipante;
    int puntajeMaximo = 0;
    int participanteGanador = 0;
    int totalDisparosEnCentro = 0;
    int centro;
int puntaje;
        int disparosEnCuadrante1 = 0;
        int disparosEnCuadrante2 = 0;
        int disparosEnCuadrante3 = 0;
        int disparosEnCuadrante4 = 0;
        int disparosEnCentro = 0;
         int cuadrante;
        int x, y;
 
        printf("Ingrese el numero de participante (negativo para terminar): ");
        scanf("%d", &numeroParticipante);
 
        while(numeroParticipante >= 0) {
            disparosEnCuadrante1 = 0;
            disparosEnCuadrante2 = 0;
            disparosEnCuadrante3 = 0;
            disparosEnCuadrante4 = 0;
            disparosEnCentro = 0;
 
        for (int i = 0; i < 5; i++)
            {
 
           do{
            printf("Ingrese la coordenada X del disparo %d: ", i + 1);
            scanf("%d", &x);
            printf("Ingrese la coordenada Y del disparo %d: ", i + 1);
            scanf("%d", &y);
            if (x==0 && y==0)
                centro=1;
           else
             centro=0;
           }while((x==0 || y==0)&& (centro!=1));
 
             cuadrante = CUADRANTE(x, y);
 
            switch (cuadrante) {
                case 1:
                    disparosEnCuadrante1++;
                    break;
                case 2:
                    disparosEnCuadrante2++;
                    break;
                case 3:
                    disparosEnCuadrante3++;
                    break;
                case 4:
                    disparosEnCuadrante4++;
                    break;
                case 0:
                    disparosEnCentro++;
                    totalDisparosEnCentro++;
                    break;
            }
 
 
        }
 
         puntaje = PUNTAJE(disparosEnCuadrante1, disparosEnCuadrante2, disparosEnCuadrante3, disparosEnCuadrante4, disparosEnCentro);
 
        printf("Puntaje obtenido por el participante %d: %d\n", numeroParticipante, puntaje);
 
        if (puntaje >= puntajeMaximo) {
            puntajeMaximo = puntaje;
            participanteGanador = numeroParticipante;
        }
 
        printf("Ingrese el numero de participante (negativo para terminar): ");
        scanf("%d", &numeroParticipante);
        }
 
    printf("El participante ganador es: %d con un puntaje de %d\n", participanteGanador, puntajeMaximo);
    printf("Cantidad total de disparos en el centro: %d\n", totalDisparosEnCentro);
 
    return 0;
}
 
 
 
int CUADRANTE(int x, int y) {
  int a;
    if (x == 0 && y == 0) {
       a= 0;  // Tiro en el centro
    } else if (x > 0) {
        if (y > 0) {
            a= 1;  // Primer cuadrante
        } else {
           a = 4;  // Cuarto cuadrante
        }
    } else {
        if (y > 0) {
            a= 2;  // Segundo cuadrante
        } else {
            a= 3;  // Tercer cuadrante
        }
    }
return a;}
 
int PUNTAJE(int c1, int c2, int c3, int c4, int centro) {
    return (c1 + c2) * 50 + (c3 + c4) * 40 + centro * 100;
}