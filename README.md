# PROJETO: Busca de Strings com Busca Sequencial
## 1. MENU
  Nosso programa inicia com um pequeno menu de 3 opções, as quas são: 1 - Cadastrar, 2 - Buscar e 3 - Sair, esse menu foi criado dentro de uma estrutura de repetição (do{ /* */ }while;) utilizando a estrutura de condição "if", "else if" e "else".
     
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

## 1.1 Opção Cadastar
  Ao clicar nessa opção o programa pergunta ao usuário quantos clientes desejam ser cadastrados, pois assim, temos o valor máximo de clientes que podem ser cadastrados em uma iteração, então, é possível criar o vetor da estrutura "Funcionarios" no tamanho exato sem desperdiçar memória. A estrutura "Funcionarios" possuem os seguintes atributos: "nome", "cargo" e "doc", onde doc é uma variável do tipo "Documento" (estrutura aninhada), que possui os atributos "RG" e "CPF". Logo em seguida, chamamos a função "cadastrar()", passando como parâmetros o vetor criado e a variável responsável por armazenar o número máximo de funcionários, dentro da função "cadastrar()" é realizado a leitura dos dados de cada funcionário digitados pelo usuário e 
armazenados em cada posição do vetor, por fim, a função insere todos os dados do vetor em um arquivo de texto chamado "funcionarios.txt".

## 1.1.1 Função Cadastrar
  A função recebe um vetor e uma variável como parâmetros, o vetor será utilizado para armazenar em cada o posição os dados da estrutura "Funcionarios", a variável será utilizada para saber
o número de iterações feitas na estrutura de repetição do tipo "for", criada dentro da função para cadastrar os dados fornecidos pelo usuário, em seguida criamos um ponteiro do tipo "FILE"
para abrir o arquivo de texto "funcionarios.txt" em modo alteração 'a' e criamos uma condição com o "if", para verificar se o arquivo foi realmente aberto corretamente, por fim, criamos
mais um "for" com o número de iterações igual ao número de funcionários cadastrados e utilizamos a palavra reservada "fprintf" para inserir todos os dados no arquivo de texto formatados da
maneira que escolhemos e fechamos o arquivo com o comando "fclose".

## 1.2 Opção Buscar
  Ao clicar nessa opção o programa pergunta ao usuário qual string deseja buscar e armazena em uma variável que é passada como parâmetro na função "buscar()", assim, como duas outras variáveis do tipo "int". Uma será utilizada para contar o número de linhas do arquivo de texto "funcionarios.txt" e a outra para será utilizada como indice dentro da função "buscar()", para fazer a alteração de posição no vetor e possibilitar pegar os dados do arquivo de texto e armazenar em cada posição.

## 1.2.1 Função Buscar
  A função recebe uma variável do tipo "char" com o nome que o usuário deseja buscar, e outras duas varáveis do tipo "int", em seguida criamos um ponteiro do tipo "FILE" para abrir o arquivo de texto "funcionarios.txt" em modo leitura 'r' e criamos uma condição com o "if", para verificar se o arquivo foi realmente aberto corretamente, para saber a quatidade de linhas do arquivo de texto "funcionarios.txt" utilizamos de uma palavra reservada da biblioteca de string "fgetc" dentro de uma estrutura de repetição "while" com a condição de ler até o fim o arquivo de texto caractere por caractere, ou seja, enquanto tiver caracteres, então para saber a quantidade de linhas usamos uma condição "if" que verifica se a linha tem caractere até a quebra de linha "\n", se sim, utilizamos uma das variavéis inteiras passadas por parâmetro "numLinhas" para contar cada linha e fechamos o arquivo. Tendo a quantidade de linhas, abrimos o arquivo de texto novamente e criamos um vetor da estrutura "Funcionarios" chamado "funcionariosLidos" com tamanho igual a quantidade de linhas menos uma, que é exatamente igual ao número de funcionários do documento de texto, então, agora usamos outra palavra reservada da biblioteca de string "fgets" dentro de um "while" que ler linha por linha do arquivo de texto, e usando o comando "sscanf" podemos pegar strings de cada linha no formato escolhido, e armazenar no vetor "funcionariosLidos" em cada posição que é alterada pela última variável inteira passada por parâmetro na função chamada "contFuncionarios", por fim, usamos o comando "strcmp" também da biblioteca de string dentro de uma condição "if", que verifica se o nome do funcionário na posição 'n' do vetor é igual ao nome armazenado na variável "nomeBusa" passada como parâmetro, se sim, o programa imprime todos os dados daquele funcionário pela ordenação de sua posição no console do compilador, fecha o arquivo de texto e retorna para a classe "main.c", se não encontrar a string buscada o algoritmo faz todas as comparaçãoes dentro do "while", saindo dele fecha o arquivo de texto e volta para a classe "main.c".

## 1.3 Opção Sair
  Essa opção contém a condição de sáida da estrutura de repetição (do{ /* */ }while;), então retorna 0 e finaliza o programa, se a opção escolhida não for nenhuma disponível no menu, o programa imprimi uma mensagem informando que não existe a opção deseja, logo é feita mais uma iteração e mostrado todas opções novamente.

## 1.4 Classes
## 1.4.1 Main.c
  Nessa classe foram implementadas as principais variáveis do programa e nosso menu de opções e de acordo com cada condição, foram chamadas as funções.

## 1.4.2 Funcionarios.c
  Nessa classe foram implementas as duas funções de nosso programa com todas as suas atribuições e funcionalidades requeridas no projeto.

## 1.4.3 Funcionarios.h
  Nessa classe de cabeçalho implementamos nossas duas estruturas "Documento" e "Funcionario" e seus atributos, e o cabeçalho da função "cadastrar()" e "buscar()".

# Complexidade do algoritmo 
  Nossa complexidade é linear, O(n) que vai depender do número de funcionários cadastrados e sua posição, onde no melhor caso ele vai esta na primeira posição e no pior vai esta na ultima, onde vai ser preciso passar por todos os funcionarios para encontrar o desejado.
