#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTDUSU 20 //Constante que define a quantidade de usuários

//Estrutura que contém as variáveis para o processo de cadastro de um paciente
typedef struct paciente
{
    char nome[100], email[100], telefone[100], nascimento[100], sexo[100], endereco[100], remedios[100], alergias[100], doencas[100];
    int idade;
} paciente;

//Função que exibe o MENU para o usuário
int menu()
{
    int opcao;
    printf("\n\n------MENU------\n\n");
    printf("\n1- CADASTRAR PACIENTES");
    printf("\n2- CONSULTA DE PACIENTES");
    printf("\n3- LISTAR TODOS");
    printf("\n4- ALTERAR DADOS");
    printf("\n5- SAIR");
    printf("\n\nESCOLHA UMA OPCAO:");
    scanf("%d", &opcao);
    //Fim do exibir MENU.
    return opcao;
}

//Função que exibe as informações para cadastro
int cadastro(paciente *p, int contador)
{
    char temp;

    printf("\n1- CADASTRO");
    printf("\n\n------SISTEMA DE CADASTRO DE PACIENTES------\n\n");
    printf("DIGITE O NOME: ");
    scanf("%c", &temp);
    fgets(p[contador].nome, 100, stdin);
    printf("DIGITE O EMAIL: ");
    fgets(p[contador].email, 100, stdin);
    printf("DIGITE O TELEFONE: ");
    fgets(p[contador].telefone, 100, stdin);
    printf("DIGITE A DATA DE NASCIMENTO: ");
    fgets(p[contador].nascimento, 100, stdin);
    printf("DIGITE A IDADE: ");
    scanf("%d", &p[contador].idade);
    printf("DIGITE O SEXO: ");
    fflush(stdin);
    scanf("%c", &temp);
    fgets(p[contador].sexo, 100, stdin);
    printf("DIGITE O ENDERECO: ");
    fgets(p[contador].endereco, 100, stdin);
    printf("REMEDIOS DE USO DIARIO: ");
    fgets(p[contador].remedios, 100, stdin);
    printf("ALERGIAS: ");
    fgets(p[contador].alergias, 100, stdin);
    printf("DOENCAS CRONICAS: ");
    fgets(p[contador].doencas, 100, stdin);
    contador++;
    //O contador++ no final irá adicionando +1 a cada pessoa cadastrada,
    //no valor especificado nas variáveis.
    return contador;
}

