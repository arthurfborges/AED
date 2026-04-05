//  Faça um programa para ler as dimensoes de um terreno (comprimento c e largura l),
// bem como o preço do metro de tela p. Imprima o custo para cercar este mesmo terreno
// com tela.

#include <stdio.h>

int main() {
    float c, l, p, result;

    printf("Digite as medidas do terreno em metro. \n Comprimento:");
        scanf("%f", &c);
    printf(" Largura: ");
        scanf("%f", &l);
    printf("Digite o preço do metro de tela:");
        scanf("%f", &p);

    result = ((2 * l) + (2 * c)) * p;

    printf("O preço para cercar este terreno com tela é %.2f", result);
}