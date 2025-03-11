#include <stdio.h>

#define TAMANHO 10       // Tamanho do tabuleiro
#define NAVIO 3          // Tamanho do navio
#define HABILIDADE 5     // Valor que marca a área afetada pela habilidade

// Inicializa o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0; // Marca com 0 (água)
        }
    }
}

// Exibe o tabuleiro com identificação de linhas e colunas
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("   ");
    for (int j = 0; j < TAMANHO; j++) {
        printf("%c ", 'A' + j); // Exibe as colunas de A a J
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1); // Exibe as linhas de 1 a 10
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 "); // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("3 "); // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("5 "); // Área afetada pela habilidade
            }
        }
        printf("\n");
    }
}

// Função para aplicar a habilidade do tipo Cone
void aplicarCone(int tabuleiro[TAMANHO][TAMANHO], int origemLinha, int origemColuna, int tamanho) {
    // A matriz de habilidade para Cone afeta as posições de forma triangular (expandindo para baixo)
    for (int i = 0; i < tamanho; i++) {
        for (int j = -i; j <= i; j++) {
            int linha = origemLinha + i;  // Linha vai aumentando à medida que se expande para baixo
            int coluna = origemColuna + j; // Coluna se expande para a esquerda e direita

            // Verifica se a posição está dentro dos limites do tabuleiro
            if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
                if (tabuleiro[linha][coluna] != 3) { // Não afeta navios
                    tabuleiro[linha][coluna] = 5; // Marca a área afetada
                }
            }
        }
    }
}

// Função para aplicar a habilidade do tipo Cruz
void aplicarCruz(int tabuleiro[TAMANHO][TAMANHO], int origemLinha, int origemColuna, int tamanho) {
    // A matriz de habilidade para Cruz afeta as linhas e colunas centradas no ponto de origem
    for (int i = -tamanho; i <= tamanho; i++) {
        int linha = origemLinha + i;
        int coluna = origemColuna + i;

        // Verifica e marca as áreas afetadas pela cruz (na linha e na coluna)
        if (linha >= 0 && linha < TAMANHO) {
            if (tabuleiro[linha][origemColuna] != 3) {  // Não afeta navios
                tabuleiro[linha][origemColuna] = 5; // Marca a área afetada
            }
        }
        if (coluna >= 0 && coluna < TAMANHO) {
            if (tabuleiro[origemLinha][coluna] != 3) {  // Não afeta navios
                tabuleiro[origemLinha][coluna] = 5; // Marca a área afetada
            }
        }
    }
}

// Função para aplicar a habilidade do tipo Octaedro
void aplicarOctaedro(int tabuleiro[TAMANHO][TAMANHO], int origemLinha, int origemColuna, int tamanho) {
    // A matriz de habilidade para Octaedro tem a forma de um losango
    for (int i = -tamanho; i <= tamanho; i++) {
        for (int j = -tamanho + abs(i); j <= tamanho - abs(i); j++) {
            int linha = origemLinha + i;
            int coluna = origemColuna + j;

            // Verifica se a posição está dentro dos limites do tabuleiro
            if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
                if (tabuleiro[linha][coluna] != 3) {  // Não afeta navios
                    tabuleiro[linha][coluna] = 5; // Marca a área afetada
                }
            }
        }
    }
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char direcao) {
    for (int i = 0; i < NAVIO; i++) {
        if (direcao == 'V') {
            tabuleiro[linha + i][coluna] = 3;  // Navio vertical
        } else if (direcao == 'H') {
            tabuleiro[linha][coluna + i] = 3;  // Navio horizontal
        } else if (direcao == 'D') {
            tabuleiro[linha + i][coluna + i] = 3;  // Navio diagonal principal
        } else if (direcao == 'D2') {
            tabuleiro[linha + i][coluna - i] = 3;  // Navio diagonal secundária
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Posicionamento fixo dos navios
    posicionarNavio(tabuleiro, 1, 2, 'V');  // Navio vertical
    posicionarNavio(tabuleiro, 6, 4, 'H');  // Navio horizontal
    posicionarNavio(tabuleiro, 3, 3, 'D');  // Navio diagonal principal
    posicionarNavio(tabuleiro, 2, 8, 'D2'); // Navio diagonal secundária

    // Exibindo o tabuleiro antes do ataque
    printf("Tabuleiro antes do ataque:\n");
    exibirTabuleiro(tabuleiro);

    // Aplicando as habilidades especiais
    aplicarCone(tabuleiro, 2, 4, 3);  // Cone no ponto (2, 4)
    aplicarCruz(tabuleiro, 6, 4, 3);  // Cruz no ponto (6, 4)
    aplicarOctaedro(tabuleiro, 4, 5, 2);  // Octaedro no ponto (4, 5)

    // Exibindo o tabuleiro após as habilidades
    printf("\nTabuleiro após as habilidades:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}