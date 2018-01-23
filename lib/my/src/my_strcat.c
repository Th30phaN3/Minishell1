#include	<stdlib.h>

char	*my_strcat(char *s1, char *s2)
{
  char	*res;
  int	i;
  int	j;
  int	len;

  if (s1 && s2)
    {
      len = my_strlen(s1) + my_strlen(s2);
      if ((res = malloc(sizeof(char) * (len + 1))) == NULL)
	return (NULL);
      j = 0;
      i = 0;
      while (s1[i])
	res[j++] = s1[i++];
      i = 0;
      while (s2[i])
	res[j++] = s2[i++];
      res[j] = 0;
    }
  else
    return (NULL);
  return (res);
}
