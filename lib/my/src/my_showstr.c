#include	<stdio.h>

void	print_specialchar(char c)
{
  int	i;

  i = 0;
  my_putchar('\\');
  if (c == 127)
    {
      my_putchar('7');
      my_putchar('f');
      return;
    }
  else
    {
      while (c != i)
	i++;
      if (i >= 0 && i <= 15)
	my_putchar('0');
      my_putnbr_base(i, "0123456789abcdef");
    }
}

int	my_showstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    {
      if (str[i] < 32 || str[i] == 127)
	print_specialchar(str[i]);
      else
	my_putchar(str[i]);
      i++;
    }
  return (0);
}
