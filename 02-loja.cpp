/*Uma loja precisa controlar a folha de pagamento de seus funcionários. Os atributos de um funcionário são nome, 
cargo, salário base, benefícios e descontos.
Criar uma struct para a loja e cadastrar uma lista de no máximo 10 funcionários com os campos acima 
e depois mostre os dados de cada um deles, com o salário liquido de cada um. 
O cálculo do salário líquido é: salário base + benefícios – descontos.
Criar operações também para exibir a média salarial da loja e exibir quem recebe o maior salário.*/
#include <stdio.h>
#define MAX_FUNC 10

struct Funcionario{

    char nome[100];
    char cargo[30];
    double salarioB, beneficios, descontos, salarioL;

    void ler(){
        printf("Digite o nome do funcionario: ");
        scanf("%[^\n]%*c", nome);
        printf("Digite o cargo do funcionario: ");
        scanf("%[^\n]%*c", cargo);
        printf("Digite o salario do funcionario: ");
        scanf("%lf%*c", &salarioB);
        printf("Digite o valor dos beneficios: ");
        scanf("%lf%*c", &beneficios);
        printf("Digite o valor dos descontos: ");
        scanf("%lf%*c", &descontos);

        salarioL = salarioB + beneficios - descontos;

    }

    void imprimir(){
        printf("NOME: %s\n", nome);
        printf("CARGO: %s\n", cargo);
        printf("BENEFICIOS: %.2lf\n", beneficios);
        printf("DESCONTOS: -%.2lf\n", descontos);
        printf("SALARIO LIQUIDO: %.2lf\n", salarioL);
    }
};

struct FolhaPagamento{
    
    Funcionario funcionarios[MAX_FUNC];
    int qtdFuncionarios = 0;

    void ler(){
        if(qtdFuncionarios >= MAX_FUNC){
            printf("Quantidade de funcionarios excedida.");
            return;
        }
        funcionarios[qtdFuncionarios].ler();
        qtdFuncionarios++;
    }

    void imprimir(){
        for(int i = 0; i < qtdFuncionarios; i++){
            funcionarios[i].imprimir();
            printf("\n");
        }
    }

    void mediaSalarial(){
        
        double media = 0, soma = 0;
        for(int i = 0; i < qtdFuncionarios; i++){
            soma += funcionarios[i].salarioL;
        }
        media = soma/qtdFuncionarios;
        printf("MEDIA SALARIAL DA LOJA: R$%.2lf\n", media);
    }

    void maiorSalario(){
        double maior = 0;
        maior = funcionarios[0].salarioL;
        int posMaior = 0;
        for(int i = 0; i < qtdFuncionarios; i++){
            if(funcionarios[i].salarioL > maior){
                maior = funcionarios[i].salarioL;
                posMaior = i;
            }
        }
        printf("FUNCIONARIO QUE POSSUI MAIOR SALARIO: %s\n", funcionarios[posMaior].nome);
    }

};

int main(){

    int opcao;
    FolhaPagamento a;

    do{
        printf("1. Cadastrar funcionario.\n");
        printf("2. Listar funcionarios.\n");
        printf("3. Exibir media salarial\n");
        printf("4. Exibir quem é o maior salário\n");
        printf("5. Sair\n");
        printf("\n");
        scanf("%d%*c", &opcao);
        
        switch(opcao){
            case 1:
                a.ler();
                break;
            case 2:
                a.imprimir();
                break;  
            case 3:
                a.mediaSalarial();
                break; 
            case 4:
                a.maiorSalario();
                break;             
        }
    }while (opcao !=5);

    return 0;
}