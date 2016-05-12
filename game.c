/*
** game.c for game.c in /Users/phe_c/Documents/Octocat/jerrai_y
** 
** Made by PHE Celine
** Login   <phe_c@etna-alternance.net>
** 
** Started on  Fri Jan 22 11:27:04 2016 PHE Celine
** Last update Fri Jan 22 16:17:32 2016 PHE Celine
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

int move(int x, int y, char labyrinthe[hauteur][longeur], char choice)
{
  if (choice == 'w' || choice == 's')
  {
    if (choice == 'w')
      labyrinthe[y-1][x] = '8';
    else
      labyrinthe[y+1][x] = '8';
  }
  else
  {
    if (choice == 'a')
      labyrinthe[y][x-1] = '8';
    else
      labyrinthe[y][x+1] = '8';
  }
  labyrinthe[y][x] = ' ';
  return (0);
}

int mode_casu ()
{
  char *buffer;
  int i;
  char replay;

  replay = ' ';
  buffer = get_map();
  i = 0;
  while (buffer[i] != '\n')
    i++;
  longeur = i;
  i = 0;
  while (buffer[i] != '\0')
    i++;
  hauteur = i / longeur;
  game_casu(buffer, hauteur, longeur);
  my_putstr("\nReplay ? (y/n) \n");
  if (getchar() == '\n')
  	replay = getchar();
  if (replay == 'y')
  	mode_casu();
  return (1);
}

int mode_hardcore ()
{
  char *buffer;
  int i;
  char replay;

  replay = ' ';
  buffer = get_map();
  i = 0;
  while (buffer[i] != '\n')
    i++;
  longeur = i;
  i = 0;
  while (buffer[i] != '\0')
    i++;
  hauteur = i / longeur;
  game_hard(buffer, hauteur, longeur);
  my_putstr("\nReplay ? (y/n) \n");
  if (getchar() == '\n')
  	replay = getchar();
  if (replay == 'y')
  	mode_hardcore();
  return (1);
}

int mode_blind ()
{
	char *buffer;
	int i;
  char replay;

	replay = ' ';
	buffer = get_map();
	i = 0;
	while (buffer[i] != '\n')
	i++;
	longeur = i;
	i = 0;
	while (buffer[i] != '\0')
	i++;
	hauteur = i / longeur;
	game_blind(buffer, hauteur, longeur);
	my_putstr("\nReplay ? (y/n)\n");
  if (getchar() == '\n')
  	replay = getchar();
 	if (replay == 'y')
  		mode_blind();
	return (1);
}

int mode_octa ()
{
	char *buffer;
	int i;
	char replay;

	replay = ' ';
	buffer = get_map();
	i = 0;
	while (buffer[i] != '\n')
	i++;
	longeur = i;
	i = 0;
	while (buffer[i] != '\0')
	i++;
	hauteur = i / longeur;
	game_octa(buffer, hauteur, longeur);
	my_putstr("\nReplay ? (y/n) \n");
  	if (getchar() == '\n')
  		replay = getchar();
  	if (replay == 'y')
  		mode_octa();
	return (1);
}
