#ifndef		GET_NEXT_LINE_H_
# define	GET_NEXT_LINE_H_

#ifndef		READ_SIZE
# define	READ_SIZE (4096)
#endif

#include	<stdlib.h>

char	*get_next_line(const int);
void	*my_realloc(void*, int, int);
int	read_file(const int, char*);

#endif
