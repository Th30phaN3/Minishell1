#ifndef		_MINISHELL_1_H_
# define	_MINISHELL_1_H_

#include        <sys/types.h>
#include	<sys/stat.h>
#include	<dirent.h>
#include	<signal.h>
#include        <unistd.h>
#include        <string.h>
#include        <stdio.h>
#include        <stdlib.h>
#include	<sys/wait.h>

#include	"my.h"
#include	"my_printf.h"
#include	"get_next_line.h"

# define	NO_REDIRECT (-42)
# define	REDIRECT_F (-2)
# define	ERROR_FD (-1)

typedef struct	s_list
{
  int		nb;
  char		*name;
  char		**opt;
  char		*redirect;
  int		good;
  struct s_list	*next;
  struct s_list	*prev;
}		t_list;

typedef	struct	s_shell
{
  t_list	*cmd;
  char		**env;
  char		*buff;
  int		nw_fd;
  int		old_fd;
}		t_shell;

typedef char**    (*blt)(t_list*, char**, int);

typedef struct	s_built
{
  char          *str;
  blt          f;
}		t_built;

void		my_putstr_fd(char*, int);
void		aff_prompt(char**);
void		get_cmd(t_shell*);
void		free_tab(char**);
void		my_exit(char*);
void		my_free_list(t_list*);
void		my_d_control(t_shell*);
void		catch_sigint(int);
int		check_pid(int);
int		is_only_zero(char*);
int		my_spe_compare(char*, char*, int);
int		compare_var(char*, char**);
int		all_var_exist(char**, char**);
int		spe_char(char, int);
int		check_line(char**);
int		my_count_char(char*, char);
int		redirect_ok_next(char*, int, int, int);
int		redirect_ok(char*, int, int, int);
int		redirect_sure(char*, int);
char		*epur_pipe_dash(char*, int, int);
char		*epur_str(char*, int, int);
char		*my_malloc(int);
void		*my_memalloc(int);
char		*find_path(char**, int, int);
char		**get_paths(char**);
int		bin_exist(char**, char*, int);
int		exec_bin(char*, t_shell*);
int		exec_binpath(t_shell*, char**);
char		*find_bin(char**, char*, int);
char		*get_varenv(char*);
char		**fill_my_env(char**);
char		*get_user(char**);
char		*get_name_cmd(char*, int*, int);
char		**get_opt_cmd(char*, int*, int, char*);
char		*take_redirect(char*, int);
int		move_in_cmd(char*, t_list**, int, int);
void		parse_cmd(char*, t_list**);
int		nb_opt(char*, int*);
int		len_opt(char*, int*);
int		move_in_directory(char*);
char		**new_env_with_pwd(char**, char*, char*);
char		**cd_minus(char**, int);
char		**modif_pwd(char**, char*, char*, int);
char		**cd_with_arg(t_list*, char**);
char		**cd_null(char**, int);
int		var_exist(char**, char*);
char		*create_var_env(char*, char*);
char		**next_setenv(char**, t_list*, int, int);
void		aff_list(t_list*, char*);
int		is_builtin(char*);
char		**exec_builtin(t_list*, char**);
char		**my_cd(t_list*, char**, int);
char		**my_env(t_list*, char**, int);
char		**my_unsetenv(t_list*, char**, int);
char		**my_setenv(t_list*, char**, int);
char		**exit_builtin(t_list*, char**, int);
int		exec_normal_cmd(t_shell*, char**);
int		do_it(t_shell*, int);
int		exec_cmd(t_shell*);
int		my_shell(t_shell*);

#endif
