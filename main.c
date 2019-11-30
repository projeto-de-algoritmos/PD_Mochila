/* Alunos: Joao Pedro Mota Jardim         - 16/0031982
           Paulo Victor de Menezes Lopes  - 16/0016428
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_VALOR 10
#define MAX_PESO 10
#define MAX_PESO_MOCHILA 40



int max(int a, int b) { return (a > b)? a : b; }

int knapSack(int pesoMochila, int peso[], int valor[], int nItens)
{
   int i, w;
   int K[nItens+1][pesoMochila+1];

   for (i = 0; i <= nItens; i++)
   {
       for (w = 0; w <= pesoMochila; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (peso[i-1] <= w)
                 K[i][w] = max(valor[i-1] + K[i-1][w-peso[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[nItens][pesoMochila];
}

void geraItensManual(int nItens, int *valor, int *peso);
void geraMochilaManual(int *pesoMochila);
int mostraMenu();

int main()
{
    int i, nItens, *valor, *peso, pesoMochila,opcao;
    srand(time(NULL));
    do{
      opcao = mostraMenu();
      switch(opcao){
        case 1:
          printf("Insira o numero de itens: ");
          scanf("%d", &nItens);
          valor = (int*)malloc(sizeof(int)*nItens);
          peso  = (int*)malloc(sizeof(int)*nItens);
          for(i = 0 ; i < nItens ; i++){
            valor[i] = rand() % MAX_VALOR +1;
            peso[i] = rand() % MAX_PESO +1;
          }
          for(int i = 0; i < nItens; i++){
            printf("Valor e o peso do item %d: %d e %d\n", i+1 , valor[i], peso[i]);
          }
          break;
        case 2:
          printf("Insira o numero de itens: ");
          scanf("%d", &nItens);
          valor = (int*)malloc(sizeof(int)*nItens);
          peso  = (int*)malloc(sizeof(int)*nItens);
          geraItensManual(nItens,valor,peso);
          printf("main\n" );
          for(int i = 0; i < nItens; i++){
            printf("Valor e o peso do item %d: %d e %d\n", i+1 , valor[i], peso[i]);
          }
          break;
        case 3:
          pesoMochila = rand() % MAX_PESO_MOCHILA +1;
          printf("Peso da Mochila: %d\n",pesoMochila);
          break;
        case 4:
          geraMochilaManual(&pesoMochila);
          break;
        case 5:
          printf("Maior valor da mochila = %d\n", knapSack(pesoMochila, peso, valor, nItens));
    }
  }while(opcao != 0);

    free(valor);
    free(peso);
    return 0;
}

void geraItens(){

}

void geraItensManual(int nItens, int *valor, int *peso){

  for(int i = 0;i < nItens; ++i){
      printf("Insira o valor do item %d: ", i+1);
      scanf("%d", &valor[i]);
      printf("Insira o peso do item %d: ", i+1);
      scanf("%d", &peso[i]);
  }
  for(int i = 0; i < nItens; i++){
    printf("Valor e o peso do item %d: %d e %d\n", i+1 , valor[i], peso[i]);
  }
}

void geraMochilaManual(int *pesoMochila){
  printf("Insira o peso da mochila: ");
  scanf("%d", pesoMochila);

}

int mostraMenu(){
  int opcao;
  //system("clear");
  printf("\n");
  printf(" ========================================\n");
  printf("|         >>>>>>>>> Menu <<<<<<<<<       |\n");
  printf("| 1 - Gerar itens aleatorios             |\n");
  printf("| 2 - Gerar itens manuais                |\n");
  printf("| 3 - Gerar tamanho da mochila aleatorio |\n");
  printf("| 4 - Gerar tamanho da mochila manual    |\n");
  printf("| 5 - Rodar algoritmo da mochila         |\n");
  printf("| 0 - Sair                               |\n");
  printf(" ========================================\n");
  printf("Sua opcao: ");
  scanf("%d",&opcao);
  return opcao;
}
