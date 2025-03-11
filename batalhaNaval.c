#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

// Inicializa o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Exibe o tabuleiro com identificação de linhas e colunas
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("   ");
    for (int j = 0; j < TAMANHO; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Posiciona um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char direcao) {
    for (int i = 0; i < NAVIO; i++) {
        if (direcao == 'V') {
            tabuleiro[linha + i][coluna] = 3;
        } else if (direcao == 'H') {
            tabuleiro[linha][coluna + i] = 3;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    inicializarTabuleiro(tabuleiro);

    // Posicionamento fixo dos navios
    posicionarNavio(tabuleiro, 1, 2, 'V'); // Navio vertical
    posicionarNavio(tabuleiro, 6, 4, 'H'); // Navio horizontal

    exibirTabuleiro(tabuleiro);
    return 0;
}