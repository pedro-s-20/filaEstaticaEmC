/*
Fila Estática- Algoritmos e Estrutura de Dados II
Pedro Sousa
Engenharia da Computação
*/
#define MAX 5

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

// Definindo a estrutura da fila, onde o tamanho do vetor depende do define de MAX
typedef struct Fila{
	int inicio;
	int fim;
	int vetor[MAX];
}Fila;

// Função para iniciar a fila
Fila* iniciaFila(){
	
	// Criando um ponteiro tipo Fila
	Fila *f;
	// Alocando espaço para a Fila
	f = (Fila *)malloc(1*sizeof(Fila));
	
	f->inicio = 0;
	// Fim apontando para -1, assim, estará cheia quando fim deve ser igual a MAX-1
	f->fim = -1;
	
	return f;
}

// função para excluir a fila, excluindo o ponteiro
int excluirFila(Fila *f){
	free(f);
	return 1;
}

// função para ver se a fila está vazia
int estahVazia(Fila* f){
	// Estará vazia quando ainda não se estiver iniciado,
	// ou quando já tiver retirado todos os itens da fila, pois ao retirar se incrementa no início
	if((f->fim == -1) || (f->inicio > f->fim)){
		return 1;
	}else{
		return 0;
	}
	
}

// função para ver se a fila está cheia
int estahCheia(Fila* f){
	// estará cheia quando o fim for igual a MAX -1
	if(f->fim == MAX-1){
		return 1;
	}else{
		return 0;
	}
	
}

// função para inserir item na fila
int inserir(Fila *f, int v){
	
	if(estahCheia(f) == 1){
		return 0;	
	}else{
		f->fim++;
		f->vetor[f->fim] = v;
		return 1;
	}
	
}

// função para retirar itens na fila
int retirar(Fila *f, int *v){
	if(estahVazia(f) == 1){
		return 0;
	}else{
		*v = f->vetor[f->inicio];
		f->inicio++;
		return 1;
	}
}

// função para ver o próximo item da fila
int proximoFila(Fila *f){
	if(estahVazia(f) == 1){
		return 0;
	}else{
		return f->vetor[f->inicio];
	}
}

// função para ver o último item da fila 
int ultimoFila(Fila *f){
	if(estahVazia(f) == 1){
		return 0;
	}else{
		return f->vetor[f->fim];
	}
}

// menu para se escolher as opções de uso das funções
int menuOpc(){
	
	int opc = 0;
	
	printf("\nEscolha uma opção:\n");
	printf("\n[1] - Criar fila");
	printf("\n[2] - Liberar fila");
	printf("\n[3] - Inserir item na fila");
	printf("\n[4] - Retirar item da fila");
	printf("\n[5] - Imprime próximo da fila");
	printf("\n[6] - Imprime último da fila");
	printf("\n[7] - Verificar se a fila está vazia");
	printf("\n[8] - Verificar se a fila está cheia");
	printf("\n[9] - Sair\n");
	scanf("%i", &opc);
	fflush(stdin);
		
	system("cls");
	
	return opc;
}

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int respMenu = 0, temFila = 0, v = 0;
	char sair = 'a';
	Fila *f;
	int retirado;
	int retornoUltimoOuInicio = 0;
	
	// navegando entre as opções escolhidas pelo usuário, enquanto ele desejar continuar utilizando o programa
	do{
		respMenu = menuOpc();
		switch(respMenu){
			
			case 1:
				system("cls");
				f = iniciaFila();
				temFila++;
				printf("\nFila criada com sucesso!\n");
				respMenu = 10;
				break;
				
			case 2:
				system("cls");
				if(temFila>0){
					excluirFila(f);
					temFila--;
					printf("\nFilha liberada com sucesso!\n");
				}else{
					printf("\nNão há fila para liberar.\n");
				}
				respMenu = 10;
				break;
				
			case 3:
				system("cls");
				if(temFila>0){
					printf("\nDigite o valor que deseja inserir na Fila: \n");
					scanf("%i", &v);
					fflush(stdin);
					if(inserir(f, v) == 1){
						printf("\nItem [%i] inserido na Fila com sucesso! \n", f->vetor[f->fim]);
					}else{
						printf("\nNão foi possível inserir item na fila pois ela está cheia\n");
					}
				}else{
					printf("\nNão há fila para inserir.\n");
				}
				respMenu = 10;
				break;
				
			case 4:
				system("cls");
				if(temFila>0){
					fflush(stdin);
					if(retirar(f, &retirado) == 1){
						printf("\nItem [%i] foi retirado da Fila com sucesso! \n", retirado);
					}else{
						printf("\nNão foi possível retirar item da fila pois ela está vazia\n");
					}
					
				}else{
					printf("\nNão há fila para retirar item.\n");
				}
				respMenu = 10;
				break;
			
			case 5:
				system("cls");
				retornoUltimoOuInicio = proximoFila(f);
				if(retornoUltimoOuInicio == 0){
					printf("\nNão há fila para imprimir item.\n");
				}else{
					printf("O próximo da fila é o: %i", retornoUltimoOuInicio);
				}
				respMenu = 10;
				
			case 6:
				system("cls");
				retornoUltimoOuInicio = ultimoFila(f);
				if(retornoUltimoOuInicio == 0){
					printf("\nNão há fila para imprimir item.\n");
				}else{
					printf("O último da fila é o: %i", retornoUltimoOuInicio);
				}	
				respMenu = 10;
				
			case 7:
				system("cls");
				if(temFila>0){
					if(estahVazia(f) == 1){
						printf("\nA fila está vazia.\n");
					}else{
						printf("\nHá itens na fila.\n");
					}
				}else{
					printf("\nNão há fila para verificar.\n");
				}
				respMenu = 10;
				break;
				
			case 8:
				system("cls");
				if(temFila>0){
					if(estahCheia(f) == 1){
						printf("\nA fila está cheia.\n");
					}else{
						printf("\nHá espaço na fila.\n");
					}
				}else{
					printf("\nNão há fila para verificar.\n");
				}
				respMenu = 10;
				break;
				
			case 9:
				system("cls");
				do{
					printf("\nDeseja realmente sair?(s/n)\n");
					scanf("%s", &sair);
					fflush(stdin);
				}while(sair != 'n' && sair != 's');
				if(sair == 'n'){
					respMenu = 10;
					break;
				}else{
						printf("\nObrigado por usar o programa!\n");
						break;
					}
			default:
				printf("\nOpção inválida, digite novamente. \n");
				respMenu = 10;
				break;
				
		}
	}while(respMenu < 1 || respMenu > 9);
	
	system("exit");
	
	return 0;
}
