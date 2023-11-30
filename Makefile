NAME = so_long.out
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
MINILIBX_FLAGS = -I/usr/include -Imlx_linux
# -Imlx_linux -I/usr/include
# -I/usr/include -Imlx-linux/lib -lmlx-linux/libmlx_Linux.a

DIR = srcs
SRCS_RAW = main.c create_tab.c create_img.c put_img_at_window.c parsing.c parsingv2.c create_tab_utils.c goto.c goto_utils.c algo_start.c algo2.c algo_utils.c \
			algo_main.c create_4_node.c create_4_node_start.c
SRCS = $(addprefix $(DIR)/,$(SRCS_RAW)) \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c
OBJS = $(SRCS:c=o)
INCLUDES = -I./includes -I./libft

LIBFT = libft.a
MINILIBX_A = mlx_linux/libmlx_Linux.a

all: $(NAME)
$(NAME): libftcompile minilibxcompile $(OBJS)
# $(CC) -o $(NAME) $(OBJS) $(LIBFT) $(MINILIBX_A) $(MINILIBX_FLAGS) -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz
	$(CC) $(OBJS) $(DEBUG) -Llibft -l:libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
clean:
	rm $(OBJS) $(OBJB) -f
fclean: clean libftclean minilibxclean
	rm $(NAME) -f
re: fclean all
libftcompile:
	$(MAKE) -C libft
libftclean:
	$(MAKE) fclean -C libft
minilibxcompile:
	$(MAKE) -C mlx_linux
minilibxclean:
	$(MAKE) clean -C mlx_linux
%.o: %.c so_long.h
	$(CC) -c $< -o $@ $(DEBUG) $(MINILIBX_FLAGS) $(CFLAGS) $(INCLUDES)