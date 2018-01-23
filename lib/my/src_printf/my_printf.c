#include	"my_printf.h"

void		take_specifiers(char *str, t_print *p)
{
  while (str[p->i] && is_normal_printf(str[p->i]) != 0)
    {
      if (str[p->i] == '#' || str[p->i] == '+')
	{
	  if (str[p->i] == '+')
	    p->plus = 1;
	  else
	    p->diese = 1;
	}
      if (str[p->i] == 'l' || str[p->i] == 'h')
	{
	  if (str[p->i] == 'l')
	    p->spe = 'l';
	  else
	    p->spe = 'h';
	}
      if (is_ok_printf(str[p->i]) == 1)
	{
	  p->space = 1;
	  skip_space(str, p);
	}
      else
	p->i++;
    }
}

int		put_flags(char *str, t_print *p, va_list arg)
{
  int		k;

  k = 0;
  while (k < 13)
    {
      if (str[p->i] == p->func[k].c)
	{
	  p->func[k].f(arg, p);
	  return (0);
	}
      k++;
    }
  return (-1);
}

int		modulo(char *str, t_print *p, va_list lst_arg)
{
  p->i++;
  if (is_ok_printf(str[p->i]) == 1)
    {
      skip_space(str, p);
      p->space = 1;
    }
  if (str[p->i] == 0)
    return (0);
  if (str[p->i] == '%')
    {
      p->n++;
      my_putchar('%');
      return (0);
    }
  take_specifiers(str, p);
  if ((put_flags(str, p, lst_arg)) == -1)
    put_error(str, p);
  p->plus = 0;
  p->diese = 0;
  p->space = 0;
  p->spe = 'n';
  return (0);
}

int		init_struct(t_print **print)
{
  if (((*print) = malloc(sizeof(**print))) == NULL)
    return (-1);
  (*print)->i = 0;
  (*print)->n = 0;
  (*print)->plus = 0;
  (*print)->space = 0;
  (*print)->diese = 0;
  (*print)->spe = 'n';
  init_func((*print)->func);
  return (0);
}

int		my_printf(char *str, ...)
{
  va_list	lst_arg;
  t_print	*p;
  int		nb;

  if (str == NULL || init_struct(&p) == -1)
    return (0);
  va_start(lst_arg, str);
  while (str[p->i])
    {
      if (str[p->i] == '%')
	modulo(str, p, lst_arg);
      else
	{
	  my_putchar(str[p->i]);
	  p->n++;
	}
      p->i++;
    }
  va_end(lst_arg);
  nb = p->n;
  free(p);
  return (nb);
}
