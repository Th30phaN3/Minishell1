#include	"minishell1.h"

char            *get_name_cmd(char *str, int *i, int j)
{
  char          *name;
  int           tmp;
  int           len;

  tmp = *i;
  len = 0;
  while (str[tmp] && (spe_char(str[tmp], 0) != 1) && str[tmp] != ' ')
    {
      len++;
      tmp++;
    }
  if ((name = malloc(sizeof(char) * len + 1)) == NULL)
    my_exit("Malloc error.\n");
  while (str[*i] && str[*i] != ' ' && \
         (spe_char(str[*i], 0) != 1) && str[*i] != ';')
    {
      name[j++] = str[*i];
      *i = *i + 1;
    }
  name[j] = 0;
  return (name);
}

char            **get_opt_cmd(char *str, int *i, int j, char *name)
{
  char          **tab;
  int		k;

  tab = my_memalloc(sizeof(char*) * (nb_opt(str, i) + 2));
  tab[j++] = my_strdup(name);
  while (str[*i] && (spe_char(str[*i], 0) != 1) && str[*i] != ';')
    {
      k = 0;
      while (str[*i] && str[*i] == ' ')
        *i = *i + 1;
      tab[j] = my_malloc(sizeof(char) * (len_opt(str, i) + 1));
      while (str[*i] && str[*i] != ' ' &&
             (spe_char(str[*i], 0) != 1) && str[*i] != ';')
	tab[j][k++] = str[(*i)++];
      tab[j][k] = 0;
      if (tab[j][0] == 0)
	tab[j] = NULL;
      j++;
      while (str[*i] && str[*i] == ' ')
        *i = *i + 1;
    }
  while (str[*i] && (spe_char(str[*i], 0) == 0) && str[*i] != ';')
    *i = *i + 1;
  tab[j] = NULL;
  return (tab);
}

char            *take_redirect(char *str, int i)
{
  char          *redirect;

  if ((redirect = malloc(sizeof(char) * 3)) == NULL)
    my_exit("Malloc error.\n");
  redirect[1] = 0;
  while (str[i] && spe_char(str[i], 0) != 1 && str[i] != ';')
    i++;
  if (str[i] == 0 || str[i] == ';')
    redirect[0] = 0;
  else
    {
      if (i < my_strlen(str) && ((str[i] == '|' && str[i + 1] == '|') ||
				 (str[i] == '&' && str[i + 1] == '&') ||
				 (str[i] == '>' && str[i + 1] == '>') ||
				 (str[i] == '<' && str[i + 1] == '<')))
	redirect[1] = str[i + 1];
      redirect[0] = str[i];
    }
  redirect[2] = 0;
  return (redirect);
}

int             move_in_cmd(char *str, t_list **cmd, int i, int nb)
{
  t_list        *tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    my_exit("Malloc error.\n");
  while (str[i] && (str[i] == ' ' || \
		    (spe_char(str[i], 0) == 1) || str[i] == ';'))
    i++;
  tmp->name = get_name_cmd(str, &i, 0);
  tmp->opt = get_opt_cmd(str, &i, 0, tmp->name);
  tmp->redirect = take_redirect(str, i);
  tmp->nb = nb;
  tmp->good = 0;
  tmp->next = (*cmd);
  (*cmd)->prev = tmp;
  while ((*cmd)->nb != 0)
    (*cmd) = (*cmd)->next;
  (*cmd)->next = tmp;
  tmp->prev = (*cmd);
  (*cmd) = tmp;
  return (i);
}

void            parse_cmd(char *buff, t_list **cmd)
{
  int           i;
  int           nb;

  i = 0;
  nb = 0;
  if ((*cmd = (t_list*)malloc(sizeof(**cmd))) == NULL)
    my_exit("Malloc error.\n");
  (*cmd)->name = get_name_cmd(buff, &i, 0);
  (*cmd)->opt = get_opt_cmd(buff, &i, 0, (*cmd)->name);
  (*cmd)->nb = nb;
  (*cmd)->good = 0;
  (*cmd)->redirect = take_redirect(buff, i);
  (*cmd)->next = (*cmd);
  (*cmd)->prev = (*cmd);
  while (buff[i])
    {
      nb++;
      i = move_in_cmd(buff, cmd, i, nb);
      while (buff[i] && buff[i] == ' ')
        i++;
    }
  (*cmd) = (*cmd)->prev;
}
