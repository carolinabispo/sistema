#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX_EMPRESAS 20

char user[20];
char password[20];

typedef struct {
    char numero[6];
    char cep[11];
    char estado[20];
    char rua[50];
} Endereco;

typedef struct {
    int residuosTratados;
    float gastosMensais;
} Relatorio;

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
} Empresa;

Empresa empresa[MAX_EMPRESAS];

// Funções
void login();
void menu();
void cadastrar();
void relatorio();
void relatoriosIndividuais();
void gerarRelatorio(int i);

int main(){
    setlocale(LC_ALL, "Portuguese");

    login();
    menu();
    return 0;
}

void login(){
    const char correctUser[10] = "usuario";
    const char correctPassword[10] = "senha123";
    int logado = 0;

    while (logado == 0){
        system("cls");
        printf("BEM VINDO, INSIRA SEU USUARIO E SENHA NOS CAMPOS ABAIXO:\n");
        printf("Nome de usuario:\n");
        scanf("%s", user);
        getchar();

        printf("Insira sua senha:\n");
        scanf("%s", password);
        getchar();

        if(strcmp(user, correctUser) == 0 && strcmp(password, correctPassword) == 0){
            printf("\n\nLOGADO!\n\n");
            logado = 1;
        } else {
            printf("Nome de usuario ou senha incorretos.\n");
            getchar();
        }
    } 
}

void menu(){
    system("cls");
    int num;
    do {
        printf("============== Menu principal ==============\n");
        printf("Selecione uma das opcoes abaixo:\n");
        printf("[1] Cadastrar nova empresa\n");
        printf("[2] Cadastrar insumos e gastos\n");
        printf("[3] Relatorio de insumos tratados e gastos\n");
        printf("[0] Sair\n");
        scanf("%d", &num);
        switch(num) {
            case 1:
                cadastrar();
                break;
            case 2:
                relatoriosIndividuais();
                break;
            case 3:
                relatorio();
                break;
        }
        getchar();
    } while(num != 0);
}

void cadastrar(){
    system("cls");
    int num, i;

    for (i = 0; i < MAX_EMPRESAS; i++) {
        printf("Insira os dados abaixo:\n");
        printf("Nome do responsavel da empresa: ");
        scanf(" %29[^\n]", empresa[i].nomeResponsavel);
        getchar();
        
        printf("Nome da empresa: ");
        scanf(" %19[^\n]", empresa[i].nomeEmpresa);
        getchar();
    
        printf("Razao Social: ");
        scanf(" %29[^\n]", empresa[i].razaoSocial);
        getchar();
    
        printf("Nome Fantasia: ");
        scanf(" %29[^\n]", empresa[i].nomeFantasia);
        getchar();
    
        printf("Email: ");
        scanf(" %19[^\n]", empresa[i].email);
        getchar();
    
        printf("CPF: ");
        scanf(" %11[^\n]", empresa[i].cpf);
        getchar();
    
        printf("Telefone: ");
        scanf(" %9[^\n]", empresa[i].telefone);
        getchar();
    
        printf("CNPJ: ");
        scanf(" %20[^\n]", empresa[i].cnpj);
        getchar();
    
        printf("Nome da rua: ");
        scanf(" %49[^\n]", empresa[i].endereco.rua);
        getchar();
    
        printf("Numero: ");
        scanf(" %5[^\n]", empresa[i].endereco.numero);
        getchar();  
        
        printf("CEP: ");
        scanf(" %10[^\n]", empresa[i].endereco.cep);
        getchar();
        
        printf("Estado: ");
        scanf(" %19[^\n]", empresa[i].endereco.estado);
        getchar(); 
        
        printf("Empresa cadastrada, aperte enter para continuar");
        getchar();
        system("cls");
        
        printf("\n[1] Continuar cadastro\n[0] Voltar ao menu principal\n");
        scanf("%d", &num);
        if (num == 0) break;
    }
}

void relatoriosIndividuais(){
    char nomeEmpresa[20];
    int i, num;

    system("cls");
    printf("Digite o nome da empresa para cadastrar os dados\n");
    scanf(" %19[^\n]", nomeEmpresa);
    getchar();

    int empresaEncontrada = 0;

    for (i = 0; i < MAX_EMPRESAS; i++) {
        if (strstr(empresa[i].nomeEmpresa, nomeEmpresa) != NULL) {
            printf("A pesquisa retornou os seguintes resultados:\n");
            printf("Nome da empresa: %s\n", empresa[i].nomeEmpresa);

            printf("\nInsira os dados abaixo:\n");
            printf("Quantidade de residuos ambientais tratados pela empresa em um mes:\n");
            scanf("%d", &empresa[i].relatorio.residuosTratados);
            getchar();
            printf("Valor estimado do custo do tratamento de residuos pela empresa em um dia:\n");
            scanf("%f", &empresa[i].relatorio.gastosMensais);
            getchar();

            printf("Atualizacoes realizadas com sucesso!\n");
            empresaEncontrada = 1;
            break;
        }
    }
    if (!empresaEncontrada) {
        printf("Empresa nao cadastrada\n");
    }
    printf("[0] Sair\n");
    scanf("%d", &num);	
}

void relatorio() {
    char nomeEmpresa[20];
    int i, num;

    system("cls");
    printf("Digite o nome da empresa para exibir o relatorio\n");
    scanf(" %19[^\n]", nomeEmpresa);
    getchar();

    int empresaEncontrada = 0;

    for (i = 0; i < MAX_EMPRESAS; i++) {
        if (strstr(empresa[i].nomeEmpresa, nomeEmpresa) != NULL) {
            gerarRelatorio(i);
            empresaEncontrada = 1;
            break;
        }
    }

    if (!empresaEncontrada) {
        printf("Empresa nao cadastrada\n");
    }
}

void gerarRelatorio(int i) {
    printf("Relatorio Geral:\n");
    printf("Responsavel: %s\n", empresa[i].nomeResponsavel);
    printf("Empresa: %s\n", empresa[i].nomeEmpresa);
    printf("Razao social: %s\n", empresa[i].razaoSocial);
    printf("Nome Fantasia: %s\n", empresa[i].nomeFantasia);
    printf("Email: %s\n", empresa[i].email);
    printf("CPF: %s\n", empresa[i].cpf);
    printf("Telefone: %s\n", empresa[i].telefone);
    printf("CNPJ: %s\n", empresa[i].cnpj);
    printf("Rua: %s\n", empresa[i].endereco.rua);
    printf("Numero: %s\n", empresa[i].endereco.numero);
    printf("CEP: %s\n", empresa[i].endereco.cep);
    printf("Estado: %s\n", empresa[i].endereco.estado);
    printf("------------------------------\n");
    printf("Residuos Tratados: %d\n", empresa[i].relatorio.residuosTratados);
    printf("Gastos Mensais: %.2f\n", empresa[i].relatorio.gastosMensais);
}
