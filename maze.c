/*
** maze.c for  in /Users/phe_c/Documents/Octocat/jerrai_y
** 
** Made by PHE Celine
** Login   <phe_c@etna-alternance.net>
** 
** Started on  Fri Jan 22 11:30:30 2016 PHE Celine
** Last update Fri Jan 22 11:30:31 2016 PHE Celine
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

/*Cette fonction affiche les solutions des maps*/
int  soluce()
{
  char reponse;

  reponse = ' ';
  my_putstr("Solution (cheater...): \n\n");
  my_putstr("\e[1mmap 1 :\e[0m ddsssdddwwwddddssdddssdd\n");
  my_putstr("\e[1mmap 2 :\e[0m ddssdddddwddddddddddddddwdddddddddssddsssassaadss\n");
  my_putstr("\e[1mmap 3 :\e[0m ddssddddsssdsssddsddddddddwddddwdwddsdssdddwwdddsss\n");
  my_putstr("Do you want to quit?(y/n)\n");
  if (getchar() == '\n')
    reponse = getchar();
  if (reponse == 'y')
    return (0);
  else
  {
    my_putstr("\033c");
    return (1);
  }
}

int end_game(int x, int y, char labyrinthe[hauteur][longeur], char choice)
{

  if ((labyrinthe[y-1][x] == 'O' && choice == 'w')
    || (labyrinthe[y+1][x] == 'O' && choice == 's')
    || (labyrinthe[y][x-1] == 'O' && choice == 'a')
    || (labyrinthe[y][x+1] == 'O' && choice == 'd'))
    return (0);
  if ((labyrinthe[y-1][x] == 'E' && choice == 'w')
    || (labyrinthe[y+1][x] == 'E' && choice == 's')
    || (labyrinthe[y][x-1] == 'E' && choice == 'a')
    || (labyrinthe[y][x+1] == 'E' && choice == 'd'))
    return (2);
  return (1);
}

int parse_tab(char* tab, int hauteur, int longeur, char labyrinthe[hauteur][longeur])
{
  int x;
  int y;
  int a;
  char new_array[longeur*hauteur];
  int b;

  b = 0;
  a = 0;
  while (tab[a] != '\0')
  {
    if (tab[a] != '\n')
    {
      new_array[b] = tab[a];
      b++;
    }
    a++;
  }
  for (y = 0; y < hauteur ; y++)
  {
    for (x = 0; x < longeur ; x++)
    {
      labyrinthe[y][x] = new_array[(y*longeur)+x];
    }
  }
  return (0);
}

void color(int x, int y, char labyrinthe[hauteur][longeur])
{
  if (labyrinthe[y][x] == 'E')
  {
    my_putstr("\e[31m");
    my_putchar(labyrinthe[y][x]);
    my_putstr("\e[0m");
  }
  else if (labyrinthe[y][x] == '8')
  {
    my_putstr("\e[34m");
    my_putchar(labyrinthe[y][x]);
    my_putstr("\e[0m");
  }
  else if (labyrinthe[y][x] == 'O')
  {
    my_putstr("\e[32m");
    my_putchar(labyrinthe[y][x]);
    my_putstr("\e[0m");
  }
  
}

int print_tab(int hauteur, int longeur, char labyrinthe[hauteur][longeur])
{
  int x;
  int y;

  for (y = 0; y < hauteur ; y++)
  {
    for (x = 0; x < longeur ; x++)
    {
      if (labyrinthe[y][x] == 'E' || labyrinthe[y][x] == '8'
        || labyrinthe[y][x] == 'O')
        color(x, y, labyrinthe);
      else
        my_putchar(labyrinthe[y][x]);
    }
    my_putstr("\n");
  }
  return (0);
}
