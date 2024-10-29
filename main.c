#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

#define MAX_EMPRESAS 20

char user[20];
char password[20];

typedef struct {
	int numero,cep;
	char estado[20];
	char rua[50];
}Endereco;

typedef struct {
	char nomeResponsavel[30];
	char nomeEmpresa[20];
	char razaoSocial[30];
	char nomeFantasia[30];
	char email[20];
	int cpf,telefone,cnpj;
	Endereco endereco;
	int ativo;
}Empresa;

//defino tamanho do vetor empresa
Empresa empresa[MAX_EMPRESAS];

//funçoes
void login();
void menu();
void cadastrar();
void relatorio();
void listarEmpresas();
int main(){
	setlocale(LC_ALL, "Portuguese");

	login();
	menu();
	return 0;
}

void login(){
	system("cls");
	printf("BEM VINDO, INSIRA SEU USUÁRIO E SENHA NOS CAMPOS ABAIXO\n");

    printf("Insira seu nome:\n");
    fgets(user, 21, stdin);
    fflush(stdin);

    printf("Insira sua senha:\n");
    fgets(password, 21, stdin);
    fflush(stdin);
    
    printf("\n\nLOGADO!\n\n");
}

void menu(){
	system("cls");
	int num;
	do{
		printf("============== Menu principal ==============\n");
        printf("Selecione uma das opções abaixo:\n");
        printf("[1] Cadastrar nova empresa\n");
        printf("[2] Empresas cadastradas\n");
        printf("[0] Sair\n");
        scanf("%d", &num);
        getchar();
        switch(num){
        	case 1:
        		cadastrar();
        		break;
        	case 2:
        		listarEmpresas();
        		break;
		}
		getchar();
	}
	while(num !=0);
}

void cadastrar(){

	system("cls");

	char nomeResponsavel[30];
	char nomeEmpresa[20];
	char razaoSocial[30];
	char nomeFantasia[30];
	char email[20];
	int cpf,telefone,cnpj;
	Endereco endereco;
	char fileName[20];
	int num,i;
	

	
	do{
		for(i =0; i<MAX_EMPRESAS;i++){
					
			printf("Insira os dados abaixo:\n");
			puts("Nome do responsável da empresa:");
			scanf(" %29[^\n]", empresa[i].nomeResponsavel);
			getchar();
			
			printf("Nome da empresa: ");
		    scanf(" %19[^\n]", empresa[i].nomeEmpresa);
		    getchar();
		
		    printf("Razão Social: ");
		    scanf(" %29[^\n]", empresa[i].razaoSocial);
		    getchar();
		
		    printf("Nome Fantasia: ");
		    scanf(" %29[^\n]", empresa[i].nomeFantasia);
		    getchar();
		
		    printf("Email: ");
		    scanf(" %19[^\n]", empresa[i].email);
		    getchar();
		
		    printf("CPF: ");
		    scanf(" %d", &empresa[i].cpf);
		    getchar();
		
		    printf("Telefone: ");
		    scanf(" %d", &empresa[i].telefone);
		    getchar();
		
		    printf("CNPJ: ");
		    scanf(" %d", &empresa[i].cnpj);
		    getchar();
		
		    printf("Nome da rua: ");
		    scanf(" %49[^\n]", empresa[i].endereco.rua);
		    getchar();
		
		    printf("Número: ");
		    scanf("%d", &empresa[i].endereco.numero);
		    getchar();  
		    
		    printf("CEP: ");
		    scanf("%d", &empresa[i].endereco.cep);
		    getchar();
		    
		    printf("Estado: ");
            scanf(" %19[^\n]", empresa[i].endereco.estado);
		    getchar(); 
		   
		   	sprintf(fileName, "empresa_%s.txt", empresa[i].nomeEmpresa);
			FILE * ponteiroFile; 
			ponteiroFile = fopen(fileName, "w");
			
		   	fprintf(ponteiroFile,"Responsável: %s, Empresa: %s,Razão social: %s,Fantasia: %s, Email: %s,CPF reponsável: %d, Telefone: %d,CNPJ: %d, Rua: %s, Número: %d, CEP: %d, Estado: %s\n",
	        empresa[i].nomeResponsavel, empresa[i].nomeEmpresa,
	        empresa[i].razaoSocial, empresa[i].nomeFantasia,
	        empresa[i].email, empresa[i].cpf,
	        empresa[i].telefone, empresa[i].cnpj,
	        empresa[i].endereco.rua, empresa[i].endereco.numero, empresa[i].endereco.cep, empresa[i].endereco.estado
			);
		
			 //testa se criou o arquivo
			if(ponteiroFile == NULL)
			{
			  	perror("Erro ao abrir o arquivo");
                exit(1);
			}
			
			fclose(ponteiroFile);
//			printf("Empresa cadastrada e arquivo '%s' gerado.\n", fileName);
			system("cls");
			break;
		}
	
			printf("\n[1]Continuar cadastro\n[0] Sair\n");
			scanf("%d", &num);
			getchar();
		
	}while(num !=0);
	
	
}

//verificar se existe a empresa antes de listar
void listarEmpresas(){
	system("cls");
	int i;
	printf("\n NOME DAS EMPRESAS: \n");
	for(i =0; i<MAX_EMPRESAS; i++){
		if(empresa[i].ativo == 1){
			printf("\n -------------------- \n");
			printf("Nome: %s\n", empresa[i].nomeEmpresa);
		}	
	}
}


void relatorio(){
	
	

}