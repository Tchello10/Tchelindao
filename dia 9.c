#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

int ReiniciaMapa (int matriz [MAX][MAX], char resp[], int l, int c);
int main() {
	//Variaveis da matriz
	int c, l, i,tamanho, j, k, m, vezes, t, nvivos;
	//Variável da sentinela
	char resp[1], rein;
	//Inicialização
	resp[0] = 's';
	nvivos = 0;
	
	
	
	
	
	//Informando o usuário o limite da matriz
	printf("O limite das linhas e colunas da matriz e 100x100\n");
	printf("-------------------------------------------------\n\n");
	//Pedido de tamanho da matriz
	/*printf("insira o numero de colunas desejadas: ");
	scanf("%d", &c);
	printf("insira o numero de linhas desejadas: ");
	scanf("%d", &l);
	printf("\n\n");
	*/
	printf("Insira o tamanho do mundo: ");
	scanf("%d", &tamanho);
	c = tamanho;
	l = tamanho;  

	
	int matriz [MAX] [MAX], matriz2[MAX][MAX];
	
	//Imprime a matriz e atribui valor 0
	for (i=0; i<l; i++){
		for (j=0 ; j<c; j++){
			 matriz [i][j]=0;
			printf(" %d", matriz [i][j]);
		}
		printf("\n");
	}
	
		

	ReiniciaMapa (matriz, resp, l, c);
	
	//Imprime a matriz
/*	for (i=0; i<l; i++){
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
*/

 printf("\n\n");
 
		if(resp[0] == 'n'){
		printf("Deseja reiniciar o mapa?");
		scanf("%s", &rein);
	
	}
		if (rein == 's'){
		ReiniciaMapa (matriz, resp, l , c);
	}

	
	//Imprime a matriz com as celulas escolhidas		
	for (i=0; i<l; i++){
		for (j=0 ; j<c; j++){
			printf(" %d", matriz [i][j]);
		}
		printf("\n");
	}
	
	for (i=0; i<l; i++){
		for (j=0 ; j<c; j++){
			matriz2 [i] [j] = matriz[i][j];
		}
	}
	
printf("Insira o numero de vezes que deseja a simulacao:");
	scanf("%d", &vezes);

for(t=0; t<vezes;t++){
	
		nvivos = 0;
		
		printf("\n--------- Evolucao: %d ----------\n", t+1);
		for (i=0; i<l; i++){
		for (j=0 ; j<c; j++){
			printf(" %d", matriz[i][j]);
		}
		printf("\n");
	}
	
			
		for (i=0; i<l; i++){
		for (j=0 ; j<c; j++){
			
				
 if (matriz[i-1][j-1]==1) nvivos++;
       
    if (matriz[i-1][j]==1) nvivos++;
           
     if (matriz[i-1][j+1]==1) nvivos++;
            
    if (matriz[i][j-1]==1) nvivos++;
          
      if (matriz[i][j+1]==1)nvivos++;
                
if (matriz[i+1][j-1]==1) nvivos++;
         
       if (matriz[i+1][j]==1) nvivos++;
               
 if (matriz[i+1][j+1]==1) nvivos++;

    
	
	
	if(nvivos == 0 || nvivos ==1 || nvivos >=4) {
		matriz2[i] [j] = 0;
	}else{
		if(nvivos == 3){
			matriz2[i] [j] = 1;
		}else{
			matriz2[i] [j] = matriz[i][j];
		}
	}
	
	}
	
	
	
}
	for (i=0; i<l; i++){
		for (j=0 ; j<c; j++){
			matriz [i] [j] = matriz2[i][j];
		}
	}

}
}

int ReiniciaMapa (int matriz [MAX][MAX], char resp[], int l, int c){
	int i, j, x, y,k, m;

	for (i=0; i<MAX; i++){
		for (j=0; j<MAX; j++){
			matriz [i][j] = 0;
			}
		}
		
	while(resp[0] != 'n'){
		
	printf("\n\nInforme a linha da celula: ");
	scanf("%d", &k);
	printf("Informe a coluna da celula: ");
	scanf("%d", &m);
	
	matriz [k-1][m-1] = 1;
	
		printf("\n");
	for (i=0; i<l; i++){
		for (j=0 ; j<c; j++){
			printf(" %d", matriz [i][j]);
		}
		printf("\n");
	}
	
	
	printf("\n");
	printf("Deseja continuar? 's' 'n' ");
	scanf("%s", &resp[0]);
	
	
			
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
