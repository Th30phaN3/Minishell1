#include	"minishell1.h"

char            *find_path(char **env, int i, int j)
{
  char          *path;
  int           check;
  int		k;

  k = 0;
  check = 0;
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], "PATH=", 5) == 0)
        {
          path = my_malloc(my_strlen(env[i]) - 4);
	  while (env[i][j])
	    path[k++] = env[i][j++];
	  path[k] = 0;
          check = 1;
        }
      i++;
    }
  if (check == 0)
    return (NULL);
  return (path);
}

char            **get_paths(char **env)
{
  char          **path;
  char          *tmp;

  if ((tmp = find_path(env, 0, 5)) != NULL)
    {
      path = my_str_to_wordtab(tmp, ':');
      free(tmp);
      return (path);
    }
  return (NULL);
}

int             bin_exist(char **path, char *str, int i)
{
  struct dirent *dir;
  DIR           *my_dir;

  if (path != NULL && path[0] != NULL && str != NULL)
    {
      while (path[i] != NULL)
	{
	  if ((my_dir = opendir(path[i])) != NULL)
	    {
	      while ((dir = readdir(my_dir)) != NULL)
		{
		  if (my_strcmp(dir->d_name, str) == 0 &&
		      my_strcmp(dir->d_name, ".") != 0 &&
		      my_strcmp(dir->d_name, "..") != 0)
		    {
		      closedir(my_dir);
		      return (1);
		    }
		}
	      closedir(my_dir);
	    }
	  i++;
	}
    }
  return (0);
}

int             exec_bin(char *bin, t_shell *shell)
{
  int           pid;

  if (access(bin, X_OK) == 0 && access(bin, F_OK) == 0)
    {
      pid = fork();
      if (pid == 0)
        {
          if (execve(bin, shell->cmd->opt, shell->env) == -1)
	    {
	      shell->cmd->good = -1;
	      my_printf("%s: Execution failed.\n", shell->cmd->name);
	      exit(-1);
	    }
        }
      wait(&pid);
      if (check_pid(pid) == -1)
	return (-2);
    }
  else
    return (-1);
  return (0);
}

int             exec_binpath(t_shell *shell, char **path)
{
  int           pid;
  char          *bin;

  bin = find_bin(path, shell->cmd->opt[0], -1);
  pid = fork();
  if (pid == 0)
    {
      if (execve(bin, shell->cmd->opt, shell->env) == -1)
	{
	  my_printf("%s: Execution failed.\n", shell->cmd->name);
	  shell->cmd->good = -1;
	  exit(-1);
	}
    }
  wait(&pid);
  free(bin);
  return (0);
}
