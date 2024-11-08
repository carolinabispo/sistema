#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

#define MAX_EMPRESAS 20

char user[20];
char password[20];

typedef struct {
	char numero[6];
	char cep[11];
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
	char cpf[12];
	char telefone[10];
	char cnpj[21];
	Endereco endereco;
	Relatorio relatorio;
}Empresa;


//defino tamanho do vetor empresa
Empresa empresa[MAX_EMPRESAS];

//funçoes
void login();
void menu();
void cadastrar();
void gerarRelatorio();
void relatoriosIndividuais();

int main(){
	setlocale(LC_ALL, "Portuguese");

	//login();
	menu();
	return 0;
}

void login(){
	const char correctUser[10] = "usuario";
	const char correctPassword[10] = "senha123";
	int logado = 0;

    while ((logado == 0)){
		system("cls");
		printf("BEM VINDO, INSIRA SEU USUÁRIO E SENHA NOS CAMPOS ABAIXO:\n");
		printf("Nome de usuario:\n");
		scanf("%s", user);
		getchar();

		printf("Insira sua senha:\n");
		scanf("%s", password);
		getchar();

		if(strcmp(user, correctUser) == 0 && strcmp(password, correctPassword) == 0){
			printf("\n\nLOGADO!\n\n");
			logado = 1;
		}
		else if (user != correctUser || password != correctPassword){
			printf("Nome de usuario ou senha incorretos.\n");
			getchar();
		}
	} 
}

void menu(){
	system("cls");
	int num;
	do{
		printf("============== Menu principal ==============\n");
        printf("Selecione uma das opcoes abaixo:\n");
        printf("[1] Cadastrar nova empresa\n");
        printf("[2] Cadastrar insumos e gastos\n");
        printf("[3] Relatorio de insumos tratados e gastos\n");
        printf("[0] Sair\n");
        scanf("%d", &num);
        switch(num){
        	case 1:
        		cadastrar();
        		break;
        	case 2:
        		relatoriosIndividuais();
        		break;
        	case 3:
        		gerarRelatorio();
                break;
		}
		getchar();
	}
	while(num !=0);
}

void cadastrar(){
    system("cls");
    int num, i;
    
    do {
        for (i = 0; i < MAX_EMPRESAS; i++) {
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
            scanf(" %14[^\n]", empresa[i].cpf);
            getchar();
        
            printf("Telefone: ");
            scanf(" %14[^\n]", empresa[i].telefone);
            getchar();
        
            printf("CNPJ: ");
            scanf(" %14[^\n]", empresa[i].cnpj);
            getchar();
        
            printf("Nome da rua: ");
            scanf(" %49[^\n]", empresa[i].endereco.rua);
            getchar();
        
            printf("Número: ");
            scanf(" %49[^\n]", empresa[i].endereco.numero);
            getchar();  
            
            printf("CEP: ");
            scanf(" %49[^\n]", empresa[i].endereco.cep);
            getchar();
            
            printf("Estado: ");
            scanf(" %19[^\n]", empresa[i].endereco.estado);
            getchar(); 
            
            printf("Empresa cadastrada, aperte enter para continuar");
            getchar();
            system("cls");
            
            printf("\n[1]Continuar cadastro\n[0] Voltar ao menu principal\n");
            scanf("%d", &num);
            system("cls");

            if (num == 0) break;
        }
    } while (num != 0);
}

void relatoriosIndividuais(){
char nomeEmpresa[20];
    int i, num;
    
  
        system("cls");
        printf("Digite o nome da empresa que deseja cadastrar os dados\n");
        scanf(" %19[^\n]", nomeEmpresa);
        getchar();

        int empresaEncontrada = 0;

        for (i = 0; i < MAX_EMPRESAS; i++) {
            if (strstr(empresa[i].nomeEmpresa, nomeEmpresa) != NULL) {
                printf("A pesquisa retornou os seguintes resultados:\n");
                printf("Nome da empresa: %s\n", empresa[i].nomeEmpresa);

                empresaEncontrada = 1;
                break;
            }
        }
        if (empresaEncontrada) {
        	printf("\n\ninsira os dados abaixo: ");
	

			printf("quantidade de resÃ­duos ambientais tratados pela empresa %s\n", nomeEmpresa );
			scanf("%d", &empresa[i].relatorio.residuosTratados);

			printf("valor estimado do custo do tratamento de resÃ­duos pela empresa %s\n", nomeEmpresa );
			scanf("%f", &empresa[i].relatorio.gastosMensais);
			printf("AtualizaÃ§Ãµes realizadas com sucesso!\n");
			printf("[0] Sair");
			scanf("%d", &num);	
            
        }else{
        	printf("Empresa não cadastrada\n");
		}
        

}

