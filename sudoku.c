#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

void trofeu(){
	system ("color 0E");
    printf("         VOCE GANHOU PARABENS!!!\n");
    printf("----------------------------------------\n");
    printf("          .-=========-.               \n");
    printf("          \\'-=======-'/               \n");
    printf("          _|   .=.   |_               \n");
    printf("         ((|  {{1}}  |))              \n");
    printf("          \\|   /|\\   |/               \n");
    printf("           \\__ '`' __/                \n");
    printf("             _`) (`_                  \n");
    printf("           _/_______\\_                \n");
    printf("          /___________\\\n----------------------------------------");
    sleep(5);
}

void imprime(int combinacao[9][9]){
	int i, j;
    char espaco = '-'; //usamos no lugar dos zeros da matriz pré-definida
    system ("color 0A");
    printf("\n---------------------------SUDOKU------------------------\n");  
    printf("      0    1    2       3    4    5       6    7    8\n"); 
    printf("---------------------------------------------------------\n"); 
    for (i = 0; i < 9; i++) { 
         if (i == 3){
                printf( "\n");
            }
            if (i == 6){
                printf("\n");
            } //formatacao da matriz, a cada tres linhas dar um enter para ela ficar divida
        printf("%d |  ", i); //formatacao da matriz, insere o numero da linha e a | pra separar da matriz 
        for (j = 0; j < 9; j++) { 
            if (j == 3){
                printf(" | "); //formatacao da matriz, na 3° coluna ele insere essa | para separar do outro bloco de colunas
            }
            if (j == 6){
                printf(" | "); //formatacao da matriz, na 6° coluna ele insere essa | para separar do outro bloco de colunas
            }
            if (combinacao[i][j] == 0){ 
                printf(" %c   ", espaco);
            } //aqui sim ele substitui o zero pelo caracter - 
            else{ 
                printf(" %d   ", combinacao[i][j]); 
            } // se nao tiver o 0 ele só imprime normal
        } 
            printf("|"); 
            printf("\n"); 
    }
}


