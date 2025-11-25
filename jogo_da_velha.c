//
// Created by juh on 11/19/25 on CLion
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m" // vermelho para 'X'
#define ANSI_COLOR_MAGENTA "\x1b[35m" // magenta para 'O'
#define ANSI_COLOR_RESET   "\x1b[0m"  // reseta a cor para o padrão do terminal

void imprime_tabuleiro(char tabuleiro[3][3]) { // função para imprimir a base do tabuleiro tictactoe
  system("clear"); // limpa a tela do terminal Linux. Para Windows usar system("cls");

  printf("\n     1   2   3\n"); // referência para facilitar a vizualização das colunas
  printf("   -------------\n");

  for (int i = 0; i < 3; i++) {
    printf("%d  |", i + 1);

    for (int j = 0; j < 3; j++) {
      char simbolo = tabuleiro[i][j];

      if (simbolo == 'X') {
        printf(ANSI_COLOR_RED " %c " ANSI_COLOR_RESET, simbolo); // coloca a cor vermelha no X
      } else if (simbolo == 'O') {
        printf(ANSI_COLOR_MAGENTA " %c " ANSI_COLOR_RESET, simbolo); // coloca a cor magenta no 0
      } else {
        printf(" %c ", simbolo); // espaço sem cor
      }

      if (j < 2) {
        printf("|"); // separador vertical
      }
    }
    printf("|\n");
    if (i < 2) {
      printf("   |---|---|---|\n"); // separador horizontal
    }
  }
  printf("   -------------\n");
}

int checaVitoria(char t[3][3]) { // função de checagem de vitória
    for (int i = 0; i < 3; i++) {
        if (t[i][0] != ' ' && t[i][0] == t[i][1] && t[i][1] == t[i][2]) return 1; // checagem das linhas
        if (t[0][i] != ' ' && t[0][i] == t[1][i] && t[1][i] == t[2][i]) return 1; // checagem das colunas
    }

    if (t[0][0] != ' ' && t[0][0] == t[1][1] && t[1][1] == t[2][2]) return 1; // checagem da diagonal direita (\)
    if (t[0][2] != ' ' && t[0][2] == t[1][1] && t[1][1] == t[2][0]) return 1; // checagem da diagonal esquerda (/)

    return 0; // ninguém ganhou :(
}

int main() {
  char tabuleiro[3][3], jogador = 0;
  int i, j, linha, coluna, rodada, ganhou;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      tabuleiro[i][j] = ' '; // inicia preenchendo os espaços do tabuleiro com espaços vazios
    }
  }

  imprime_tabuleiro(tabuleiro); // chama a função e desenha o tabuleiro inicial ;)

  ganhou = 0; // inicia a flag como falsa pq ninguém ganhou ainda né :P

  for (rodada = 1; rodada <= 9 && ganhou == 0; rodada++) { // loop máximo 9 rodadas e enquanto ninguém ganhar
    if (rodada % 2 == 1) { // usa o resto da divisão como determinador da vez do jogador 1 e 2
      jogador = 'X';
    } else {
      jogador = 'O';
    }

    do {
      printf("Digite as coordenadas (Linha e Coluna de 1 a 3) em que quer colocar o '%c': ", jogador);
      scanf("%d %d", &linha, &coluna);
    } while (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha - 1][coluna - 1] != ' '); // coloca o limite do espaço e se a casa n estiver preenchida

    tabuleiro[linha - 1][coluna - 1] = jogador; // coloca 'X' ou 'O' na posição correta (usa -1 para converter 1-3 para índices 0-2)
    imprime_tabuleiro(tabuleiro); // desenha o tabuleiro novamente mas com a nova jogada

    ganhou = checaVitoria(tabuleiro); // chama a função de verificar a vitória
  }

  if (ganhou == 0) {
    printf("\nDeu velha! O jogo empatou T_T\n");
  }
  else {
      printf("\nParabéns! O jogador '%c' (%s%c%s) ganhou!\n", jogador, (jogador == 'X' ? ANSI_COLOR_RED : ANSI_COLOR_MAGENTA), jogador, ANSI_COLOR_RESET);
  } // código para mostrar 'X' ou '0' com a cor certa

  return 0;
}