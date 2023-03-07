NAME		= push_swap

SRC		= 	push_swap.c	\
			helper.c	\
			swap.c

SRCOBJ	= $(SRC:.c=.o)

VPATH	= src src/moves
CC		= cc
RM		= rm -f
IFLAGS	= -I include
CFLAGS	= -Wall -Wextra -Werror
CAFILES = libft-gpasztor/libft.a
CAFLAGS = $(CAFILES) $(IFLAGS)

%.o : %.c
	@$(CC) $(CFLAGS) -c $<

$(NAME) : libmake $(SRCOBJ)
	@$(CC) $(SRCOBJ) $(CAFLAGS) -fsanitize=address -o $(NAME)

libmake:
	@git submodule update --init --recursive --remote
	@cd libft-gpasztor && $(MAKE)
	@curl https://icanhazdadjoke.com/

clean: 
	@$(RM) $(SRCOBJ)
	@cd libft-gpasztor && $(MAKE) clean

fclean: clean
	@$(RM) $(NAME)
	@cd libft-gpasztor && $(MAKE) fclean

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re libmake
