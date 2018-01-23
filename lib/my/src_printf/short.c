#include	"my_printf.h"

void    my_put_pointeur(long int ptr, char *base)
{
  int   k;

  k = my_strlen(base);
  if (ptr / k)
    my_put_pointeur(ptr / k, base);
  my_putchar(base[ptr % k]);
}

void            my_put_short_hexa(short unsigned int nbr, char *base)
{
  int           k;

  k = my_strlen(base);
  if (nbr / k)
    my_put_short_hexa(nbr / k, base);
  my_putchar(base[nbr % k]);
}

void            my_put_short_nbr_base(short int nbr, char *base)
{
  int      k;

  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  k = my_strlen(base);
  if (nbr / k)
    my_put_short_nbr_base(nbr / k, base);
  my_putchar(base[nbr % k]);
}
