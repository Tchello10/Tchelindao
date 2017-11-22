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
	char resp[1], rein, salvar;

	//Inicialização
	resp[0] = 's';
	nvivos = 0;

	//Informando o usuário o limite da matriz
	printf("O limite das linhas e colunas da matriz e 100x100\n");
	printf("-------------------------------------------------\n\n");

	printf("Insira o tamanho do mundo: ");
	scanf("%d", &tamanho);

	c = tamanho;
	l = tamanho;


	int matriz [MAX] [MAX], matriz2[MAX][MAX];

	//Imprime a matriz e atribui valor 0
	for (i=0; i<l; i++){
		for (j=0 ; j<c; j++){
			matriz[i][j]= matriz2[i][j] = 0;
			printf(" %d", matriz [i][j]);
		}
		printf("\n");
	}

	ReiniciaMapa (matriz, resp, l, c);

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
			printf(" %d", matriz[i][j]);
		}
		printf("\n");
	}


    for(i = 0;i < l;i++){
        for(j = 0;j < c;j++){
            matriz2[i][j] = matriz[i][j];
        }
    }

	printf("Insira o numero de vezes que deseja a simulacao:");
	scanf("%d", &vezes);

	for(t = 0; t < vezes; t++){

		printf("\n--------- Evolucao: %d ----------\n", t+1);

		for(i = 0;i < l; i++){
            for(j = 0;j < c; j++){
                printf("%d", matriz2[i][j]);
            }
            printf("\n");
        }

        printf("\n");


		for (i = 0; i < l; i++){
			for (j = 0 ; j < c; j++){

                nvivos = 0;

				if (matriz[(i-1+tamanho)%tamanho][(j-1+tamanho)%tamanho]==1){
                    nvivos++;
				}
                if (matriz[(i-1+tamanho)%tamanho][j]==1){
                    nvivos++;
                }
                if (matriz[(i-1+tamanho)%tamanho][(j+1)%tamanho]==1){
                    nvivos++;
                }
                if (matriz[i][(j-1+tamanho)%tamanho]==1){
                    nvivos++;
                }
                if (matriz[i][(j+1)%tamanho]==1){
                    nvivos++;
                }
                if (matriz[(i+1)%tamanho][(j-1+tamanho)%tamanho]==1){
                    nvivos++;
                }
                if (matriz[(i+1)%tamanho][j]==1){
                    nvivos++;
                }
                if (matriz[(i+1)%tamanho][(j+1)%tamanho]==1){
                    nvivos++;
                }



				/* Atribuir o valores atualizadoos*/
                if ((nvivos == 0)||(nvivos == 1)||(nvivos >= 4)){
                    matriz2[i][j] = 0;
                }
                else {
                    if(nvivos == 3){
                        matriz2[i][j] = 1;
                    }
                    else {
                        matriz2[i][j] = matriz[i][j];
                    }
                }
			}
		}

		/* Atribuindo a matriz real(matriz2) na matriz de teste(matriz)*/
        for(i = 0;i < l;i++){
            for(j = 0;j < c;j++){
                matriz[i][j] = matriz2[i][j];
            }
        }

	}


printf("Voce deseja salvar?(S/N)");
salvar = getch();
if(salvar == 'S' ||salvar == 's' ){
	char mundo[100]; // Variavel do tipo char que vai ser impressa no arquivo	


	FILE *arq; // Declarando o arquivo

	int result; // variavel para auxiliar na manipulacao do arquivo

	arq = fopen("recJogodaVida.txt", "wt"); // Comando para abrir o arquivo onde recSuperElisa e o nome do arquivo, e "wt" e o modo para abrir o arquivo
	
	if(arq == NULL){ // se a variavel receber o valor nulo significa que nao criou
		printf("Problemas na criacao do arquivo\n");
	}



	for(i=0; i< tamanho;i++){
		for(c=0; c< tamanho; c++){
			if(matriz[i][c]==1){ // If para saber qual a posicao dos vivos, no meu caso 1 sao os vivos
				//printf("%d - %d", i,c);
				//printf("\n");				
				sprintf(mundo, "%d - %d \n", i,c );// colocando na variavel elisa o que esta nos parenteses como se fosse um printf
				printf("%d-%d \n", i,c ); // exibindo a posicao dos bixo vivos
				result = fputs(mundo,arq);	// colocando no arquivo a variavel elisa
			}
		}
	}

fclose(arq); // fechando o arquivo
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

