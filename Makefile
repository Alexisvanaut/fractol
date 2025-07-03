NAME		= fractol

SRC_DIR		= srcs
INC_DIR		= includes
LIBFT_DIR	= libft
MLX_DIR		= minilibx-linux

SRCS		= \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/mandelbrot.c \
	$(SRC_DIR)/put_pixel.c \
	$(SRC_DIR)/julia.c \
	$(SRC_DIR)/hook.c \
	$(SRC_DIR)/color.c \
	$(SRC_DIR)/alexis.c \
	$(SRC_DIR)/init_data.c \
	$(SRC_DIR)/utils.c

OBJS		= $(SRCS:.c=.o)

LIBFT		= $(LIBFT_DIR)/libft.a
MLX			= $(MLX_DIR)/libmlx.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

LDFLAGS		= -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
