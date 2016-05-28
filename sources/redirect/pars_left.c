/*
** pars_left.c for  in /home/xx/Rendu/PSU/42SH
**
** Made by boris saint-bonnet
** Login   <saint-_o@epitech.net>
**
** Started on  Wed May 25 05:11:17 2016 boris saint-bonnet
** Last update Sat May 28 10:33:09 2016 Gambini Lucas
*/

# include 		"42.h"

int			dep_init_left(char **cmd, t_red *var, int *i, int *j)
{
  if (*i == 1)
    {
      var->cmd[0] = strdup(cmd[++(*i)]);
      while (cmd[++(*i)] && strcmp(cmd[*i], "<") != 0)
	var->cmd[(*j)++] = strdup(cmd[*i]);
      var->cmd[*j] = NULL;
      return (FAILURE);
    }
  else
    {
      *i = 1;
      var->cmd[0] = strdup(cmd[0]);
      while (cmd[*i] && strcmp(cmd[*i], "<") != 0)
	var->cmd[(*j)++] = strdup(cmd[(*i)++]);
      var->cmd[*j] = NULL;
      return (FAILURE);
    }
  return (SUCCESS);
}

void            	init_simpleleft(char **cmd, t_red *var)
{
  int           	i;
  int           	j;

  i = -1;
  j = 1;
  if ((var->cmd = malloc((tab_lenght(cmd)) * sizeof(char*))) == NULL)
    my_exit(42);
  var->cmd[tab_lenght(cmd) - 1] = NULL;
  while (cmd[++i])
    {
      if ((strcmp(cmd[i], "<")) == 0)
	{
	  if (!(cmd[i + 1]))
	    {
	      fprintf(stderr, "Error: parsing nears '%c'\n", cmd[i][0]);
	      var->name = NULL;
	      return;
	    }
	  var->name = strdup(cmd[++i]);
	  if (dep_init_left(cmd, var, &i, &j) == FAILURE)
	    break;
	}
    }
}
