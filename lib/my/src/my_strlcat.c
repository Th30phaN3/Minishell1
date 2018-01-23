int	my_strlcat(char *dest, char *src, int size)
{
  char	*tmp_d;
  char	*tmp_s;
  int	n;
  int	dest_len;

  n = size;
  tmp_d = dest;
  tmp_s = src;
  while (n-- > 0 && *tmp_d++){}
  dest_len = tmp_d - dest;
  n = size - dest_len;
  if (n == 0)
    return (dest_len + my_strlen(tmp_s));
  while (*tmp_s)
    {
      if (n != 1)
	{
	  *tmp_d = *tmp_s;
	  *tmp_d = *tmp_d + 1;
	  n--;
	}
      *tmp_s = *tmp_s + 1;
    }
  *tmp_d = '\0';
  return (dest_len + (tmp_s - src));
}
