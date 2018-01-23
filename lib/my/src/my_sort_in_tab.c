void	my_sort_int_tab(int *tab, int size)
{
  int	tmp;
  int	i;
  int	check;

  check = 1;
  i = 1;
  while (check == 1)
    {
      check = 0;
      i = 1;
      while (i < size)
	{
	  if (tab[i - 1] > tab[i])
	    {
	      tmp = tab[i - 1];
	      tab[i - 1] = tab[i];
	      tab[i] = tmp;
	      check = 1;
	    }
	  i++;
	}
    }
}
