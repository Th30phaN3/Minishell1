int	is_ok(char c)
{
  if (c != '\0')
    {
      if (c >= '0' && c <= '9' || c == '+' || c == '-')
	return (0);
    }
  return (1);
}

int	check_limit(int tmp, int res, char *str)
{
  int	i;
  int	l;

  l = 0;
  i = 0;
  while (str[i] != '\0' && (str[i] < '1' || str[i] > '9'))
    i++;
  while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
    {
      l++;
      i++;
    }
  i = i - l;
  if (l > 10 || (str[i] > '2' && l == 10))
    return (1);
  if (l == 10 && str[i] == '2')
    if ((tmp > 0 && res < 0) || (tmp < 0 && res > 0))
      return (1);
  return (0);
}

int     my_getnb(char *str, int i, int res, int nb)
{
  int   neg;
  int	tmp;

  neg = 1;
  while (is_ok(str[i]) == 0)
    {
      tmp = res;
      if (str[i] <= '9' && str[i] >= '0')
        {
          nb = str[i] - 48;
          res = (res * 10) + nb;
        }
      if (str[i] == '-')
        neg *= -1;
      if (res == -2147483648)
	return (-2147483648);
      if (check_limit(tmp, res, str) == 1)
	return (0);
      i++;
    }
  return (res * neg);
}

int	my_getnbr(char *str)
{
  int	i;
  int	res;
  int	nb;
  int	final_r;

  i = 0;
  res = 0;
  nb = 0;
  final_r = my_getnb(str, i, res, nb);
  return (final_r);
}
