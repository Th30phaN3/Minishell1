#include	"my_printf.h"

void		put_float(va_list arg, t_print *p)
{
  double	nb;
  int		tmp;

  nb = va_arg(arg, double);
  tmp = (int)nb;
  if (p->plus == 1 && tmp >= 0)
    {
      my_putchar('+');
      p->n++;
    }
  if (p->plus == 0 && p->space == 1 && tmp >= 0)
    {
      my_putchar(' ');
      p->n++;
    }
  my_putnbr_pbase(tmp, "0123456789");
  nb = (nb - tmp) * 1000000;
  my_putchar('.');
  if (nb < 0)
    nb = -nb;
  if (nb < 100000)
    nb++;
  my_putnbr_pbase((int)nb, "0123456789");
  p->n += (nb_len((int)nb, "0123456789") + nb_len(tmp, "0123456789") + 1);
}

void		put_write_char(va_list arg, t_print *p)
{
  int		*var;

  var = va_arg(arg, int*);
  *var = p->n;
}

int		nb_len(long int nb, char *base)
{
  int		i;
  int		len;

  i = 0;
  len = my_strlen(base);
  if (nb < 0)
    i++;
  while (nb / len)
    {
      nb /= len;
      i++;
    }
  return (i + 1);
}

void                    my_putnbr_hexa(long unsigned int nbr, char *base)
{
  long unsigned int     k;

  k = my_strlen(base);
  if (nbr / k)
    my_putnbr_hexa(nbr / k, base);
  my_putchar(base[nbr % k]);
}

void            my_putnbr_pbase(long int nbr, char *base)
{
  long int      k;

  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  k = my_strlen(base);
  if (nbr / k)
    my_putnbr_pbase(nbr / k, base);
  my_putchar(base[nbr % k]);
}
