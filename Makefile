NAME = fractol

SRCDIR = src

SRC =	draw.c \
        events.c \
        julia.c \
        main.c \
        mandelabs.c \
        mandelbrot.c \
        mandelcube.c

OBJ = $(addprefix $(SRCDIR)/, $(SRC:.c=.o))

LIB_PATH = libft

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_PATH)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) $(LIB_PATH)/libft.a -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	gcc -c -Wall -Wextra -Werror -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C $(LIB_PATH)

fclean:
	rm -f $(NAME)
	rm -f $(OBJ)
	make fclean -C $(LIB_PATH)

re: fclean all
