# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/25 19:15:33 by emadriga          #+#    #+#              #
#    Updated: 2022/01/23 23:24:41 by emadriga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Source files
SRC	=	ft_atoi.c			ft_bzero.c			ft_calloc.c			ft_isalnum.c		\
		ft_isalpha.c		ft_isascii.c		ft_isdigit.c		ft_isprint.c		\
		ft_itoa.c			ft_memccpy.c		ft_memchr.c			ft_split.c			\
		ft_memcmp.c			ft_memcpy.c			ft_memmove.c		ft_memset.c			\
		ft_putchar_fd.c		ft_putendl_fd.c		ft_putnbr_fd.c		ft_putstr_fd.c		\
		ft_strchr.c			ft_strdup.c			ft_strjoin.c		ft_strlcat.c		\
		ft_strlcpy.c		ft_strlen.c			ft_strtrim.c		ft_strncmp.c		\
		ft_strnstr.c		ft_strrchr.c		ft_strmapi.c		ft_substr.c			\
		ft_tolower.c		ft_toupper.c		ft_isspace.c							\
		ft_lstadd_back.c	ft_lstadd_front.c	ft_lstclear.c		ft_lstdelone.c		\
		ft_lstiter.c		ft_lstlast.c		ft_lstnew.c			ft_lstsize.c		\
		ft_lstmap.c			get_next_line.c		ft_strreplace.c		ft_strreplaceat.c	\
		ft_strcmp.c			ft_free.c			ft_strjoin_freedouble.c

# Name of the Library
NAME	= libft.a

# Compiling flags
FLAGS	= -Wall -Wextra -Werror

OBJS	= $(SRC:.c=.o)

# Compile last modifications
.c.o:
			@gcc $(FLAGS) -c -o $@ $<

# all rule
all:		$(NAME)

# Compile as library
$(NAME):	$(OBJS)
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)
			@echo "\033[1;34m[INFO]\033[0m Library [$(NAME)] created!"

# clean rule
clean:
			@rm -f $(OBJS)
			@echo "\033[1;34m[INFO]\033[0m Objects removed!"
# fclean rule
fclean:		clean
			@rm -f $(NAME)
			@echo "\033[1;34m[INFO]\033[0m Library removed!"

# re rule
re:			fclean all

# phony
.PHONY:		all clean fclean re
