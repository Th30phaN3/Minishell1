void	my_putstring_base(void *ptr, char *base)
{
  int	*tab;
  int	nb;

  tab = (int*)ptr;
  nb = sizeof(void*) / sizeof(int);
  my_putnbr_base(tab[0], base);
}

void	show_mem(char *str)
{
  int	j;

  j = 0;
  my_putstring_base(str, "0123456789abcdef");
  my_putchar(':');
  my_putchar(' ');
  while (j < 16)
    {
      if (str[j] < 16)
	my_putchar('0');
      my_putnbr_base(str[j], "0123456789abcdef");
      if (j % 2 == 1)
	my_putchar(' ');
      j++;
    }
  j = 0;
  while (j < 16)
    {
      if (str[j] < 32 || str[j] == 127)
	my_putchar('.');
      else
	my_putchar(str[j]);
      j++;
    }
  my_putchar('\n');
}

int	my_showmem(char *str, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      show_mem(str);
      str = str + 16;
      i++;
    }
  return (0);
}
