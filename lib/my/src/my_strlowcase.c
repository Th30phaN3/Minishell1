#include	<stdio.h>

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (NULL);
  while (*(str + i) > 0)
    {
      if ((*(str + i) <= 'Z' && *(str + i) >= 'A'))
	*(str + i) = *(str + i) + 32;
      i++;
    }
  return (str);
}
