#include	"minishell1.h"

int		check_line(char **opt)
{
  int           i;

  i = 0;
  if (opt[0] != NULL)
    {
      while (opt[0][i])
	{
	  if (opt[0][i] == '/')
	    return (1);
	  i++;
	}
    }
  return (0);
}

char            *find_bin(char **path, char *str, int i)
{
  struct dirent *dir;
  DIR           *my_dir;
  char		*bin;

  while (path[++i] != NULL)
    {
      if ((my_dir = opendir(path[i])) != NULL)
	{
	  while ((dir = readdir(my_dir)) != NULL)
	    {
	      if (my_strcmp(dir->d_name, str) == 0)
		{
		  bin = my_strcat(path[i], "/");
		  bin = my_strcat(bin, str);
		  closedir(my_dir);
		  return (bin);
		}
	    }
	  closedir(my_dir);
	}
    }
  return (str);
}

int             nb_opt(char *str, int *i)
{
  int           tmp;
  int           nb;

  nb = 0;
  tmp = (*i);
  while (str[tmp] && (spe_char(str[tmp], 0) != 1) && str[tmp] != ';')
    {
      if (str[tmp] == ' ')
        nb++;
      tmp++;
    }
  return (nb);
}

int             len_opt(char *str, int *i)
{
  int           tmp;
  int           nb;

  tmp = (*i);
  nb = 0;
  while (str[tmp] && str[tmp] != ' ' &&
         (spe_char(str[tmp], 0) != 1) && str[tmp] != ';')
    {
      tmp++;
      nb++;
    }
  return (nb);
}

void            aff_list(t_list *cmd, char *str)
{
  my_printf("str_epuree=XX%sXX\n", str);
  while (cmd->nb != 0)
    cmd = cmd->next;
  my_printf("---\ncmd->nb=%i\ncmd->name=%s\n", cmd->nb, cmd->name);
  show_tab(cmd->opt);
  my_printf("cmd->redirect=%s\n", cmd->redirect);
  cmd = cmd->prev;
  while (cmd->nb != 0)
    {
      my_printf("---\ncmd->nb=%i\ncmd->name=%s\n", cmd->nb, cmd->name);
      show_tab(cmd->opt);
      my_printf("cmd->redirect=%s\n", cmd->redirect);
      cmd = cmd->prev;
    }
}
