#include <stdio.h>

// Tamanho do tabuleiro
# define N 10

// Função para exibir o tabuleiro
void exibirTabuleiro (int tabuleiro [N][N]){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            printf("%d", tabuleiro [i][j]); //Exibe as células do tabuleiro
        }
        printf("\n");
    }
}

// Função para posicionar o navio horizontalmente
int posicionarNavioHorizontal (int tabuleiro [N][N], int linha, int coluna, int tamanho){
    //Verifica se a posição inicial e o tamanho do navio são válidos
    if (coluna + tamanho > N){
        printf("Navio horizontal não cabe no tabuleiro\n");
        return 0; //Posição inválida
    }

    //Verificar se as células ond o navio será posicionado estão livres
    for (int i=0; i<tamanho; i++){
        if (tabuleiro [linha][coluna + i] !=0){
            printf(" O navio se sobrepoe a outro navio!\n");
            return 0; // Há sobreposição
        }
    }

    // Posiciona o navio horizontalmente
    for (int i = 0; i < tamanho; i++){
        tabuleiro[linha][coluna + i]=3; //Marcar célula com 3
    }
    return 1;
}

//Função para posicionar o navio verticalmente
int posicionarNavioVertical (int tabuleiro [N][N], int linha, int coluna, int tamanho){
    // Verifica se a posição inicial e a posição do navio são válidos
    if (linha + tamanho >N){
        printf(" Navio vertical não cabe no tabuleiro !\n");
        return 0;
    }

    //Verifica se as células onde o navio será posicionado estão livres
    for (int i = 0; i < tamanho; i++){
        if (tabuleiro [linha + i][coluna] !=0){
            printf ("O navio se sobrepoe a outro navio !\n");
            return 0; // Há sobreposição
        }
    }

    // Posiciona o navio verticalmente
    for (int i=0; i<tamanho; i++){
        tabuleiro[linha+i][coluna]=3; //Marcar a célula com 3 (parte do navio)
    }
    return 1;
}

int main(){
    //Inicializa o tabuleiro com água (0 em todas as células)
    int tabuleiro [N][N] = {0};

    //Coordenadas
    int linhaHorizontal = 2, colunaHorizontal = 3;
    int linhaVertical = 5, colunaVertical = 6;
    int tamanhoNavio = 3;

    //Posicionar os navios
    if (posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal, tamanhoNavio)){
        printf(" Navio horizontal posicionado com sucesso\n");
    }

    if (posicionarNavioVertical (tabuleiro, linhaVertical, colunaVertical, tamanhoNavio)){
        printf ("Navio vertical posicionado com sucesso\n");
    }

    //Exibe o tabuleiro com os navios posicionados
    printf("\n Tabuleiro após o posicionamento dos navios:\n");
    exibirTabuleiro (tabuleiro);
    return 0;
}