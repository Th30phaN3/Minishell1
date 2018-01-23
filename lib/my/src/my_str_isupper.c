#include	<stdio.h>

int	my_str_isupper(char *str)
{
  int   c;

  c = 0;
  if (str[0] == '\0' || str == NULL)
    return (1);
  while (str[c])
    {
      if (str[c] >= 'A' && str[c] <= 'Z')
        c++;
      else
        return (0);
    }
  return (1);
}
