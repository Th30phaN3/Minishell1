#include	<stdio.h>

char	*my_revstr(char *str)
{
  int	i;
  int	j;
  int	tmp;

  if (str == NULL)
    return (NULL);
  i = 0;
  j = my_strlen(str);
  j--;
  while (i <= j)
    {
      tmp = str[i];
      str[i] = str[j];
      str[j] = tmp;
      i++;
      j--;
    }
  return (str);
}
