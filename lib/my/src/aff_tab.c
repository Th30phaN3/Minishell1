#include	<stdlib.h>
#include	"my.h"

int		aff_tab(char **tab)
{
  int		i;

  i = 0;
  if (tab == NULL || tab[0] == NULL)
    return (-1);
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
  return (0);
}
