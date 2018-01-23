#include	"minishell1.h"

void            catch_sigint(int sig_num)
{
  signal(SIGINT, catch_sigint);
  my_putstr("\b\b  \n$>");
  sig_num = sig_num;
}

void		my_putstr_fd(char *s, int fd)
{
  int		i;

  i = 0;
  while (s[i])
    write(fd, &s[i++], 1);
}

int		check_pid(int pid)
{
  if (pid == 11)
    {
      my_putstr_fd("Segmentation fault\n", 2);
      return (-1);
    }
  if (pid == 8)
    {
      my_putstr_fd("Floating point exception\n", 2);
      return (-1);
    }
  if (pid == 7)
    {
      my_putstr_fd("Program received signal [[SIGBUS]], Bus error.\n", 2);
      return (-1);
    }
  return (0);
}
