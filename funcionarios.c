#include <stdio.h>
#include <string.h>
#include "funcionarios.h"

void cadastrar(Funcionario funcionarios[], int numMaxFuncionarios) {
    int i = 0;
    for (i = 0; i < numMaxFuncionarios; i++) {
        printf("Nome: ");
        scanf(" %59[^\n]", funcionarios[i].nome);
        printf("Cargo: ");
        scanf(" %59[^\n]", funcionarios[i].cargo);
        printf("RG: ");
        scanf(" %29[^\n]", funcionarios[i].doc.RG);
        printf("CPF: ");
        scanf(" %29[^\n]", funcionarios[i].doc.CPF);
        printf("Funcionario cadastrado com sucesso!\n");
    }
        
    FILE *arquivo = fopen("funcionarios.txt", "a");
    if (arquivo == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO!");
    }

    for (i = 0; i < numMaxFuncionarios; i++) {
        fprintf(arquivo, "NOME:%s|CARGO:%s|RG:%s|CPF:%s\n", funcionarios[i].nome, funcionarios[i].cargo, funcionarios[i].doc.RG, funcionarios[i].doc.CPF);
    }
    fclose(arquivo);
}

void buscar(char nomeBusca[], int numMaxLinhas, int contFuncionarios) {

    FILE *arquivo = fopen("funcionarios.txt", "r");
    if (arquivo == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO!");
    }

    char caractere;
    while ((caractere = fgetc(arquivo)) != EOF) {
        if (caractere == '\n') {
            numMaxLinhas++;
        } else if (caractere != '\n' && numMaxLinhas > 0) {
            numMaxLinhas++;
        }
    }
    fclose(arquivo);

    arquivo = fopen("funcionarios.txt", "r");
    if (arquivo == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO!");
    }

    Funcionario funcionariosLidos[numMaxLinhas-1];
    char linha[500];
    while (fgets(linha, sizeof(linha), arquivo)) {
        sscanf(linha, "NOME:%59[^|CARGO:]|CARGO:%59[^|RG:]|RG:%29[^|CPF:]|CPF:%29[^\n]", funcionariosLidos[contFuncionarios].nome, funcionariosLidos[contFuncionarios].cargo, funcionariosLidos[contFuncionarios].doc.RG, funcionariosLidos[contFuncionarios].doc.CPF);
        if (strcmp(funcionariosLidos[contFuncionarios].nome, nomeBusca) == 0) {
            printf("DADOS:\n");
            printf("Nome: %s\nCargo: %s\nRG: %s\nCPF: %s\n", funcionariosLidos[contFuncionarios].nome, funcionariosLidos[contFuncionarios].cargo, funcionariosLidos[contFuncionarios].doc.RG, funcionariosLidos[contFuncionarios].doc.CPF);
            printf("Funcionario encontrado!\n");
            fclose(arquivo);
            return;
        }
        contFuncionarios++;
    }
    fclose(arquivo);
    printf("O nome buscado nao foi encontrado, tente novamente!\n");
}
