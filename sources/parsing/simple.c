/*
** check_error.c for  in /home/xx/Rendu/PSU/42SH
** 
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
** 
** Started on  Fri May 20 07:28:50 2016 boris saint-bonnet
** Last update Sat Jun  4 04:14:43 2016 boris saint-bonnet
*/

#include "42.h"

void    simple_first(t_pars *var, char c)
{
  if (var->ret[0] == c && var->ret[1] && var->ret[1] != c &&
      var->ret[1] != ' ' && var->ret[2])
    {
      var->bef = my_strcut(var->ret, 0, 1, 0);
      var->aft = my_strcut(var->ret, 1, 0, 0);
      xfree(var->ret);
      var->ret = my_strcatc(var->bef, var->aft, 3, 0);
      xfree(var->aft);
    }
}

char    *simples(char *s, char c)
{
  t_pars        var;

  var.ret = strdup(s);
  xfree(s);
  simple_first(&var, c);
  while ((check_finish(var.ret, c, 1) == -1))
    {
      var.i = -1;
      while (var.ret[++var.i])
	{
	  if (var.ret[var.i] == c && var.ret[var.i + 1] != c &&
	      var.ret[var.i - 1] != c && var.ret[var.i - 1] != ' ')
	    {
	      var.bef = my_strcut(var.ret, 0, (var.i), 0);
	      var.aft = my_strcut(var.ret, (var.i), 0, 0);
	      xfree(var.ret);
	      var.ret = my_strcatc(var.bef, var.aft, 3, 0);
	      xfree(var.aft);
	    }
	  if (var.ret[var.i] == c && var.ret[var.i + 1] != c &&
	      var.ret[var.i - 1] != c && var.ret[var.i + 1] != ' ')
	    simple_space_after(&var);
	}
    }
  return (var.ret);
}

void    simple_space_after(t_pars *var)
{
  var->bef = my_strcut(var->ret, 0, (var->i + 1), 0);
  var->aft = my_strcut(var->ret, (var->i + 1), 0, 0);
  xfree(var->ret);
  var->ret = my_strcatc(var->bef, var->aft, 3, 0);
  xfree(var->aft);
}
