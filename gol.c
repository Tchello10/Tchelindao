#include <stdio.h>
#include <stdlib.h>

int main() {
	//Variaveis da matriz
	int c, l, i, j, k, m;
	//Variável da sentinela
	char resp;
	
	//Pedido de tamanho da matriz
	printf("insira o numero de colunas desejadas: ");
	scanf("%d", &c);
	printf("insira o numero de linhas desejadas: ");
	scanf("%d", &l);
	printf("\n\n");
	
	int matriz [l] [c];
	
	//Atribuição da matriz padrao com valor 1
	for (i=0; i<l; i++){
		for (j=0 ; j<c; j++){
			matriz [i][j] = 1;
		}
	
	}
	
	//Imprime a matriz
	for (i=0; i<l; i++){
		for (j=0 ; j<c; j++){
			printf(" %d", matriz [i][j]);
		}
		printf("\n");
	}
	
	//Loop para continuar ou nao a inserção de celulas
	while(resp != 'n'){
	
	printf("\n\nInforme a linha da celula: ");
	scanf("%d", &k);
	printf("Informe a coluna da celula: ");
	scanf("%d", &m);
	
	matriz [k-1][m-1] = 0;
	
	printf("\n");
	printf("Deseja continuar? 's' 'n' ");
	scanf("%s", &resp);
}
	
	//Imprime a matriz com as celulas escolhidas		
	for (i=0; i<l; i++){
		for (j=0 ; j<c; j++){
			printf(" %d", matriz [i][j]);
		}
		printf("\n");
	}

}

