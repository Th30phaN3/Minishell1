#include	<stdlib.h>
#include	"my_printf.h"

int             is_normal_printf(char c)
{
  if (c != '\t' && c != ' ' && c != 'h' &&
      c != 'l' && c != '#' && c != '+')
    return (0);
  return (-1);
}

int     is_ok_printf(char c)
{
  if (c == ' ' || c == '\t')
    return (1);
  if (c == 0)
    return (-1);
  return (0);
}

void    skip_space(char *str, t_print *p)
{
  while (str[p->i] && is_ok_printf(str[p->i]) == 1)
    p->i++;
}

void	aff_modif(t_print *p)
{
  if (p->diese == 1)
    {
      my_putchar('#');
      p->n++;
    }
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
}

void	put_error(char *str, t_print *p)
{
  if (str[p->i] == 0)
    return;
  my_putchar('%');
  p->n++;
  if (is_ok(str[p->i]) == 0 && str[p->i] != '%')
    {
      aff_modif(p);
      my_putchar(str[p->i]);
      p->n++;
    }
}
