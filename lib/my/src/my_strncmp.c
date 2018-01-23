#include	<stdio.h>

int	my_strncmp(char *s1, char *s2, int n)
{
  int   i;

  i = 0;
  while (s1[i] != 0 && s2[i] != 0 && i < n - 1 && s1[i] == s2[i])
    i++;
  return (s1[i] - s2[i]);
}
