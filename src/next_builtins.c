#include	"minishell1.h"

int		compare_var(char *str, char **opt)
{
  int		i;

  i = 1;
  while (opt[i] != NULL)
    {
      if (my_spe_compare(str, opt[i], my_strlen(opt[i])) == 0)
	return (0);
      i++;
    }
  return (-1);
}

int		all_var_exist(char **env, char **opt)
{
  int		nb;
  int		i;
  int		j;

  j = 1;
  nb = 0;
  while (opt[j] != NULL)
    {
      i = 0;
      while (env[i] != NULL)
	{
	  if (my_spe_compare(env[i], opt[j], my_strlen(opt[j])) == 0)
	    nb++;
	  i++;
	}
      j++;
    }
  return (nb);
}

int             var_exist(char **env, char *str)
{
  int           i;

  i = 0;
  while (env[i] != NULL && \
	 my_spe_compare(env[i], str, my_strlen(str)) != 0)
    i++;
  if (env[i] != NULL)
    return (0);
  return (-1);
}

char            *create_var_env(char *name, char *value)
{
  char          *res;
  int           i;
  int           j;

  i = 0;
  j = 0;
  if (value == NULL)
    res = my_malloc(sizeof(char) * my_strlen(name) + 2);
  else
    res = my_malloc(sizeof(char) * (my_strlen(name) + my_strlen(value) + 2));
  while (name[i])
    res[j++] = name[i++];
  res[j++] = '=';
  if (value != NULL)
    {
      i = 0;
      while (value[i])
        res[j++] = value[i++];
    }
  res[j] = 0;
  return (res);
}

char            **next_setenv(char **env, t_list *builtin, int ok, int i)
{
  if (ok != 0)
    {
      while (env[i] != NULL)
        i++;
      env[i++] = create_var_env(builtin->opt[1], builtin->opt[2]);
      env[i] = NULL;
    }
  else
    {
      while (env[i] != NULL && \
             my_spe_compare(env[i], builtin->opt[1], \
			    my_strlen(builtin->opt[1])) != 0)
        i++;
      if (env[i] != NULL)
        env[i] = create_var_env(builtin->opt[1], builtin->opt[2]);
    }
  return (env);
}
