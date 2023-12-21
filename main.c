#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <locale.h>

void limpar_buffer();

void update_matriz(char matriz[3][3], char jogada, char X_O);

bool verificar_ganhador(char matriz[3][3], char X_O);

bool verificar_jogada(char matriz[3][3], char X_O);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char jogada;
    bool jogando;
    short int rodadas;
    bool resultado;
    char X_O;
    bool continuar;

    char primeiro;

    char matriz[3][3] = {{'1', '2', '3'},
                        {'4','5', '6'},
                        {'7', '8','9'}};

    //Inicio do jogo

    rodadas = 0;
    resultado = false;

    printf("Quem começa [X/O]? ");
    scanf("%c", &primeiro);
    primeiro = toupper(primeiro);
    limpar_buffer();

    // Imprimir matriz para a primeira jogada

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c |", matriz[i][j]);
        }

        printf("\n");
    }

    do
    {
        continuar = false;
        printf("Escolha uma opção: ");
        scanf("%c", &jogada);
        if (primeiro == 'X')
        {
            if (rodadas % 2 == 0)
            {
                X_O = 'X';
            }

            else
            {
                X_O = 'O';
            }
        }

        else
        {
            if (rodadas % 2 == 0)
            {
                X_O = 'O';
            }

            else
            {
                X_O = 'X';
            }
        }


        do
        {
            if (verificar_jogada(matriz, jogada))
            {
                update_matriz(matriz, jogada, X_O);
                continuar = true;
            }

            else
            {
                limpar_buffer();
                printf("Posição já ocupada. Tente novamente: ");
                scanf("%c", &jogada);
            }

        }
        while (continuar == false);

        rodadas += 1;
        resultado = verificar_ganhador(matriz, X_O);
        //printf("%d\n", resultado);

        limpar_buffer();
    }

    while (rodadas < 9 && !resultado);

    if (resultado == true)
    {
        printf("O jogador %c venceu!", X_O);
    }

    else
    {
        printf("Deu velha!");
    }


    return 0;
}

// Funções

void update_matriz(char matriz[3][3], char jogada, char X_O)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matriz[i][j] == jogada)
            {
                matriz[i][j] = X_O;
            }
            printf(" %c |", matriz[i][j]);
        }

        printf("\n");
    }
}

bool verificar_ganhador(char matriz[3][3], char X_O)
{
    // Verificar linhas
    if (matriz[0][0] == X_O && matriz[0][1] == X_O && matriz[0][2] == X_O)
    {
        return true;
    }

    else if (matriz[1][0] == X_O && matriz[1][1] == X_O && matriz[1][2] == X_O)
    {
        return true;
    }

    else if (matriz[2][0] == X_O && matriz[2][1] == X_O && matriz[2][2] == X_O)
    {
        return true;
    }


    // Verificar colunas

    else if (matriz[0][0] == X_O && matriz[1][0] == X_O && matriz[2][0] == X_O)
    {
        return true;
    }

    else if (matriz[0][1] == X_O && matriz[1][1] == X_O && matriz[2][1] == X_O)
    {
        return true;
    }

    else if (matriz[0][2] == X_O && matriz[1][2] == X_O && matriz[2][2] == X_O)
    {
        return true;
    }

    // Verificar diagonais

    else if (matriz[0][0] == X_O && matriz[1][1] == X_O && matriz[2][2] == X_O)
    {
        return true;
    }

    else if (matriz[0][2] == X_O && matriz[1][1] == X_O && matriz[2][0] == X_O)
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool verificar_jogada(char matriz[3][3], char jogada)
{
    int count = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matriz[i][j] == jogada) // Verifica se a posição é igual ao número da jogada, se for, significa que não está ocupada e retorna true
            {
                return true;
            }
        }
    }

    return false; // Se a posição estiver ocupada ela retorna false
}


void limpar_buffer()
{
    char caractere;

    while ((caractere = getchar()) != '\n');
}
