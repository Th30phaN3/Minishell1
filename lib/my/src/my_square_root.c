int	my_square_root(int nb)
{
  int	sqr;

  sqr = 0;
  while ((sqr * sqr) < nb)
    sqr++;
  if (nb == (sqr * sqr))
    return (sqr);
  else
    return (0);
}
