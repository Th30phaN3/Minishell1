#include	<stdlib.h>
#include	"my.h"

char		**my_tabdup(char **tab, int size)
{
  int		i;
  char		**res;

  i = 0;
  res = my_memalloc(sizeof(char*) * size);
  while (tab[i] != NULL)
    {
      res[i] = my_strdup(tab[i]);
      i++;
    }
  res[i] = NULL;
  return (res);
}
