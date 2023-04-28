#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

//Informações
struct camposDados {

    char nome[40];
    int dia;
    char diaC[2];
    int mes;
    char mesC[2];
    int ano;
    char anoC[4];
    char email[50];
    long long telefone2;
    char telefone2C[12];
    long long telefone;
    char telefoneC[12];
    char rua[20];
    char numeroC[10];
    int numero;
    char bairro[20];
    char cidade[20];
    char estado[20];
    char complemento[100];
    long long cep;
    char cepC[15];
};

struct CPF {

    char cpfC[12];

};

struct diagnostico {
    int dia;
    char diaC[2];
    int mes;
    char mesC[2];
    int ano;
    char anoC[4];
};

struct user{
    char user[10];
    char password[8];
};

//Cadastro e login
void cadastro(void);
void cadLogin(void);
void menu(void);


char teste();
int continua = 1;
char morbidade [60];


int main(){
    system("cls");
//morbidade
    setlocale(LC_ALL,"Portuguese");
        cadLogin();

}

int i;
void cadastro (void){

    char apoioNome[500];
    char tracos[]= "------------------------------------------------";
    FILE *ponteiro1;
    FILE *ponteiro2;
    ponteiro1 = fopen("risco.txt", "a");
    ponteiro2 = fopen("cadastro.txt", "a");
    if( ponteiro1 == NULL && ponteiro2 == NULL){
        printf("Erro na abertura do arquivo!");
    return 1;
  }


    long long cpf;
    struct CPF cadCpf;
    struct camposDados ;
    struct diagnostico data;
    int opCadNtelefone;

    system("cls");
    printf("\n******************DADOS PESSOAIS*******************\n");
    printf("\n---------------------------------------------------");


    char login[12];
    FILE *pontCadCpf;
    pontCadCpf = fopen ("cpf.txt","a");
    rCpf:

    printf("\nDigite o seu CPF.\n");
    printf("\nCPF: ");

    fflush(stdin);
    gets(cadCpf.cpfC);

     if(strlen(cadCpf.cpfC) == 0){
        goto rCpf;
    }

    for(i=0; i<cadCpf.cpfC[i]; i++) {
        if(!(cadCpf.cpfC[i]>='0' && cadCpf.cpfC[i]<='9' && strlen(cadCpf.cpfC)==11)){
            printf("\n***CPF inválido. Tente Novamente! ***\n");
                goto rCpf;
            break;
        }







        else{

            cpf = atoll(cadCpf.cpfC);

        }
    }

    FILE *consulta;
        consulta = fopen ("cpf.txt","r");
        while((fscanf(consulta,"%s",&login)) !=EOF){
                if (strcmp(cadCpf.cpfC,login ) == 0){
                    printf("\n---CPF já em uso.---\n");
                    goto rCpf;
                    fclose(consulta);
                    break;
                }
        }
            fprintf(pontCadCpf, "\n%s", cadCpf.cpfC);
            fclose(pontCadCpf);

    rNome:
    printf("\nNOME: ");
    gets(dados.nome);

     if(strlen(dados.nome) == 0){
        goto rNome;
    }


    for(i=0; i<dados.nome[i];i++){
            fflush(stdin);
             if (dados.nome[i] == 'a'){
                    dados.nome[i] = 'a';
                } if(dados.nome[i] >= 'a' && dados.nome[i] <= 'z' || dados.nome[i] >= 'A' && dados.nome[i] <= 'Z' || dados.nome[i] == 'A'){
                    if(dados.nome[i] == 'a'){
                            dados.nome[i] = 'a';
                    }
                    }else
                    {
                        printf("***Caracter Invalido.***");
                        goto rNome;
                        break;
                }
}

    printf("---------------------------------------------------");

    printf("DATA DE NASCIMENTO");
    rDiaNascimento:
    printf("\n    =>DIA dd : ");
    fflush(stdin);
    gets(dados.diaC);


     if(strlen(dados.diaC) == 0){
        goto rDiaNascimento;
    }



    for(i=0; i<dados.diaC[i]; i++) {
        if(!(dados.diaC[i]>='0' && dados.diaC[i]<='9' && strlen(dados.diaC)==2)){
            printf("\n--- Data Invalida. Tente Novamente!---\n");
                goto rDiaNascimento;
            break;
        }
        else{
            dados.dia = atoi(dados.diaC);
        }
    }
    rMesNascimento:
    printf("          =>Mês mm : ");
    fflush(stdin);
    gets(dados.mesC);

    if(strlen(dados.mesC) == 0){
        goto rMesNascimento;
    }

    for(i=0; i<dados.mesC[i]; i++) {
        if(!(dados.mesC[i]>='0' && dados.mesC[i]<='9' && strlen(dados.mesC)==2)){
            printf("\n--- Mês Invalido. Tente Novamente!---\n");
                goto rMesNascimento;
            break;
        }
        else{
            dados.mes = atoi(dados.mesC);
        }
    }
    rAnoNascimento:
    printf("");
    printf("             =>ANO aaaa : ");
    fflush(stdin);
    gets(dados.anoC);

    if(strlen(dados.anoC) == 0){
        goto rAnoNascimento;
    }

    printf("---------------------------------------------------");
    for(i=0; i<dados.anoC[i]; i++) {
        if(!(dados.anoC[i]>='0' && dados.anoC[i]<='9' && strlen(dados.anoC)==4)){
            printf("\n--- Ano Invalido. Tente Novamente!---\n");
                goto rAnoNascimento;
            break;
        }
        else{
            dados.ano = atoi(dados.anoC);
        }
    }

    rEmail:
    printf("\nE-mail: ");
    fflush(stdin);
    gets(dados.email);
    printf("---------------------------------------------------");


    if(strlen(dados.email) == 0){
        goto rEmail;
    }

    rTelefone:
    printf("Numero de Telefone");
    printf("--- Cadastre dois Numeros ---");
    printf("Digite os numeros em sequencia");
    printf("Informe o Telefone Principal");
    fflush(stdin);
    gets(dados.telefoneC);
    printf("---------------------------------------------------");

    if(strlen(dados.telefoneC) == 0){
        goto rTelefone;
    }

    for(i=0; i<dados.telefoneC[i]; i++) {
        if(!(dados.telefoneC[i]>='0' && dados.telefoneC[i]<='9')){
            printf("\n--- Número Inválido!---\n");
                goto rTelefone;
            break;
        }
        else{
            dados.telefone = atoll(dados.telefoneC);
        }
    }

    rTelefone2:
    printf("Informe o segundo numero de telefone: ");
    fflush(stdin);
    gets(dados.telefone2C);

    if(strlen(dados.telefone2C) == 0){
        goto rTelefone2;
    }

    for(i=0; i<dados.telefone2C[i]; i++) {
        if(!(dados.telefone2C[i]>='0' && dados.telefone2C[i]<='9')){
            printf("\n--- Número Inválido!---\n");
                goto rTelefone2;
            break;
        }
        else{
            dados.telefone2 = atoll(dados.telefone2C);
        }
    }
    system("cls");
    printf("---------------------------------------------------");
    printf("Data de testagem Positiva para COVID19");
    rDiaMorb:
    printf("\n   =>Dia dd: ");
    fflush(stdin);
    gets(data.diaC);

    if(strlen(data.diaC) == 0){
        goto rDiaMorb;
    }

    for(i=0; i<data.diaC[i]; i++) {
        if(!(data.diaC[i]>='0' && data.diaC[i]<='9' && strlen(data.diaC)==2)){
            printf("\n---Data Inválida!---\n");
                goto rDiaMorb;
            break;
        }
        else{
            data.dia = atoi(data.diaC);
        }
    }
    rMesMorb:
    printf("\n        =>Mês mm: ");
    fflush(stdin);
    gets(data.mesC);


    if(strlen(data.mesC) == 0){
        goto rMesMorb;
    }

        for(i=0; i<data.mesC[i]; i++) {
        if(!(data.mesC[i]>='0' && data.mesC[i]<='9' && strlen(data.mesC)==2)){
            printf("\n---Mês Inválido!---\n");
                goto rMesMorb;
            break;
        }
        else{
            data.mes = atoi(data.mesC);
        }
    }
    rAnoMorb:
    printf("\n              =>Ano aaaa: ");
    fflush(stdin);
    gets(data.anoC);

    if(strlen(data.anoC) == 0){
        goto rAnoMorb;
    }


    for(i=0; i<data.anoC[i]; i++) {
        if(!(data.anoC[i]>='0' && data.anoC[i]<='9' && strlen(data.anoC)==4)){
            printf("\n---Ano Inválido!---\n");
                goto rAnoMorb;
            break;
        }
        else{
            data.ano = atoi(data.anoC);
        }
    }
    system("cls");
    printf("---------------------------------------------------");
    printf("Dados Residencial");

    rCep:
    printf("\Cep Local: ");
    fflush(stdin);
    gets(dados.cepC);

    if(strlen(dados.cepC) == 0){
        goto rCep;
    }

    for(i=0; i<dados.cepC[i]; i++) {
        if(!(dados.cepC[i]>='0' && dados.cepC[i]<='9'&&strlen(dados.cepC)<9)){
            printf("\n---Cep Inválido!---\n");
                goto rCep;
            break;
        }
        else{
            dados.cep = atoll(dados.cepC);
        }
    }
    printf("---------------------------------------------------");

    rRua:
    printf("\nRua: ");
    fflush(stdin);
    gets(dados.rua);

    if(strlen(dados.rua) == 0){
        goto rRua;
    }

    printf("---------------------------------------------------");

    rNumero:
    printf("\nNúmero: ");
    gets(dados.numeroC);

    if(strlen(dados.numeroC) == 0){
        goto rNumero;
    }

    printf("---------------------------------------------------");
    for(i=0; i<dados.numeroC[i]; i++) {
        if(!(dados.numeroC[i]>='0' && dados.numeroC[i]<='9'&& strlen(dados.numeroC)<11)){
            printf("Número Inválido!");
                goto rNumero;
            break;
        }
        else{
            dados.numero = atoll(dados.numeroC);
        }
    }

    rComplemento:
    printf("\nComplemento: ");
    gets(dados.complemento);

    if(strlen(dados.complemento) == 0){
        goto rComplemento;
    }


    printf("---------------------------------------------------");

    rCidade:
    printf("\nCidade: ");
    fflush(stdin);
    gets(dados.cidade);

    if(strlen(dados.cidade) == 0){
        goto rCidade;
    }

    for(i=0; i<dados.cidade[i];i++){
            fflush(stdin);
             if (dados.cidade[i] == ' '){
                    dados.cidade[i] = 'a';
                } if(dados.cidade[i] >= 'a' && dados.cidade[i] <= 'z' || dados.cidade[i] >= 'A' && dados.cidade[i] <= 'Z' || dados.cidade[i] == 'A'){
                    if(dados.cidade[i] == 'a'){
                            dados.cidade[i] = ' ';
                    }
                    }else
                    {
                        printf("\nCaracter inválido");
                        goto rCidade;
                        break;
                }
}

    printf("---------------------------------------------------");

    rBairro:
    printf("\nBairro: ");
    fflush(stdin);
    gets(dados.bairro);

    if(strlen(dados.bairro) == 0){
        goto rBairro;
    }
    printf("---------------------------------------------------");

    rEstado:
    printf("\nEstado: ");
    fflush(stdin);
    gets(dados.estado);

    if(strlen(dados.estado) == 0){
        goto rEstado;
    }

    printf("---------------------------------------------------");

    for(i=0; i<dados.estado[i];i++){
            fflush(stdin);
             if (dados.estado[i] == ' '){
                    dados.estado[i] = '�';
                } if(dados.estado[i] >= 'a' && dados.estado[i] <= 'z' || dados.estado[i] >= 'A' && dados.estado[i] <= 'Z' || dados.estado[i] == '�'){
                    if(dados.estado[i] == '�'){
                            dados.estado[i] = ' ';
                    }
                    }else
                    {
                        printf("\nCaracter invalido!");
                        goto rEstado;
                        break;
                }
}

    int opMorb; // caso o paciente tenha algum tipo de morbidade
    char opMorbC[3]; //Validação

    retornMorb : //retorna cadastro de morbidade
    system("cls");
    printf("  -------------------------------------------------");
    printf("\n  -O paciente possui algum tipo de morbidade?     -");
    printf("\n  -[1]Sim                                         -");
    printf("\n  -[2]Não                                         -\n");
    printf("  -------------------------------------------------");
    printf("\nEscolha a opção Desejada: ");
    fflush(stdin);
    gets(opMorbC);

    for(i=0; i<opMorbC[i];i++){
        if(strlen(opMorbC)==1 && opMorbC[i] =='1' || strlen(opMorbC)==1 && opMorbC[i] =='2' ){
            opMorb = atoi(opMorbC);
            break;
        }
        else{
            printf("Opção Invalida!");
            break;
        }

    }

    if(opMorb == 1 ) {
        printf("---------------------------------------------------");
        printf("\nMorbidade do Paciente: ");
        fflush(stdin);
        gets(morbidade);
    }

    else if( opMorb !=1 && opMorb !=2 ) {
        goto retornMorb;
    }

    printf("\n---Dados Cadastrados com Sucesso");

    int idade = 2020 - dados.ano;

    if (idade >= 65) {
            fprintf(ponteiro1, "\nIdade: %d",idade);
            fprintf(ponteiro1, "\nCep: %08lld\n\n", dados.cep);
            fprintf(ponteiro1, "\n\n\%s", tracos);
            fclose(ponteiro1);
    }

    fprintf(ponteiro2, "\nNome: %s\n", dados.nome);
    fprintf(ponteiro2, "\nData de Nascimento: %d/%d/%d", dados.dia,dados.mes,dados.ano);
    fprintf(ponteiro2, "\nIdade: %d",idade);
    fprintf(ponteiro2, "\nCpf: %011lld",cpf);
    fprintf(ponteiro2, "\nE-mail: %s", dados.email);
    fprintf(ponteiro2, "\nTelefone: %lld", dados.telefone);
    fprintf(ponteiro2, "\nTelefone 2: %lld", dados.telefone2);
    if (opMorb == 1){
        fprintf(ponteiro2, "Morbidade: %s", morbidade);
    } else {
        fprintf(ponteiro2, "Nenhuma Morbidade");

    }
    fprintf(ponteiro2, "Diagnosticado em: %d/%d/%d", data.dia,data.mes,data.ano);
    fprintf(ponteiro2, "Cep: %08lld", dados.cep);
    fprintf(ponteiro2, "Rua: %s", dados.rua);
    fprintf(ponteiro2, "Complemento: %s", dados.complemento);
    fprintf(ponteiro2, "Cidade: %s", dados.cidade);
    fprintf(ponteiro2, "Bairro: %s", dados.bairro);
    fprintf(ponteiro2, "Estado: %s", dados.estado);
    fprintf(ponteiro2, "%s", tracos);

    fclose(ponteiro2);
}
FILE *cadastrar; // Cadastrar login
FILE *logar;
char user[20];
char password[20];
char c; //Deletar
char str[20]; //armazenar user para consulta
char str2[20]; //armazenar senha para consulta
int rep =1;
void cadLogin(void){
    while(rep == 1){
    int opCadLogin;
    char opCadLoginC[2];
    teste:
    printf("************************SARS MANAGEMENT COVID19***********************\n");

    printf("\n                   -------------------------------------------------- ");
    printf("\n                  |               (1)Acessar Base                     |");
    printf("\n                  |          (2) Cadastrar Novo Paciente              |");
    printf("\n                  |                   (0) Sair                        |");
    printf("\n                   -------------------------------------------------- ");
    printf("\n\n  Digite o Desejado:    ");
    fflush(stdin);
    gets(opCadLoginC);
    for(i=0; i<opCadLoginC[i];i++){
        if(strlen(opCadLoginC)==1 && opCadLoginC[i] =='1' || strlen(opCadLoginC)==1 && opCadLoginC[i] =='2' || strlen(opCadLoginC)==1 && opCadLoginC[i] =='0' ){
            opCadLogin = atoi(opCadLoginC);
            break;
        }
        else{
            printf("Opção Inválida. Tente Novamente.");
            break;
        }

    }

    system("cls");

    switch(opCadLogin){
    case 1:
        logar = fopen("login.txt","r");
        printf("\  ---------------------------------------------------\n");
        printf("\n        Seja Bem vindo Digite Seus dados de acesso    ");
        printf("\n\n  ---------------------------------------------------\n\n");
        printf("  USUARIO: ");
        fflush(stdin);
        gets(user);
        printf("  SENHA: ");

        while((c=getch())!=13){
                if (c != 8)
                {
                    password[i] = c;
                    printf("*");
                    i++;
                }
                else
                {
                    i--;
                    if (i < 0)
                    {
                        i++;
                    }
                    else
                    {
                        printf("\b \b");
                    }
                }
            }
                  password[i]='\0';
                  i=0;

        printf("\n  ---------------------------------------------------");
        printf("\n  ***************************************************");
        if (logar == NULL) {
            printf("\n  Nenhum login e senha foi cadastrado ainda\n");
            printf("\n  Cadastre o usuario e senha\n");
            printf("\n  Pressione ENTER para retornar a tela inical...\n");
            scanf("ENTER");
            system("cls");

            return cadLogin();
            break;
        }
        while((fscanf(logar,"%s %s",&str, &str2)) !=EOF) {
                if ( ( strcmp( str, user) == 0) && ( strcmp( str2, password ) == 0 ))
                {

                    Beep(1200,200);
                    printf("\n Acesso concedido");
                    menu();
                    break;
        }
        system("cls");
        printf("\n  (User ou senha incorreto)\n");

        printf("\n  (Tente novamente!)\n");

        printf("\n  Pressione enter para retornar a tela inical...");

        Beep(565,2000);
        scanf("ENTER");
        system("cls");

        return cadLogin();
        //goto teste;
        break;
}
break;
fclose(logar);
    rCadLogin:
    case 2:
        cadastrar = fopen("login.txt", "a");

        if (cadastrar == NULL){
            printf("Erro na abertura do arquivo!");
        }

        struct user userPass;
        printf("\n  ---------------------------------------------------\n");
        printf("  \n             Cadastro De Usuario e Senha            ");
        printf("\n  ---------------------------------------------------\n");
        rUser:
        printf("\n  USUARIO: ");
        fflush(stdin);
        gets(userPass.user);

        if(strlen(userPass.user) == 0){
        goto rUser;
    }


        printf("\n  ---------------------------------------------------\n");
        rPassword:
        printf("\n  SENHA: ");
        fflush(stdin);
        gets(userPass.password);

        if(strlen(userPass.password) == 0){
        goto rPassword;
    }

        printf("\n  ---------------------------------------------------\n");

        fprintf(cadastrar, "\n%s", userPass.user);
        fprintf(cadastrar, "\n%s", userPass.password);

        printf("  Usuario e Senha Cadastrado com Sucesso ");
        printf(" Pressione enter para retornar a tela inical...");
        scanf("ENTER");
        system("cls");
        fclose(cadastrar);
        return cadLogin();
    case 0 :
            printf("\n--------------- Sistema Finalizado -------------------\n");
            rep = 0;
            rep = 0;
            break;

    default :
        printf("***Opção invalida***");
        return cadLogin();
        break;
    }
    }
}

