#include	"minishell1.h"

char		**my_cd(t_list *builtin, char **env, int i)
{
  i = i;
  if (builtin->opt[1] != NULL)
    {
      if (builtin->opt[2] == NULL)
	{
	  if (my_strcmp("-", builtin->opt[1]) == 0)
	    env = cd_minus(env, 0);
	  else
	    env = cd_with_arg(builtin, env);
	}
      else
	my_printf("cd: Too many arguments.\n");
    }
  else
    {
      if (var_exist(env, "HOME") == 0)
	env = cd_null(env, 0);
    }
  return (env);
}

char		**my_env(t_list *builtin, char **env, int i)
{
  builtin = builtin;
  if (env[0] != NULL)
    {
      while (env[i] != NULL)
	my_printf("%s\n", env[i++]);
    }
  return (env);
}

char		**my_unsetenv(t_list *builtin, char **env, int j)
{
  char		**nw_env;
  int		i;
  int		nb_var;
  int		len_t;

  len_t = tab_len(env);
  i = -1;
  if (env != NULL && (nb_var = all_var_exist(env, builtin->opt)) > 0)
    {
      while (env[++i] != NULL)
	if (compare_var(env[i], builtin->opt) == 0)
	  env[i] = NULL;
      i = -1;
      nw_env = my_memalloc(sizeof(char*) * (len_t - nb_var + 1));
      while (++i < len_t)
	if (env[i] != NULL)
	  nw_env[j++] = my_strdup(env[i]);
      nw_env[j] = NULL;
      free_tab(env);
      return (nw_env);
    }
  if (builtin->opt[1] == NULL)
    my_printf("unsetenv: Too few arguments.\n");
  return (env);
}

char		**my_setenv(t_list *builtin, char **env, int i)
{
  char		**nw_env;
  int		ok;

  if (builtin->opt[1] != NULL)
    {
      while (builtin->opt[i] != NULL)
	i++;
      if (i > 3)
	{
	  my_putstr("setenv: Too many arguments.\n");
	  return (env);
	}
      if ((ok = var_exist(env, builtin->opt[1])) != 0)
	nw_env = my_tabdup(env, tab_len(env) + 2);
      else
	nw_env = my_tabdup(env, tab_len(env) + 1);
      nw_env = next_setenv(nw_env, builtin, ok, 0);
      free_tab(env);
      return (nw_env);
    }
  my_env(builtin, env, 0);
  return (env);
}

char		**exit_builtin(t_list *builtin, char **env, int nb)
{
  if (builtin->opt[1] != NULL)
    {
      nb = my_getnbr(builtin->opt[1]);
      if (nb == 0 && is_only_zero(builtin->opt[1]) != 0)
	{
	  my_printf("exit: Expression Syntax.\n");
	  return (env);
	}
    }
  my_putstr("exit\n");
  my_free_list(builtin);
  free_tab(env);
  exit(nb);
  return (env);
}
