/*
Fila Est�tica- Algoritmos e Estrutura de Dados II
Pedro Sousa
Engenharia da Computa��o
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

// Fun��o para iniciar a fila
Fila* iniciaFila(){
	
	// Criando um ponteiro tipo Fila
	Fila *f;
	// Alocando espa�o para a Fila
	f = (Fila *)malloc(1*sizeof(Fila));
	
	f->inicio = 0;
	// Fim apontando para -1, assim, estar� cheia quando fim deve ser igual a MAX-1
	f->fim = -1;
	
	return f;
}

// fun��o para excluir a fila, excluindo o ponteiro
int excluirFila(Fila *f){
	free(f);
	return 1;
}

// fun��o para ver se a fila est� vazia
int estahVazia(Fila* f){
	// Estar� vazia quando ainda n�o se estiver iniciado,
	// ou quando j� tiver retirado todos os itens da fila, pois ao retirar se incrementa no in�cio
	if((f->fim == -1) || (f->inicio > f->fim)){
		return 1;
	}else{
		return 0;
	}
	
}

// fun��o para ver se a fila est� cheia
int estahCheia(Fila* f){
	// estar� cheia quando o fim for igual a MAX -1
	if(f->fim == MAX-1){
		return 1;
	}else{
		return 0;
	}
	
}

// fun��o para inserir item na fila
int inserir(Fila *f, int v){
	
	if(estahCheia(f) == 1){
		return 0;	
	}else{
		f->fim++;
		f->vetor[f->fim] = v;
		return 1;
	}
	
}

// fun��o para retirar itens na fila
int retirar(Fila *f, int *v){
	if(estahVazia(f) == 1){
		return 0;
	}else{
		*v = f->vetor[f->inicio];
		f->inicio++;
		return 1;
	}
}

// fun��o para ver o pr�ximo item da fila
int proximoFila(Fila *f){
	if(estahVazia(f) == 1){
		return 0;
	}else{
		return f->vetor[f->inicio];
	}
}

// fun��o para ver o �ltimo item da fila 
int ultimoFila(Fila *f){
	if(estahVazia(f) == 1){
		return 0;
	}else{
		return f->vetor[f->fim];
	}
}

// menu para se escolher as op��es de uso das fun��es
int menuOpc(){
	
	int opc = 0;
	
	printf("\nEscolha uma op��o:\n");
	printf("\n[1] - Criar fila");
	printf("\n[2] - Liberar fila");
	printf("\n[3] - Inserir item na fila");
	printf("\n[4] - Retirar item da fila");
	printf("\n[5] - Imprime pr�ximo da fila");
	printf("\n[6] - Imprime �ltimo da fila");
	printf("\n[7] - Verificar se a fila est� vazia");
	printf("\n[8] - Verificar se a fila est� cheia");
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
	
	// navegando entre as op��es escolhidas pelo usu�rio, enquanto ele desejar continuar utilizando o programa
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
					printf("\nN�o h� fila para liberar.\n");
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
						printf("\nN�o foi poss�vel inserir item na fila pois ela est� cheia\n");
					}
				}else{
					printf("\nN�o h� fila para inserir.\n");
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
						printf("\nN�o foi poss�vel retirar item da fila pois ela est� vazia\n");
					}
					
				}else{
					printf("\nN�o h� fila para retirar item.\n");
				}
				respMenu = 10;
				break;
			
			case 5:
				system("cls");
				retornoUltimoOuInicio = proximoFila(f);
				if(retornoUltimoOuInicio == 0){
					printf("\nN�o h� fila para imprimir item.\n");
				}else{
					printf("O pr�ximo da fila � o: %i", retornoUltimoOuInicio);
				}
				respMenu = 10;
				
			case 6:
				system("cls");
				retornoUltimoOuInicio = ultimoFila(f);
				if(retornoUltimoOuInicio == 0){
					printf("\nN�o h� fila para imprimir item.\n");
				}else{
					printf("O �ltimo da fila � o: %i", retornoUltimoOuInicio);
				}	
				respMenu = 10;
				
			case 7:
				system("cls");
				if(temFila>0){
					if(estahVazia(f) == 1){
						printf("\nA fila est� vazia.\n");
					}else{
						printf("\nH� itens na fila.\n");
					}
				}else{
					printf("\nN�o h� fila para verificar.\n");
				}
				respMenu = 10;
				break;
				
			case 8:
				system("cls");
				if(temFila>0){
					if(estahCheia(f) == 1){
						printf("\nA fila est� cheia.\n");
					}else{
						printf("\nH� espa�o na fila.\n");
					}
				}else{
					printf("\nN�o h� fila para verificar.\n");
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
				printf("\nOp��o inv�lida, digite novamente. \n");
				respMenu = 10;
				break;
				
		}
	}while(respMenu < 1 || respMenu > 9);
	
	system("exit");
	
	return 0;
}
