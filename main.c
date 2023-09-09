#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // cabecalho do jogo
    printf("------------------\n");
    printf("Bem vindo ao jogo\n");
    printf("------------------\n");

    int segundos = time(0);
    srand(segundos);
    int aleatoriogrande = rand();
    int numerocorreto = aleatoriogrande % 100;

    int tentativas = 0;
    int tentativaspermitidas;
    int dificuldade;
    double pontuacao = 1000;

    printf("Qual nivel de dificuldade voce deseja?\n");
    printf("1 - facil\n");
    printf("2 - medio\n");
    printf("3 - dificil\n");
    printf("4 - avancado\n");
    printf("escolha: ");
    scanf("%d", &dificuldade);

    switch (dificuldade)
    {
    case 1:
        tentativaspermitidas = 15;
        break;
    case 2:
        tentativaspermitidas = 9;
        break;
    case 3:
        tentativaspermitidas = 6;
        break;
    case 4:
        tentativaspermitidas = 4;
        break;
    default:
        tentativaspermitidas = 9;
        break;
    }

    for (int i = 1; i <= tentativaspermitidas; i++)
    {
        int chute;
        printf("Chute numero: %d\n", tentativas + 1);
        printf("Qual e o seu chute? ");
        scanf("%d", &chute);
        if (chute < 0)
        {
            printf("O Valor deve ser positivo\n");
            continue;
        }
        printf("O seu chute foi: %d\n", chute);

        int acertou = (chute == numerocorreto);
        int maior = (chute > numerocorreto);

        if (acertou)
        {
            printf("Parabens! Voce acertou\n");
            printf("Sua pontuacao foi de: %.2f!\n", pontuacao);
            break;
        }
        else if (maior)
        {
            printf("Puts! voce errou, o numero correto e menor\n");
        }
        else
        {
            printf("Puts! voce errou, o numero correto e maior\n");
        };
        tentativas++;
        double diferenca = abs(numerocorreto - chute) / 2.0;
        pontuacao -= diferenca;
    }
    printf("Fim De Jogo\n");
    return 0;
}
