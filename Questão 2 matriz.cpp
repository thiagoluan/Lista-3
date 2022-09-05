//Declaração das bibliotecas
#include <stdio.h>
#include  <stdlib.h>

//Função para verificar se o número digitado pelo usuário está na matriz ou não
int mat(int **matriz, int linha, int coluna, int num){
	
	//A variável "i" é o contador que percorre as linhas e o "j" as colunas
	int j, i, r;
	for(i = 0; i<linha; i++){
		for(j = 0; j<coluna; j++){
			
			//Se o valor inserido pelo usuário for igual o valor que tem na matriz, retorna "1" para o usuário
			if(matriz[i][j] == num){
				r = 1;
				
			//Se o valor inserido pelo usuário for diferente do valor que tem na matriz, retorna "0" para o usuário
			}else{
				r = 0;
			}
		}
	}
	//retornando valor amarzenado em "r"
	return r;
}


int main(){

	//Declarando as variáveis
	int num;
	int i, j;
	int linhas, colunas;
	
	//Pedindo para o usuário informar a quantidade de linhas e colunas da matriz 
	printf("Informe a quantidade de linhas da matriz: \n");
	scanf("%d", &linhas);
	printf("Informe a quantidade de colunas da matriz: \n");
	scanf("%d", &colunas);
	
	//Declarando um vetor do tipo int e alocando dinânmicamente
	int **matriz = matriz = (int **)malloc(linhas * sizeof(int*));
	
	//Fazendo alocação dinâmica com as linhas
	for(i = 0; i < linhas; i++){
		matriz[i] = (int *)malloc(colunas * sizeof(int));
	}
	
	//Laço de repetição para preencher a matriz
	for(i = 0; i<linhas; i++){
		printf("digite os valores: ");
		for(j=0; j<colunas; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
	
	printf("\n\nDADOS DA MATRIZ:\n");
	
	//Laço de repetição para exibir os valores da matriz
	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	//Pedindo para o usuário informar um número
	printf("Infofme um numero: \n");
	scanf("%d", &num);
	
	//Exibindo se o número digitado pelo usuário tem na matriz ou não. caso tenha vai retorar 1, se não tiver retorna 0
	printf("%d ", mat(matriz, linhas, colunas, num));
	
	//liberação das linhas.
	for(i = 0; i<linhas; i++){
		free(matriz[i]);
	}
	//Liberação da matriz
	free(matriz);

	return 0;
}
