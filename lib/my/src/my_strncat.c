char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[j])
    j++;
  while (i < nb)
    {
      dest[j] = src[i];
      i++;
      j++;
    }
  dest[j] = '\0';
  return (dest);
}
