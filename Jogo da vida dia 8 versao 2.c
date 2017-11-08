#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

int ReiniciaMapa (int matriz [MAX][MAX]);

int main() {
	//Variaveis da matriz
	int c, l, i, j, k, m, vezes, t, nvivos;
	//Variável da sentinela
	char resp, rein;
	//Inicialização
	resp= 's';
	rein= 'n';
	
	
	//Informando o usuário o limite da matriz
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


	//Imprime a matriz
	
	for (i=0; i<l; i++){
		for (j=0 ; j<c; j++){
			printf(" %d", matriz [i][j]);
		}
		printf("\n");
	}	


 printf("\n\n\n\n");
 
		if(resp == 'n'){
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
printf("Insira o numero de vezes que deseja a simulação:");
	scanf("%d", &vezes);

for(t=0; t<vezes;t++){

			printf("\n--------- Evolucao: %d ----------\n", t+1);

			for(i=1;i<l;i++){
                for(j=1;j<c;j++){
                    nvivos=0; 					

                  //verifica a posicao i-1, j-1 da matriz
					if(matriz[k][m]==0){
						nvivos++;
						}

                  //verifica a posicao i-1, j da matriz

					if(matriz[k][m]==0){
						nvivos++;}

                  //verifica a posicao i-1, j+1 da matriz

					if(matriz[k][m]==0){
						nvivos++;}

                  //verifica a posicao i, j-1 da matriz

					if(matriz[k][m]==0){
						nvivos++;}

                  //verifica a posicao i, j+1 da matriz

					if(matriz[i][j+1]==0){
						nvivos++;}

                  //verifica a posicao i+1, j-1 da matriz

					if(matriz[i+1][j-1]==0){
						nvivos++;}

                  //verifica a posicao i+1, j da matriz

					if(matriz[i+1][j]==0){
						nvivos++;}

                  //verifica a posicao i+1, j+1 da matriz
					if(matriz[i+1][j+1]==0){
						nvivos++;}
			
                  //celula viva com menos d 2 vizinhos vivos -- morre

					if(matriz[i][j]==0 && nvivos<2){
							matriz[i][j]=1;
					}

				 //celula viva com mais do que 3 vizinhos vivos --- morre
						else  if(matriz[i][j]==0 && nvivos>3){
							matriz[i][j]=1;
						}

				//celula viva com exactamente 2 ou 3 vizinhos vivos --- vive
						else if(matriz[i][j]==0 && (nvivos==2)||nvivos==3){
							matriz[i][j]=0;
						}
				//celula morta com exactamente 3 vizinhos vivos --- viva
						else if(matriz[i][j]==1 && nvivos==3){
							matriz[i][j]=0;
						}
						else { matriz[i][j]=1;}				
                }//fim for do j
        }//fim for do i

}
}
int ReiniciaMapa (int matriz [MAX][MAX]){
	int l, c, i, j, x, y,k, m, resp;

	for (i=0; i<MAX; i++){
		for (j=0; j<MAX; j++){
			matriz [i][j] = 1;
			}
		}
	while(resp != 'n'){
		
	printf("\n\nInforme a linha da celula: ");
	scanf("%d", &k);
	printf("Informe a coluna da celula: ");
	scanf("%d", &m);
	
	matriz [k-1][m-1] = 0;
	
	printf("\n");
	printf("Deseja continuar? 's' 'n' ");
	scanf("%s", &resp);
	
			for (i=0; i<l; i++){
		for (j=0 ; j<c; j++){
			printf(" %d", matriz [i][j]);
		}
		printf("\n");
	}
	}
	}	

/*void AlocarCelula (int matriz [MAX][MAX], char resp[]){
	int k, m;

	while(resp[0] != 'n'){
		
	printf("\n\nInforme a linha da celula: ");
	scanf("%d", &k);
	printf("Informe a coluna da celula: ");
	scanf("%d", &m);
	
	matriz [k-1][m-1] = 0;
	
	printf("\n");
	printf("Deseja continuar? 's' 'n' ");
	scanf("%s", &resp[0]);
	
	}
}

		//vai fazer t evolucoes.
		for(t=0; t<vezes;t++){

			printf("\n--------- Evolucao: %d ----------\n", t+1);

			for(i=1;i<linhas+1;i++){
                for(j=1;j<colunas+1;j++){
                    nvivos=0; 					

                  //verifica a posicao i-1, j-1 da matriz
					if(matriz[i-1][j-1]==1){
						nvivos++;
						}

                  //verifica a posicao i-1, j da matriz

					if(matriz[i-1][j]==1){
						nvivos++;}

                  //verifica a posicao i-1, j+1 da matriz

					if(matriz[i-1][j+1]==1){
						nvivos++;}

                  //verifica a posicao i, j-1 da matriz

					if(matriz[i][j-1]==1){
						nvivos++;}

                  //verifica a posicao i, j+1 da matriz

					if(matriz[i][j+1]==1){
						nvivos++;}

                  //verifica a posicao i+1, j-1 da matriz

					if(matriz[i+1][j-1]==1){
						nvivos++;}

                  //verifica a posicao i+1, j da matriz

					if(matriz[i+1][j]==1){
						nvivos++;}

                  //verifica a posicao i+1, j+1 da matriz
					if(matriz[i+1][j+1]==1){
						nvivos++;}
			
                  //celula viva com menos d 2 vizinhos vivos -- morre

					if(matriz[i][j]==1 && nvivos<2){
							matriz[i][j]=0;
					}

				 //celula viva com mais do que 3 vizinhos vivos --- morre
						else  if(matriz[i][j]==1 && nvivos>3){
							matriz[i][j]=0;
						}

				//celula viva com exactamente 2 ou 3 vizinhos vivos --- vive
						else if(matriz[i][j]==1 && (nvivos==2)||nvivos==3){
							matrizNova[i][j]=1;
						}
				//celula morta com exactamente 3 vizinhos vivos --- viva
						else if(matriz[i][j]==0 && nvivos==3){
							matriz[i][j]=1;
						}
						else { matriz[i][j]=0;}				
                }//fim for do j
        }//fim for do i
*/
