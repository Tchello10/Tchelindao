#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

int ReiniciaMapa (int matriz [MAX][MAX], char resp[], int l, int c);

int main() {
	//Variaveis da matriz
	int c = MAX, l = MAX, i,tamanho, j, k, m, p , vezes, t, nvivos,seg;
	int matriz [MAX] [MAX], matriz2[MAX][MAX];
	seg=1;
	char opcao;
	//Variável da sentinela
	char resp[1],padrao, rein, salvar, carregar;
	tamanho = 10;
	//Inicialização
	resp[0] = 's';
	nvivos = 0;

	for (i=0; i<l; i++){
		for (j=0 ; j<c; j++){
			matriz[i][j]= matriz2[i][j] = 0;	
					
		}
	}
	
	matriz[0][0] = matriz2[0][0] = 1;
    matriz[0][1] = matriz2[0][0] = 1;
    matriz[0][2] = matriz2[0][0] = 1;
    
	printf("\n \nDeseja carregar o ultimo jogo?(S/N)");
	carregar = getch();
	if(carregar == 'S' ||carregar == 's' ){		
		
		
		for(i=0;i<tamanho;i++){
			for(j=0;j<tamanho;j++){
					matriz[i][j] = matriz2[i][j] = 0;
				
			}			
		}
		
		
		printf("\n\nLendo arquivo...\n\n");

	    int linha, coluna;
	    FILE *arq2;
	    char url[] = "recJogodaVida.txt";
	    
	    arq2 = fopen(url, "r");
	    if(arq2 == NULL)
	            printf("Erro, nao foi possivel abrir o arquivo\n");
	    else
	        if((fscanf(arq2,"Tamanho: %d\n", &tamanho)) != EOF){
	            printf("Tamanho: %d\n", tamanho);
	        }        
	
	        while( (fscanf(arq2,"Linha [%d] - Coluna [%d]\n", &linha, &coluna)) != EOF){
	        	linha = linha -1; coluna = coluna - 1;
	            matriz[linha][coluna] = matriz2[linha][coluna] = 1;
	            printf("Alguem vivo na possicao -> Linha: %d Coluna: %d\n", linha+1, coluna+1);
	        }    
	    fclose(arq2);	
	    
	    printf("\tMundo carregado...\n");
	    
	}	
	
	do{
		printf("\n");
		
		printf("\nPara Configurar = C");
		printf("\nPara Jogar = J");
		printf("\nPara Padroes = P");
		printf("\nPara Sair = S");

		printf("\n\nForneca a opcao: ");
		scanf("%s", &opcao);	
		
		switch(opcao){
			case 'p':
			case 'P':
				matriz[0][0] = matriz2[0][0] = 0;
			    matriz[0][1] = matriz2[0][0] = 0;
			    matriz[0][2] = matriz2[0][0] = 0;
				
				printf("Qual padrao voce deseja? (S)apo ou (G)lider (B)loco?");
				scanf("%s", &padrao);
				
				switch(padrao){
					case 'B': 
					case 'b':
						matriz[5][5] = matriz2[5][5] = 1;
					    matriz[5][6] = matriz2[5][6] = 1;
					    matriz[6][5] = matriz2[6][5] = 1;
						matriz[6][6] = matriz2[6][6] = 1;		
						break;
					case 'G':
					case 'g':
						matriz[5][5] = matriz2[5][5] = 1;
					    matriz[5][6] = matriz2[5][6] = 1;
					    matriz[5][7] = matriz2[5][7] = 1;
						matriz[6][5] = matriz2[6][5] = 1;
						matriz[7][6] = matriz2[7][6] = 1;
						break;
					case 'S':
					case 's':
					matriz[5][5] = matriz2[5][5] = 1;
				    matriz[5][6] = matriz2[5][6] = 1;
				    matriz[6][5] = matriz2[6][5] = 1;
					matriz[6][6] = matriz2[6][6] = 1;
					matriz[5][7] = matriz2[5][7] = 1;
					matriz[6][4] = matriz2[6][4] = 1;	
						break;
						
				}
				break;	
			case 'C':
			case 'c':
			printf("Insira o tamanho do mundo de no maximo 100: ");
			scanf("%d", &tamanho);
				
			printf("\n \nDigite o intervalo em segundos que deseje gerar as evolucoes:");
			scanf("%d",&seg);
	
	for (i=0; i<l; i++){
		for (j=0 ; j<c; j++){
			matriz[i][j]= matriz2[i][j] = 0;	
				}
			}
		c = tamanho;
		l = tamanho;
		
		for (i=0; i<l; i++){
			for (j=0 ; j<c; j++){
				printf(" %d", matriz [i][j]);
			}
			printf("\n");
		}		
	
		ReiniciaMapa (matriz, resp, l, c);	
					
	case'j':
					
	c = tamanho;
	l = tamanho;
	
	printf ("\n\n");

	

	//Imprime a matriz e atribui valor 0
	for (i=0; i<l; i++){
		for (j=0 ; j<c; j++){
			printf(" %d", matriz [i][j]);
		}
		printf("\n");
	}

	resp[0] = 'n';

 	printf("\n\n");

	if(resp[0] == 'n' || resp[0] == 'N'){
		printf("Deseja reiniciar o mapa?");
		scanf("%s", &rein);
	}
	if (rein == 's' || rein == 'S'){
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


	printf("\n \nInsira o numero de vezes que deseja a simulacao:");
	scanf("%d", &vezes);
	


	printf("\n--------- Primeira Geracao :D ----------\n\n", t+1);

		for(i = 0;i < l; i++){
            for(j = 0;j < c; j++){
                printf(" %d", matriz2[i][j]);
            }
            printf("\n");
        }

        printf("\n");


	for(t = 0; t < vezes; t++){

		sleep(seg);


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
        
        printf("\n--------- Evolucao: %d ----------\n\n", t+1);

		for(i = 0;i < l; i++){
            for(j = 0;j < c; j++){
                printf(" %d", matriz2[i][j]);
            }
            printf("\n");
        }

        printf("\n");
        

	}
	
	


printf("\n \nVoce deseja salvar?(S/N)");
salvar = getch();
if(salvar == 'S' ||salvar == 's' ){
	char mundo[100]; // Variavel do tipo char que vai ser impressa no arquivo	


	FILE *arq; // Declarando o arquivo

	int result, contador = 0; // variavel para auxiliar na manipulacao do arquivo

	arq = fopen("recJogodaVida.txt", "wt"); // Comando para abrir o arquivo onde recSuperElisa e o nome do arquivo, e "wt" e o modo para abrir o arquivo
	
	if(arq == NULL){ // se a variavel receber o valor nulo significa que nao criou
		printf("Problemas na criacao do arquivo\n");
	}



	printf("\n\nSalvando arquivo...\n");

    sprintf(mundo, "Tamanho: %d\n", tamanho);
    printf("Tamanho: %d\n", tamanho);
    result = fputs(mundo, arq);

    for(i=0; i < tamanho;i++){
        for(j=0; j< tamanho; j++){;
            if(matriz2[i][j] == 1){                
                sprintf(mundo, "Linha [%d] - Coluna [%d]\n", i+1,j+1);
                printf("Linha [%d] Coluna [%d]\n", i+1,j+1 );
                result = fputs(mundo,arq);
                contador++;
            }
        }       
    }
    fclose(arq);
    printf("Gravacao concluida com sucesso\nSeres Vivos gravados: %d\n", contador);
}

}
		
		
	}while(opcao != 's' && opcao != 'S');
		

 
}
			
/*	c = tamanho;
	l = tamanho;
	
	printf ("\n\n");

	

	//Imprime a matriz e atribui valor 0
	for (i=0; i<l; i++){
		for (j=0 ; j<c; j++){
			printf(" %d", matriz [i][j]);
		}
		printf("\n");
	}

	resp[0] = 'n';

 	printf("\n\n");

	if(resp[0] == 'n' || resp[0] == 'N'){
		printf("Deseja reiniciar o mapa?");
		scanf("%s", &rein);
	}
	if (rein == 's' || rein == 'S'){
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


	printf("\n \nInsira o numero de vezes que deseja a simulacao:");
	scanf("%d", &vezes);
	


	printf("\n--------- Primeira Geracao :D ----------\n\n", t+1);

		for(i = 0;i < l; i++){
            for(j = 0;j < c; j++){
                printf(" %d", matriz2[i][j]);
            }
            printf("\n");
        }

        printf("\n");


	for(t = 0; t < vezes; t++){

		sleep(seg);


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



				/* Atribuir o valores atualizadoos
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

		/* Atribuindo a matriz real(matriz2) na matriz de teste(matriz)
        for(i = 0;i < l;i++){
            for(j = 0;j < c;j++){
                matriz[i][j] = matriz2[i][j];
            }
        }
        
        printf("\n--------- Evolucao: %d ----------\n\n", t+1);

		for(i = 0;i < l; i++){
            for(j = 0;j < c; j++){
                printf(" %d", matriz2[i][j]);
            }
            printf("\n");
        }

        printf("\n");
        

	}
	
	


printf("\n \nVoce deseja salvar?(S/N)");
salvar = getch();
if(salvar == 'S' ||salvar == 's' ){
	char mundo[100]; // Variavel do tipo char que vai ser impressa no arquivo	


	FILE *arq; // Declarando o arquivo

	int result, contador = 0; // variavel para auxiliar na manipulacao do arquivo

	arq = fopen("recJogodaVida.txt", "wt"); // Comando para abrir o arquivo onde recSuperElisa e o nome do arquivo, e "wt" e o modo para abrir o arquivo
	
	if(arq == NULL){ // se a variavel receber o valor nulo significa que nao criou
		printf("Problemas na criacao do arquivo\n");
	}



	printf("\n\nSalvando arquivo...\n");

    sprintf(mundo, "Tamanho: %d\n", tamanho);
    printf("Tamanho: %d\n", tamanho);
    result = fputs(mundo, arq);

    for(i=0; i < tamanho;i++){
        for(j=0; j< tamanho; j++){;
            if(matriz2[i][j] == 1){                
                sprintf(mundo, "Linha [%d] - Coluna [%d]\n", i+1,j+1);
                printf("Linha [%d] Coluna [%d]\n", i+1,j+1 );
                result = fputs(mundo,arq);
                contador++;
            }
        }       
    }
    fclose(arq);
    printf("Gravacao concluida com sucesso\nSeres Vivos gravados: %d\n", contador);
}

}
*/

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

