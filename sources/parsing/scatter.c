/*
** scatter.c for scatter in /home/gambin_l/Shared/42SH
**
** Made by Lucas Gambini
** Login   <gambin_l@epitech.net>
**
** Started on  Mon May 23 16:43:07 2016 Lucas Gambini
** Last update Wed May 25 08:43:38 2016 Gambini Lucas
*/

#include	"42.h"

int		exec_scatter(t_list *list)
{
  char		**env;
  t_cmd		*tmp;
  int		builtin;

  tmp = list->head;
  env = extract_env(list->myEnv);
  while (tmp && tmp->cmd[0])
    {
      if ((builtin = check_built(tmp)) == FAILURE && tmp->go_on == 1)
	normal_scatter(tmp, env, list->path);
      /*else
	builtin_scatter(list, tmp, builtin);*/
      tmp = tmp->next;
    }
  free_tab(env);
  return (SUCCESS);
}
