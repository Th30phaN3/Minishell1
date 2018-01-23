#include	"minishell1.h"

int             spe_char(char c, int opt)
{
  if (opt == 0)
    {
      if (c == '|' || c == '>' || c == '<' || c == '&')
	return (1);
      return (0);
    }
  else
    {
      if (c == '|' || c == '>' || c == '<')
	return (1);
    }
  return (0);
}

int             my_count_char(char *s, char c)
{
  int           i;
  int           nb;

  i = 0;
  nb = 0;
  while (s[i])
    {
      if (s[i] == c)
        nb++;
      i++;
    }
  return (nb);
}

char            *epur_pipe_dash(char *str, int i, int j)
{
  char          *nw;

  if ((nw = malloc(sizeof(char) * my_strlen(str) + \
                   my_count_char(str, '-') + 1)) == NULL)
    return (NULL);
  while (str[i])
    {
      if (i > 0 && str[i] == '-' && str[i - 1] != ' ')
        nw[j++] = ' ';
      if (i < my_strlen(str) && str[i] == ' ' && \
	  ((spe_char(str[i + 1], 0) == 1) || str[i + 1] == ';'))
        i++;
      if (i > 0 && str[i] == ' ' && (spe_char(str[i - 1], 0) == 1))
        i++;
      nw[j++] = str[i++];
    }
  nw[j] = 0;
  free(str);
  if (redirect_sure(nw, 0) != 0)
    nw[0] = 0;
  return (nw);
}

char            *epur_str(char *str, int i, int j)
{
  char          *nw;

  if (str == NULL)
    return (NULL);
  nw = my_malloc(sizeof(char) * my_strlen(str) + 1);
  while (str[i] != 0 && (str[i] == ' ' || str[i] == '\t'))
    i++;
  while (str[i] != 0)
    {
      while (str[i] != 0 && str[i] != ' ' && str[i] != '\t')
        nw[j++] = str[i++];
      if (str[i] != 0 && (str[i] == ' ' || str[i] == '\t'))
        if (str[i + 1] != 0)
          nw[j++] = ' ';
      while (str[i] != 0 && (str[i] == ' ' || str[i] == '\t'))
        i++;
    }
  nw[j] = 0;
  if (j > 0 && nw[j - 1] == ' ')
    nw[j - 1] = 0;
  if ((nw = epur_pipe_dash(nw, 0, 0)) == NULL)
    return (NULL);
  return (nw);
}
