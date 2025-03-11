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

// Verifica se um navio pode ser posicionado sem sobreposição e dentro dos limites
int podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char direcao) {
    for (int i = 0; i < NAVIO; i++) {
        if (direcao == 'V' && (linha + i >= TAMANHO || tabuleiro[linha + i][coluna] != 0)) {
            return 0;
        }
        if (direcao == 'H' && (coluna + i >= TAMANHO || tabuleiro[linha][coluna + i] != 0)) {
            return 0;
        }
        if (direcao == 'D' && (linha + i >= TAMANHO || coluna + i >= TAMANHO || tabuleiro[linha + i][coluna + i] != 0)) {
            return 0;
        }
        if (direcao == 'D2' && (linha + i >= TAMANHO || coluna - i < 0 || tabuleiro[linha + i][coluna - i] != 0)) {
            return 0;
        }
    }
    return 1;
}

// Posiciona um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char direcao) {
    if (podePosicionar(tabuleiro, linha, coluna, direcao)) {
        for (int i = 0; i < NAVIO; i++) {
            if (direcao == 'V') {
                tabuleiro[linha + i][coluna] = 3;
            } else if (direcao == 'H') {
                tabuleiro[linha][coluna + i] = 3;
            } else if (direcao == 'D') {
                tabuleiro[linha + i][coluna + i] = 3;
            } else if (direcao == 'D2') {
                tabuleiro[linha + i][coluna - i] = 3;
            }
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

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    inicializarTabuleiro(tabuleiro);

    // Posicionamento fixo dos navios
    posicionarNavio(tabuleiro, 1, 2, 'V'); // Navio vertical
    posicionarNavio(tabuleiro, 6, 4, 'H'); // Navio horizontal
    posicionarNavio(tabuleiro, 3, 3, 'D'); // Navio diagonal principal
    posicionarNavio(tabuleiro, 2, 8, 'D2'); // Navio diagonal secundária

    exibirTabuleiro(tabuleiro);
    return 0;
}