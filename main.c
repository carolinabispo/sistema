#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>  
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	setlocale(LC_ALL, "Portuguese");
//	declarando variaveis

	char registerUser[20];
	char registerPassword[20];
	char user[20];
	char password[20];
	int loginEfetuado = 0; //0 - Falso e  1 - Verdadeiro
	
	printf("BEM VINDO, REGISTRE SEU USUARIO NOS CAMPOS ABAIXO\n");
	
	printf("Insira seu nome:\n");
	scanf("%s", registerUser);
	printf("Insira sua senha: \n");
	scanf("%s", registerPassword);
	
	printf("registro realizado, pressione enter para continuar");	
	
	getch();  // aguarda pressionar tecla

    system("cls");  // limpa a tela para uma proxima tela
    printf("tela de login, insira seu nome e senha nos campos abaixo: \n");
	
	
//	comparar login e senha
	while(!loginEfetuado){
		printf("Digite o usuario:\n");
		scanf("%s", user);
		
		printf("Insira sua senha:\n");
		scanf("%s", password);
	
		if (strcmp(registerUser, user) == 0 && strcmp(registerPassword, password) == 0){
            printf("\n\nLOGADO!\n\n");
            loginEfetuado = 1;
            
            getch();  // aguarda pressionar tecla

    		system("cls");  // limpa a tela para uma proxima tela
        }
        else
            printf("\n\nDADOS INVALIDOS!\n\n");    
    }
    
    printf("==============Menu principal================");
    printf("Selecione uma das opcoes abaixo:\n");
    
    printf("[1]Cadastrar nova empresa");
    
}
