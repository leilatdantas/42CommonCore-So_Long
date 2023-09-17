# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 18:00:33 by lebarbos          #+#    #+#              #
#    Updated: 2023/09/17 12:10:07 by lebarbos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
MAGENTA	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#COMMANDS
RM = rm -rf
AR = ar -rcs
UNAME = $(shell uname)

#FLAGS
CFLAGS	= -Wall -Wextra -Werror -g #-fsanitize=address
LFLAGS	= -L ./libft -lft -L ./get_next_line -lgnl -L ./ft_printf -lftprintf -I $(DEPS)
ifeq ($(UNAME), Darwin) 
	CC = cc
	LFLAGS += -framework OpenGL -framework AppKit -L ./mlx_mac -lmlx
else ifeq ($(UNAME), FreeBSD) 
	CC = clang
else 
	CC = cc
	LFLAGS += -L ./mlx_linux -lmlx -Ilmlx -lXext -lX11 -lm
endif

#PATHS
DEPS			= include
SRCS			= srcs
SRCS_BONUS		= srcs_bonus
LIBFT_PATH		= libft
GNL_PATH		= get_next_line
PRINTF_PATH		= ft_printf
ifeq ($(UNAME), Darwin)
	MLX_PATH = ./mlx_mac
else
	MLX_PATH = ./mlx_linux
endif
OTHERS			= maps
OBJ_PATH		= objs
OBJ_PATH_BONUS	= objs_bonus

#FILES
NAME			= so_long
SRC_FILES		= init utils valid_map endgame so_long main game controls
OBJS			= $(SRC_FILES:%=%.o)
TARGET			= $(addprefix $(OBJ_PATH)/, $(OBJS))
#BONUS
NAME_BONUS		= so_long_bonus
SRC_FILES_BONUS = check_map_b endgame_b init_b main_b move_player_b read_map_b so_long_b utils_b walls_b load_images_b put_graphics_b move_enemies_b animate_b destroy_b
OBJS_BONUS		= $(SRC_FILES_BONUS:%=%.o)
TARGET_BONUS	= $(addprefix $(OBJ_PATH_BONUS)/, $(OBJS_BONUS))

#RULES 
all: $(NAME)

$(NAME): $(OBJ_PATH) $(TARGET)
	echo "$(MAGENTA)Compiling:$(RESET) $(GREEN)libft/*$(RESET)"
	make -C $(LIBFT_PATH)
	
	echo "$(MAGENTA)Compiling:$(RESET) $(GREEN)get_next_line/*$(RESET)"
	make -C $(GNL_PATH)
	
	echo "$(MAGENTA)Compiling:$(RESET) $(GREEN)ft_printf/*$(RESET)"
	make -C $(PRINTF_PATH)

	echo "$(MAGENTA)Compiling:$(RESET) $(GREEN)mlx/*$(RESET)"
	make -C $(MLX_PATH) 2> /dev/null
	
	echo "$(CYAN)🔗 Linking: $(RESET) $(CFLAGS) $(GREEN)*$(RESET)"
	$(CC) $(CFLAGS) $(TARGET) $(LFLAGS) -o $(NAME) -I$(DEPS)
	
	echo "$(GREEN)🎉 YAY! Compilation is done!$(RESET)"
	
$(OBJ_PATH)/%.o : $(SRCS)/%.c 
	echo "$(MAGENTA)Compiling:$(RESET) $(CFLAGS) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(DEPS)

$(OBJ_PATH) :
	mkdir -p $(OBJ_PATH)

bonus : $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_PATH_BONUS) $(TARGET_BONUS)
	echo "$(MAGENTA)Compiling BONUS:$(RESET) $(GREEN)libft/*$(RESET)"
	make -C $(LIBFT_PATH)
	
	echo "$(MAGENTA)Compiling BONUS:$(RESET) $(GREEN)get_next_line/*$(RESET)"
	make -C $(GNL_PATH)
	
	echo "$(MAGENTA)Compiling BONUS:$(RESET) $(GREEN)ft_printf/*$(RESET)"
	make -C $(PRINTF_PATH)

	echo "$(MAGENTA)Compiling BONUS:$(RESET) $(GREEN)mlx/*$(RESET)"
	make -C $(MLX_PATH) 2> /dev/null
	
	echo "$(CYAN)🔗 Linking: $(RESET) $(CFLAGS) $(GREEN)*$(RESET)"
	$(CC) $(CFLAGS) $(TARGET_BONUS) $(LFLAGS) -o $(NAME_BONUS) -I$(DEPS)
	
	echo "$(GREEN)🎉 YAY! BONUS is done!$(RESET)"
	
$(OBJ_PATH_BONUS)/%.o : $(SRCS_BONUS)/%.c 
	echo "$(MAGENTA)Compiling BONUS:$(RESET) $(CFLAGS) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(DEPS)

$(OBJ_PATH_BONUS) :
	mkdir -p $(OBJ_PATH_BONUS)



clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(GNL_PATH)
	make clean -C $(PRINTF_PATH)	
	make clean -C $(MLX_PATH)
	
	echo "$(RED)🗑️  Deleted: $(RESET) $(GREEN)$(OBJ_PATH)$(RESET)"
	$(RM) $(OBJ_PATH)

	echo "$(RED)🗑️  Deleted: $(RESET) $(GREEN)$(OBJ_PATH_BONUS)$(RESET)"
	$(RM) $(OBJ_PATH_BONUS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(GNL_PATH)
	make fclean -C $(PRINTF_PATH)	
	
	echo "$(RED)🗑️  Deleted: $(RESET) $(GREEN)$(NAME)$(RESET)"
	$(RM) $(NAME)

	echo "$(RED)🗑️  Deleted: $(RESET) $(GREEN)$(NAME_BONUS)$(RESET)"
	$(RM) $(NAME_BONUS)

re: fclean all

rebonus: fclean bonus

.SILENT: