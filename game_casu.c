/*
** game_casu.c for game_casu.c in /Users/phe_c/Documents/Octocat/jerrai_y
** 
** Made by PHE Celine
** Login   <phe_c@etna-alternance.net>
** 
** Started on  Fri Jan 22 11:29:15 2016 PHE Celine
** Last update Fri Jan 22 11:29:17 2016 PHE Celine
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

void  my_putchar(char c)
{
  write (1, &c, 1);
}

char choose_move()
{
  char choice;

  choice = ' ';
  my_putstr("\n\e[1mChoose w, a, s or d.\e[0m\n");
  if (getchar() == '\n')
      choice =  getchar();
  while (choice != 'w' && choice != 'a' 
    && choice != 's' && choice != 'd')
  {
    my_putstr("\n\e[31mChoose w, a, s or d.\e[0m\n");
    if (getchar() == '\n')
      choice =  getchar();
  }
  return (choice);
}

int deplacement(int hauteur, int longeur, char labyrinthe[hauteur][longeur], char choice)
{
  int x;
  int y;
  int end;

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
  end = end_game(x, y, labyrinthe, choice);
  move(x, y, labyrinthe, choice);
  if (end == 0)
    my_putstr("\e[31mYou loose !\e[0m\n");
  return (end);
}

int game_casu(char* tab, int hauteur, int longeur)
{
  char choice;
  char labyrinthe[hauteur][longeur];
  int i;

  i = 1;
  parse_tab(tab, hauteur, longeur, labyrinthe);
  while (1)
  {
    my_putstr("\033c");
    print_tab(hauteur, longeur, labyrinthe);
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
