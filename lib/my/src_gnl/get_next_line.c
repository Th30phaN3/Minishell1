#include	"get_next_line.h"

void		*my_realloc(void *data, int size, int i)
{
  void		*nw_data;
  char		*dest;
  char		*src;

  if (data == NULL)
    {
      if ((data = malloc(size)) == NULL)
	return (NULL);
      return (data);
    }
  if ((nw_data = malloc(size)) == NULL)
    return (NULL);
  dest = nw_data;
  src = data;
  while (i < size)
    {
      i++;
      *dest = *src;
      dest++;
      src++;
    }
  free(data);
  return (nw_data);
}

int		read_file(const int fd, char *car)
{
  static char	buffer[READ_SIZE];
  static int	rd = READ_SIZE;
  static int	i = 0;

  if (i == 0 || i >= rd)
    {
      i = 0;
      if ((rd = read(fd, buffer, READ_SIZE)) < 0)
	return (0);
    }
  if (rd != 0)
    {
      if (buffer[i] == 10)
	*car = 0;
      else
	*car = buffer[i];
    }
  else
    {
      *car = 0;
      return (0);
    }
  i++;
  return (rd);
}

char		*get_next_line(const int fd)
{
  char		*res;
  int		i;
  int		rd;

  i = 0;
  if (fd < 0 || READ_SIZE < 0)
    return (NULL);
  if (((res = malloc(sizeof(char) * READ_SIZE + 1)) == NULL) ||
      (rd = read_file(fd, &res[i])) == 0)
    return (NULL);
  while (res[i])
    {
      i++;
      if (i % READ_SIZE == 0)
	if ((res = my_realloc(res, READ_SIZE + i, 0)) == NULL)
	  return (NULL);
      read_file(fd, &res[i]);
    }
  return (res);
}
