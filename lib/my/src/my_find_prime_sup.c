int	my_find_prime_sup(int nb)
{
  int	sup;

  while ((sup = my_is_prime(nb)) == 0)
    nb++;
  return (nb);
}
