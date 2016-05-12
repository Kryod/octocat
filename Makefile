##
## Makefile for Makefile in /Users/phe_c/Documents/Octocat/jerrai_y
## 
## Made by PHE Celine
## Login   <phe_c@etna-alternance.net>
## 
## Started on  Fri Jan 22 15:46:48 2016 PHE Celine
## Last update Fri Jan 22 16:16:09 2016 PHE Celine
##

CC		=		gcc
NAME		=		octocat
SRC		=		maze.c 		\
				fonctions.c 	\
				game_octaview.c \
				game_blind.c 	\
				game_hard.c 	\
				game_casu.c 	\
				game.c 		\
				menu.c		
CFLAGS		=		-W -Wall -Wextra -Werror
RM		=		rm -f
OBJ		=		$(SRC:%.c=%.o)

$(NAME):			$(OBJ)
				$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

all:				$(NAME)

clean:
				$(RM) $(OBJ)

fclean:				clean
				$(RM) $(NAME)

re:				fclean all