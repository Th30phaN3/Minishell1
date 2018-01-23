#include	"my_printf.h"

void	put_unsigned(va_list arg, t_print *p)
{
  long	lnb;
  int	nb;

  if (p->spe == 'l' || p->spe == 'n')
    {
      lnb = va_arg(arg, long unsigned int);
      my_putnbr_base(lnb, "0123456789");
      p->n += nb_len(lnb, "0123456789");
    }
  if (p->spe == 'h')
    {
      nb = va_arg(arg, unsigned int);
      my_put_short_nbr_base(nb, "0123456789");
      p->n += nb_len(nb, "0123456789");
    }
}

void	put_octal(va_list arg, t_print *p)
{
  long	lnb;
  int	nb;

  if (p->diese == 1)
    {
      my_putchar('0');
      p->n++;
    }
  if (p->spe == 'l' || p->spe == 'n')
    {
      lnb = va_arg(arg, long unsigned int);
      my_putnbr_base(lnb, "01234567");
      p->n += nb_len(lnb, "01234567");
    }
  if (p->spe == 'h')
    {
      nb = va_arg(arg, unsigned int);
      my_put_short_nbr_base(nb, "01234567");
      p->n += nb_len(nb, "01234567");
    }
}

void            put_point(va_list arg, t_print *p)
{
  long unsigned nb;

  if (p->plus == 1)
    {
      my_putchar('+');
      p->n++;
    }
  if (p->space == 1 && p->plus == 0)
    {
      my_putchar(' ');
      p->n++;
    }
  if ((nb = va_arg(arg, long unsigned int)) != 0)
    {
      my_putstr("0x");
      p->n += 2;
      my_put_pointeur(nb, "0123456789abcdef");
      p->n += nb_len(nb, "0123456789abcdef");
    }
  else
    {
      my_putstr("(nil)");
      p->n += 5;
    }
}

void    put_bin(va_list arg, t_print *p)
{
  long unsigned nb;

  nb = va_arg(arg, long unsigned int);
  my_putnbr_base(nb, "01");
  p->n += nb_len(nb, "01");
}
