/*
** fonctions.c for fonctions.c in /Users/phe_c/Documents/Octocat/jerrai_y
** 
** Made by PHE Celine
** Login   <phe_c@etna-alternance.net>
** 
** Started on  Fri Jan 22 11:28:58 2016 PHE Celine
** Last update Fri Jan 22 16:17:19 2016 PHE Celine
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

void  my_put_nbr(int n);

void	my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str++;
    }
}

char  *readLine()
{
  ssize_t	ret;
  char		*buff;

  if ((buff = malloc(sizeof (*buff) * (100 + 1))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 100)) > 1)
    {
      buff[ret - 1] = '\0';
      return (buff);
    }
  buff[0] = '\0';
  return (buff);
}

char  *my_strcpy(char *dest, char *src)
{
  int	 s;

  s = 0;
  while (src[s] != '\0')
    {
      dest[s] = src[s];
      s++;
    }
  return (dest);
}

void	la_boucle(int c)
{
  if (c >= 10 || c < 0)
    {
      my_put_nbr(c / 10);
      my_put_nbr(c % 10);
    }
  else
    {
      my_putchar(c + 48);
    }
}

void	my_put_nbr(int n)
{
  int c;
  
  c = n;
  if (c < 10 && c >= 0)
    {
      my_putchar(c + 48);
    }
  else if (c > 9)
    {
      la_boucle(c);
    }
  else if (n == -2147483648)
    {
      my_putstr("-2147483648");
    }
  else
    {
      my_putchar('-');
      c = -1 * c;
      la_boucle(c);
    }
}
