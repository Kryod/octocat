/*
** game_octaview.c for game_octaview.c in /Users/phe_c/Documents/Octocat/jerrai_y
** 
** Made by PHE Celine
** Login   <phe_c@etna-alternance.net>
** 
** Started on  Fri Jan 22 11:30:11 2016 PHE Celine
** Last update Fri Jan 22 11:30:14 2016 PHE Celine
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

int print_tab_octa(int hauteur, int longeur, char labyrinthe[hauteur][longeur])
{
  int a;
  int b;
  int x;
  int y;

  x = 0;
  y = 0;
  while (labyrinthe[y][x] != '8')
  {
    if ((x+1) == longeur)
    {
      x = 0;
      y = y + 1;
    }
    else
      x++;
  }

  for (a = (y - 1); a <= (y+1) ; a++)
  {
    for (b = (x - 1); b <= (x+1)  ; b++)
        my_putchar(labyrinthe[a][b]);
    my_putstr("\n");
  }
  return (0);
}

int game_octa(char* tab, int hauteur, int longeur)
{
  char choice;
  char labyrinthe[hauteur][longeur];
  int i;

  i = 1;
  parse_tab(tab, hauteur, longeur, labyrinthe);
  while (1)
  {
    my_putstr("\033c");
    print_tab_octa(hauteur, longeur, labyrinthe);
    choice = choose_move();
    i = deplacement(hauteur, longeur, labyrinthe, choice);
    if (i == 2)
    {
      my_putstr("\e[32mYou win !\e[0m\n");
      i = 0;
    }
    if (i == 0)
      return (0);
  }
  my_putstr("\n");
}
