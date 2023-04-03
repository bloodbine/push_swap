NAME		= push_swap

SRC		= 	push_swap.c		\
			move_helper.c	\
			helper.c		\
			swap.c			\
			push.c			\
			rotate.c		\
			reverse_rotate.c\
			sort.c			\
			sort_helper.c	\
			sort_back.c		\
			error.c

SRCOBJ	= $(SRC:.c=.o)

VPATH	= src src/moves
CC		= cc
RM		= rm -f
IFLAGS	= -I include
CFLAGS	= -Wall -Wextra -Werror
CAFILES = libft/libft.a
CAFLAGS = $(CAFILES) $(IFLAGS)

%.o : %.c
	@$(CC) $(CFLAGS) -c $<

$(NAME) : libmake $(SRCOBJ)
	@$(CC) $(SRCOBJ) $(CAFLAGS) -fsanitize=address -o $(NAME)

libmake:
	@git submodule update --init --recursive --remote
	@cd libft && $(MAKE)

clean: 
	@$(RM) $(SRCOBJ)
	@cd libft && $(MAKE) clean

fclean: clean
	@$(RM) $(NAME)
	@cd libft && $(MAKE) fclean

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re libmake
