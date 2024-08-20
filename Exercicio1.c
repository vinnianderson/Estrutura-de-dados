#include <stdio.h>

typedef struct {
    float nota1;
    float nota2;
    float nota3;
} Aluno;


float calcular_media(Aluno aluno) {
    return (aluno.nota1 + aluno.nota2 + aluno.nota3) / 3.0;
}

int main() {
    Aluno aluno;
int i = 0;
    printf("Digite a primeira nota: ");
    scanf("%f", &aluno.nota1);
    printf("Digite a segunda nota: ");
    scanf("%f", &aluno.nota2);
    printf("Digite a terceira nota: ");
    scanf("%f", &aluno.nota3);


    float media = calcular_media(aluno);

    printf("A média das notas é: %.2f\n", media);
    if(media > 5){
        printf("***************Aprovado***************\n");
    }else{
        printf("***************Reprovado***************\n");
    };

    return 0;
}
