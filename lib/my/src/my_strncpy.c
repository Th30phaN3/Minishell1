#include	<stdio.h>

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  if (n <= 0 || dest == NULL || src == NULL)
    return (NULL);
  while (i < n && src[i])
    {
      dest[i] = src[i];
      i++;
    }
  if (i < n)
    dest[i] = '\0';
  return (dest);
}