void jogo_verificacao(int combinacao[9][9]){ //funcao do jogo que recebe a matriz escolhida
    int cont = 0; //contador pro jogo ficar rodando enquanto a matriz nao eh toda preenchida
    int original[9][9]; //matriz original para comparar com a matriz onde o usuario vai alterar os valores 
    int numero_maximo_colunas = 0;
    int numero_maximo_linhas = 0;
    int l = 0;
    int c = 0;
    int desistir = 1;
    int i, j, i1, j1, i2, j2;

    for (i1 = 0; i1 < 9; i1++){ //aqui cria a matriz original com os valores pré-definidos da matriz sorteada antes de ser alterada
        for (j1 = 0; j1 <9; j1 ++){
            original[i1][j1] = combinacao[i1][j1];
        }
    }

    while (cont < 81){
        int linha, coluna, valor; //valores que o usuario insere 

        imprime(combinacao);
        printf("---------------------------------------------------------\n");  
        printf("para desistir digite 999 a qualquer momento\n");
        printf("---------------------------------------------------------\n");  
        printf("Em qual linha e coluna deseja inserir um valor?");
        printf("\nLinha: ");
        scanf("%d", &linha);
        
        if (linha == 999){
        	system ("color 0C");
            printf("\nATE MAIS DESISTENTE! BOA SORTE NA PROXIMA\n");
            sleep(2);
            break;
        }
        while (linha < 0 || linha > 8 && linha <= 998 || linha > 999){
        	system ("color 0C");
            printf("\nA LINHA DEVE SER ENTRE 0 E 8!\n");
            sleep(2);
            system ("color 0A");
            printf("\nInsira a linha novamente: \n");
            scanf("%d", &linha);
        }
        if (linha == 999){
        	system ("color 0C");
            printf("\nATE MAIS DESISTENTE! BOA SORTE NA PROXIMA\n");
            sleep(2);
            break;
        }
        
        printf("Coluna: ");
        scanf("%d", &coluna);
        if (coluna == 999){
        	system ("color 0C");
            printf("\nATE MAIS DESISTENTE! BOA SORTE NA PROXIMA\n");
            sleep(2);
            break;
        }
        while (coluna < 0 || coluna > 8 && coluna <= 998 || coluna > 999){
        	system ("color 0C");
            printf("\nA COLUNA DEVE SER ENTRE 0 E 8!\n");
            sleep(2);
            system ("color 0A");
            printf("\nInsira a coluna novamente: \n");
            scanf("%d", &coluna);
        }
        if (coluna == 999){
        	system ("color 0C");
            printf("\nATE MAIS DESISTENTE! BOA SORTE NA PROXIMA\n");
            sleep(2);
            break;
        }
        
        printf("Qual o valor?\n"); 
        scanf("%d", &valor); 
        if (valor == 999){
        	system ("color 0C");
            printf("\nATE MAIS DESISTENTE! BOA SORTE NA PROXIMA\n");
            sleep(2);
            break;
        }
        while (valor <= 0 || valor > 9 && valor <= 998 || valor > 999){
        	system ("color 0C");
            printf("\nO VALOR DEVE SER ENTRE 1 E 9!\n");
            sleep(2);
            system ("color 0A");
            printf("\nInsira o valor novamente: \n");
            scanf("%d", &valor);
        }
        if (valor == 999){
        	system ("color 0C");
            printf("\nATE MAIS DESISTENTE! BOA SORTE NA PROXIMA\n");
            sleep(2);
            break;
        }
        
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) { 
                //as condicoes a seguir servem para economizar linhas de codigo,
                //onde será definido os valores a serem usados no for de comparacao
                //de quadrante posteriormente
                    if (linha >= 0 && linha<3){
                        l = 0;
                        numero_maximo_linhas = 2;
                        // aqui por ex, se o usuario digita linha 1 ele seta esses valores 
                        // para comparar apenas dentro desse intervalo, juntamente com 
                        // as colunas
                    }
                    
                    else if (linha >= 3 && linha <6){
                         l = 3;
                        numero_maximo_linhas = 5;
                    }
                    
                    else if (linha >= 6 && linha <9){
                        l = 6;
                        numero_maximo_linhas = 8;
                    }
                    
                    if (coluna >= 0 && coluna<3){
                        c = 0;
                        numero_maximo_colunas = 2;
                        // o mesmo que ocorre com as linhas, 
                        // só que com as colunas, dessa forma
                        // cria uma "matriz" com esses valores 
                    }
                    
                    else if (coluna >= 3 && coluna <6){
                        c = 3;
                        numero_maximo_colunas = 5;
                    }
                    
                    else if (coluna >= 6 && coluna <9){
                        c = 6;
                        numero_maximo_colunas = 8;
                    }
                
                // nesse for usaremos os valores definidos acuma para entao
                // conseguirmos comparar uma matriz pequena de 3x3 (quadrante)
                for (l = l; l <= numero_maximo_linhas; l++) {
                    int c1 = c;
                    // criamos esse c1 aqui porque estavamos com um problema:
                    // na linha X ele comparava com os valores da coluna X, Y e Z 
                    // mas nas proximas linhas Y e Z os valores da coluna nao 
                    // eram resetados por estarem como "c = c", dessa forma
                    // tivemos que colocar c1 = c, que ai toda vez que ele fizer
                    // a coluna x y e z ele voltava pra proxima linha e resetava 
                    // o c1 para x, pra poder fazer o y e z novamente 
                    for (c1 = c1; c1 <= numero_maximo_colunas; c1++){
					
					if(original[l][c1] != 0 && l == linha && c1 == coluna){ //se o valor for pré-definido ele nao altera 
						system ("color 0C");
						printf("\n------------------------------");
                        printf("\n| VOCE NAO PODE ALTERAR AQUI |\n");
                        printf("------------------------------\n");
						i = 9;
                        j = 9;
						sleep(2);            	
					}	
                        if (combinacao[l][c1] == valor && i == 0){ //ve se o valor ja esta na matriz
                        	system ("color 0C");
                        	printf("\n--------------------------------------");
                            printf("\n| ESSE NUMERO JA EXISTE NO QUADRANTE |\n");
                            printf("--------------------------------------\n");
                            l = numero_maximo_linhas;
                            c1 = numero_maximo_colunas;
                            i = 9;
                            j = 9;
                            sleep(2);
                        }
                        if (l == numero_maximo_linhas && c1 == numero_maximo_colunas){
                            if (combinacao[linha][j] == valor){ //ve se o valor ja esta na linha
								system ("color 0C");
								printf("\n-------------------------------");
                                printf("\n| VALOR JA EXISTENTE NA LINHA |\n");
                                printf("-------------------------------\n");
                                i = 9;
                                j = 9;
                                sleep(2);
                            }
                            
                            else if (combinacao[i][coluna] == valor){ //ve se o valor ja esta na coluna 
                            	system ("color 0C");
                            	printf("\n--------------------------------");
                                printf("\n| VALOR JA EXISTENTE NA COLUNA |\n");
                                printf("--------------------------------\n");
                                i = 9;
                                j = 9;
                                sleep(2);
                            }
                            else if (j == 8 && i == 8){ //se o valor nao estiver na linha e na coluna ele entra aqui
                            
                                if (combinacao[linha][coluna] != 0){ //se ele quiser inserir em uma posição que ja tem numero
                            
                                    if (original[linha][coluna] != combinacao[linha][coluna]){ //mudar apenas se o valor nao for pre-definido
                                    	combinacao[linha][coluna] = valor;
                                    	j = 9;
                                        i = 9;
                                    }     
                                }
                                
                                else if (combinacao[linha][coluna] == 0){ // se ele quiser inserir em uma posição vazia e nao tem o numero na linha e nem na coluna ou quadrante
                                    combinacao[linha][coluna] = valor;
                                    j = 9;
                                    i = 9;
                                }
                            }
                        }
                    }
                }
                
                cont = 0;
                 for (i2 = 0; i2 < 9; i2++) {
                    for (j2 = 0; j2 < 9; j2++) {
                        if (combinacao[i2][j2] != 0){
                            cont = cont + 1;
                        }
                    }
                }
            }
        }
    }
    if (cont > 80){
        trofeu();
    }
}

