/*
** menu.c for menu.c in /Users/phe_c/Documents/Octocat/jerrai_y
** 
** Made by PHE Celine
** Login   <phe_c@etna-alternance.net>
** 
** Started on  Fri Jan 22 11:28:27 2016 PHE Celine
** Last update Fri Jan 22 11:28:47 2016 PHE Celine
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

/*Cette fonction est le manuel qui presente les differentes commandes.*/
int	man()
{
  char reponse;

  reponse = ' ';
  my_putchar('\n');
	my_putstr("\e[1mA\e[0m - In this mode of game, it's necessary to enter tour by tour the direction\n");
	my_putstr("\e[1mB\e[0m - In this mode of game, it's necessary to enter all the route to arrive at the exit.\n");
  my_putstr("\e[1mC\e[0m - In this mode of game, find the exit in pitch black.\n");
  my_putstr("\e[1mD\e[0m - In this mode of game, you can only see what's around you.\n");
	my_putstr("\e[1mH\e[0m - This choice allows to have acess to the man.\n");
	my_putstr("\e[1mQ\e[0m - This choice allows to leave the game.\n\n");
  my_putstr("Do you want to quit?(y/n) ");
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

/*Cette fonction sert a afficher le menu.*/
void	choice()
{
  my_putstr("  ______     ______  ___________   ______     ______     ___    ___________ \n");
  my_putstr(" /  __  \\   /      ||           | /  __  \\   /      |   /   \\  |           |\n");
  my_putstr("|  |  |  | |  ,----'`---|  |----`|  |  |  | |  ,----'  /  ^  \\ `---|  |----`\n");
  my_putstr("|  |  |  | |  |         |  |     |  |  |  | |  |      /  /_\\  \\    |  |\n");
  my_putstr("|  `--'  | |  `----     |  |     |  `--'  | |  `----./  _____  \\   |  |\n");
  my_putstr(" \\______/   \\_____|     |__|      \\______/   \\______/__/     \\__\\  |__|\n");
  my_putstr("\n\n\e[1mWelcome little octocat... Today, you're mission is to cross the four different labyrinths...\e[0m\n\n\n");
	my_putstr("                    [ \e[1mA\e[0m ] - Mode \e[1mCasu\e[0m\n");
	my_putstr("                    [ \e[1mB\e[0m ] - Mode \e[1mHardcore\e[0m\n");
  my_putstr("                    [ \e[1mC\e[0m ] - Mode \e[1mBlind\e[0m\n");
  my_putstr("                    [ \e[1mD\e[0m ] - Mode \e[1mOctaview\e[0m\n");
	my_putstr("                    [ \e[1mH\e[0m ] - Help\n"); /*Fonction man*/
	my_putstr("                    [ \e[1mQ\e[0m ] - Quit\n\n"); /*Fonction exitgame*/
}

/*Cette fonction permet de quitter le jeu.*/
int		exitgame()
{
	my_putstr("\n\e[1mSee you soon !\e[0m\n");
	return (0);
}

/*Cette fonction permet de choisir A, B, H ou Q.*/
int	choose()
{ 
  char menu;

	my_putstr("\n\n\e[1mChoose menu :\e[0m");
	my_putstr("\n");
	menu =  getchar();
  my_putstr("\n");
  while (menu != 'A' && menu != 'B' 
    && menu != 'H' && menu != 'Q'
    && menu != 'C' && menu != 'D'
    && menu != 'S')
  {
     menu = '\0';
    my_putstr("\e[1mChoose A, B, C, D, H, Q.\e[0m\n");
    if (menu == '\0')
      menu =  getchar();
  }
  return (menu-65);
}

/*Fonction principale*/
int main()
{
  int c;
  int i;

  c = 0;
  i = 1;
  my_putstr("\033c");
  while (i != 0)
  {
  	choice();
  	c = choose();
    int (*tab[19]) ();
    tab[0] = &mode_casu;
    tab[1] = &mode_hardcore;
    tab[2] = &mode_blind;
    tab[3] = &mode_octa;
    tab[7] = &man;
    tab[16] = &exitgame;
    tab[18] = &soluce;

    if (tab[c])
      i = tab[c](c);
    else
      my_putstr("\e[1mChoose A, B, C, D, H ,Q or S.\e[0m\n");
  }
  return (0);
}
