#include <stdio.h>
#include <stdlib.h>

/* @Victor Yuiti Sather Umezu */

typedef struct{
    int dia, mes, ano;
}DataNas;

typedef struct{
    DataNas dataNas;
    int idade;
    char sexo;
    char nome[100];
}Cliente;

// Procedimento para imprimir os dados de um Cliente
void imprimirCliente(Cliente c){
    printf("\n\tNome: %s", c.nome);
    printf("\tIdade: %d\n", c.idade);
    printf("\tSexo: %c\n", c.sexo);
    printf("\tData de nas.: %d/%d/%d\n\n", c.dataNas.dia, c.dataNas.mes, c.dataNas.ano);
}

// função que lê os dados de um Cliente e retorna para quem chamou
Cliente lerCliente(){
    Cliente c;
    printf("\nDigite seu nome: ");
    scanf("%s", &c.nome);
    scanf("%c");// scanf("%c") somente para debugar!!
    printf("\nDigite F ou M para o sexo: ");
    scanf("%c", &c.sexo);
    scanf("%c");
    printf("\nDigite sua data de nascimento no formato dd mm aaaa: ");
    scanf("%d%d%d", &c.dataNas.dia, &c.dataNas.mes, &c.dataNas.ano);
    scanf("%c");
    c.idade = 2023 - c.dataNas.ano;
    
    return c;
}

int main() {
    int i;
    int posicaoAtual = 0;
    Cliente clientes[50];
    int escolha;
    
    //Menu básico feito com switch e laço de repetição!
    do{
	
	escolha = 0;
	
	printf("[1] Cadastrar cliente\n");
	printf("[2] Listar clientes\n");
	printf("[3] Sair\n");
	printf("Escolha: ");
	scanf("%d", &escolha);
	scanf("%c");

	switch(escolha)
	{
		case 1:
		{
					
			clientes[posicaoAtual] = lerCliente();
			posicaoAtual++;
			break;
		}
		
		case 2:
		{
			
			for(i = 0; i < posicaoAtual; i++){
				imprimirCliente(clientes[i]);
			}
			break;
		}
		
		case 3:
		{
			exit(3);
			
			break;
		}
		default:
			break;
	}	
			
} while(escolha != 3);

    return 0;
}