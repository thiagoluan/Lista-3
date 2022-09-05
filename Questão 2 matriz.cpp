//Declara��o das bibliotecas
#include <stdio.h>
#include  <stdlib.h>

//Fun��o para verificar se o n�mero digitado pelo usu�rio est� na matriz ou n�o
int mat(int **matriz, int linha, int coluna, int num){
	
	//A vari�vel "i" � o contador que percorre as linhas e o "j" as colunas
	int j, i, r;
	for(i = 0; i<linha; i++){
		for(j = 0; j<coluna; j++){
			
			//Se o valor inserido pelo usu�rio for igual o valor que tem na matriz, retorna "1" para o usu�rio
			if(matriz[i][j] == num){
				r = 1;
				
			//Se o valor inserido pelo usu�rio for diferente do valor que tem na matriz, retorna "0" para o usu�rio
			}else{
				r = 0;
			}
		}
	}
	//retornando valor amarzenado em "r"
	return r;
}


int main(){

	//Declarando as vari�veis
	int num;
	int i, j;
	int linhas, colunas;
	
	//Pedindo para o usu�rio informar a quantidade de linhas e colunas da matriz 
	printf("Informe a quantidade de linhas da matriz: \n");
	scanf("%d", &linhas);
	printf("Informe a quantidade de colunas da matriz: \n");
	scanf("%d", &colunas);
	
	//Declarando um vetor do tipo int e alocando din�nmicamente
	int **matriz = matriz = (int **)malloc(linhas * sizeof(int*));
	
	//Fazendo aloca��o din�mica com as linhas
	for(i = 0; i < linhas; i++){
		matriz[i] = (int *)malloc(colunas * sizeof(int));
	}
	
	//La�o de repeti��o para preencher a matriz
	for(i = 0; i<linhas; i++){
		printf("digite os valores: ");
		for(j=0; j<colunas; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
	
	printf("\n\nDADOS DA MATRIZ:\n");
	
	//La�o de repeti��o para exibir os valores da matriz
	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	//Pedindo para o usu�rio informar um n�mero
	printf("Infofme um numero: \n");
	scanf("%d", &num);
	
	//Exibindo se o n�mero digitado pelo usu�rio tem na matriz ou n�o. caso tenha vai retorar 1, se n�o tiver retorna 0
	printf("%d ", mat(matriz, linhas, colunas, num));
	
	//libera��o das linhas.
	for(i = 0; i<linhas; i++){
		free(matriz[i]);
	}
	//Libera��o da matriz
	free(matriz);

	return 0;
}
