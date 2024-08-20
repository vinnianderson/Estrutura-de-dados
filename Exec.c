#include <stdio.h>

// Definindo a struct para armazenar as notas
typedef struct {
    float nota1;
    float nota2;
    float nota3;
} Aluno;

// Função para calcular a média das notas
float calcular_media(Aluno aluno) {
    return (aluno.nota1 + aluno.nota2 + aluno.nota3) / 3.0;
}

int main() {
    Aluno aluno;

    // Entrada das notas
    printf("Digite a primeira nota: ");
    scanf("%f", &aluno.nota1);
    printf("Digite a segunda nota: ");
    scanf("%f", &aluno.nota2);
    printf("Digite a terceira nota: ");
    scanf("%f", &aluno.nota3);

    // Cálculo da média
    float media = calcular_media(aluno);

    // Exibindo a média
    printf("A média das notas é: %.2f\n", media);

    return 0;
}
