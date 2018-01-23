CC	= gcc

RM	= rm -f

NAME	= libmy.a

DIR_N	= src/
DIR_P	= src_printf/
DIR_G	= src_gnl/

FLAGS	= -W -Wall -Werror -Wextra -pedantic

SRC	=	$(DIR_N)my_find_prime_sup.c	\
		$(DIR_N)my_getnbr.c		\
		$(DIR_N)my_isneg.c		\
		$(DIR_N)my_is_prime.c		\
		$(DIR_N)my_power_rec.c		\
		$(DIR_N)my_putchar.c		\
		$(DIR_N)tab_len.c		\
		$(DIR_N)my_tabdup.c		\
		$(DIR_N)show_tab.c		\
		$(DIR_N)my_putnbr_base.c	\
		$(DIR_N)my_put_nbr.c		\
		$(DIR_N)my_putstr.c		\
		$(DIR_N)my_revstr.c		\
		$(DIR_N)my_showmem.c		\
		$(DIR_N)my_showstr.c		\
		$(DIR_N)my_show_wordtab.c	\
		$(DIR_N)my_sort_in_tab.c	\
		$(DIR_N)my_square_root.c	\
		$(DIR_N)my_strcapitalize.c	\
		$(DIR_N)my_strcut.c		\
		$(DIR_N)my_strcat.c		\
		$(DIR_N)my_strcmp.c		\
		$(DIR_N)my_strcpy.c		\
	        $(DIR_N)my_strdup.c		\
		$(DIR_N)my_str_isalpha.c	\
		$(DIR_N)my_str_islower.c	\
		$(DIR_N)my_str_isnum.c		\
		$(DIR_N)my_str_isprintable.c	\
		$(DIR_N)my_str_isupper.c	\
		$(DIR_N)my_strlcat.c		\
		$(DIR_N)my_strlen.c		\
		$(DIR_N)my_strlowcase.c		\
		$(DIR_N)my_strncat.c		\
	    	$(DIR_N)my_strncmp.c		\
	     	$(DIR_N)my_strncpy.c		\
	     	$(DIR_N)my_strstr.c		\
	        $(DIR_N)my_str_to_wordtab.c	\
		$(DIR_N)my_strupcase.c		\
		$(DIR_N)my_swap.c		\
		$(DIR_P)error.c			\
		$(DIR_P)func.c			\
		$(DIR_P)my_printf.c		\
		$(DIR_P)put.c			\
		$(DIR_P)putnbr2.c		\
		$(DIR_P)putnbr.c		\
		$(DIR_P)putstr.c		\
		$(DIR_P)short.c			\
		$(DIR_G)get_next_line.c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc ../$(NAME) $(OBJ)
	cp $(DIR_N)my.h ../../include/
	cp $(DIR_P)my_printf.h ../../include/
	cp $(DIR_G)get_next_line.h ../../include/

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
