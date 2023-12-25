NAME = fdf
B_NAME = b_fdf
B_PATH = bonus
M_PATH = mandatory

M_SRC = $(M_PATH)/get_next_line.c \
	$(M_PATH)/main.c \
	$(M_PATH)/draw.c \
	$(M_PATH)/init.c \
	$(M_PATH)/utils_libft1.c \
	$(M_PATH)/utils_libft2.c \
	$(M_PATH)/ft_split.c \
	$(M_PATH)/menu.c \
	$(M_PATH)/read.c \
	$(M_PATH)/error.c

B_SRC = $(B_PATH)/get_next_line.c \
	$(B_PATH)/main.c \
	$(B_PATH)/draw.c \
	$(B_PATH)/init.c \
	$(B_PATH)/utils_libft1.c \
	$(B_PATH)/utils_libft2.c \
	$(B_PATH)/ft_split.c \
	$(B_PATH)/menu.c \
	$(B_PATH)/read.c \
	$(B_PATH)/controls.c \
	$(B_PATH)/rotate.c \
	$(B_PATH)/error.c

M_OBJ = $(M_SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -O3

MINILIBX_PATH = minilibx
MINILIBX_LIB = -Lminilibx -lmlx -framework OpenGL -framework AppKit

m: $(M_OBJ)
	@ cd $(MINILIBX_PATH) && make
	@ $(CC) $(CFLAGS) $(MINILIBX_LIB) $(M_OBJ) -o $(NAME)

b: $(B_OBJ)
	@ cd $(MINILIBX_PATH) && make
	@ $(CC) $(CFLAGS) $(MINILIBX_LIB) $(B_OBJ) -o $(B_NAME)

all: b m

clean:
	@ rm -f $(M_OBJ) $(B_OBJ) $(MINILIBX_LIB)
	@ cd $(MINILIBX_PATH) && make clean

fclean: clean
	@ rm -f $(NAME) $(B_NAME)

re: fclean all
