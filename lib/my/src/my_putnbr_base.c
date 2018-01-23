#include	<stdio.h>

int	strl(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	my_putnbr_base(int nbr, char *base)
{
  int   i;

  if (base == NULL)
    return (0);
  if (nbr < 0)
    {
      nbr = -nbr;
      my_putchar('-');
    }
  i = strl(base);
  if (nbr >= i - 1)
    my_putnbr_base(nbr / i, base);
  my_putchar(base[nbr % i]);
  return (nbr);
}
