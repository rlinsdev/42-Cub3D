NAME = cub3D
BONUS = cub3D_bonus

# Collors
RESET 	= \033[0m
GREEN 	= \033[0;32m
RED 	= \033[0;31m

# Paths
PATH_SRC 		= ./src/
PATH_OBJS 		= ./objs/
INC_PATH 		= ./include/
VPATH 			= $(shell find $(PATH_SRC) -type d)


PATH_SRC_BONUS 	= ./bonus/src_bonus/
PATH_OBJS_BONUS = ./bonus/objs_bonus/
INC_PATH_BONUS 	= ./bonus/include_bonus/
VPATH 			+= $(shell find $(PATH_SRC_BONUS) -type d)

# Libft files and directories
LIBFT_PATH 		= ./lib/libft/
LIBFT 			= $(LIBFT_PATH)/libft.a

MLXFLAGS 		= -lmlx -lXext -lX11 -lm

# Compilation
CC = cc -g
CFLAGS = -Wall -Wextra -Werror

#Check Leak memory
LEAK = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s


# Bash commands
RM			= rm -rf
NO_PRINT	= --no-print-directory

INCLUDE = -I $(INC_PATH) -I $(LIBFT_PATH)
INCLUDE_BONUS = -I $(INC_PATH_BONUS) -I $(LIBFT_PATH)

SRCS 	=	main.c val_files.c init_map.c \
			parse_file.c parse_map.c \
			game_control.c game_draw.c game_engine.c game_loop.c \
			error_handler.c sanitization.c \
			val_map.c parse_texture.c exit.c val_texture.c \
			parse_map_partial.c parse_texture_partial.c \
			debug.c parse_text_wall.c \
			val_move.c parse_img.c val_map_partial.c

SRCS_BONUS = main_bonus.c val_files_bonus.c init_map_bonus.c \
			parse_file_bonus.c parse_map_bonus.c \
			game_control_bonus.c game_draw_bonus.c game_engine_bonus.c game_loop_bonus.c \
			error_handler_bonus.c sanitization_bonus.c \
			val_map_bonus.c parse_texture_bonus.c exit_bonus.c val_texture_bonus.c \
			parse_map_partial_bonus.c parse_texture_partial_bonus.c \
			debug_bonus.c parse_text_wall_bonus.c \
			val_move_bonus.c parse_img_bonus.c val_map_partial_bonus.c


OBJS = $(addprefix $(PATH_OBJS), $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(PATH_OBJS_BONUS), $(SRCS_BONUS:.c=.o))


all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)Build Successful$(RESET)"

$(BONUS): $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(INCLUDE_BONUS)  $(OBJS_BONUS) $(LIBFT) $(MLXFLAGS) -o $(BONUS)
	@echo "$(GREEN)Build Successful$(RESET)"

$(PATH_OBJS)%.o: %.c
	@mkdir -p $(PATH_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(PATH_OBJS_BONUS)%.o: %.c
	@mkdir -p $(PATH_OBJS_BONUS)
	@$(CC) $(CFLAGS) $(INCLUDE_BONUS) -c $< -o $@

# Libft rule
$(LIBFT):
	@make -C $(LIBFT_PATH) $(NO_PRINT)

clean:
	@echo "$(RED)Cleaning objects...$(RESET)"
	@$(RM) $(PATH_OBJS)
	@$(RM) $(PATH_OBJS_BONUS)
	@make -C $(LIBFT_PATH) clean $(NO_PRINT)
	@echo "$(GREEN)Done!$(RESET)"

fclean: clean
	@echo  "$(RED)Cleaning all...$(RESET)"
	@$(RM) $(NAME)
	@$(RM) $(BONUS)
	@make -C $(LIBFT_PATH) fclean $(NO_PRINT)
	@echo "$(RED)Cleaning binaries...$(RESET)"
	@echo "$(GREEN)Done!$(RESET)"

re: fclean all

bonus: $(LIBFT) $(BONUS)

rebonus: fclean bonus

norma:
	norminette $(PATH_SRC) $(LIBFT_PATH) $(INC_PATH)


run:
	./cub3D ./maps/2.cub

valgrind:
	$(LEAK) ./cub3D ./maps/1-simple-map.cub

.PHONY: all run re clean fclean
