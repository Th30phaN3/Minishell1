#include	"minishell1.h"

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  if (tab != NULL && tab[0] != NULL)
    {
      while (tab[i] != NULL)
	free(tab[i++]);
    }
  free(tab);
}

void            my_exit(char *str)
{
  my_putstr(str);
  exit(-1);
}

void            my_free_list(t_list *cmd)
{
  t_list        *tmp;
  t_list        *tp;

  while (cmd->nb != 0)
    cmd = cmd->next;
  tmp = cmd->next;
  while (tmp->nb != 0)
    {
      tp = tmp->next;
      free(tmp->name);
      free_tab(tmp->opt);
      free(tmp->redirect);
      free(tmp);
      tmp = tp;
    }
  free(tmp);
}

void            my_d_control(t_shell *shell)
{
  free_tab(shell->env);
  my_putstr("exit\n");
  exit(-42);
}
