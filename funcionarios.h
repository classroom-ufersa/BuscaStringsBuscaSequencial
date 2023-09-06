typedef struct documento {
    char RG[30];
    char CPF[30];
} Documento;

typedef struct funcionario {
    char nome[60];
    char cargo[60];
    Documento doc;
} Funcionario;

void cadastrar(Funcionario funcionarios[], int numMaxFuncionarios);
void buscar(char nomeBusca[], int numMaxLinhas, int contFuncionarios);