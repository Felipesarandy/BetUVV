#include <stdio.h>
#include <stdlib.h>

void BetUVV(int idade, int *pontuacao_extra, int *pontuacao_total);

void BetUVV(int idade, int *pontuacao_extra, int *pontuacao_total)
{
    int pontuacao_inicial = 0, i;
    *pontuacao_extra = 0;

    if (idade < 18) {
        *pontuacao_extra = -1;
        *pontuacao_total = -1;
        return;
    }

    if (idade >= 18 && idade <= 30)
        pontuacao_inicial = 300;

    else if (idade >= 31 && idade <= 45)
        pontuacao_inicial = 400;

    else if (idade > 45)
        pontuacao_inicial = 500;

    for (i = 10; i <= idade; i++)
        *pontuacao_extra += i;


    *pontuacao_total = pontuacao_inicial + *pontuacao_extra;
}

int main()
{
    int opcao;
    int idade, pontuacao_extra, pontuacao_total;

    do
    {
        printf("\n === MENU === \n");
        printf("\n(1) - Inserir Jogador");
        printf("\n(0) - Sair");
        printf("\nDigite aqui: ");
        scanf("%i", &opcao);

        if (opcao == 1)
        {
            printf("\n Insira sua idade: ");
            scanf("%i", &idade);

            BetUVV(idade, &pontuacao_extra, &pontuacao_total);

            if (pontuacao_extra == -1 || pontuacao_total == -1)
                printf("Idade inválida. Deve ser maior ou igual a 18.\n");

            else
            {
                printf("Pontuação Extra: %i\n", pontuacao_extra);
                printf("Pontuação Total: %i\n", pontuacao_total);
            }
        }

        else if (opcao == 0)
            printf("\n Saindo do programa...\n");

        else
            printf("\n Opção inválida. Tente novamente.\n");

    }
    while (opcao != 0);

    return 0;
}
