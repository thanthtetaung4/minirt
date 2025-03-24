# Paths and Files
MLX_PATH = ./mlx
MLX_LIB = $(MLX_PATH)/libmlx.a
MLX_REPO = https://github.com/42Paris/minilibx-linux.git
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CFLAGS = -Wall -Wextra -Werror
# CFLAGS =

# Source and object files
MAP_PATH = ./src/map
WIN_CTRL_PATH = ./src/win_ctrl
UTILS_PATH = ./src/utils
RENDER_PATH = ./src/render
GAME_PATH = ./src/game
FREE_PATH = ./src/free
SRCS = src/main.c src/get_next_line/get_next_line.c src/get_next_line/get_next_line_utils.c \
		# $(WIN_CTRL_PATH)/win_ctrl.c
OBJS = $(SRCS:.c=.o)

# Compiler
CC = cc

# Executable name
NAME = minirt

# Rules
all: $(NAME)
	 @echo "\033[32m[$(NAME) is ready for use]\033[0m"

$(NAME): $(MLX_LIB) $(OBJS)  $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -L$(LIBFT_PATH) $(LIBFT) $(MLX_LIB) -o $(NAME)

# Clone and compile the MiniLibX library
$(MLX_LIB):
	@if [ ! -d "$(MLX_PATH)" ]; then \
		echo "\033[33m[Cloning MiniLibX...]\033[0m"; \
		git clone $(MLX_REPO) $(MLX_PATH); \
	fi
	@$(MAKE) -C $(MLX_PATH)

# Compile the libft library
$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

# Test
TEST = mytest
test: $(TEST)
	 @echo "\033[32m[$(test) is ready for use]\033[0m"

$(TEST): $(TETST_OBJS) $(MLX_LIB) $(LIBFT)
	$(CC) $(CFLAGS) $(TETST_OBJS) $(MLX_FLAGS) -L$(LIBFT_PATH) -lft -o $(TEST)
TEST_PATH = ./test
TEST_SRCS = $(TEST_PATH)/render_test.c
TETST_OBJS = $(TEST_SRCS:.c=.o)

# Clean object files
clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@echo "\033[33m[Cleaned up]\033[0m"

# Clean object files and executable
fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@echo "\033[33m[Fully cleaned up]\033[0m"

# Recompile everything
re: fclean all

# Compile .o files
%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -I$(LIBFT_PATH) -c $< -o $@

.PHONY: all clean fclean re
