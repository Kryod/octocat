/*
** game_hard.c for game_hard.c in /Users/phe_c/Documents/Octocat/jerrai_y
** 
** Made by PHE Celine
** Login   <phe_c@etna-alternance.net>
** 
** Started on  Fri Jan 22 11:29:43 2016 PHE Celine
** Last update Fri Jan 22 11:29:45 2016 PHE Celine
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "prototype.h"

char* get_map()
{
  int fp;
  char choix;
  static char buffer[1000];

  my_putstr("\e[1mChoose a map(1 ,2 or 3. Default 1):\e[0m\n");
  if (getchar() == '\n')
  {}
  choix = getchar();
  if (choix == '2')
    fp = open("map2", O_RDONLY);
  else if (choix == '3')
    fp = open("map3", O_RDONLY);
  else
    fp = open("map", O_RDONLY);
  read(fp, buffer, 1000);
  my_putstr("\n");
  close(fp);
  return (buffer);
}

int aff_hard(int hauteur, int longeur, char labyrinthe[hauteur][longeur], char choice)
{
	 usleep(90000);
    my_putstr("\033c");
    print_tab(hauteur, longeur, labyrinthe);
    return (deplacement(hauteur, longeur, labyrinthe, choice));
}

int lw_condition(int i, char a)
{
	if (a != 'w' && a != 'a'
      && a != 's' && a != 'd')
    {
      my_putstr("\e[31mYou loose !\e[0m\n");
      i = 0;
    }
    if (i == 2)
    {
      my_putstr("\e[32mYou win !\e[0m\n");
      i = 0;
    }
    return (i);
}

int boucle_hard(char* choice , int hauteur, int longeur, char labyrinthe[hauteur][longeur])
{
  int a;
  int i;
  i = 1;
  a = 0;
  while (1)
  {
  	i = aff_hard(hauteur, longeur, labyrinthe, choice[a]);
  	i = lw_condition(i, choice[a]);
    if (i == 0)
    {
	    free(choice);
      return (0);
    }
    a++;
  }
}

int game_hard(char* tab, int hauteur, int longeur)
{
  char *choice;
  char labyrinthe[hauteur][longeur];

  choice = malloc((hauteur * longeur)*sizeof(char));
  if (choice == NULL)
  	return 0;
  parse_tab(tab, hauteur, longeur, labyrinthe);/**/
  print_tab(hauteur, longeur, labyrinthe);
  my_putstr("\n\e[1mEnter the path (w, a, s and d): \e[0m\n");
  choice = readLine();
  return (boucle_hard(choice , hauteur, longeur, labyrinthe));
}
