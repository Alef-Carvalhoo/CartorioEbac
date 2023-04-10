#include <stdio.h> // BIBLIOTECA DE COMUNICAÇÃO COM O USUÁRIO 
#include <stdlib.h> // BIBLIOTECA DE ALOCAÇÃO DE ESPAÇO EM MEMÓRIA 
#include <locale.h> // BIBLIOTECA DE ALOCAÇÃO DE TEXTO POR REGIÃO
#include <string.h> // BIBLIOTECA RESPONSÁVEL POR CUIDAR DAS STRINGS

int registro() // função responsável por cadastrar os usuários no sistema
{
		//inicio criação de variáveis/ string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		// final da criação de variáveis/string
		
		
		printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuário
		scanf("%s", cpf); //%s refere-se a string
		
		strcpy(arquivo, cpf); // RESPONSÁVEL POR COPIAR OS VALORES DAS STRINGS
		
		FILE *file; // CRIA O ARQUIVO
		file = fopen(arquivo, "w"); // CRIA O ARQUIVO e a "W" significa escrever
		fprintf(file,cpf); // SALVO O VALOR DA VARIÁVEL 
		fclose(file); // FECHA O ARQUIVO 
		
		file = fopen(arquivo, "a"); // "a" atualiza o arquivo
 		fprintf(file,"\nNOME: ");
		fclose(file);
		
		printf("Digite um nome a ser cadastrado: ");
		scanf("%s", nome);
		
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,"\nSOBRENOME: ");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadstrado: ");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,"\nCARGO: ");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s", cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file, cargo);
		fclose(file);
		
		system("pause"); 
				
		
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite aqui o CPF a ser consultado: ");
	scanf("%s",cpf);

	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado! \n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas são as informações do usuário: \n");
		printf("%s", conteudo);
		printf("\n");
		
		
	}
		system("pause");
		
}

int deletar()
{

	char cpf[40];

	
	printf("Digite o CPF do usuario a ser deletado: ");

	scanf("%s", cpf);

	
	remove(cpf);

	
	FILE *file;

	file = fopen(cpf,"r");

	
	if(file == NULL);

	{

		printf("O usuario não se encontra no sistema!.\n");

		system("pause");

	}
		
		
}

int main()
{
	
	int opcao = 0; // Definindo variáveis
	int laco = 1;
	
	for(laco = 2; laco = 2;)
	{
	
		system("cls"); // responsável por limpar a tela
	
		setlocale(LC_ALL, "portuguese"); // Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n");
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar os nomes\n\n"); 
		printf("Opção: "); // Fim do menu

		scanf("%d", &opcao); // Armazenando a escolha do usuário
	
		system("cls"); // Limpa a tela
	 
	 	switch(opcao) // inicio da seleção do menu
	 	{
	 		case 1: 
	 		registro(); // CHAMADA DE FUNÇÃO DE REGISTRO 
			break;
			
			case 2:
			consulta(); // CHAMADA DE FUNÇÃO DE CONSULTA 
			break;
			
			case 3:
			deletar(); // CHAMADA DE FUNÇÃO DE DELETAR
			break;
			
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
				
	 		
		 }
	 
		
}
}