int main()
{
    //Declarando as variáveis
    char nomeAltera[10], temp;
    int opcao;
    int contador = 0;
    int alterar, posAltera = QTDUSU + 1;
    paciente p[QTDUSU];

    do
    {
        opcao = menu();
        //Aqui utilizamos a estrutura condicional de múltipla escolha (switch case), que quando
        //o usuário escolher uma das opções,s erá redirecionado direto para sua opção.
        switch (opcao)
        {
        case 1:
            contador = cadastro(p, contador);
            break;
        //No caso 2,é a opção de consulta, o usuário digita um nome que vai ser procurado em todas
        //posições da variável, se tiver no cadastro, mostrará todos os dados do paciente, se não
        //exibirá a mensagem contida no ELSE.
        case 2:
            printf("\n2- CONSULTA\n");
            int posicao = QTDUSU + 1;
            char auxiliar[100];
            printf("Digite o nome do paciente: ");
            scanf("%c", &temp);
            fgets(auxiliar, 100, stdin);

            int i;
            for (i = 0; i < contador; i++)
            {
                if (strcmp(auxiliar, p[i].nome) == 0)
                {
                    posicao = i;
                    break;
                }
            }
            if (posicao != QTDUSU + 1)
            {

                printf("%s\n", p[posicao].nome);
                printf("%s\n", p[posicao].email);
                printf("%s\n", p[posicao].telefone);
                printf("%s\n", p[posicao].nascimento);
                printf("%d\n", p[posicao].idade);
                printf("%s\n", p[posicao].sexo);
                printf("%s\n", p[posicao].endereco);
                printf("%s\n", p[posicao].remedios);
                printf("%s\n", p[posicao].alergias);
                printf("%s\n", p[posicao].doencas);
            }
            else
            {
                printf("USUARIO NAO ENCONTRADO\n");
            }
            break;

        //O caso 3, lista todos os pacientes já registrados.
        case 3:
            printf("\n3- LISTAR\n");
            int j;
            for (j = 0; j < contador; j++)
            {
                printf("%s\n", p[j].nome);
                printf("%s\n", p[j].email);
                printf("%s\n", p[j].telefone);
                printf("%s\n", p[j].nascimento);
                printf("%d\n", p[j].idade);
                printf("%s\n", p[j].sexo);
                printf("%s\n", p[j].endereco);
                printf("%s\n", p[j].remedios);
                printf("%s\n", p[j].alergias);
                printf("%s\n", p[j].doencas);
            }
            break;

        //O caso 4 é para alterar algum cadastro, o usuário digita o nome do paciente, se for
        //localizado, o programa perguntará o que ele deseja alterar e mostrará opções. Se não,
        //exibirá a mensagem contidade no ELSE.
        case 4:
            printf("\nDIGITE O NOME DE QUAL PACIENTE DESEJA ALTERAR:");
            scanf("%c", &temp);
            fgets(nomeAltera, 100, stdin);
            for (j = 0; j < contador; j++)
            {
                if (strcmp(p[j].nome, nomeAltera) == 0)
                {
                    posAltera = j;
                }
                else
                {
                    printf("DIGITE UMA OPCAO VALIDA");
                }
            }

            printf("\n-----ALTERAR DADOS-----\n");
            printf("\n1- ALTERAR NOME:\n");
            printf("\n2- ALTERAR EMAIL:\n");
            printf("\n3- ALTERAR TELEFONE:\n");
            printf("\n4- ALTERAR DATA DE NASCIMENTO:\n");
            printf("\n5- ALTERAR IDADE:\n");
            printf("\n6- ALTERAR SEXO:\n");
            printf("\n7- ALTERAR ENDERECO:\n");
            printf("\n8- ALTERAR REMEDIOS:\n");
            printf("\n9- ALTERAR ALERGIAS:\n");
            printf("\n10- ALTERAR DOENCAS CRONICAS:\n");
            printf("\nDIGITE A OPCAO QUE DESEJA ALTERAR:");
            scanf("%d", &alterar);

            if (alterar == 1)
            {
                printf("\nALTERAR NOME:\n");
                scanf("%s", p[posAltera].nome);
            }
            else if (alterar == 2)
            {
                printf("\nALTERAR EMAIL:\n");
                scanf("%s", p[posAltera].email);
            }
            else if (alterar == 3)
            {
                printf("\nALTERAR TELEFONE:\n");
                scanf("%s", p[posAltera].telefone);
            }
            else if (alterar == 4)
            {
                printf("\nALTERAR DATA DE NASCIMENTO:\n");
                scanf("%s", p[posAltera].nascimento);
            }
            else if (alterar == 5)
            {
                printf("\nALTERAR IDADE:\n");
                scanf("%d", &p[posAltera].idade);
            }
            else if (alterar == 6)
            {
                printf("\nALTERAR SEXO:\n");
                scanf("%s", p[posAltera].sexo);
            }
            else if (alterar == 7)
            {
                printf("\nALTERAR ENDERECO:\n");
                scanf("%s", p[posAltera].endereco);
            }
            else if (alterar == 8)
            {
                printf("\nALTERAR REMEDIOS:\n");
                scanf("%s", p[posAltera].remedios);
            }
            else if (alterar == 9)
            {
                printf("\nALTERAR ALERGIAS:\n");
                scanf("%s", p[posAltera].alergias);
            }
            else if (alterar == 10)
            {
                printf("\nALTERAR DOENCAS:\n");
                scanf("%s", p[posAltera].doencas);
            }
            else
            {
                printf("OPCAO INVALIDA");
            }

            posAltera = QTDUSU + 1;
            break;

        //O caso 5 é a opção de sair.O While no final executa esse programa
        //enquanto a opção for diferente de 5, quando for igual a 5 ele	finaliza.
        case 5:
            printf("\n5- SAIR");
            break;
        default:
            printf("DIGITE UMA OPCAO VALIDA");
            break;
        }
    } while (opcao != 5);

    return 0;
}
