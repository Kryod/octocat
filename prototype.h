/*
** prototype.h for prototype.h in /Users/phe_c/Documents/Octocat/jerrai_y
** 
** Made by PHE Celine
** Login   <phe_c@etna-alternance.net>
** 
** Started on  Fri Jan 22 15:50:06 2016 PHE Celine
** Last update Fri Jan 22 16:19:20 2016 PHE Celine
*/

#ifndef PROTOTYPE
# define PROTOTYPE
int longeur;
int hauteur;

void  	my_putchar(char c);
void  	my_putstr(char *str);
char*	readLine();
char*	my_strcpy(char *dest, char *src);
int 	mode_casu ();
int 	mode_hardcore ();
void	my_put_nbr(int n);
int	end_game(int x, int y, char labyrinthe[hauteur][longeur], char choice);
int 	move(int x, int y, char labyrinthe[hauteur][longeur], char choice);
char* 	get_map();
int 	parse_tab(char* tab, int hauteur, int longeur, char labyrinthe[hauteur][longeur]);
int 	print_tab(int hauteur, int longeur, char labyrinthe[hauteur][longeur]);
char 	choose_move();
int 	deplacement(int hauteur, int longeur, char labyrinthe[hauteur][longeur], char choice);
int 	game_casu(char* tab, int hauteur, int longeur);
int 	boucle_hard(char* choice , int hauteur, int longeur, char labyrinthe[hauteur][longeur]);
int 	game_hard(char* tab, int hauteur, int longeur);
int 	print_tab_blind(int hauteur, int longeur, char labyrinthe[hauteur][longeur]);
int 	game_blind(char* tab, int hauteur, int longeur);
int 	mode_blind ();
int 	game_blind(char* tab, int hauteur, int longeur);
int 	print_tab_octa(int hauteur, int longeur, char labyrinthe[hauteur][longeur]);
int 	mode_octa ();
int 	game_octa(char* tab, int hauteur, int longeur);
int 	aff_hard(int hauteur, int longeur, char labyrinthe[hauteur][longeur], char choice);
int 	lw_condition(int i, char a);
int 	soluce();
void 	color(int x, int y, char labyrinthe[hauteur][longeur]);

#endif
