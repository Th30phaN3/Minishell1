#include	"my_printf.h"

void	put_char(va_list arg, t_print *p)
{
  my_putchar(va_arg(arg, int));
  p->n++;
}

void	put_str(va_list arg, t_print *p)
{
  char	*str;

  str = va_arg(arg, char*);
  if (str == NULL)
    {
      my_putstr("(null)");
      p->n += 6;
    }
  else
    {
      my_putstr(str);
      p->n += my_strlen(str);
    }
}

void    char_no_print(char *str, int i)
{
  if (str[i] >= 7 && str[i] != 127)
    {
      my_putchar('\\');
      my_putchar('0');
    }
  if (str[i] >= 0 && str[i] < 7)
    {
      my_putchar('\\');
      my_putstr("00");
    }
  if (str[i] == 127)
    my_putchar('\\');
  my_putnbr_base(str[i], "01234567");
}

int	my_spe_putstr(char *str)
{
  int   i;
  int	k;

  i = 0;
  k = 0;
  while (str[i])
    {
      if (str[i] < 32 || str[i] == 127)
	{
	  char_no_print(str, i);
	  k += 4;
	}
      else
	{
	  my_putchar(str[i]);
	  k++;
	}
      i++;
    }
  return (k);
}

void	spe_putstr(va_list arg, t_print *p)
{
  char	*str;

  str = va_arg(arg, char*);
  if (str == NULL)
    {
      my_putstr("(null)");
      p->n += 6;
    }
  else
    p->n += my_spe_putstr(str);
}
