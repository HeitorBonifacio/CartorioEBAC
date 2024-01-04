#include <stdio.h> // Biblioteca de comunicacao com o usuario
#include <stdlib.h> //Biblioteca de alocacao de espaco em memoria
#include <locale.h> //Biblioteca de alocacoes de texto por regiao
#include <string.h> //Biblioteca responsavel por cuidar das strings

int registro()
{
	setlocale (LC_ALL, "Portuguese");
	
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadatrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	
	system("pause");
	
}

int consulta()
{
	setlocale (LC_ALL, "Portuguese"); //Definicao de linguagem
	
	char cpf[50];
	char conteudo[300];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf); //armazenamento a variavel "cpf" utilizando a funcao string "%s"
	
	FILE *file;
	file = fopen(cpf, "r"); // Abre o arquivo cpf e "R" de READ(ler) a informacao nele
	
	if(file == NULL) // Se a informacao nao existir traz a seguinte informacao
	{
		printf("Nao foi possivel abrir o arquivo,nao localizado!.\n");
	}
	
	while(fgets(conteudo,300,file)!= NULL) //While (enquanto) tiver informacao, armazene a informacao em conteudo se for diferente de NULL (nulo)
	{
		printf("\n Essas sao as informacoes do usuario: "); //informacao a aparecer antes dos dados
		printf("%s",conteudo);
		printf("\n\n"); // comando para pular linha no final 
	}
	system("pause");
	
}

int deletar()
{
	setlocale (LC_ALL, "Portuguese"); //Definicao de linguagem
	
	char cpf[50];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file; 
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O CPF do usuario descrito nao se encontra no sistema!.\n");
		system("pause");	
	}
	
}



int main()
	{
	int opcao=0; // Definindo Variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls");  //Deletar o console anterior
	
	setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf ("000 Cartório da Ebac 000\n\n"); //Inicio do menu 
	printf ("Escolha a opção desejada do menu:\n\n");
	printf ("\t1 - Registrar nomes\n");	
	printf ("\t2 - Consultar nomes\n");
	printf ("\t3 - Deletar nomes\n\n\n");
	printf ("\t4 - Sair do menu\n");  
	printf ("Escolha uma das opções desejada:");//Fim do menu 
	
	scanf("%d", &opcao);	//Ordem de Armazenar e scanear a escolha do usuario
	
	system("cls"); //Deletar o console anterior
	
	switch(opcao)
	{
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
		printf("Obrigado por utilizar o sistema");
		return 0; 
		break;
	    
		default:
	    printf("Essa opção está inválida!\n");
	    system("pause"); 
		break; 
	}
	} //Fim da selecao
	
	}





