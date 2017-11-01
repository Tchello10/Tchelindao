#include<stdio.h>

#define MAX 102
#define CELVIVA 1
#define CELMORTA 0

void jogo();


void jogo(){

        int i, j,t;
        int matrizActual[MAX][MAX];
        int matrizNova[MAX][MAX];
        int linhas=-1, colunas=-1, vezes, celvivas=-1, plinhas=-1, pcolunas=-1;
        int nvivos;

		
		//iniciar os valores dos campos da matriz actual
        for(i=0; i<MAX; i++){
			for(j=0;j<MAX;j++){
                         matrizActual[i][j]=-1;
					  }
		}

		//iniciar os valores dos campos da matriz actual
        for(i=0; i<MAX; i++){
			for(j=0;j<MAX;j++){
                 matrizNova[i][j]=-1;
				  }
		}


		//pedir os valores ao utilizador
        printf("\nQuantas evolucoes deseja (numero de vezes a jogar)?");
        scanf("%d", &vezes);
		while(linhas<=0 || linhas>(MAX-2)){
        printf("\nQuantas linhas deseja no tabuleiro de jogo?");
		printf("\nNumero maximo de linhas: %d.\n", (MAX-2));
        scanf("%d", &linhas);
		}
		while(colunas<=0 || colunas>(MAX-2)){
        printf("\nQuantas colunas deseja no tabuleiro de jogo?");
		printf("\nNumero maximo de colunas: %d.\n", (MAX-2));
        scanf("%d", &colunas);
		}

        printf("\nSerao jogadas %d evolucoes num tabuleiro com %d linhas e %d colunas.\n", vezes, linhas, colunas);

		//iniciar a submatriz do utilizador dentro da matriz principal
        for(i=0;i<linhas;i++)
                for(j=0;j<colunas;j++)
                        matrizActual[i+1][j+1]=CELMORTA;


		while(celvivas<0){
			printf("\nQuantas celulas vivas (O numero de celulas vivas devera ser positivo)?\n");
			scanf("%d", &celvivas);
		}
		if(celvivas==0)
			printf("\n ATENCAO: Nenhuma celula viva");
       
		/*Preenche Matriz actual do utilizador*/
        for(i=0;i<celvivas;i++){

                printf("\nCELULA VIVA %d", i+1);
				printf("\nO seu tabuleiro tem %d linhas e %d colunas.\n", linhas,colunas);
				while(plinhas<0||plinhas>linhas){
                printf("\nInsira posicao linha para a celula viva %d: ", i+1);
                scanf("%d", &plinhas);
				}
				while(pcolunas<0||pcolunas>colunas){
			
                printf("\nInsira posicao coluna para a celula viva %d: ", i+1);
                scanf("%d", &pcolunas);
				}
                matrizActual[plinhas][pcolunas]=CELVIVA;
				plinhas=-1;
				pcolunas=-1;
        }


		printf("\n***** Tabuleiro introduzido *****\n");

		//mostra a matriz introduzida pelo utilizador
		 for(i=1;i<=linhas;i++){
                        printf("\n");
                        for(j=1;j<=colunas;j++){
								if(matrizActual[i][j]==CELVIVA)
								printf("| * |"); //celula viva
							else
								printf("|   |"); //celula morta
						}
		 }


		//vai fazer t evolucoes.
		for(t=0; t<vezes;t++){

			printf("\n--------- Evolucao: %d ----------\n", t+1);

			for(i=1;i<linhas+1;i++){
                for(j=1;j<colunas+1;j++){
                    nvivos=0; 					

                  //verifica a posicao i-1, j-1 da matriz
					if(matrizActual[i-1][j-1]==CELVIVA){
						nvivos++;
						}

                  //verifica a posicao i-1, j da matriz

					if(matrizActual[i-1][j]==CELVIVA){
						nvivos++;}

                  //verifica a posicao i-1, j+1 da matriz

					if(matrizActual[i-1][j+1]==CELVIVA){
						nvivos++;}

                  //verifica a posicao i, j-1 da matriz

					if(matrizActual[i][j-1]==CELVIVA){
						nvivos++;}

                  //verifica a posicao i, j+1 da matriz

					if(matrizActual[i][j+1]==CELVIVA){
						nvivos++;}

                  //verifica a posicao i+1, j-1 da matriz

					if(matrizActual[i+1][j-1]==CELVIVA){
						nvivos++;}

                  //verifica a posicao i+1, j da matriz

					if(matrizActual[i+1][j]==CELVIVA){
						nvivos++;}

                  //verifica a posicao i+1, j+1 da matriz
					if(matrizActual[i+1][j+1]==CELVIVA){
						nvivos++;}
			
                  //celula viva com menos d 2 vizinhos vivos -- morre

					if(matrizActual[i][j]==CELVIVA && nvivos<2){
							matrizNova[i][j]=CELMORTA;
					}

				 //celula viva com mais do que 3 vizinhos vivos --- morre
						else  if(matrizActual[i][j]==CELVIVA && nvivos>3){
							matrizNova[i][j]=CELMORTA;
						}

				//celula viva com exactamente 2 ou 3 vizinhos vivos --- vive
						else if(matrizActual[i][j]==CELVIVA && (nvivos==2)||nvivos==3){
							matrizNova[i][j]=CELVIVA;
						}
				//celula morta com exactamente 3 vizinhos vivos --- viva
						else if(matrizActual[i][j]==CELMORTA && nvivos==3){
							matrizNova[i][j]=CELVIVA;
						}
						else { matrizNova[i][j]=CELMORTA;}				
                }//fim for do j
        }//fim for do i


       //mostra a nova matriz calculada
        for(i=1;i<=linhas;i++){
                        printf("\n");
                        for(j=1;j<=colunas;j++){
							if(matrizNova[i][j]==1)
								printf("| * |");
							else
								printf("|   |");
						  }
					}

		//copia a informacao da matriz nova calculada para a matriz actual para voltar a fazer os calculos
		for(i=0;i<MAX;i++){
			for(j=0;j<MAX;j++)
				matrizActual[i][j]=matrizNova[i][j];		
			}

	}//fim for do t

	printf("\n\n");
}

int main(){

	int inicio=0; //para saber se e a primeira vez que o utilizador joga ou nao
	int opcao=-1;


	while(opcao!=0){
	
		if(inicio==0){
			printf("\nJOGO DA VIDA\n");
			printf("\nBenvindo ao jogo da vida!\n");
			printf("Para jogar prima 1\nPara sair prima 0\n ");
			inicio=1;
		}
		else{
			printf("\nJOGO DA VIDA\n");
			printf("\nDeseja jogar novamente?\n");
			printf("Para jogar prima 1\n");
			printf("Para sair prima 0\n");
		}
		scanf("%d", &opcao);

		switch (opcao){
				case 1: jogo();
				case 0: break; //para sair do jogo
			}//fim do switch
	

	}//fim do while

	printf("\nObrigado por ter jogado. Volte sempre.\n");
	return (0);
}
