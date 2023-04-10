#include <stdio.h> // BIBLIOTECA DE COMUNICA��O COM O USU�RIO 
#include <stdlib.h> // BIBLIOTECA DE ALOCA��O DE ESPA�O EM MEM�RIA 
#include <locale.h> // BIBLIOTECA DE ALOCA��O DE TEXTO POR REGI�O
#include <string.h> // BIBLIOTECA RESPONS�VEL POR CUIDAR DAS STRINGS

int registro() // fun��o respons�vel por cadastrar os usu�rios no sistema
{
		//inicio cria��o de vari�veis/ string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		// final da cria��o de vari�veis/string
		
		
		printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
		scanf("%s", cpf); //%s refere-se a string
		
		strcpy(arquivo, cpf); // RESPONS�VEL POR COPIAR OS VALORES DAS STRINGS
		
		FILE *file; // CRIA O ARQUIVO
		file = fopen(arquivo, "w"); // CRIA O ARQUIVO e a "W" significa escrever
		fprintf(file,cpf); // SALVO O VALOR DA VARI�VEL 
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
		printf("N�o foi possivel abrir o arquivo, n�o localizado! \n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas s�o as informa��es do usu�rio: \n");
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

		printf("O usuario n�o se encontra no sistema!.\n");

		system("pause");

	}
		
		
}

int main()
{
	
	int opcao = 0; // Definindo vari�veis
	int laco = 1;
	
	for(laco = 2; laco = 2;)
	{
	
		system("cls"); // respons�vel por limpar a tela
	
		setlocale(LC_ALL, "portuguese"); // Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar os nomes\n\n"); 
		printf("Op��o: "); // Fim do menu

		scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	
		system("cls"); // Limpa a tela
	 
	 	switch(opcao) // inicio da sele��o do menu
	 	{
	 		case 1: 
	 		registro(); // CHAMADA DE FUN��O DE REGISTRO 
			break;
			
			case 2:
			consulta(); // CHAMADA DE FUN��O DE CONSULTA 
			break;
			
			case 3:
			deletar(); // CHAMADA DE FUN��O DE DELETAR
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
				
	 		
		 }
	 
		
}
}
