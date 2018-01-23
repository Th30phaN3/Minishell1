#include	"minishell1.h"

int	is_only_zero(char *str)
{
  int	i;
  int	ok;

  i = 0;
  ok = 0;
  if (str != NULL)
    {
      while (str[i])
	{
	  if (str[i] != '0')
	    ok = -1;
	  i++;
	}
    }
  else
    ok = -1;
  return (ok);
}

int	my_spe_compare(char *varenv, char *arg, int len_arg)
{
  int	i;
  int	ok;

  ok = 0;
  i = 0;
  while (varenv[i] && varenv[i] != '=')
    {
      if (arg[i] == 0 && varenv[i] != '=')
	return (-1);
      if (varenv[i] != arg[i])
	ok = -1;
      i++;
    }
  if (i != len_arg || ok == -1)
    ok = -1;
  return (ok);
}

char    *my_malloc(int size)
{
  char  *str;
  int   i;

  i = 0;
  if ((str = malloc(size)) == NULL)
    exit(EXIT_FAILURE);
  while (i < size)
    str[i++] = 0;
  return (str);
}

void            *my_memalloc(int size)
{
  char          *ptr;

  if (size <= 0)
    return (NULL);
  ptr = my_malloc(size * sizeof(*ptr));
  return ((void*)ptr);
}

char		**new_env_with_pwd(char **env, char *oldpwd, char *pwd)
{
  char		**nw_env;
  int		i;
  int		o;
  int		p;

  o = 0;
  p = 0;
  if (var_exist(env, "PWD") != 0)
    p++;
  if (var_exist(env, "OLDPWD") != 0)
    o++;
  i = tab_len(env);
  nw_env = my_tabdup(env, i + o + p + 1);
  if (o > 0)
    nw_env[i++] = create_var_env("OLDPWD", oldpwd);
  if (p > 0)
    nw_env[i++] = create_var_env("PWD", pwd);
  nw_env[i] = NULL;
  return (nw_env);
}
