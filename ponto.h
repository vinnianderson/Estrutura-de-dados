#ifndef PONTO_H
#define PONTO_H


typedef struct {
    double raio;
} Esfera;


void initEsfera(Esfera *e, double raio);

double obtenhaRaio(const Esfera *e);

double calculeArea(const Esfera *e);


double calculeVolum(const Esfera *e);

#endif 
