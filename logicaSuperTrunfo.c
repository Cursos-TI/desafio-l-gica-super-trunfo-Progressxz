#include <stdio.h>

#define MAX_CIDADES 100 // Limite máximo de cidades que podem ser cadastradas

int main() {
    int n; // Número de cidades a serem cadastradas

    // Solicita ao usuário a quantidade de cidades
    printf("Quantas cidades deseja cadastrar? ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_CIDADES) {
        printf("Número inválido de cidades. O máximo permitido é %d.\n", MAX_CIDADES);
        return 1; // Sai do programa caso o número seja inválido
    }

    // Declaração dos vetores para armazenar as cidades
    char estado[n][50];         // Armazena o nome completo do estado
    char codigo[n][5];          // Código da carta (ex: "A01")
    char nome[n][50];           // Nome da cidade
    int populacao[n];           // População
    float area[n];              // Área em km²
    float pib[n];               // PIB
    int pontos_turisticos[n];   // Número de pontos turísticos
    float densidade[n];         // Densidade populacional

    // Cadastro das cidades
    for (int i = 0; i < n; i++) {
        printf("\nCadastro da cidade %d:\n", i + 1);

        printf("Nome do Estado: ");
        getchar();
        scanf(" %[^\n]", estado[i]);

        printf("Código da cidade (ex: A01): ");
        getchar();
        scanf("%4s", codigo[i]);

        printf("Nome da cidade: ");
        getchar();
        scanf(" %[^\n]", nome[i]);

        printf("População (Não use . ou , como separador de milhar/milhão): ");
        getchar();
        scanf("%d", &populacao[i]);

        printf("Área (em km² Não use . ou , como separador de milhar/milhão): ");
        getchar();
        scanf("%f", &area[i]);

        printf("PIB (Não use . ou , como separador de milhar): ");
        getchar();
        scanf("%f", &pib[i]);

        printf("Número de pontos turísticos: ");
        getchar();
        scanf("%d", &pontos_turisticos[i]);

        // Cálculo da densidade populacional
        densidade[i] = populacao[i] / area[i];
    }

    // Exibir os dados cadastrados
    printf("\n=== Cidades Cadastradas ===\n");
    for (int i = 0; i < n; i++) {
        printf("\nCidade %d:\n", i + 1);
        printf("Estado: %s\n", estado[i]);
        printf("Código: %s\n", codigo[i]);
        printf("Nome: %s\n", nome[i]);
        printf("População: %d habitantes\n", populacao[i]);
        printf("Área: %.f km²\n", area[i]);
        printf("PIB: %.f\n", pib[i]);
        printf("Pontos Turísticos: %d\n", pontos_turisticos[i]);
        printf("Densidade Populacional: %.2f hab/km²\n", densidade[i]);
    }

    // Menu para selecionar critérios de comparação
    int comparar_populacao, comparar_pib, comparar_pontos_turisticos, comparar_densidade;
    printf("\nSelecione os critérios para comparação (1 para sim, 0 para não):\n");
    printf("Comparar População? ");
    scanf("%d", &comparar_populacao);
    printf("Comparar PIB? ");
    scanf("%d", &comparar_pib);
    printf("Comparar Pontos Turísticos? ");
    scanf("%d", &comparar_pontos_turisticos);
    printf("Comparar Densidade Populacional? ");
    scanf("%d", &comparar_densidade);

    // Comparação de cartas
    int vencedor = 0; // Índice da cidade vencedora
    int maior_pontuacao = 0;

    for (int i = 0; i < n; i++) {
        int pontuacao = 0;

        // Ganha ponto se o valor for maior que o dos concorrentes (exceto na densidade)
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (comparar_populacao && populacao[i] > populacao[j]) pontuacao++;
                if (comparar_pib && pib[i] > pib[j]) pontuacao++;
                if (comparar_pontos_turisticos && pontos_turisticos[i] > pontos_turisticos[j]) pontuacao++;
                if (comparar_densidade && densidade[i] < densidade[j]) pontuacao++; // Densidade menor é melhor
            }
        }

        if (pontuacao > maior_pontuacao) {
            maior_pontuacao = pontuacao;
            vencedor = i;
        }
    }

    // Exibir a cidade vencedora com base nos critérios escolhidos
    printf("\n=== Cidade Vencedora ===\n");
    printf("Código: %s\n", codigo[vencedor]);
    printf("Nome: %s\n", nome[vencedor]);
    printf("Estado: %s\n", estado[vencedor]);
    if (comparar_populacao) {
        printf("População: %d habitantes\n", populacao[vencedor]);
    }
    if (comparar_pib) {
        printf("PIB: %.f\n", pib[vencedor]);
    }
    if (comparar_pontos_turisticos) {
        printf("Pontos Turísticos: %d\n", pontos_turisticos[vencedor]);
    }
    if (comparar_densidade) {
        printf("Densidade Populacional: %.2f hab/km²\n", densidade[vencedor]);
    }

    return 0;
}