void gerarRelatorio() {
    char nomeEmpresa[20];
    int i, num;
    
    do {
        system("cls");
        printf("Digite o nome da empresa que deseja exibir o relatório\n");
        scanf(" %19[^\n]", nomeEmpresa);
        getchar();

        int empresaEncontrada = 0;

        for (i = 0; i < MAX_EMPRESAS; i++) {
            if (strstr(empresa[i].nomeEmpresa, nomeEmpresa) != NULL) {
                printf("A pesquisa retornou os seguintes resultados:\n");
                printf("Nome da empresa: %s\n", empresa[i].nomeEmpresa);

                empresaEncontrada = 1;
                break;
            }
        }
        if (!empresaEncontrada) {
            printf("Empresa não cadastrada\n");
        }

        printf("\n[1] Gerar relatório consumo\n[0] Voltar ao menu principal\n");
        scanf("%d", &num);

        switch (num) {
            case 1:
                //gerar relatório
                if (empresaEncontrada) {
                    do{
                        printf("Responsavel: %s\n - Empresa: %s\n - Razão social: %s\n - Fantasia: %s\n - Email: %s\n - CPF: %s\n - Telefone: %s\n - CNPJ: %s\n - Rua: %s\n - Número: %s\n - CEP: %s\n - Estado: %s\n", 
                        empresa[i].nomeResponsavel, empresa[i].nomeEmpresa, 
                        empresa[i].razaoSocial, empresa[i].nomeFantasia, 
                        empresa[i].email, empresa[i].cpf, empresa[i].telefone, 
                        empresa[i].cnpj, empresa[i].endereco.rua, empresa[i].endereco.numero, 
                        empresa[i].endereco.cep, empresa[i].endereco.estado); 
                        
                        printf("------------------------------\nRelatório de insumos e gastos:\n", "- Residuos tratados: %s\n","- Gastos mensais: %s\n", 
                        empresa[i].relatorio.residuosTratados, empresa[i].relatorio.gastosMensais);
                        
                        printf("\nDeseja gerar o arquivo do relatorio acima?\n [1]Gerar arquivo\n [0]Voltar ao menu principal\n");
                        scanf("%d", &num);
                        
                        //gerar arquivo do relatório
                        if(num == 1) {
                            char fileName[20];
                            sprintf(fileName, "empresa_%s.txt", empresa[i].nomeEmpresa);
                            FILE *ponteiroFile = fopen(fileName, "w");
                    
                            if (ponteiroFile == NULL) {
                            perror("Erro ao abrir o arquivo");
                            exit(1);}
                            
                            fprintf(ponteiroFile, "Responsavel: %s\n • Empresa: %s\n • Razão social: %s\n • Fantasia: %s\n • Email: %s\n • CPF: %s\n • Telefone: %s\n • CNPJ: %s\n • Rua: %s\n • Número: %s\n • CEP: %s\n • Estado: %s\n", 
                            empresa[i].nomeResponsavel, empresa[i].nomeEmpresa,
                            empresa[i].razaoSocial, empresa[i].nomeFantasia,
                            empresa[i].email, empresa[i].cpf, empresa[i].telefone, 
                            empresa[i].cnpj, empresa[i].endereco.rua, empresa[i].endereco.numero, 
                            empresa[i].endereco.cep, empresa[i].endereco.estado);
                           
                            fprintf(ponteiroFile, "------------------------------\n Relatório de insumos e gastos:\n", "• Residuos tratados: %s\n","• Gastos mensais: %s\n", empresa[i].relatorio.residuosTratados, empresa[i].relatorio.gastosMensais);
                        
                            fclose(ponteiroFile);
                            num = 0;
                            system("cls");
                        };
                    }while(num != 0);
                
                }else {
                    printf("Não é possível gerar relatório para uma empresa não cadastrada.\n");
                }
                break;
        }
    } while (num != 0);
}

