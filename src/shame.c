#include	"minishell1.h"

int             redirect_ok_next(char *s, int i, int j, int k)
{
  int           ok;

  ok = 0;
  if (spe_char(s[0], 0) == 1 || \
      (i > 0 && spe_char(s[i], 0) == 1 && s[i - 1] == ';'))
    ok = -2;
  if (s[i] == '|' && (s[j] == '\0' || s[j] == ';' || s[j] == '&'))
    ok = -2;
  if (j < my_strlen(s) && s[i] == '|' && s[j] == '|' &&
      (s[k] == '\0' || s[k] == ';' || s[k] == '&' || s[k] == '|'))
    ok = -2;
  if (s[i] == '&' && (s[j] == 0 || s[j] == '|' || \
		      s[j] == '>' || s[j] == '<' || s[j] == ';'))
    ok = -2;
  if (s[i] == '&' && (s[j] != '&' && i > 0 && s[i - 1] != '&'))
    ok = -2;
  if (j < my_strlen(s) && s[i] == '&' && s[j] == '&' &&
      (s[k] == '\0' || s[k] == ';' || s[k] == '&' || s[k] == '|'))
    ok = -2;
  if (ok == -2)
    my_putstr("Invalid null command.\n");
  return (ok);
}

int             redirect_ok(char *s, int i, int j, int k)
{
  int           ok;

  ok = 0;
  if (s[i] == '|' && (s[j] == '>' || s[j] == '<'))
    ok = -1;
  if (s[i] == '<' && (s[j] == '>' || s[j] == ';' || \
		      s[j] == 0 || s[j] == '&' || s[j] == '|'))
    ok = -1;
  if (s[i] == '>' && (s[j] == '<' || s[j] == ';' || \
		      s[j] == 0 || s[j] == '&' || s[j] == '|'))
    ok = -1;
  if (j < my_strlen(s) && s[i] == '>' && s[j] == '>' && \
      (s[k] == '>' || s[k] == '<' || s[k] == '|' || s[k] == '&' || s[k] == 0))
    ok = -1;
  if (j < my_strlen(s) && s[i] == '<' && s[j] == '<' && \
      (s[k] == '<' || s[k] == '>' || s[k] == '|' || s[k] == '&' || s[k] == 0))
    ok = -1;
  if (ok != -1)
    ok = redirect_ok_next(s, i, j, k);
  else
    my_putstr("Missing name for redirect.\n");
  return (ok);
}

int		redirect_sure(char *s, int i)
{
  while (s[i])
    {
      if (spe_char(s[i], 0) == 1)
	{
	  if (i < my_strlen(s) && redirect_ok(s, i, i + 1, i + 2) != 0)
	    return (-1);
	}
      i++;
    }
  return (0);
}
