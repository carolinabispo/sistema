#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

#define MAX_EMPRESAS 20

char user[20];
char password[20];

//configura�ao da chavbe para criptografia
char CHAVE[] = "AbcDeF";
#define TAM_CHAVE (sizeof(CHAVE) - 1)

//vetor de entrada do texto a ser criptografado

//vetor de entrada do texto a ser criptografado
char TEXTO[500];
int TAM_TEXTO = 500; 

typedef struct {
	int numero,cep;
	char estado[20];
	char rua[50];
}Endereco;

typedef struct{
	int residuosTratados;
	float gastosMensais;
}Relatorio;

typedef struct {
	char nomeResponsavel[30];
	char nomeEmpresa[20];
	char razaoSocial[30];
	char nomeFantasia[30];
	char email[20];
	int cpf,telefone,cnpj;
	Endereco endereco;
	Relatorio relatorio;
	int ativo;
}Empresa;


//defino tamanho do vetor empresa
Empresa empresa[MAX_EMPRESAS];

//funçoes
void login();
void menu();
void cadastrar();
void consultas();
//void listarEmpresas();
void relatoriosIndividuais();
void criptografar();
void recebeArquivo();

int main(){
	setlocale(LC_ALL, "Portuguese");

//	login();
	menu();
	return 0;
}

void login(){
	system("cls");
	printf("BEM VINDO, INSIRA SEU USU�RIO E SENHA NOS CAMPOS ABAIXO\n");

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
	
	while(1){
			printf("============== Menu principal ==============\n");
        printf("Selecione uma das op��es abaixo:\n");
        printf("[1] Cadastrar nova empresa\n");
        printf("[2] Consultar empresas\n");
        printf("[3] Relat�rio de insumos tratados e gastos\n");
        printf("[4] Sair\n");
        scanf("%d", &num);
        getchar();
          switch(num){
        	case 1:
        		system("cls");
        		cadastrar();
        		break;
        	case 2:
        		system("cls");
        		consultas();
        		break;
        	case 3:
        		system("cls");
//        		relatoriosIndividuais();
				recebeArquivo("arquivo");
        	case 4:
        		system("cls");
        		printf("\n Finalizando...\n");
        		system("pause");
        		exit(0);
        	default:
        		printf("Op��o inv�lida tente novamente");
		}
        
	}
//	do{
//		printf("============== Menu principal ==============\n");
//        printf("Selecione uma das op��es abaixo:\n");
//        printf("[1] Cadastrar nova empresa\n");
//        printf("[2] Consultar empresas\n");
//        printf("[3] Relat�rio de insumos tratados e gastos");
//        printf("[0] Sair\n");
//        scanf("%d", &num);
//        getchar();
//        switch(num){
//        	case 1:
//        		cadastrar();
//        		break;
//        	case 2:
//        		consultas();
//        		break;
//        	case 3:
//        		relatoriosIndividuais();
//		}
//		getchar();
//	}
//	while(num !=0);
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
			puts("Nome do respons�vel da empresa:");
			scanf(" %29[^\n]", empresa[i].nomeResponsavel);
			getchar();
			
			printf("Nome da empresa: ");
		    scanf(" %19[^\n]", empresa[i].nomeEmpresa);
		    getchar();
		
		    printf("Raz�o Social: ");
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
		
		    printf("N�mero: ");
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
			
		   	fprintf(ponteiroFile,"Respons�vel: %s, Empresa: %s,Razão social: %s,Fantasia: %s, Email: %s,CPF reponsável: %d, Telefone: %d,CNPJ: %d, Rua: %s, Número: %d, CEP: %d, Estado: %s\n",
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
	
			printf("\n[1]Continuar cadastro\n[0] Voltar ao menu principal\n");
			scanf("%d", &num);
			getchar();
		
	}while(num !=0);
	
}

//verificar se existe a empresa antes de listar
// void listarEmpresas(){
// 	system("cls");
// 	int i, encontrou = 0;
// 	printf("\n NOME DAS EMPRESAS: \n");
// 	for(i =0; i<MAX_EMPRESAS; i++){
// 		if(empresa[i].ativo == 1){
// 			printf("\n -------------------- \n");
// 			printf("Nome: %s\n", empresa[i].nomeEmpresa);
// 		}	
// 	}
// }


void consultas(){
	char nomeEmpresa[20];
	int i, num;
	do{
		system("cls");
		printf("Digite o nome da empresa que deseja fazer atualiza��es:\n");
		scanf("%s", nomeEmpresa);
		getchar();
		for(i=0; i< MAX_EMPRESAS; i++ ){
			if (strstr(empresa[i].nomeEmpresa, nomeEmpresa) != NULL ){
				printf("A pesquisa retornou os seguintes resultados:\n");
				printf("Nome da empresa: %s\n", empresa[i].nomeEmpresa);
			}else {
				printf("Empresa n�o encontrada!\n");
			}
			break;				
		} 
		printf("\n[1]Gerar relat�rio consumo\n[0]Voltar ao menu principal\n");
		
		scanf("%d", &num);
		getchar();
	} while (num !=0);
}

void relatoriosIndividuais(){
	system("cls");
	
	char nomeEmpresa[20];
	int num,i;
	printf("Insira qual empresa deseja realizar atualiza��es:\n");
	fgets(nomeEmpresa, sizeof(nomeEmpresa), stdin);

	for(i=0; i<MAX_EMPRESAS; i++){
			if (strstr(empresa[i].nomeEmpresa, nomeEmpresa) != NULL ){
				printf("Nome da empresa: %s\n", empresa[i].nomeEmpresa);
				break;
			}
	}
	printf("insira os dados abaixo: ");
	do {
		for(i = 0; i< MAX_EMPRESAS; i++){
			printf("quantidade de res�duos ambientais tratados pela empresa %s\n", nomeEmpresa );
			scanf("%d", &empresa[i].relatorio.residuosTratados);

			printf("valor estimado do custo do tratamento de res�duos pela empresa %s\n", nomeEmpresa );
			scanf("%f", &empresa[i].relatorio.residuosTratados);
			printf("[0] Sair");
			scanf("%d", &num);
			break;
		}
	
	}while(num!=0);
 
 printf("Atualiza��es realizadas com sucesso!\n");
}

void criptografar(){
	
}


void recebeArquivo(char tipo[]){
	char aux[TAM_TEXTO];
	if(strcmp(tipo, "arquivo")== 0){
		printf("\n\nRecebendo arquivo\n\n");
		relatoriosIndividuais()	;
		
		if(strlen(aux) <=TAM_TEXTO){
			printf("TEXTO RECEBIDO");
			printf("criptografando");
		}		
//if (strlen(TEXTO) > 0 && strlen(TEXTO) <= TAM_TEXTO) {
//            strncpy(aux, TEXTO, TAM_TEXTO - 1);
//            aux[TAM_TEXTO - 1] = '\0';  // Garante o t�rmino da string em aux
//            printf("Conte�do recebido: %s\n", aux);
//        } else {
//            printf("Erro: o conte�do do texto est� fora do tamanho permitido.\n");
//        }

		system("pause");
	}else{
		printf("\n\nErro ao receber arquivo\n\n");
	}
}
