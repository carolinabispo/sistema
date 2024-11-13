#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

#define MAX_EMPRESAS 20

char user[20];
char password[20];

typedef struct
{
    char numero[6];
    char cep[11];
    char estado[20];
    char rua[50];
} Endereco;

typedef struct
{
    int residuosTratados;
    float gastosMensais;
} Relatorio;

typedef struct
{
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

// defino tamanho do vetor empresa
Empresa empresa[MAX_EMPRESAS];

// funçoes
void login();
void menu();
void cadastrar();
void relatorio();
void cadastrarRelatorio();
void gerarRelatorio();
void atualizaRelatorio();
void criptografar();
void descriptografar();

int main()
{
    setlocale(LC_ALL, "Portuguese");

    login();
    menu();
    return 0;
}

void login()
{
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

void menu()
{
    system("cls");
    int num;
    do
    {
        printf("============== Menu principal ==============\n");
        printf("Selecione uma das opcoes abaixo:\n");
        printf("[1] Cadastrar nova empresa\n");
        printf("[2] Cadastrar insumos e gastos\n");
        printf("[3] Relatorio de insumos tratados e gastos\n");
        printf("[4] Atualizar relatorio de insumos e gastos\n");
        printf("[0] Sair\n");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            cadastrar();
            break;
        case 2:
            cadastrarRelatorio();
            break;
        case 3:
            relatorio();
            break;
        case 4:
            atualizaRelatorio();
            break;
        case 0:
            printf("Saindo...");
            break;
        }

        getchar();
    } while (num != 0);
}

void cadastrar()
{
    system("cls");
    int num, i;

    do
    {
        for (i = 0; i < MAX_EMPRESAS; i++)
        {
            printf("Insira os dados abaixo:\n");
            puts("Nome do responsavel da empresa:");
            scanf(" %29[^\n]", empresa[i].nomeResponsavel);
            getchar();
            criptografar(empresa[i].nomeResponsavel);

            printf("Nome da empresa: ");
            scanf(" %19[^\n]", empresa[i].nomeEmpresa);
            getchar();
            criptografar(empresa[i].nomeEmpresa);

            printf("Razao Social: ");
            scanf(" %29[^\n]", empresa[i].razaoSocial);
            getchar();
            criptografar(empresa[i].razaoSocial);

            printf("Nome Fantasia: ");
            scanf(" %29[^\n]", empresa[i].nomeFantasia);
            getchar();
            criptografar(empresa[i].nomeFantasia);

            printf("Email: ");
            scanf(" %19[^\n]", empresa[i].email);
            getchar();
            criptografar(empresa[i].email);

            printf("CPF: ");
            scanf(" %14[^\n]", empresa[i].cpf);
            getchar();
            criptografar(empresa[i].cpf);

            printf("Telefone: ");
            scanf(" %14[^\n]", empresa[i].telefone);
            getchar();
            criptografar(empresa[i].telefone);

            printf("CNPJ: ");
            scanf(" %14[^\n]", empresa[i].cnpj);
            getchar();
            criptografar(empresa[i].cnpj);

            printf("Nome da rua: ");
            scanf(" %49[^\n]", empresa[i].endereco.rua);
            getchar();
            criptografar(empresa[i].endereco.rua);

            printf("Numero: ");
            scanf(" %49[^\n]", empresa[i].endereco.numero);
            getchar();
            criptografar(empresa[i].endereco.numero);

            printf("CEP: ");
            scanf(" %49[^\n]", empresa[i].endereco.cep);
            getchar();
            criptografar(empresa[i].endereco.cep);

            printf("Estado: ");
            scanf(" %19[^\n]", empresa[i].endereco.estado);
            getchar();
            criptografar(empresa[i].endereco.estado);

            printf("Empresa cadastrada, aperte enter para continuar");
            getchar();
            system("cls");

            printf("\n[1]Continuar cadastro\n[0] Voltar ao menu principal\n");
            scanf("%d", &num);
            system("cls");

            if (num == 0)
                break;
        }
    } while (num != 0);
}

void cadastrarRelatorio()
{
    char nomeEmpresa[20];
    int i, num;

    system("cls");
    printf("Digite o nome da empresa que deseja cadastrar os dados\n");
    scanf(" %19[^\n]", nomeEmpresa);
    getchar();
    system("cls");

    int empresaEncontrada = 0;

    for (i = 0; i < MAX_EMPRESAS; i++)
    {
        char nomeEmpresaDescriptografado[20];
        strcpy(nomeEmpresaDescriptografado, empresa[i].nomeEmpresa);
        descriptografar(nomeEmpresaDescriptografado);

        if (strstr(nomeEmpresaDescriptografado, nomeEmpresa) != NULL)
        {
            descriptografar(empresa[i].nomeEmpresa);
            printf("A pesquisa retornou os seguintes resultados:\n");
            printf("Nome da empresa: %s\n", nomeEmpresaDescriptografado);

            empresaEncontrada = 1;
            break;
        }
    }
    if (empresaEncontrada)
    {
        printf("\ninsira os dados abaixo:\n");

        printf("quantidade de residuos ambientais tratados pela empresa em um mes:\n");
        scanf("%d", &empresa[i].relatorio.residuosTratados);
        getchar();
        printf("valor estimado do custo do tratamento de residuos pela empresa em um dia:\n");
        scanf("%f", &empresa[i].relatorio.gastosMensais);
        getchar();

        printf("Atualizacoes realizadas com sucesso!\n");
        printf("[0] Sair\n");
        scanf("%d", &num);
        system("cls");
    }
    else
    {
        printf("Empresa nao cadastrada\n");
    }
}

void relatorio()
{
    char nomeEmpresa[20];
    int i, num;

    do
    {
        system("cls");
        printf("Digite o nome da empresa que deseja exibir o relatorio\n");
        descriptografar(nomeEmpresa);

        scanf(" %19[^\n]", nomeEmpresa);
        getchar();

        int empresaEncontrada = 0;

        for (i = 0; i < MAX_EMPRESAS; i++)
        {
            if (strstr(empresa[i].nomeEmpresa, nomeEmpresa) != NULL)
            {
                printf("A pesquisa retornou os seguintes resultados:\n");
                printf("Nome da empresa: %s\n", empresa[i].nomeEmpresa);

                empresaEncontrada = 1;
                break;
            }
        }
        if (!empresaEncontrada)
        {
            printf("Empresa nao cadastrada\n");
        }
        printf("\n[1] Gerar relatorio de consumo\n[0] Voltar ao menu principal\n");
        scanf("%d", &num);

        system("cls");

        switch (num)
        {
        case 1:
            if (empresaEncontrada)
            {
                gerarRelatorio(i, num);
                num = 0;
            }
            else
            {
                printf("Nao é possivel gerar relatorio para uma empresa nao cadastrada.\n");
            }
            break;
        }
    } while (num != 0);
}

void gerarRelatorio(int i, int num)
{

    while (num != 0)
    {
        printf("Relatorio Geral:\n");
        descriptografar(empresa[i].nomeResponsavel);
        printf("Responsavel: %s\n", empresa[i].nomeResponsavel);

        printf("Empresa: %s\n", empresa[i].nomeEmpresa);

        descriptografar(empresa[i].razaoSocial);
        printf("Razao social: %s\n", empresa[i].razaoSocial);

        descriptografar(empresa[i].nomeFantasia);
        printf("Nome Fantasia: %s\n", empresa[i].nomeFantasia);

        descriptografar(empresa[i].email);
        printf("Email: %s\n", empresa[i].email);

        descriptografar(empresa[i].cpf);
        printf("CPF: %s\n", empresa[i].cpf);

        descriptografar(empresa[i].telefone);
        printf("Telefone: %s\n", empresa[i].telefone);

        descriptografar(empresa[i].cnpj);
        printf("CNPJ: %s\n", empresa[i].cnpj);

        descriptografar(empresa[i].endereco.rua);
        printf("Rua: %s\n", empresa[i].endereco.rua);

        descriptografar(empresa[i].endereco.numero);
        printf("Numero: %s\n", empresa[i].endereco.numero);

        descriptografar(empresa[i].endereco.cep);
        printf("CEP: %s\n", empresa[i].endereco.cep);

        descriptografar(empresa[i].endereco.estado);
        printf("Estado: %s\n", empresa[i].endereco.estado);

        printf("------------------------------\n");
        printf("Relatorio de insumos e gastos:\n");
        printf("- Residuos tratados semestralmente: %d\n- Gastos mensais: %.2f\n",
               empresa[i].relatorio.residuosTratados * 6, empresa[i].relatorio.gastosMensais * 30);

        printf("\nDeseja gerar o arquivo do relatorio acima?\n [1]Gerar arquivo\n [0]Voltar ao menu principal\n");
        scanf("%d", &num);

        // gerar arquivo do relatório
        if (num == 1)
        {

            char fileName[20];
            sprintf(fileName, "./empresa_%s.txt", empresa[i].nomeEmpresa);
            FILE *ponteiroFile = fopen(fileName, "w");

            if (ponteiroFile == NULL)
            {
                perror("Erro ao abrir o arquivo");
                exit(1);
            }

            fprintf(ponteiroFile, "Relatório Geral:\n • Responsável: %s\n • Empresa: %s\n • Razão social: %s\n • Fantasia: %s\n • Email: %s\n • CPF: %s\n • Telefone: %s\n • CNPJ: %s\n • Rua: %s\n • Número: %s\n • CEP: %s\n • Estado: %s\n",
                    empresa[i].nomeResponsavel, empresa[i].nomeEmpresa,
                    empresa[i].razaoSocial, empresa[i].nomeFantasia,
                    empresa[i].email, empresa[i].cpf, empresa[i].telefone,
                    empresa[i].cnpj, empresa[i].endereco.rua, empresa[i].endereco.numero,
                    empresa[i].endereco.cep, empresa[i].endereco.estado);

            fprintf(ponteiroFile, "------------------------------\nRelatório de insumos e gastos:\n");
            fprintf(ponteiroFile, "• Resíduos tratados semestralmente: %d\n• Gastos mensais: %.2f\n", empresa[i].relatorio.residuosTratados * 6, empresa[i].relatorio.gastosMensais * 30);
            fprintf(ponteiroFile, "\n---------------------------------------\n");

            fclose(ponteiroFile);
            // exibe o arquivo na tela
            char openCommand[150];
            sprintf(openCommand, "start %s", fileName);
            system(openCommand);

            num = 0;
            system("cls");
            break;
        }
    }
}

void atualizaRelatorio(int i, int num)
{
    char nomeEmpresa[20];

    while (num != 0)
    {
        system("cls");
        printf("Digite o nome da empresa que deseja atualizar os dados\n");
        scanf(" %19[^\n]", nomeEmpresa);
        getchar();
        system("cls");

        int empresaEncontrada = 0;

        for (i = 0; i < MAX_EMPRESAS; i++)
        {
            if (strstr(empresa[i].nomeEmpresa, nomeEmpresa) != NULL)
            {
                printf("A pesquisa retornou os seguintes resultados:\n");
                printf("Nome da empresa: %s\n", empresa[i].nomeEmpresa);

                empresaEncontrada = 1;
                break;
            }
        }
        if (empresaEncontrada)
        {
            printf("\ninsira os dados abaixo:\n");

            printf("quantidade de residuos ambientais tratados pela empresa em um mes:\n");
            scanf("%d", &empresa[i].relatorio.residuosTratados);
            getchar();
            printf("valor estimado do custo do tratamento de residuos pela empresa em um dia:\n");
            scanf("%f", &empresa[i].relatorio.gastosMensais);
            getchar();

            printf("Atualizacoes realizadas com sucesso!\n");
        }
        else
        {
            printf("Empresa nao cadastrada\n");
        }

        printf("\nDeseja gerar o arquivo do relatorio acima?\n [1]Gerar arquivo\n [0]Voltar ao menu principal\n");
        scanf("%d", &num);

        if (num == 1)
        {
            char fileName[20];
            sprintf(fileName, "./empresa_%s.txt", empresa[i].nomeEmpresa);
            FILE *ponteiroFile = fopen(fileName, "a");

            if (ponteiroFile == NULL)
            {
                perror("Erro ao abrir o arquivo");
                exit(1);
            }

            fprintf(ponteiroFile, "Relatório Geral:\n • Responsável: %s\n • Empresa: %s\n • Razão social: %s\n • Fantasia: %s\n • Email: %s\n • CPF: %s\n • Telefone: %s\n • CNPJ: %s\n • Rua: %s\n • Número: %s\n • CEP: %s\n • Estado: %s\n",
                    empresa[i].nomeResponsavel, empresa[i].nomeEmpresa,
                    empresa[i].razaoSocial, empresa[i].nomeFantasia,
                    empresa[i].email, empresa[i].cpf, empresa[i].telefone,
                    empresa[i].cnpj, empresa[i].endereco.rua, empresa[i].endereco.numero,
                    empresa[i].endereco.cep, empresa[i].endereco.estado);

            fprintf(ponteiroFile, "------------------------------\nRelatório de insumos e gastos:\n");
            fprintf(ponteiroFile, "• Resíduos tratados semestralmente: %d\n• Gastos mensais: %.2f\n", empresa[i].relatorio.residuosTratados * 6, empresa[i].relatorio.gastosMensais * 30);
            fprintf(ponteiroFile, "\n---------------------------------------\n");

            fclose(ponteiroFile);

            char openCommand[150];
            sprintf(openCommand, "start %s", fileName);
            system(openCommand);

            num = 0;
            system("cls");
            break;
        }
    }
}

void criptografar(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        str[i] = str[i] + 3;
    }
}

void descriptografar(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        str[i] = str[i] - 3;
    }
}