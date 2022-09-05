//declara��o das biliotecas
#include<stdio.h> 
#include<stdlib.h>  
#include<locale.h>  

// prototipo da fun��o multiplica��o
int **mult(int **a, int **b, int n); 

// prototipo da fun��o libera matriz
void mat_libera(int** mat, int n);
 
int main(void){
	
	// declara��o de variavel tipo int
    int n, i, j; 
    setlocale(LC_ALL, "Portuguese");

    printf("\n\n");
    
    //solicita ao usuario o valor da matriz
    printf("Digite a dimens�o da matriz nxn:\n ");
    
	// ler os dados  
    scanf("%d", &n);  

	//declara��o de ponteiro tipo int
    int **a,**b;  
    
    //alca��o dinamica de a
    a=(int **)(malloc(n*sizeof(int*))); 
    
    //la�o de repeti��o 
    for(i=0;i<n;i++){ 
        a[i]=(int*)(malloc(n*sizeof(int)));
    }
    
    //aloca��o dinamica de b
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
    
    // chama a fun��o que realiza a multiplica��o entre as matrizes
    int **matriz = mult(a, b, n); 
    printf("A multiplica��o dos elementos de A x B \n");
    for(i=0;i<n;i++){
    	printf("\n");
        for(j=0;j<n;j++){
            printf(" %d  ", matriz[i][j]);

        }
    }

	//chamada da fun��o que libera a matriz A 
    mat_libera(a, n); 
    
    //chamada da fun��o que libera a matriz B
    mat_libera(b, n); 

    return(0);

}

//fun��o que libera as matrizes A e B
void mat_libera(int** mat, int n){ 
  int i;
     for(i = 0; i < n; i++){
        free(mat[i]); 
     }
    free(mat);
}

// fun��o que realiza a multip�ica��o entre as matrizes A e B
int **mult(int **a, int **b, int n){ 
    int i, j;
    int **resul;
    resul=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++){
    	
    	//aloca��o dinamica do resul em int
        resul[i]=(int*)malloc(n*sizeof(int)); 
        
    }
    
    //la�o de repeti��o que passa pelos valores das matrizes e realiza a multiplica��o
    for( i=0;i<n;i++){
        for(j=0;j<n;j++){ 
            resul[i][j] = a[i][j] * b[i][j]; 
        }
    }
    return resul;

}
