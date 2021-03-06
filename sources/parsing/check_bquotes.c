/*
** chek_bqotes.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Fri May 20 06:37:19 2016 boris saint-bonnet
** Last update Sat Jun  4 02:59:22 2016 boris saint-bonnet
*/

# include "42.h"

int		check_bquotes(char *str)
{
  int		i;
  int		nb;

  nb = 0;
  i = -1;
  while (str[++i])
    if (str[i] == '`')
      nb++;
  return (nb == 2 ? SUCCESS : FAILURE);
}

char		*my_bquotes(char *str)
{
  int		beg;
  int		i;

  i = -1;
  if (!str)
    return (NULL);
  if (check_bquotes(str) == -1)
    return (str);
  while (str[++i] != '`');
  beg = i;
  while (str[++i] != '`');
  return (my_strcut(str, (beg + 1), 0, (strlen(str) - i)));
}
