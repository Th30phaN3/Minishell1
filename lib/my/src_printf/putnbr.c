#include	"my_printf.h"

void	put_int_next(int nb, t_print *p)
{
  if (p->plus == 1 && nb >= 0)
    {
      my_putchar('+');
      p->n++;
    }
  if (p->plus == 0 && p->space == 1 && nb >= 0)
    {
      my_putchar(' ');
      p->n++;
    }
  if (p->spe == 'n')
    my_putnbr_base(nb, "0123456789");
  else
    my_put_short_nbr_base(nb, "0123456789");
  p->n += nb_len(nb, "0123456789");
}

void	put_int(va_list arg, t_print *p)
{
  int	nb;
  long	lnb;

  if (p->spe == 'n' || p->spe == 'h')
    {
      nb = va_arg(arg, int);
      put_int_next(nb, p);
    }
  if (p->spe == 'l')
    {
      lnb = va_arg(arg, long);
      if (p->plus == 1 && lnb >= 0)
	{
	  my_putchar('+');
	  p->n++;
	}
      if (p->space == 1 && p->plus == 0 && lnb >= 0)
	{
	  my_putchar(' ');
	  p->n++;
	}
      my_putnbr_base(lnb, "0123456789");
      p->n += nb_len(lnb, "0123456789");
    }
}

void	put_hexa_s(va_list arg, t_print *p)
{
  long	lnb;
  int	nb;

  if (p->diese == 1)
    {
      my_putstr("0x");
      p->n += 2;
    }
  if (p->spe == 'l' || p->spe == 'n')
    {
      lnb = va_arg(arg, long unsigned int);
      my_putnbr_hexa(lnb, "0123456789abcdef");
      p->n += nb_len(lnb, "0123456789abcdef");
    }
  if (p->spe == 'h')
    {
      nb = va_arg(arg, unsigned int);
      my_put_short_hexa(nb, "0123456789abcdef");
      p->n += nb_len(nb, "0123456789abcdef");
    }
}

void	put_hexa_b(va_list arg, t_print *p)
{
  long	lnb;
  int	nb;

  if (p->diese == 1)
    {
      my_putstr("0X");
      p->n += 2;
    }
  if (p->spe == 'l' || p->spe == 'n')
    {
      lnb = va_arg(arg, long unsigned int);
      my_putnbr_hexa(lnb, "0123456789ABCDEF");
      p->n += nb_len(lnb, "0123456789ABCDEF");
    }
  if (p->spe == 'h')
    {
      nb = va_arg(arg, unsigned int);
      my_put_short_hexa(nb, "0123456789ABCDEF");
      p->n += nb_len(nb, "0123456789ABCDEF");
    }
}
