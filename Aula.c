#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro(){
	
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		
		printf("Digite o CPF a ser cadastrado: ");
		scanf("%s", cpf);
		
		strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
		
		FILE *file; // CRIA O ARQUIVO NO BANCO DE DADOS
		file = fopen(arquivo, "w");
		fprintf (file, cpf); // salva o valor da variavel
		fclose (file); // fecha o arquivo
		
		file = fopen(arquivo, "a");
		fprintf (file, ",");
		fclose (file);
		
		printf ("Digite o nome a ser cadastrado: ");
		scanf ("%s", nome);
		
		file = fopen(arquivo, "a");
		fprintf(file, nome);
		fclose (file);
		
		file = fopen(arquivo, "a");
		fprintf (file, ",");
		fclose (file);
		
		printf ("Digite o sobrenome a ser cadastrado: ");
		scanf ("%s", sobrenome);
		
		file = fopen (arquivo, "a");
		fprintf (file, sobrenome);
		fclose (file);
		
		file = fopen(arquivo, "a");
		fprintf (file, ",");
		fclose (file);
		
		printf ("Digite o cargo a ser cadastrado: ");
		scanf ("%s", cargo);
		
		file = fopen (arquivo, "a");
		fprintf (file, cargo);
		fclose (file);
		
		system("pause");
		
}

int consulta(){
	
		setlocale(LC_ALL, "Portuguese");
		
		char cpf[40];
		char conteudo[200];
		
		printf ("Digite o CPF a ser consultado: ");
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf , "r");
		
		if (file == NULL){
			printf ("CPF não localizado \n");
		}
		
		while (fgets(conteudo, 200, file) !=NULL){
			printf ("\nEssas são as informações do usuário: ");
			printf ("%s", conteudo);
			printf("\n\n\n!");
		}
		system("pause");

}

int deletar(){
	char cpf [40];
	
	printf("Digite o CPF que deseja deletar: ");
	scanf("%s", cpf);
	
	FILE *file; 
	file = fopen(cpf, "r");
	fclose(file);
	
	
	if(file == NULL){
		printf("Usuário não se encontra no sistema!\n");
		system("pause");
	} else{
		if(remove(cpf) == 0){
			printf("Usuário deletado com sucesso!\n");
			system("pause");
		}
	}
	
	
}

 
int main(){ 
 	
 	int opcao = 0; // definindo variaveis
 	int x = 1;
 	
 	for (x=1; x=1;){
	 
	 
	     system("cls");

		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
			printf ("Cartório EBAC\n\n"); //inicio menu
			printf ("Escolha a opção desejada no menu: \n\n");
			printf ("\t1 - Registrar Nomes\n");
			printf ("\t2 - Consultar Nomes\n");
			printf ("\t3 - Deletar Nomes\n");
			printf ("\t4 - Sair do programa\n");
			printf("Opção: "); // final menu
				
			scanf("%d", &opcao); //armazenando escolha user
			
			system("cls");
			
			switch(opcao){
				case 1: 
				registro();
				break;
				
				case 2:
				consulta();
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o programa");
				return 0;
				break;
				
				default:
				printf("Essa opção não existe!\n");
				system("pause");
				break;
			}
			
			
	
		}
	
}

