#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <winsock2.h>
#include <mysql.h>


void main()
{
    setlocale(LC_ALL, "Portuguese"); // Permite acento nas letrar
    login(); // chama tela de login
    //getData("'Wellington'");
    //telaPrincipal();
}

void login(){

    char usuario [12];
    char senha [7];
    printf("Olá! \n");
    printf("Por favor Insira o usuario: \n");
    scanf("%s", &usuario);
    if(strlen(usuario) <= 10){
        strcat(usuario,"'");
        printf("Digite sua Senha de acesso:\n");
        scanf("%s", &senha);
        if(strlen(senha) <= 5 ){
            strcat(senha,"'");
            getUsuario(usuario, senha);
        }else{
            printf("Senha invalida! Verifique os campos");
            main();
        }

    }else{
        printf("Usuario invalido! Verifique os campos");
        main();
    }



}


void getUsuario(char LoginUser[], char LoginPass[])
{
    char *host = "localhost";
    char *user = "root";
    char *pass = "1234567";
    char *db = "db_projetopizza";
    unsigned int port = 3306;
    char *socket = NULL;
    unsigned int flags = 0;
    MYSQL *conn;
    MYSQL_RES *res;
    conn = mysql_init(NULL);
    if(!(mysql_real_connect(conn,host,user,pass,db,port,socket,flags)))
    {
        fprintf(stderr, "Error: %s [%d\n]", mysql_error(conn), mysql_errno(conn));
        exit(1);
    }
    char usuario[strlen(LoginUser)];
    char senha[strlen(LoginPass)];
    char query[100] = "Select * from tb_usuario where login = '";
    strcpy(usuario,LoginUser);
    strcat(query, usuario);
    strcat(query," And senha = '");
    strcpy(senha,LoginPass);
    strcat(query, senha);
    mysql_query(conn, query);
    res = mysql_store_result(conn);
    int num = mysql_num_rows(res);
    if(num > 0){
        telaPrincipal();
    }else{
        int opcao;
        printf("Usuario ou senha invalidos! \nSelecione uma das opções abaixo \n");
        printf("\t 1 Login \t 0 Sair\n");
        scanf("%i", &opcao);
        if(opcao == 1){
            system("cls");
            main();
        }else{
            system("exit");
        }
    }
    mysql_free_result(res);
    mysql_close(conn);
}

void telaPrincipal(){
    system("cls");
    int opcao;
    printf("Seja Bem vindo\n");
    printf("Selecione uma das opções abaixo para navegar no sistema: \n");
    printf("  \t 1 Cadastros \t 0 Sair \n "); //REFAZER
    scanf("%i", &opcao);

    switch(opcao){
    case 1:
        telaCadastros();
        break;
    }

}

void telaCadastros(){
    printf("Cadastro \n");
    printf("O que deseja Cadastrar? \n");
    printf("\t 1 - Bebidas \t 2 - Sabores \t 3 - Pizzaiolos \t 4 - Pedidos \t 5 - Clientes \t 6 - Reclamações \t 7 - Elogios \t  8 - Promoções \t ");

}
