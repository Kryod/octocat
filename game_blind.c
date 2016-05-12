/*
** game_blind.c for game_blind.c in /Users/phe_c/Documents/Octocat/jerrai_y
** 
** Made by PHE Celine
** Login   <phe_c@etna-alternance.net>
** 
** Started on  Fri Jan 22 11:27:49 2016 PHE Celine
** Last update Fri Jan 22 11:27:56 2016 PHE Celine
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

int print_tab_blind(int hauteur, int longeur, char labyrinthe[hauteur][longeur])
{
  int x;
  int y;

  for (y = 0; y < hauteur ; y++)
  {
    for (x = 0; x < longeur ; x++)
    {
      if (labyrinthe[y][x] == '8' || labyrinthe[y][x] == 'E')
        my_putchar(labyrinthe[y][x]);
      else
        my_putchar(' ');
    }
    my_putstr("\n");
  }
  return (0);
}

int game_blind(char* tab, int hauteur, int longeur)
{
  char choice;
  char labyrinthe[hauteur][longeur];
  int i;

  i = 1;
  parse_tab(tab, hauteur, longeur, labyrinthe);
  while (1)
  {
    my_putstr("\033c");
    print_tab_blind(hauteur, longeur, labyrinthe);
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
