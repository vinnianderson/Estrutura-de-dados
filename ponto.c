#include <stdio.h>
#include <math.h>
#include "ponto.h"

void initEsfera(Esfera *e, double raio) {
    if (raio < 0) {
        printf("Somente Numeros Naturais no Raio!!.\n");
        return;
    }
    e->raio = raio;
}

double obtenhaRaio(const Esfera *e) {
    return e->raio;
}

double calculeArea(const Esfera *e) {
    return 4 * M_PI * e->raio * e->raio;
}

double calculeVolum(const Esfera *e) {
    return (4.0 / 3.0) * M_PI * pow(e->raio, 3);
}
