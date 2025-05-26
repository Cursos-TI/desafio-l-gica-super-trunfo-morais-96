#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// ======== Estrutura que define uma carta do jogo ========
struct Carta {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

// ======== Função auxiliar: mostra o nome do atributo escolhido ========
void exibirNomeAtributo(int opcao) {
    switch(opcao) {
        case 1: printf("População"); break;
        case 2: printf("Área"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Pontos Turísticos"); break;
        case 5: printf("Densidade Demográfica"); break;
    }
}

// ======== Função auxiliar: retorna o valor numérico de um atributo da carta ========
float obterValorAtributo(struct Carta pais, int atributo) {
    switch(atributo) {
        case 1: return (float)pais.populacao;
        case 2: return pais.area;
        case 3: return pais.pib;
        case 4: return (float)pais.pontosTuristicos;
        case 5: return pais.densidadeDemografica;
        default: return 0;
    }
}

// ======== Função principal do programa ========
int main() {
    int op1, op2;

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Cartas com atributos gerados aleatoriamente
    struct Carta pais1 = {
        "Brasil",
        rand() % 300000000 + 100000000,     // População entre 100M e 400M
        (float)(rand() % 8000000 + 1000000), // Área entre 1M e 9M km²
        (float)(rand() % 150 + 50) / 10.0,   // PIB entre 5.0 e 20.0 trilhões
        rand() % 100 + 1,                    // Pontos turísticos entre 1 e 100
        (float)(rand() % 500 + 10)           // Densidade entre 10 e 510 hab/km²
    };

    struct Carta pais2 = {
        "Alemanha",
        rand() % 150000000 + 50000000,       // População entre 50M e 200M
        (float)(rand() % 3000000 + 200000),  // Área entre 0.2M e 3.2M km²
        (float)(rand() % 200 + 30) / 10.0,   // PIB entre 3.0 e 23.0 trilhões
        rand() % 100 + 1,                    // Pontos turísticos entre 1 e 100
        (float)(rand() % 500 + 10)           // Densidade entre 10 e 510 hab/km²
    };

    // Menu de seleção do primeiro atributo
    printf("===== SUPER TRUNFO PAÍSES =====\n");
    printf("Escolha o primeiro atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
    scanf("%d", &op1);

    // Menu dinâmico para o segundo atributo
    printf("\nEscolha o segundo atributo para comparar (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != op1) {
            printf("%d - ", i);
            exibirNomeAtributo(i);
            printf("\n");
        }
    }
    printf("Digite sua opção: ");
    scanf("%d", &op2);

    // Validação das escolhas
    if (op1 < 1 || op1 > 5 || op2 < 1 || op2 > 5 || op1 == op2) {
        printf("Erro: Atributos inválidos ou repetidos!\n");
        return 1;
    }

    // Coleta dos valores escolhidos
    float valor1A = obterValorAtributo(pais1, op1);
    float valor2A = obterValorAtributo(pais2, op1);
    float valor1B = obterValorAtributo(pais1, op2);
    float valor2B = obterValorAtributo(pais2, op2);

    int pontosPais1 = 0;
    int pontosPais2 = 0;

    // Comparação do primeiro atributo
    if (op1 == 5) // Densidade: menor vence
        (valor1A < valor2A) ? pontosPais1++ : (valor2A < valor1A) ? pontosPais2++ : 0;
    else
        (valor1A > valor2A) ? pontosPais1++ : (valor2A > valor1A) ? pontosPais2++ : 0;

    // Comparação do segundo atributo
    if (op2 == 5) // Densidade: menor vence
        (valor1B < valor2B) ? pontosPais1++ : (valor2B < valor1B) ? pontosPais2++ : 0;
    else
        (valor1B > valor2B) ? pontosPais1++ : (valor2B > valor1B) ? pontosPais2++ : 0;

    // Soma dos atributos
    float soma1 = valor1A + valor1B;
    float soma2 = valor2A + valor2B;

    // Exibição dos resultados
    printf("\n--- COMPARAÇÃO DE CARTAS ---\n");
    printf("País 1: %s\n", pais1.nome);
    printf("País 2: %s\n\n", pais2.nome);

    printf("Atributo 1: ");
    exibirNomeAtributo(op1);
    printf("\n%s: %.2f\n%s: %.2f\n\n", pais1.nome, valor1A, pais2.nome, valor2A);

    printf("Atributo 2: ");
    exibirNomeAtributo(op2);
    printf("\n%s: %.2f\n%s: %.2f\n\n", pais1.nome, valor1B, pais2.nome, valor2B);

    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", pais1.nome, soma1);
    printf("%s: %.2f\n", pais2.nome, soma2);

    // Resultado final
    if (soma1 > soma2)
        printf("\nResultado final: %s venceu a rodada!\n", pais1.nome);
    else if (soma2 > soma1)
        printf("\nResultado final: %s venceu a rodada!\n", pais2.nome);
    else
        printf("\nResultado final: Empate!\n");

    return 0;
}