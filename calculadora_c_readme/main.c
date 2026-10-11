#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    while (1) {

        printf("--------------------------------------------\n");
        printf("                Calculadora\n");
        printf("--------------------------------------------\n");
        printf("Selecione uma operacao:\n");
        printf("1. Adicao\n");
        printf("2. Subtracao\n");
        printf("3. Multiplicacao\n");
        printf("4. Divisao\n");
        printf("5. Sair\n\n");

        int operacao;
        char entrada[100];
        char extra;

        // Leitura e validação da operação
        while (1) {
            printf("Operacao escolhida: ");
            fgets(entrada, sizeof(entrada), stdin);

            if (sscanf(entrada, "%d %c", &operacao, &extra) == 1) {
                if (operacao >= 1 && operacao <= 5) {
                    break;
                }
            }

            printf("Entrada invalida! Digite um numero inteiro de 1 a 5.\n");
        }

        // Opção para sair
        if (operacao == 5) {
            break;
        }

        double numero1;
        double numero2;

        // Leitura do primeiro número
        while (1) {
            printf("Digite o primeiro valor: ");

            if (fgets(entrada, sizeof(entrada), stdin) != NULL &&
                sscanf(entrada, "%lf %c", &numero1, &extra) == 1) {
                break;
            }

            printf("Valor invalido! Digite um numero.\n");
        }

        // Leitura do segundo número
        while (1) {
            printf("Digite o segundo valor: ");

            if (fgets(entrada, sizeof(entrada), stdin) != NULL &&
                sscanf(entrada, "%lf %c", &numero2, &extra) == 1) {
                break;
            }

            printf("Valor invalido! Digite um numero.\n");
        }

        printf("\nResultado da operacao: ");

        if (operacao == 1) {
            printf("%.2f + %.2f = %.2f\n",
                   numero1, numero2, numero1 + numero2);
        }
        else if (operacao == 2) {
            printf("%.2f - %.2f = %.2f\n",
                   numero1, numero2, numero1 - numero2);
        }
        else if (operacao == 3) {
            printf("%.2f * %.2f = %.2f\n",
                   numero1, numero2, numero1 * numero2);
        }
        else if (operacao == 4) {

            if (numero2 == 0) {
                printf("Nao e possivel dividir por zero.\n");
            }
            else {
                printf("%.2f / %.2f = %.2f\n",
                       numero1, numero2, numero1 / numero2);
            }
        }

        // Pergunta se deseja continuar
        char continua;

        while (1) {
            printf("\nDeseja continuar calculando? (s/n): ");

            fgets(entrada, sizeof(entrada), stdin);

            if (sscanf(entrada, " %c %c", &continua, &extra) == 1) {

                if (continua == 's' || continua == 'S') {
                    break;
                }

                if (continua == 'n' || continua == 'N') {
                    printf("\nObrigado por calcular!\n");
                    return 0;
                }
            }

            printf("Resposta invalida! Digite apenas s ou n.\n");
        }

        printf("\n");
    }

    printf("\nObrigado por calcular!\n");

    return 0;
}