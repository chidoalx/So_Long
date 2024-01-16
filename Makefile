CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

SRCS = so_long.c \
	draw_map.c \
	read_map.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	movemont.c \
	set_parametr.c\
	ft_putnbr_fd.c \
	ft_split.c \
	get_next_line.c \
	get_next_line_utils.c \
	parcing.c

OBJECTS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

%.o: %.c so_long.h
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

clean:
	@$(RM) $(OBJECTS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean $(NAME)

