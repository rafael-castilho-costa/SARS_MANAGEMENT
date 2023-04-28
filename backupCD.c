#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

struct infoCampos {

    char nome[60];
    int dia;
    char diaS[15]; 
    int mes; 
    char mesS[4]; 
    int ano; 
    char anoC[6]; 
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
    char complemento[50];
    long long cep;
    char cepC[9];
};

struct CPF {

    char cpfC[12];

};

struct diagnostico {
    int dia;
    char diaS[3];
    int mes;
    char mesS[3];
    int ano;
    char anoC[5];
};

struct user{
    char user[20];
    char password[20];
};


void cadastro(void);
void cadLogin(void); //Cadastro e login
void menu(void);


char teste();

int continua = 1;

char morbidade [60];


int main(){
    system("color E2");
    system("cls");

//morbidades
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
    struct campos dados ;
    struct diagnostico data;
    int opCadNtelefone;

    system("cls");
    printf("\n******************Dados Pessoais*******************\n");
    printf("\n---------------------------------------------------");
	
	
    char login[12];
    FILE *pontCadCpf;
    pontCadCpf = fopen ("cpf.txt","a");
    rCpf:
	
    printf("\nDigite o CPF.\n");
    printf("\nCPF: ");
	
    fflush(stdin);
    gets(cadCpf.cpfC);

     if(strlen(cadCpf.cpfC) == 0){
        goto rCpf;
    }

    for(i=0; i<cadCpf.cpfC[i]; i++) {
        if(!(cadCpf.cpfC[i]>='0' && cadCpf.cpfC[i]<='9' && strlen(cadCpf.cpfC)==11)){
            printf("\nInvalido. Tente Novamente!\n");
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
                    printf("\n\n CPF já Cadastrado.\n");
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

    //Inicio For
    for(i=0; i<dados.nome[i];i++){
            fflush(stdin);
             if (dados.nome[i] == ' '){
                    dados.nome[i] = 'a';
                } if(dados.nome[i] >= 'a' && dados.nome[i] <= 'z' || dados.nome[i] >= 'A' && dados.nome[i] <= 'Z' || dados.nome[i] == '�'){
                    if(dados.nome[i] == 'a'){
                            dados.nome[i] = ' ';
                    }
                    }else
                    {
                        printf("\nCaracter invalido.");
                        goto rNome;
                        break;
                }
}
//fim for
    printf("---------------------------------------------------");

    printf("\n Data de Nascimento");
    rDiaNascimento:
    printf("\n    =>DIA dd : ");
    fflush(stdin);
    gets(dados.diaS);


     if(strlen(dados.diaS) == 0){
        goto rDiaNascimento;
    }



    for(i=0; i<dados.diaS[i]; i++) {
        if(!(dados.diaS[i]>='0' && dados.diaS[i]<='9' && strlen(dados.diaS)==2)){
            printf("\nInvalido. Tente Novamente!\n");
                goto rDiaNascimento;
            break;
        }
        else{
            dados.dia = atoi(dados.diaS);
        }
    }
    rMesNascimento:
    printf("          =>Mes mm : ");
    fflush(stdin);
    gets(dados.mesS);

    if(strlen(dados.mesS) == 0){
        goto rMesNascimento;
    }

    for(i=0; i<dados.mesS[i]; i++) {
        if(!(dados.mesS[i]>='0' && dados.mesS[i]<='9' && strlen(dados.mesS)==2)){
            printf("\nInvalido. Tente Novamente!\n");
                goto rMesNascimento;
            break;
        }
        else{
            dados.mes = atoi(dados.mesS);
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
            printf("\nInvalido. Tente Novamente!\n");
                goto rAnoNascimento;
            break;
        }
        else{
            dados.ano = atoi(dados.anoC);
        }
    }

    rEmail:
    printf("\nEMAIL: ");
    fflush(stdin);
    gets(dados.email);
    printf("---------------------------------------------------");


    if(strlen(dados.email) == 0){
        goto rEmail;
    }

    rTelefone:
    printf("\n\n�NUMERO DE TELEFONE\n\n");
    printf("***Cadastre at� dois n�meros de telefone\n");
    printf("Digite os n�meros todos juntos XXXX...\n\n");
    printf("INFORME O N� DE TELEFONE PRINCIPAL: ");
    fflush(stdin);
    gets(dados.telefoneC);
    printf("---------------------------------------------------");

    if(strlen(dados.telefoneC) == 0){
        goto rTelefone;
    }

    for(i=0; i<dados.telefoneC[i]; i++) {
        if(!(dados.telefoneC[i]>='0' && dados.telefoneC[i]<='9')){
            printf("\n***Inv�lido. \nVerifique se digitou apenas numeros\n***");
                goto rTelefone;
            break;
        }
        else{
            dados.telefone = atoll(dados.telefoneC);
        }
    }

    rTelefone2:
    printf("\n\nINFORME O N� DE TELEFONE 2: ");
    fflush(stdin);
    gets(dados.telefone2C);

    if(strlen(dados.telefone2C) == 0){
        goto rTelefone2;
    }

    for(i=0; i<dados.telefone2C[i]; i++) {
        if(!(dados.telefone2C[i]>='0' && dados.telefone2C[i]<='9')){
            printf("\n***Inv�lido. \nVerifique se digitou apenas numeros\n***");
                goto rTelefone2;
            break;
        }
        else{
            dados.telefone2 = atoll(dados.telefone2C);
        }
    }
    system("cls");
    printf("---------------------------------------------------");
    printf("\n�DATA DO DIAGN�STICO DE COVID 19");
    rDiaMorb:
    printf("\n   =>DIA dd: ");
    fflush(stdin);
    gets(data.diaS);

    if(strlen(data.diaS) == 0){
        goto rDiaMorb;
    }

    for(i=0; i<data.diaS[i]; i++) {
        if(!(data.diaS[i]>='0' && data.diaS[i]<='9' && strlen(data.diaS)==2)){
            printf("\nInvalido. Tente Novamente!\n");
                goto rDiaMorb;
            break;
        }
        else{
            data.dia = atoi(data.diaS);
        }
    }
    rMesMorb:
    printf("\n        =>M�S mm: ");
    fflush(stdin);
    gets(data.mesS);


    if(strlen(data.mesS) == 0){
        goto rMesMorb;
    }

        for(i=0; i<data.mesS[i]; i++) {
        if(!(data.mesS[i]>='0' && data.mesS[i]<='9' && strlen(data.mesS)==2)){
            printf("\nInvalido. Tente Novamente!\n");
                goto rMesMorb;
            break;
        }
        else{
            data.mes = atoi(data.mesS);
        }
    }
    rAnoMorb:
    printf("\n              =>ANO aaaa: ");
    fflush(stdin);
    gets(data.anoC);

    if(strlen(data.anoC) == 0){
        goto rAnoMorb;
    }


    for(i=0; i<data.anoC[i]; i++) {
        if(!(data.anoC[i]>='0' && data.anoC[i]<='9' && strlen(data.anoC)==4)){
            printf("\nInvalido. Tente Novamente!\n");
                goto rAnoMorb;
            break;
        }
        else{
            data.ano = atoi(data.anoC);
        }
    }
    system("cls");
    printf("---------------------------------------------------");
    printf("\n\n�Dados de Endere�o\n\n");

    rCep:
    printf("\CEP: ");
    fflush(stdin);
    gets(dados.cepC);

    if(strlen(dados.cepC) == 0){
        goto rCep;
    }

    for(i=0; i<dados.cepC[i]; i++) {
        if(!(dados.cepC[i]>='0' && dados.cepC[i]<='9'&&strlen(dados.cepC)<9)){
            printf("\n******Inv�lido. \nVerifique se digitou apenas numeros \n e se n�o excedeu ou n�o atingiu a quantidade permitida\nDigite os 8 n�meros do CEP***");
                goto rCep;
            break;
        }
        else{
            dados.cep = atoll(dados.cepC);
        }
    }
    printf("---------------------------------------------------");

    rRua:
    printf("\nRUA: ");
    fflush(stdin);
    gets(dados.rua);

    if(strlen(dados.rua) == 0){
        goto rRua;
    }

    printf("---------------------------------------------------");

    rNumero:
    printf("\nN�MERO: ");
    gets(dados.numeroC);

    if(strlen(dados.numeroC) == 0){
        goto rNumero;
    }

    printf("---------------------------------------------------");
    for(i=0; i<dados.numeroC[i]; i++) {
        if(!(dados.numeroC[i]>='0' && dados.numeroC[i]<='9'&& strlen(dados.numeroC)<11)){
            printf("\nInvalido. Tente Novamente!\n");
                goto rNumero;
            break;
        }
        else{
            dados.numero = atoll(dados.numeroC);
        }
    }

    rComplemento:
    printf("\nCOMPLEMENTO: ");
    gets(dados.complemento);

    if(strlen(dados.complemento) == 0){
        goto rComplemento;
    }


    printf("---------------------------------------------------");

    rCidade:
    printf("\nCIDADE: ");
    fflush(stdin);
    gets(dados.cidade);

    if(strlen(dados.cidade) == 0){
        goto rCidade;
    }

    for(i=0; i<dados.cidade[i];i++){
            fflush(stdin);
             if (dados.cidade[i] == ' '){
                    dados.cidade[i] = '�';
                } if(dados.cidade[i] >= 'a' && dados.cidade[i] <= 'z' || dados.cidade[i] >= 'A' && dados.cidade[i] <= 'Z' || dados.cidade[i] == '�'){
                    if(dados.cidade[i] == '�'){
                            dados.cidade[i] = ' ';
                    }
                    }else
                    {
                        printf("\n***Caracter inv�lido. Informe apenas letras***");
                        goto rCidade;
                        break;
                }
}
//fim for

    printf("---------------------------------------------------");

    rBairro:
    printf("\nBAIRRO: ");
    fflush(stdin);
    gets(dados.bairro);

    if(strlen(dados.bairro) == 0){
        goto rBairro;
    }
    printf("---------------------------------------------------");

    rEstado:
    printf("\nESTADO: ");
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
                        printf("\n***Caracter inv�lido. Informe apenas letras***");
                        goto rEstado;
                        break;
                }
}
//fim for
    int opMorb; //Op��o referente caso o paciente tenha algum tipo de morbidade
    char opMorbC[3]; //Validado

    retornMorb : //retorna cadastro de morbidade
    system("cls");
    printf("  -------------------------------------------------");
    printf("\n  -O paciente possui algum tipo de morbidade?     -");
    printf("\n  -[1]SIM                                         -");
    printf("\n  -[2]N�O                                         -\n");
    printf("  -------------------------------------------------");
    printf("\nEscolha a op��o dejesada: ");
    fflush(stdin);
    gets(opMorbC); //op morbidade

    for(i=0; i<opMorbC[i];i++){
        if(strlen(opMorbC)==1 && opMorbC[i] =='1' || strlen(opMorbC)==1 && opMorbC[i] =='2' ){
            opMorb = atoi(opMorbC);
            break;
        }
        else{
            printf("Op��o inv�lida");
            break;
        }

    }

    if(opMorb == 1 ) {
        printf("---------------------------------------------------");
        printf("\nMORBIDADE DO PACIENTE: ");
        fflush(stdin);
        gets(morbidade);
    }

    else if( opMorb !=1 && opMorb !=2 ) {
        goto retornMorb;
    }

    printf("\n\nDADOS CADASTRADOS COM SUCESSO!\n\n");

    int idade = 2020 - dados.ano; //ano dignostico - ano idade

    if (idade >= 65) {
            fprintf(ponteiro1, "\nIDADE: %d",idade);
            fprintf(ponteiro1, "\nCEP: %08lld\n\n", dados.cep);
            fprintf(ponteiro1, "\n\n\%s", tracos);
            fclose(ponteiro1);
    }

    fprintf(ponteiro2, "\nNOME: %s\n", dados.nome);
    fprintf(ponteiro2, "\nDATA DE NASCIMENTO: %d/%d/%d", dados.dia,dados.mes,dados.ano);
    fprintf(ponteiro2, "\nIDADE: %d",idade);
    fprintf(ponteiro2, "\nCPF: %011lld",cpf);
    fprintf(ponteiro2, "\nEMAIL: %s", dados.email);
    fprintf(ponteiro2, "\nTELEFONE: %lld", dados.telefone);
    fprintf(ponteiro2, "\nTELEFONE 2: %lld", dados.telefone2);
    if (opMorb == 1){
        fprintf(ponteiro2, "\nMORBIDADE: %s", morbidade);
    } else {
        fprintf(ponteiro2, "\nMORBIDADE: NENHUMA");

    }
    fprintf(ponteiro2, "\nDIAGN�STICO REALIZADO EM: %d/%d/%d", data.dia,data.mes,data.ano);
    fprintf(ponteiro2, "\nCEP: %08lld", dados.cep);
    fprintf(ponteiro2, "\nRUA: %s", dados.rua);
    fprintf(ponteiro2, "\nCOMPLEMENTO: %s", dados.complemento);
    fprintf(ponteiro2, "\nCIDADE: %s", dados.cidade);
    fprintf(ponteiro2, "\nBAIRRO: %s", dados.bairro);
    fprintf(ponteiro2, "\nESTADO: %s", dados.estado);
    fprintf(ponteiro2, "\n\n\%s", tracos);

    fclose(ponteiro2);
}//Fim funcao cadastro
FILE *cadastrar; // Cadastrar login
FILE *logar;
char user[20];
char password[20];
char c; //apagar
char str[20]; //ARMAZENA O USUARIO PARA CONSULTA
char str2[20]; //ARMAZENA A SENHA PARA CONSULTA
int rep =1;
void cadLogin(void){
    while(rep == 1){
    int opCadLogin;
    char opCadLoginC[2];
    teste:
    printf("......................................................................................\n");
    printf("........CCCCC..............AAA..........DDDDDDDDD.............11..........99999.......\n");
    printf("......CC~~~~~CC...........AA=AA.........DD~~~~~~~DD.........1111........99~~~~~99.....\n");
    printf("....CC~~~~~~~~~CC........AA~~~AA........DD~~~~~~~~~DD......11.11.......99~~~~~~~~99...\n");
    printf("....CC~~~~~~~~~........AA~~~~~~~AA......DD~~~~~~~~~~DD........11........99~~~~~~999...\n");
    printf("....CC~~~~~~~~~.......AAAAAAAAAAAAA.....DD~~~~~~~~~~DD........11.........9999999999...\n");
    printf("....CC~~~~~~~~~CC....AA~~~~~~~~~~~AA....DD~~~~~~~~~DD.........11.................99...\n");
    printf("......CC~~~~~CC.....AA~~~~~~~~~~~~~AA...DD~~~~~~~DD...........11........99......99....\n");
    printf("........CCCCC......AA~~~~~~~~~~~~~~~AA..DDDDDDDDD............1111.........999999......\n");
    printf("......................................................................................\n");

    printf("\n                   ***************************************************");
    printf("\n                   *               [1]LOGAR NO SISTEMA               *");
    printf("\n                   *          [2]CADASTRAR USU�RIO E SENHA           *");
    printf("\n                   *                    [0]SAIR                      *");
    printf("\n                   ***************************************************");
    printf("\n\n  Digite o n�mero da op��o:    ");
    fflush(stdin);
    gets(opCadLoginC);
    for(i=0; i<opCadLoginC[i];i++){
        if(strlen(opCadLoginC)==1 && opCadLoginC[i] =='1' || strlen(opCadLoginC)==1 && opCadLoginC[i] =='2' || strlen(opCadLoginC)==1 && opCadLoginC[i] =='0' ){
            opCadLogin = atoi(opCadLoginC);
            break;
        }
        else{
            printf("Op��o inv�lida");
            break;
        }

    }

    system("cls");

    switch(opCadLogin){
    case 1:
        logar = fopen("login.txt","r");
        printf("\  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
        printf("\n                      LOGIN                             ");
        printf("\n\n  ---------------------------------------------------\n\n");
        printf("  USUARIO: ");
        fflush(stdin);
        gets(user);
        printf("\n  ---------------------------------------------------\n\n");
        printf("  SENHA: ");

        while((c=getch())!=13){ //13 � o valor de ENTER na tabela ASCII
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
        printf("\n\n  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
        if (logar == NULL) {
            printf("\n  Nenhum login e senha foi cadastrado ainda");
            printf("\n  *Cadastre o usuario e senha\n\n");
            printf("\n  Pressione ENTER para retornar a tela inical...");
            scanf("ENTER");
            system("cls");

            return cadLogin();
            break;
        }
        while((fscanf(logar,"%s %s",&str, &str2)) !=EOF) {
                if ( ( strcmp( str, user) == 0) && ( strcmp( str2, password ) == 0 ))
                {

                    Beep(1200,200);
                    printf("\n   Logado com sucesso");
                    menu();
                    break;
        }
        system("cls");
        printf("\n  (Usu�rio e/ou senha incorreto)\n");
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

        struct user userPass; //STRUCT USUARIO E SENHA
        printf("  \n             CADASTRO DE USU�RIO E SENHA            ");
        printf("\n\n  ---------------------------------------------------\n");
        rUser:
        printf("\n  USU�RIO: ");
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

        printf("  USU�RIO E SENHA CADASTRADO COM SUCESSO\n");
        printf("\n  Pressione enter para retornar a tela inical...");
        scanf("ENTER");
        system("cls");
        fclose(cadastrar);
        return cadLogin();
    case 0 :
            printf("\n\n***************SISTEMA FINALIZADO*******************\n\n");
            printf("\n\DICA: (Se quiser pesquisar um determinado paciente\nutilize o atalho CTRL+F dentro do arquivo e\nfiltre o paciente pelo nome, cpf, idade etc.)\n\n\n");
            rep = 0;
            rep = 0;
            break;

    default :
        printf("\n***Op��o Inv�lida***\n\n");
        return cadLogin();
        break;
    }
    }
}//Fim cadLogin

int opMenu, opCadastro;
char opMenuC[2],opCadastroC[2];
void menu(void) {
    printf("\n  ---------------------------------------------------");
    printf("\n  -[1]CADASTRAR PACIENTES                           -");
    printf("\n  -[2]Voltar ao menu inicial                        -");
    printf("\n  ---------------------------------------------------");
    printf("\n   Digite o n�mero da op��o:   ");
    fflush(stdin);
    gets(opMenuC);
    for(i=0; i<opMenuC[i];i++){
        if(strlen(opMenuC)==1 && opMenuC[i] =='1' || strlen(opMenuC)==1 && opMenuC[i] =='2' ){
            opMenu = atoi(opMenuC);
            break;
        }
        else{
            printf("Op��o inv�lida");
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
            printf("\n  -Deseja realizar um novo cadastro?                -");
            printf("\n  -[1]SIM                                           -");
            printf("\n  -[2]N�O                                           -");
            printf("\n  ---------------------------------------------------");
            printf("\n Digite o n�mero da op��o:   ");
            fflush(stdin);
            gets(opCadastroC);

    for(i=0; i<opCadastroC[i];i++){
        if(strlen(opCadastroC)==1 && opCadastroC[i] =='1' || strlen(opCadastroC)==1 && opCadastroC[i] =='2' ){
            opCadastro= atoi(opCadastroC);
            break;
        }
        else{
            printf("Op��o inv�lida");
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

            default : printf("\n\nOpc�o Inv�lida");
            return cadLogin();
            break;
    }

}