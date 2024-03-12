/*Criar uma struct para armazenar um cliente, contendo os seguintes dados: nome, data de nascimento, idade e sexo.
O sexo é apenas uma letra (M ou F) e a data de nascimento deve ser armazenada numa struct de data, com 3 inteiros
(dia, mês e ano).
A idade deve ser calculada quando a data de nascimento for lida, e não solicitada ao usuário. 
Guarde a data atual numa variável da struct de data e crie uma função para calcular a idade.
Após isso, criar um menu com 2 opções: cadastrar cliente e listar clientes. 
Na primeira, um cliente deve ser lido e na segunda exibidos todos os clientes em ordem de cadastro.
Trate para que seu aplicativo armazene no máximo 50 clientes ao mesmo tempo.*/

#include <stdio.h>
#include <time.h>
#define MAX_CLIENTES 50

struct Data{
    
    int diaN;
    int mesN;
    int anoN;
   
    void calculoIdade(){
        struct tm *p;
        time_t seconds;

        time(&seconds);
        p = localtime(&seconds);

        int diaA = p->tm_mday;
        int mesA = p->tm_mon + 1;
        int anoA = p->tm_year + 1900;

        int idade = ((anoA * 365 + mesA * 30 + diaA) - (anoN * 365 + mesN * 30 + diaN)) / 365;
        printf("Idade = %d anos\n", idade);
    }
};

struct Cliente{
    
    Data dataNascimento;

    char nome[100];
    char sexo;

    void ler(){
        printf("Digite o nome do(a) cliente:");
        scanf("%[^\n]%*c", nome);
        printf("Digite o sexo do(a) cliente: ");
        scanf("%c%*c", &sexo);
        printf("Digite o dia do nascimento do(a) cliente: ");
        scanf("%d%*c", &dataNascimento.diaN);
        printf("Digite o mes do nascimento do(a) cliente: ");
        scanf("%d%*c", &dataNascimento.mesN);
        printf("Digite o ano do nascimento do(a) cliente: ");
        scanf("%d%*c", &dataNascimento.anoN);
        
    }

    void imprimir(){
        printf("Clientes cadastrados: \n");
        printf("Nome: %s\n", nome);
        printf("Sexo: %c\n", sexo);
        printf("Data de nascimento: %d/%d/%d\n", dataNascimento.diaN, dataNascimento.mesN, dataNascimento.anoN);
        dataNascimento.calculoIdade();
        printf("\n");
    }

};

struct Cadastrar{
    
    Cliente clientes[MAX_CLIENTES];
    int qtdClientes = 0;
    
    void ler(){
        if (qtdClientes >= MAX_CLIENTES){
            printf("Cadastro de clientes esta cheio.\n");
            return;
        }
        clientes[qtdClientes].ler();
        qtdClientes++;
    }

    void imprimir(){
        for(int i = 0; i < qtdClientes; i++){
            clientes[i].imprimir();
        }
    }

};


int main(){
    
    Cadastrar a;
    int opcao;

    do{
        printf("1. Cadastrar cliente.\n");
        printf("2. Listar clientes.\n");
        printf("3. Sair\n");
        printf("\n");
        scanf("%d%*c", &opcao);
        
        switch(opcao){
            case 1:
                a.ler();
                break;
            case 2:
                a.imprimir();
                break;            
        }
    }while (opcao !=3);
    
    return 0;
}
