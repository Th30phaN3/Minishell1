#include	"minishell1.h"

int		is_builtin(char *str)
{
  if (my_strcmp(str, "cd") == 0 || my_strcmp(str, "env") == 0 || \
      my_strcmp(str, "unsetenv") == 0 || my_strcmp(str, "setenv") == 0 || \
      my_strcmp(str, "exit") == 0)
    return (0);
  return (-1);
}

char		**exec_builtin(t_list *builtin, char **env)
{
  t_built	built[5] = {{"cd", my_cd},
			    {"env", my_env},
			    {"unsetenv", my_unsetenv},
			    {"setenv", my_setenv},
			    {"exit", exit_builtin},
  };
  int		i;
  int		ok;

  i = 0;
  ok = 0;
  while (i < 5)
    {
      if (my_strcmp(builtin->name, built[i].str) == 0 && ok == 0)
	{
	  env = built[i].f(builtin, env, 0);
	  ok = 1;
	}
      i++;
    }
  return (env);
}

int		exec_normal_cmd(t_shell *shell, char **path)
{
  char		*bin;

  if (bin_exist(path, shell->cmd->opt[0], 0) == 1)
    exec_binpath(shell, path);
  else
    {
      if (check_line(shell->cmd->opt) == 1)
	{
	  bin = shell->cmd->opt[0];
	  if (exec_bin(bin, shell) == -1)
	    {
	      my_printf("%s: Command not found.\n", shell->cmd->name);
	      shell->cmd->good = -1;
	      return (-1);
	    }
	  free(bin);
	}
      else
	{
	  shell->cmd->good = -1;
	  my_printf("%s: Command not found.\n", shell->cmd->name);
	  return (-1);
	}
    }
  return (0);
}

int		do_it(t_shell *shell, int nb)
{
  char		**path;

  path = get_paths(shell->env);
  if (is_builtin(shell->cmd->name) == 0)
    {
      shell->env = exec_builtin(shell->cmd, shell->env);
      shell->cmd = shell->cmd->prev;
      nb = shell->cmd->nb;
    }
  else
    {
      if (shell->cmd->name[0] != 0)
	exec_normal_cmd(shell, path);
      if (shell->nw_fd == REDIRECT_F)
	shell->cmd = shell->cmd->prev;
      shell->cmd = shell->cmd->prev;
      nb = shell->cmd->nb;
    }
  free_tab(path);
  return (nb);
}

int		exec_cmd(t_shell *shell)
{
  int		nb;

  nb = 0;
  shell->nw_fd = NO_REDIRECT;
  shell->old_fd = NO_REDIRECT;
  while (shell->cmd->nb != 0)
    shell->cmd = shell->cmd->next;
  if ((nb = do_it(shell, nb)) == -1)
    return (-1);
  while (nb != 0 && shell->cmd->name[0] != 0)
    {
      if ((nb = do_it(shell, nb)) == -1)
	return (-1);
    }
  return (0);
}
