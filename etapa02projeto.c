#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTDUSU 20

int main()
{
	//Declarando as variáveis de acordo com as necessidades de um formulário para consulta
	// especificados na etapa 01.
	char nome[10][QTDUSU], email[10][QTDUSU], telefone[10][QTDUSU], nascimento[10][QTDUSU], sexo[10][QTDUSU], endereco[10][QTDUSU], remedios[10][QTDUSU], alergias[10][QTDUSU], doencas[10][QTDUSU];
	char nomeAltera[10];
	int idade[10];
	int opcao;
	int contador = 0;
	int alterar, posAltera = QTDUSU + 1;
	
	do
	{
		//Exibir MENU para o usuário.
		printf("\n\n------MENU------\n\n");
		printf("\n1- CADASTRAR PACIENTES");
		printf("\n2- CONSULTA DE PACIENTES");
		printf("\n3- LISTAR TODOS");
		printf("\n4- ALTERAR DADOS");
		printf("\n5- SAIR");
		printf("\n\nESCOLHA UMA OPCAO:");
		scanf("%d", &opcao);
		//Fim do exibir MENU.
	
		//Aqui utilizamos a estrutura condicional de múltipla escolha (switch case), que quando
		//o usuário escolher uma das opções,s erá redirecionado direto para sua opção.
		//No caso 1,é a parte de cadastro onde o usuário vai inserir os dados.E o contador++
		//no final irá adicionando +1 a cada pessoa cadastrada, no valor especificado nas variáveis.
		switch (opcao){
		case 1:
			printf("\n1- CADASTRO");
			printf("\n\n------SISTEMA DE CADASTRO DE PACIENTES------\n\n");

			printf("\nDIGITE O NOME: ");
			scanf("%s", nome[contador]);

			printf("\nDIGITE O EMAIL: ");
			scanf("%s", email[contador]);

			printf("\nDIGITE O TELEFONE: ");
			scanf("%s", telefone[contador]);

			printf("\nDIGITE A DATA DE NASCIMENTO: ");
			scanf("%s", nascimento[contador]);

			printf("\nDIGITE A IDADE: ");
			scanf("%d", &idade[contador]);

			printf("\nDIGITE O SEXO: ");
			scanf("%s", sexo[contador]);

			printf("\nDIGITE O ENDERECO: ");
			scanf("%s", endereco[contador]);

			printf("\nREMEDIOS DE USO DIARIO: ");
			scanf("%s", remedios[contador]);

			printf("\nALERGIAS: ");
			scanf("%s", alergias[contador]);

			printf("\nDOENCAS CRONICAS: ");
			scanf("%s", doencas[contador]);

			contador++;
			break;
		
		//No caso 2,é a opção de consulta, o usuário digita um nome que vai ser procurado em todas 
		//posições da variável, se tiver no cadastro, mostrará todos os dados do paciente, se não 
		//exibirá a mensagem contida no ELSE. 
		case 2:
			printf("\n2- CONSULTA\n");
			int posicao = 11;
			char auxiliar[20];
			scanf("%s", auxiliar);

			int i;
			for (i = 0; i < contador; i++)
			{
				if (strcmp(auxiliar, nome[i]) == 0)
				{
					posicao = i;
					break;
				}
			}
			if (posicao != 11)
			{

				printf("%s\n", nome[posicao]);
				printf("%s\n", email[posicao]);
				printf("%s\n", telefone[posicao]);
				printf("%s\n", nascimento[posicao]);
				printf("%d\n", idade[posicao]);
				printf("%s\n", sexo[posicao]);
				printf("%s\n", endereco[posicao]);
				printf("%s\n", remedios[posicao]);
				printf("%s\n", alergias[posicao]);
				printf("%s\n", doencas[posicao]);
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
				printf("%s\n", nome[j]);
				printf("%s\n", email[j]);
				printf("%s\n", telefone[j]);
				printf("%s\n", nascimento[j]);
				printf("%d\n", idade[j]);
				printf("%s\n", sexo[j]);
				printf("%s\n", endereco[j]);
				printf("%s\n", remedios[j]);
				printf("%s\n", alergias[j]);
				printf("%s\n", doencas[j]);
			}
			break;
		
		//O caso 4 é para alterar algum cadastro, o usuário digita o nome do paciente, se for
		//localizado, o programa perguntará o que ele deseja alterar e mostrará opções. Se não,
		//exibirá a mensagem contidade no ELSE. 
		case 4:
			printf("\nDIGITE O NOME DE QUAL PACIENTE DESEJA ALTERAR:");
			scanf("%s", nomeAltera);
			for (j = 0; j < contador; j++)
			{
				if (strcmp(nome[j], nomeAltera) == 0){
					posAltera = j;
				}else{
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
				scanf("%s", nome[posAltera]);
			}
			else if (alterar == 2)
			{
				printf("\nALTERAR EMAIL:\n");
				scanf("%s", email[posAltera]);
			}
			else if (alterar == 3)
			{
				printf("\nALTERAR TELEFONE:\n");
				scanf("%s", telefone[posAltera]);
			}
			else if (alterar == 4)
			{
				printf("\nALTERAR DATA DE NASCIMENTO:\n");
				scanf("%s", nascimento[posAltera]);
			}
			else if (alterar == 5)
			{
				printf("\nALTERAR IDADE:\n");
				scanf("%d", &idade[posAltera]);
			}
			else if (alterar == 6)
			{
				printf("\nALTERAR SEXO:\n");
				scanf("%s", sexo[posAltera]);
			}
			else if (alterar == 7)
			{
				printf("\nALTERAR ENDERECO:\n");
				scanf("%s", endereco[posAltera]);
			}
			else if (alterar == 8)
			{
				printf("\nALTERAR REMEDIOS:\n");
				scanf("%s", remedios[posAltera]);
			}
			else if (alterar == 9)
			{
				printf("\nALTERAR ALERGIAS:\n");
				scanf("%s", alergias[posAltera]);
			}
			else if (alterar == 10)
			{
				printf("\nALTERAR DOENCAS:\n");
				scanf("%s", doencas[posAltera]);
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
