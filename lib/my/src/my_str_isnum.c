#include	<stdio.h>

int	my_str_isnum(char *str)
{
  int   c;

  c = 0;
  if (str[0] == '\0' || str == NULL)
    return (1);
  while (str[c])
    {
      if (str[c] >= '0' && str[c] <= '9')
        c++;
      else
        return (0);
    }
  return (1);
}
