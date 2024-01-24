CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

BONUS_DIR = so_long_bonus

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
	parcing.c \
	flood_map.c \
	enemy_touch.c \

SRCS_BONNUS = $(BONUS_DIR)/so_long_bonus.c\
 $(BONUS_DIR)/draw_map.c \
 $(BONUS_DIR)/read_map.c \
 $(BONUS_DIR)/ft_putchar_fd.c \
 $(BONUS_DIR)/ft_putstr_fd.c \
 $(BONUS_DIR)/ft_itoa.c \
 $(BONUS_DIR)/movemont.c \
 $(BONUS_DIR)/set_parametr.c\
 $(BONUS_DIR)/ft_split.c \
 $(BONUS_DIR)/get_next_line.c \
 $(BONUS_DIR)/get_next_line_utils.c \
 $(BONUS_DIR)/parcing.c \
 $(BONUS_DIR)/flood_map.c \
 $(BONUS_DIR)/enemy_touch.c \

OBJECTS = $(SRCS:.c=.o)

OBJECTS_BONNUS = $(SRCS_BONNUS:.c=.o)

RM = rm -f

all: $(NAME)

%.o: %.c so_long.h
	$(CC) -g -fsanitize=address $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJECTS)
	$(CC) -g -fsanitize=address $(CFLAGS) $(OBJECTS) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

bonus: $(OBJECTS_BONNUS)
	$(CC) -g -fsanitize=address $(CFLAGS) $(OBJECTS_BONNUS) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

clean:
	$(RM) $(OBJECTS) $(OBJECTS_BONNUS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