void escolher_matriz(int decisao_menu){ //para voce poder jogar em tres niveis diferentes :)
    int combinacao0[9][9] = {
    {8,0,0,0,5,2,0,0,0},
    {0,0,3,8,4,6,0,7,5},
    {0,7,5,9,0,1,0,0,0},
    {0,5,1,3,0,4,6,0,0},
    {0,8,6,5,2,0,0,1,7},
    {2,9,4,1,0,0,0,8,3},
    {0,1,0,4,7,0,0,0,0},
    {4,0,7,2,9,5,0,0,8},
    {5,0,0,6,0,8,0,4,9}};
    int combinacao1[9][9]  = {
    {0,8,6,4,0,7,2,0,9},
    {0,0,0,5,1,0,0,0,0},
    {0,2,4,0,0,0,5,3,7},
    {2,5,0,0,4,1,0,8,0},
    {0,0,1,0,0,8,0,7,0},
    {0,0,0,0,0,0,0,2,0},
    {3,0,0,0,7,5,0,9,1},
    {6,0,8,0,2,0,7,0,0},
    {7,0,0,6,9,3,8,0,0}}; 
    int combinacao2[9][9]  = {
    {0,0,8,0,5,0,0,0,2},
    {0,2,0,0,9,0,0,4,1},
    {0,0,4,0,3,0,0,0,9},
    {0,0,0,0,0,0,0,1,8},
    {0,0,0,0,0,0,0,0,0},
    {5,7,0,4,0,0,2,0,0},
    {0,0,0,0,0,7,0,0,3},
    {0,0,7,0,6,0,4,0,0},
    {0,6,1,3,0,0,0,9,0}}; 

    if (decisao_menu == 1){
        jogo_verificacao(combinacao0);
    }
    else if (decisao_menu == 2){
        jogo_verificacao(combinacao1);
    }
    else if (decisao_menu == 3){
        jogo_verificacao(combinacao2);
    }
}

int main() 
{ 
    int decisao_menu;
	system ("color 0D");
    printf("|====================|\n"); 
    printf("|BEM VINDO AO SUDOKU |\n"); 
    printf("|====================|\n"); 
    printf("|  1 - Modo facil    |\n"); 
    printf("|  2 - Modo medio    |\n");
    printf("|  3 - Modo dificil  |\n");
	printf("|====================|\n");  
    scanf("%d", &decisao_menu); 
    if (decisao_menu == 1){ 
        escolher_matriz(decisao_menu); 
    } 
    else if (decisao_menu == 2){
        escolher_matriz(decisao_menu);
    }
    else if (decisao_menu == 3){
        escolher_matriz(decisao_menu); 
    }
    else if (decisao_menu < 0 && decisao_menu > 3){ 
        printf("Opcao nao encontrada. Até mais!!"); 
    } 
    
    return 0; 
}
