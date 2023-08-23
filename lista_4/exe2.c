#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 30
#define MAX_NAME_LENGTH 100

int main()
{
  char players[MAX_PLAYERS][MAX_NAME_LENGTH];
  char currentBobinho[MAX_NAME_LENGTH];
  char loser[MAX_NAME_LENGTH], stealer[MAX_NAME_LENGTH];
  int numPlayers = 0;
  int numRoubadas = 0;
  int i, j;

  while (1)
  {
    scanf("%s", players[numPlayers]);
    if (strcmp(players[numPlayers], "Fim") == 0)
    {
      break;
    }
    numPlayers++;
  }

  scanf("%s", currentBobinho);
  scanf("%d", &numRoubadas);

  for (i = 0; i < numRoubadas; i++)
  {
    scanf("%s %s", loser, stealer);

    int indexLoser = -1;
    int indexStealer = -1;

    for (j = 0; j < numPlayers; j++)
    {
      if (strcmp(players[j], loser) == 0)
      {
        indexLoser = j;
      }
      if (strcmp(players[j], stealer) == 0)
      {
        indexStealer = j;
      }
    }

    if (indexLoser != -1 && indexStealer != -1)
    {
      // Atualizar a posição do jogador perdedor na lista
      // para a posição do jogador que roubou a bola
      strcpy(players[indexLoser], players[indexStealer]);
    }
  }

  // Encontrar o índice do jogador que começa como bobinho
  int currentIndex = -1;
  for (i = 0; i < numPlayers; i++)
  {
    if (strcmp(players[i], currentBobinho) == 0)
    {
      currentIndex = i;
      break;
    }
  }

  // Remover jogadores da roda até que reste apenas um
  while (numPlayers > 1)
  {
    // O índice do jogador a ser removido
    int removeIndex = (currentIndex + numRoubadas - 1) % numPlayers;

    // Imprimir o jogador que foi removido (opcional, para debug)
    printf("Removendo: %s\n", players[removeIndex]);

    // Remover o jogador atual da roda
    for (i = removeIndex; i < numPlayers - 1; i++)
    {
      strcpy(players[i], players[i + 1]);
    }

    // Atualizar o índice atual para o próximo jogador
    currentIndex = removeIndex % (numPlayers - 1);

    numPlayers--;
  }

  printf("Vencedor: %s\n", players[0]);

  return 0;
}
