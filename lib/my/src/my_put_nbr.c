int     aff_exept()
{
  my_putchar('-');
  my_putchar('2');
  my_putchar('1');
  my_putchar('4');
  my_putchar('7');
  my_putchar('4');
  my_putchar('8');
  my_putchar('3');
  my_putchar('6');
  my_putchar('4');
  my_putchar('8');
  return (0);
}

int     my_put_nbr(int nb)
{
  if ((nb < 0) && (nb != -2147483648))
    {
      my_putchar('-');
      nb *= -1;
    }
  if (nb == -2147483648)
    return (aff_exept());
  if (nb > 9)
    my_put_nbr(nb / 10);
  my_putchar((nb % 10) + 48);
}
