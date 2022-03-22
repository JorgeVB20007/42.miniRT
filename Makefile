# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 19:44:26 by emadriga          #+#    #+#              #
#    Updated: 2022/03/22 21:15:25 by emadriga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program's name
NAME	= miniRT

# compiler
GCC		= clang

# compiling flags
FLAGS	= -Wall -Wextra -Werror $(SANITIZE) -pedantic

# sanitize
# SANITIZE =
# SANITIZE = -g3 -fsanitize=address
SANITIZE = -Ofast -fsanitize=address

# Header files
INCLUDES_FILES =	constants.h				\
					minirt.h				\
					dtos.h					\
					functions/coloring.h	\
					functions/parser.h		\
					functions/utils.h

# Source and object files
SRC_FILES	= 	main.c								\
				coloring/line_collision_checker.c	\
				coloring/set_color_matrix.c			\
				coloring/get_collision_point.c		\
				parser/fill_struct_by_type.c		\
				parser/parser.c						\
				parser/setting_corners.c			\
				parser/setting_cam_vectors.c		\
				render/render.c						\
				utils/rt_lst_functs.c				\
				utils/deg2rad.c						\
				utils/getmodule.c					\
				utils/plane_managing.c				\
				utils/vctr_int_operations.c			\
				utils/vctr_vctr_operations.c		\
				utils/sphere_managing.c				\
				utils/vctr_dot_product.c			\
				utils/vctr_turn2unit.c

OBJ_FILES	= $(SRC_FILES:.c=.o)

# Folders
INC_DIR = ./includes/
SRC_DIR = ./src/
OBJ_DIR = ./obj/
LIBFT_DIR = ./libft/
MINLBX_DIR = ./minilibx_mms_20200219/

# Paths
INCLUDES = $(addprefix $(INC_DIR), $(INCLUDES_FILES))
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

# Libft and Minilibx linkers
LNK  = -L $(LIBFT_DIR) -lft $(SANITIZE) -L $(MINLBX_DIR) \
	   -lmlx -framework OpenGL -framework AppKit

# all rule
all: obj $(LIBFT) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)coloring/
	@mkdir -p $(OBJ_DIR)parser/
	@mkdir -p $(OBJ_DIR)render/
	@mkdir -p $(OBJ_DIR)utils/
$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(INCLUDES)
	@$(GCC) $(FLAGS) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Compiling
$(NAME): $(OBJ)
	@echo "\033[0;33mCompiling... Wait a sec.\033[0;31m"
	@$(GCC) $(OBJ) $(FLAGS) $(LNK) -lm -o $(NAME)
	@echo "\033[0;32m$(NAME) generated!\033[0;37m"

bonus:	all

# clean rule
clean:
			@rm -Rf $(OBJ_DIR)
			@make -C $(LIBFT_DIR) clean
			@echo "\033[1;34m[INFO]\033[0m Objects removed!"

# fclean rule
fclean:		clean
			@rm -f $(NAME)
			@make -C $(LIBFT_DIR) fclean
			@echo "$(NAME) removed!"
			
# mynorm rule
mynorm:
	norminette $(SRC_DIR) $(INC_DIR) $(LIBFT_DIR)

# re rule
re:			fclean all bonus

# phony
.PHONY:		all clean fclean re mynorm
