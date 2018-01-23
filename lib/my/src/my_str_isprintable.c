#include	<stdio.h>

int	my_str_isprintable(char *str)
{
  int   c;

  c = 0;
  if (str[0] == '\0' || str == NULL)
    return (1);
  while (str[c] != '\0')
    {
      if (str[c] >= 32 && str[c] <= 126)
        c++;
      else
        return (0);
    }
  return (1);
}
