//declaração das biliotecas
#include<stdio.h> 
#include<stdlib.h>  
#include<locale.h>  

// prototipo da função multiplicação
int **mult(int **a, int **b, int n); 

// prototipo da função libera matriz
void mat_libera(int** mat, int n);
 
int main(void){
	
	// declaração de variavel tipo int
    int n, i, j; 
    setlocale(LC_ALL, "Portuguese");

    printf("\n\n");
    
    //solicita ao usuario o valor da matriz
    printf("Digite a dimensão da matriz nxn:\n ");
    
	// ler os dados  
    scanf("%d", &n);  

	//declaração de ponteiro tipo int
    int **a,**b;  
    
    //alcação dinamica de a
    a=(int **)(malloc(n*sizeof(int*))); 
    
    //laço de repetição 
    for(i=0;i<n;i++){ 
        a[i]=(int*)(malloc(n*sizeof(int)));
    }
    
    //alocação dinamica de b
    b=(int**)(malloc(n*sizeof(int*))); 
    for(j=0;j<n;j++){
        b[j]=(int*)(malloc(n*sizeof(int)));
    }
    printf("Matriz A:\n"); 
    
    //passa pela marriz A e armazena seu valor
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Digite os elementos: ");
            scanf("%d", &a[i][j]);
        }
    }
    printf("Matriz B:\n");  
    
    //passa pela marriz B e armazena seu valor
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Digite os elementos: ");
            scanf("%d", &b[i][j]);
        }
    }
    
    // chama a função que realiza a multiplicação entre as matrizes
    int **matriz = mult(a, b, n); 
    printf("A multiplicação dos elementos de A x B \n");
    for(i=0;i<n;i++){
    	printf("\n");
        for(j=0;j<n;j++){
            printf(" %d  ", matriz[i][j]);

        }
    }

	//chamada da função que libera a matriz A 
    mat_libera(a, n); 
    
    //chamada da função que libera a matriz B
    mat_libera(b, n); 

    return(0);

}

//função que libera as matrizes A e B
void mat_libera(int** mat, int n){ 
  int i;
     for(i = 0; i < n; i++){
        free(mat[i]); 
     }
    free(mat);
}

// função que realiza a multipçicação entre as matrizes A e B
int **mult(int **a, int **b, int n){ 
    int i, j;
    int **resul;
    resul=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++){
    	
    	//alocação dinamica do resul em int
        resul[i]=(int*)malloc(n*sizeof(int)); 
        
    }
    
    //laço de repetição que passa pelos valores das matrizes e realiza a multiplicação
    for( i=0;i<n;i++){
        for(j=0;j<n;j++){ 
            resul[i][j] = a[i][j] * b[i][j]; 
        }
    }
    return resul;

}
