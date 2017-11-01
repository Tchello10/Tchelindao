#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

int ReiniciaMapa (int matriz [MAX][MAX]);
void AlocarCelula (int matriz [MAX] [MAX], char resp[]);

int main() {
	//Variaveis da matriz
	int c, l, i, j, k, m;
	//Vari�vel da sentinela
	char resp [1], rein;
	//Inicializa��o
	rein = 'n';
	
	//Informando o usu�rio o limite da matriz
	printf("O limite das linhas e colunas da matriz e 100x100\n");
	printf("-------------------------------------------------\n\n");
	//Pedido de tamanho da matriz
	printf("insira o numero de colunas desejadas: ");
	scanf("%d", &c);
	printf("insira o numero de linhas desejadas: ");
	scanf("%d", &l);
	printf("\n\n");
	
	int matriz [MAX] [MAX];

	ReiniciaMapa (matriz);
	
	//Imprime a matriz
	for (i=0; i<l; i++){
		for (j=0 ; j<c; j++){
			printf(" %d", matriz [i][j]);
		}
		printf("\n");
	}	

	AlocarCelula (matriz, resp);
	
	//Imprime a matriz
	i = 0;
	j = 0;
	
	for (i=0; i<l; i++){
		for (j=0 ; j<c; j++){
			printf(" %d", matriz [i][j]);
		}
		printf("\n");
	}	


 printf("\n\n\n\n");
 
		if(resp[1] == 'n'){
		printf("Deseja reiniciar o mapa?");
		scanf("%s", &rein);
	}
	
		if (rein == 's'){
		ReiniciaMapa (matriz);
	}

	
	//Imprime a matriz com as celulas escolhidas		
	for (i=0; i<l; i++){
		for (j=0 ; j<c; j++){
			printf(" %d", matriz [i][j]);
		}
		printf("\n");
	}


}

int ReiniciaMapa (int matriz [MAX][MAX]){
	int l, c, i, j, x, y;

	for (i=0; i<MAX; i++){
		for (j=0; j<MAX; j++){
			matriz [i][j] = 1;
			}
		}
	}	

void AlocarCelula (int matriz [MAX] [MAX], char resp[]){
	int c, l, i, j, k, m;
	char rein;
	rein = 'n';
	
	while(resp[1] != 'n'){
		
	printf("\n\nInforme a linha da celula: ");
	scanf("%d", &k);
	printf("Informe a coluna da celula: ");
	scanf("%d", &m);
	
	matriz [k-1][m-1] = 0;
	
	printf("\n");
	printf("Deseja continuar? 's' 'n' ");
	scanf("%s", &resp[1]);
	}
}

