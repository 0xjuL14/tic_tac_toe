# Jogo da Velha (Tic-Tac-Toe) em C com Cores ANSI

Este projeto é uma implementação clássica do **Jogo da Velha** para terminal, desenvolvido em **linguagem C** e utiliza códigos de escape **ANSI** para uma experiência visual aprimorada e funções modulares para checagem de vitória e desenho do tabuleiro.

---

## Funcionalidades

- **Interface Colorida:** O jogador `X` é exibido em **vermelho** e o jogador `O` em **magenta**, facilitando a visualização no terminal.  
- **Tabuleiro Limpo:** O uso de `system("clear")` garante que o tabuleiro seja redesenhado perfeitamente a cada jogada.  
- **Lógica Modular:** A checagem de vitória é isolada na função `checaVitoria()`, tornando o código principal (`main`) limpo e legível.  
- **Validação de Jogada:** Impede que o usuário jogue em coordenadas inválidas (fora do 1–3) ou em casas já preenchidas.

---

## Como Compilar e Jogar

A compilação deverá ser feita usando o **GCC (GNU Compiler Collection)**.

### 1_ Compilação 
No terminal, navegue até o diretório do arquivo `.c` e execute:

```bash
gcc jogo_da_velha.c -o jogo_da_velha
```

### 2_ Execução

```bash
./jogo_da_velha
```

---

## Simulação no Terminal

Exemplo de execução (a aparência pode variar conforme o terminal):

```
./jogo_da_velha
     1   2   3
   -------------
1  |   |   |   |
   |---|---|---|
2  |   | X |   |
   |---|---|---|
3  | O |   |   |
   -------------

Digite as coordenadas (Linha e Coluna de 1 a 3) em que quer colocar o 'X':

(Após algumas jogadas...)

     1   2   3
   -------------
1  | X | O | O |
   |---|---|---|
2  |   | X |   |
   |---|---|---|
3  | O | O | X |
   -------------

Parabéns! O jogador 'X' ganhou!
```

---

## Requisitos de Cor

Para visualizar as cores vermelho e magenta, o terminal deve ser compatível com códigos **ANSI**. A maioria dos terminais modernos, como o **PowerShell**, o **GNOME Console**, o **Konsole**, e **VS Code Terminal**, são compatíveis.

---

## Estrutura do Código

| Função | Tipo | Descrição |
|--------|------|-----------|
| `main()` | `int` | Controla o loop do jogo (máximo 9 rodadas), alterna entre 'X' e 'O', e gerencia a entrada do usuário. |
| `imprime_tabuleiro()` | `void` | Desenha a matriz 3x3 na tela e aplica as cores ANSI (`\x1b[31m` e `\x1b[35m`) aos símbolos. |
| `checaVitoria()` | `int` | Contém a lógica de verificação das 8 condições de vitória (3 linhas, 3 colunas, 2 diagonais). Retorna `1` (ganhou) ou `0` (continua). |

---

## Destaques Técnicos

A customização visual está na redefinição dos símbolos:

```c
#define ANSI_COLOR_RED      "\x1b[31m" // Vermelho
#define ANSI_COLOR_MAGENTA  "\x1b[35m" // Magenta
#define ANSI_COLOR_RESET    "\x1b[0m"  // Reset

// Exemplo de uso dentro do loop de impressão:
printf(ANSI_COLOR_RED " %c " ANSI_COLOR_RESET, simbolo);
```

O código insere o código da cor, imprime o símbolo e imediatamente insere `ANSI_COLOR_RESET` para que o texto seguinte (os separadores `|` e coordenadas) não fiquem coloridos.

---

## Conclusão

A ideia deste projeto é demonstrar o uso de **matrizes**, **condicionais** e **funções modulares** em C, adicionando um toque visual bonito e prático para o terminal <3

---

Feito com 🖤 por [@0xjuL14](https://github.com/0xjuL14)
