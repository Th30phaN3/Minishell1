#include	"minishell1.h"

void    aff_prompt(char **env)
{
  char  *name;

  if ((name = get_user(env)) != NULL)
    {
      my_putstr(name);
      my_putstr("->");
      free(name);
    }
  else
    my_putstr("$>");
}

void		get_cmd(t_shell *shell)
{
  char		*s;

  s = get_next_line(0);
  shell->buff = epur_str(s, 0, 0);
  free(s);
}

int		my_shell(t_shell *shell)
{
  while (42)
    {
      signal(SIGINT, catch_sigint);
      aff_prompt(shell->env);
      get_cmd(shell);
      if (shell->buff == NULL)
	my_d_control(shell);
      if (shell->buff[0] != 0 && shell->buff[0] != '\n')
	{
	  parse_cmd(shell->buff, &shell->cmd);
	  exec_cmd(shell);
	  my_free_list(shell->cmd);
	  free(shell->buff);
	}
    }
  free_tab(shell->env);
  return (0);
}

int		main(int ac, char **av, char **ae)
{
  t_shell	*shell;

  (void)ac;
  (void)av;
  if ((shell = malloc(sizeof(*shell))) == NULL)
    my_exit("Minishell initialisation failed.\n");
  shell->env = fill_my_env(ae);
  my_shell(shell);
  return (0);
}
