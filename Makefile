NAME = cub3D

# Collors
RESET 	= \033[0m
GREEN 	= \033[0;32m
RED 	= \033[0;31m

# Paths
PATH_SRC 		= ./src/
PATH_MAIN 		= $(PATH_SRC)main/
PATH_INIT 		= $(PATH_SRC)init/
PATH_VALI 		= $(PATH_SRC)validation/
PATH_UTIL 		= $(PATH_SRC)util/
PATH_OBJS 		= ./objs/
INC_PATH 		= ./include/

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
CC = gcc -g
# FLAGS = -Wall -Wextra -Werror TODO: Descomentar
FLAGS =

#Chedk Leak memory
LEAK = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s


# Bash commands
RM			= rm -rf
NO_PRINT	= --no-print-directory
READ_LN		= -l readline

INCLUDE = -I $(INC_PATH) -I $(LIBFT_PATH)

SRCS =	$(PATH_MAIN)main.c \
		$(PATH_INIT)init.c \
		$(PATH_VALI)val_args.c \
		$(PATH_UTIL)error_handler.c \
		$(PATH_INIT)init_map.c \

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRCS))

all: $(MLX) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCLUDE) $(LIBFT) $(MLX) $(MLXFLAGS) $(READ_LN)
	@echo "$(GREEN)Build Successful$(RESET)"

$(PATH_OBJS)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)main/
	@mkdir -p $(PATH_OBJS)init/
	@mkdir -p $(PATH_OBJS)validation/
	@mkdir -p $(PATH_OBJS)util/
	@$(CC) $(CFLAGS) $(INCLUDE) -I. -c $< -o $@ $(MLXFLAGS)

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
	make re && ./cub3D ./maps/2-pdf-map.cub

valgrind:
	$(LEAK) ./cub3D ./maps/xxxx

.PHONY: all run re clean fclean
