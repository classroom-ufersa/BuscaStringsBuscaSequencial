#include <stdio.h>
#include <string.h>
#include "funcionarios.c"

int main() {

    int numMaxFuncionarios = 0;
    int contFuncionarios = 0;
    int numMaxLinhas = 0;
    char nomeBusca[60];
    int opcao;

    do {
        printf("\nMENU:\n"); 
        printf("1 - Cadastrar\n");
        printf("2 - Buscar\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Digite o numero de funciocarios que deseja cadastrar: ");
            scanf(" %d",&numMaxFuncionarios);
            Funcionario funcionarios[numMaxFuncionarios];
            cadastrar(funcionarios, numMaxFuncionarios);
        } else if (opcao == 2) {
            printf("Digite o nome do funcionario a ser buscado: ");
            scanf(" %59[^\n]", nomeBusca);
            buscar(nomeBusca, numMaxLinhas, contFuncionarios);
        } else if (opcao == 3) {
            printf("Muito obrigado, ate mais!\n");
        } else {
            printf("Opcao invalida, verifique o menu novamente.");
        }

    } while (opcao != 3);

    return 0;
}