int opMenu, opCadastro;
char opMenuC[2],opCadastroC[2];
void menu(void) {
    printf("\n  ---------------------------------------------------");
    printf("\n  -[1]Cadastrar Pacientes                           -");
    printf("\n  -[2]Voltar ao menu inicial                        -");
    printf("\n  ---------------------------------------------------");
    printf("\n   Digite o numero da opção:   ");
    fflush(stdin);
    gets(opMenuC);
    for(i=0; i<opMenuC[i];i++){
        if(strlen(opMenuC)==1 && opMenuC[i] =='1' || strlen(opMenuC)==1 && opMenuC[i] =='2' ){
            opMenu = atoi(opMenuC);
            break;
        }
        else{
            printf("Opção Inválida");
            break;
        }

    }
    system("cls");
        switch(opMenu) {
            teste:
            system("color E2");
            system("cls");
            case 1 : cadastro();
            printf("\n  ---------------------------------------------------");
            printf("\n  -Deseja Realizar outro Cadastro ?                -");
            printf("\n  -[1]Sim                                          -");
            printf("\n  -[2]Não                                          -");
            printf("\n  ---------------------------------------------------");
            printf("\n Digite o Numero da Opção:   ");
            fflush(stdin);
            gets(opCadastroC);

    for(i=0; i<opCadastroC[i];i++){
        if(strlen(opCadastroC)==1 && opCadastroC[i] =='1' || strlen(opCadastroC)==1 && opCadastroC[i] =='2' ){
            opCadastro= atoi(opCadastroC);
            break;
        }
        else{
            printf("Opção Invalida");
            break;
        }

    }
            system("cls");

            if(opCadastro == 1){
                goto teste;
            }

            if(opCadastro == 2){
                cadLogin();
            }

            case 2 :
            cadLogin();
            break;

            default : printf("Opção Invalida");
            return cadLogin();
            break;
    }

}
