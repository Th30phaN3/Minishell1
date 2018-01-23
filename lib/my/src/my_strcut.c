#include	<stdlib.h>

char		*my_strcut(char *src, int beg, int end)
{
  char		*res;
  int		i;
  int		j;

  j = 0;
  i = beg;
  if ((res = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
    return (NULL);
  while (j < end && src[i])
    res[j++] = src[i++];
  res[j] = 0;
  return (res);
}
