//Declaração das bibliotecas
#include <stdio.h>
#include <locale.h>

int main(void) {
	setlocale(LC_ALL, "portuguese");
	
	//Declarando as variáveis do tipo int
	int n, i, j;
	
	//Declarando uma matriz 3x3 do tipo int
	int mat[3][3];
	
	//Laços de repetição para preencher a matriz
	
	printf("Insira os nove elementos da matriz 3x3:\n");
	
	//Laço para inserir os valores da matriz
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	
	//Laços de repetição para exibir os valores  da matriz
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	//Inicializando as variáveis para somar a diagonal principal e secundária com 0
	int somaDP = 0, somaDS = 0;
	
	//Laço para realizar a soma da diagonal principal
	for (i = 0; i < 3; i++) {
		somaDP += mat[i][i];
	}
	
	//Laço para realizar a soma da diagonal secundária
	for (i = 0; i < 3; i++) {
		somaDS += mat[i][3-i-1];
	}
	
	printf("\nSoma das linhas: ");
	
	//criando um vetor para percorrer as linhas e fazer a soma
	int vetL[n];
	
	//Laço para realizar a soma das linhas
	for (i = 0; i < 3; i++) {
		vetL[i] = 0;
		for (j = 0; j < 3; j++) {
			vetL[i] += mat[i][j];
		}
	}
	
	//Laço para exibir a soma das linhas
	for (i = 0; i < 3; i++) {
		printf("%d ", vetL[i]);
	}

	printf("\nSoma das colunas: ");
	
	//criando um vetor para percorrer as colunas e fazer a soma
	int vetC[3];
	
	//Laço para realizar a soma das linhas
	for (j = 0; j < 3; j++) {
		vetC[j] = 0;
		for (i = 0; i < 3; i++) {
			vetC[j] += mat[i][j];
		}
	}
	
	//Laço para exibir a soma das linhas
	for (i = 0; i < 3; i++) {
		printf("%d ", vetC[i]);
	}
	
	//Exibindo a soma da diagonal principal e secundária
	printf("\nA Soma da diagonal principal é %d e da secundária é %d\n", somaDP, somaDS);
	
	//Declarando variáveis para testar as linhas e colunas e as inicializando com 1
	int testaL = 1, testaC = 1;
	
	/*Dentro desse laço, se o vetl na posição i for diferente do vetl na posição i-1, testaL vai receber 0.
	  Da mesma forma vai acontecer com o vetC e testaC*/
	for (i = 1; i <  3; i++) {
		if (vetL[i] != vetL[i-1]) {
			testaL = 0;
		} else if (vetC[i] != vetC[i-1]) {
			testaC = 0;
		}
	}
	
	//Etrutura de decisão para saber se a matriz é um quadrado mágico ou não
	if (testaL && testaC && somaDP == somaDS && somaDP == vetL[0]) {
		printf("Quadrado mágico");
	} else {
		printf("Quadrado não mágico");
	}

	return 0;
}
