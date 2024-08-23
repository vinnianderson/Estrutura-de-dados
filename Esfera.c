#include <stdio.h>

#include "ponto.h"

int main() {
    Esfera esferaR;
    double raio;

    
    printf("Digite o raio da esfera: ");
    if (scanf("%lf", &raio) != 1) {

        printf("Invalido. Somente Numeros Naturais.\n");

        return 1; 
    }

    initEsfera(&esferaR, raio);

  
    printf("raio: %.4f\n", obtenhaRaio(&esferaR));
    printf("area da superfície: %.2f\n", calculeArea(&esferaR));
    printf("volume: %.4f\n", calculeVolum(&esferaR));

    return 0;
}
