#include	"minishell1.h"

char            *get_varenv(char *str)
{
  char          *res;
  int           i;

  i = 0;
  if ((res = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[i])
    {
      res[i] = str[i];
      i++;
    }
  res[i] = 0;
  return (res);
}

char            **fill_my_env(char **ae)
{
  char          **tab;
  int           i;

  i = 0;
  if ((tab = malloc(sizeof(char*) * (tab_len(ae) + 1))) == NULL)
    return (NULL);
  if (ae == NULL || ae[0] == NULL)
    tab[0] = NULL;
  else
    {
      while (ae[i] != NULL)
        {
          tab[i] = get_varenv(ae[i]);
          i++;
        }
      tab[i] = NULL;
    }
  return (tab);
}

char    *get_user(char **env)
{
  char  *user;
  int   i;
  int   j;
  int   k;
  int   ok;

  i = 0;
  j = 5;
  k = 0;
  if (env[0] == NULL)
    return (NULL);
  while (env[i] != NULL && ((ok = my_strncmp("USER=", env[i], 5)) != 0))
    i++;
  if (env[i] != NULL && ok == 0)
    {
      user = my_malloc(sizeof(char) * my_strlen(env[i]) - 4);
      while (env[i][j])
        user[k++] = env[i][j++];
      user[k] = 0;
      return (user);
    }
  return (NULL);
}
