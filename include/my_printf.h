#ifndef		_MY_PRINTF_
# define	_MY_PRINTF_

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdarg.h>

typedef struct	s_print	t_print;
typedef struct	s_func t_func;
typedef void	(*func)(va_list, t_print*);

struct		s_func
{
  char		c;
  func		f;
};

struct		s_print
{
  int		i;
  int		n;
  int		plus;
  int		space;
  int		diese;
  char		spe;
  t_func	func[13];
};

int my_printf(char*, ...);
int init_struct(t_print**);
t_func *init_func(t_func*);
t_func *init_continue(t_func*);
int put_flags(char*, t_print*, va_list);
int is_ok_printf(char);
void skip_space(char*, t_print*);
int modulo(char *, t_print*, va_list);
void put_float(va_list, t_print*);
void put_write_char(va_list, t_print*);
void put_point(va_list, t_print*);
void put_bin(va_list, t_print*);
void put_int(va_list, t_print*);
void put_hexa_s(va_list, t_print*);
void put_hexa_b(va_list, t_print*);
void put_unsigned(va_list, t_print*);
void put_octal(va_list, t_print*);
void put_char(va_list, t_print*);
void put_str(va_list, t_print*);
void spe_putstr(va_list, t_print*);
int my_spe_putstr(char*);
void char_no_print(char*, int);
void my_put_pointeur(long int, char*);
void my_putnbr_hexa(long unsigned int, char *);
void my_put_short_hexa(short unsigned int, char*);
void my_putnbr_pbase(long int, char*);
void my_put_short_nbr_base(short int, char*);
void put_error(char*, t_print*);

#endif
