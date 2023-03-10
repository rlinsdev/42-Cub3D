NAME = cub3D

# Collors
RESET 	= \033[0m
GREEN 	= \033[0;32m
RED 	= \033[0;31m

# Paths
PATH_SRC 		= ./src/
PATH_OBJS 		= ./objs/
INC_PATH 		= ./include/
VPATH 			= $(shell find $(PATH_SRC) -type d)

# maps
#MAP = maps/map_3x5.ber TODO: Colocar mapa do Cub3D

# Libft files and directories
LIBFT_PATH 		= ./lib/libft/
LIBFT 			= ./lib/libft.a

# Minilibx
MLX_PATH	= ./lib/minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)
MLXFLAGS 		= -lmlx -lXext -lX11

# Compilation
CC = cc -g
FLAGS = -Wall -Wextra -Werror

#Chedk Leak memory
LEAK = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s


# Bash commands
RM			= rm -rf
NO_PRINT	= --no-print-directory

INCLUDE = -I $(INC_PATH) -I $(LIBFT_PATH)

SRCS +=		main.c \
			val_args.c val_files.c \
			parse_file.c parse_map.c \
			init_map.c init_data.c \
			mlx_img.c mlx_init.c mlx_hooks.c \
			error_handler.c sanitization.c \
			val_map.c parse_texture.c exit.c \
			parse_map_partial.c parse_texture_partial.c \
			val_texture.c


OBJS = $(addprefix $(PATH_OBJS), $(SRCS:.c=.o))

all: $(MLX) $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(INC_PATH)cub3d.h
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)Build Successful$(RESET)"

$(PATH_OBJS)%.o: %.c
	@mkdir -p $(PATH_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Libft rule
$(LIBFT):
	@make -C $(LIBFT_PATH) $(NO_PRINT)

# MLX rule
$(MLX):
	make -sC $(MLX_PATH)

clean:
	@echo "$(RED)Cleaning objects...$(RESET)"
	@$(RM) $(PATH_OBJS)
	@make -C $(LIBFT_PATH) clean $(NO_PRINT)
	@make -C $(MLX_PATH) clean $(NO_PRINT)
	@echo "$(GREEN)Done!$(RESET)"

fclean: clean
	@echo  "$(RED)Cleaning all...$(RESET)"
	@$(RM) $(NAME)
	@make -C $(LIBFT_PATH) fclean $(NO_PRINT)
	@echo "$(RED)Cleaning binaries...$(RESET)"
	@echo "$(GREEN)Done!$(RESET)"

re: fclean all

bonus: all

rebonus: fclean all

norma:
	norminette $(PATH_SRC)
	norminette $(LIBFT_PATH)

run:
	make re && ./cub3D ./maps/3-simple-map_new_line.cub
#	./cub3D ./maps/4.cub

valgrind:
	$(LEAK) ./cub3D ./maps/2-pdf-map.cub

.PHONY: all run re clean fclean
