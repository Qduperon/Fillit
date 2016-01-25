# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qduperon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 11:29:17 by qduperon          #+#    #+#              #
#    Updated: 2016/01/25 16:54:42 by qduperon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

NAME_LIB = libft.a

SRC_LIB = src_lib/ft_atoi.c \
		src_lib/ft_bzero.c \
		src_lib/ft_clear_tab.c \
		src_lib/ft_isalnum.c \
		src_lib/ft_isalpha.c \
		src_lib/ft_isascii.c \
		src_lib/ft_isdigit.c \
		src_lib/ft_isprint.c \
		src_lib/ft_isspace.c \
		src_lib/ft_itoa.c \
		src_lib/ft_lstadd.c \
		src_lib/ft_lstdel.c \
		src_lib/ft_lstdelone.c \
		src_lib/ft_lstiter.c \
		src_lib/ft_lstmap.c \
		src_lib/ft_lstnew.c \
		src_lib/ft_memalloc.c \
		src_lib/ft_memccpy.c \
		src_lib/ft_memchr.c \
		src_lib/ft_memcmp.c \
		src_lib/ft_memcpy.c \
		src_lib/ft_memdel.c \
		src_lib/ft_memmove.c \
		src_lib/ft_memset.c \
		src_lib/ft_putchar.c \
		src_lib/ft_putchar_fd.c \
		src_lib/ft_putendl.c \
		src_lib/ft_putendl_fd.c \
		src_lib/ft_putnbr.c \
		src_lib/ft_putnbr_fd.c \
		src_lib/ft_putstr.c \
		src_lib/ft_putstr_fd.c \
		src_lib/ft_size_base.c \
		src_lib/ft_strcat.c \
		src_lib/ft_strchr.c \
		src_lib/ft_strclr.c \
		src_lib/ft_strcmp.c \
		src_lib/ft_strcpy.c \
		src_lib/ft_strdel.c \
		src_lib/ft_strdup.c \
		src_lib/ft_strequ.c \
		src_lib/ft_striter.c \
		src_lib/ft_striteri.c \
		src_lib/ft_strjoin.c \
		src_lib/ft_strlcat.c \
		src_lib/ft_strlen.c \
		src_lib/ft_strmap.c \
		src_lib/ft_strmapi.c \
		src_lib/ft_strncat.c \
		src_lib/ft_strncmp.c \
		src_lib/ft_strncpy.c \
		src_lib/ft_strnequ.c \
		src_lib/ft_strnew.c \
		src_lib/ft_strnstr.c \
		src_lib/ft_strrchr.c \
		src_lib/ft_strrev.c \
		src_lib/ft_strsplit.c \
		src_lib/ft_strstr.c \
		src_lib/ft_strsub.c \
		src_lib/ft_strtolower.c \
		src_lib/ft_strtoupper.c \
		src_lib/ft_strtrim.c \
		src_lib/ft_tolower.c \
		src_lib/ft_toupper.c \

OBJ = ft_atoi.o \
	  ft_bzero.o \
	  ft_clear_tab.o \
	  ft_isalnum.o \
	  ft_isalpha.o \
	  ft_isascii.o \
	  ft_isdigit.o \
	  ft_isprint.o \
	  ft_isspace.o \
	  ft_itoa.o \
	  ft_lstadd.o \
	  ft_lstdel.o \
	  ft_lstdelone.o \
	  ft_lstiter.o \
	  ft_lstmap.o \
	  ft_lstnew.o \
	  ft_memalloc.o \
	  ft_memccpy.o \
	  ft_memchr.o \
	  ft_memcmp.o \
	  ft_memcpy.o \
	  ft_memdel.o \
	  ft_memmove.o \
	  ft_memset.o \
	  ft_putchar.o \
	  ft_putchar_fd.o\
	  ft_putendl.o \
	  ft_putendl_fd.o \
	  ft_putnbr.o \
	  ft_putnbr_fd.o \
	  ft_putstr.o \
	  ft_putstr_fd.o \
	  ft_size_base.o \
	  ft_strcat.o \
	  ft_strchr.o \
	  ft_strclr.o \
	  ft_strcmp.o \
	  ft_strcpy.o \
	  ft_strdel.o \
	  ft_strdup.o \
	  ft_strequ.o \
	  ft_striter.o \
	  ft_striteri.o \
	  ft_strjoin.o \
	  ft_strlcat.o \
	  ft_strlen.o \
	  ft_strmap.o \
	  ft_strmapi.o \
	  ft_strncat.o \
	  ft_strncmp.o \
	  ft_strncpy.o \
	  ft_strnequ.o \
	  ft_strnew.o \
	  ft_strnstr.o \
	  ft_strrchr.o \
	  ft_strrev.o \
	  ft_strsplit.o \
	  ft_strstr.o \
	  ft_strsub.o \
	  ft_strtolower.o \
	  ft_strtoupper.o \
	  ft_strtrim.o \
	  ft_tolower.o \
	  ft_toupper.o \

SRC = src/main.c \
	src/tetriminos.c \
	src/check_file.c \
	src/resolve.c \

OBJ_LIB = $(SRC_LIB:.c=.o)

FLAGS = -Werror -Wextra -Wall

all: $(NAME_LIB) $(NAME)

$(NAME_LIB):
	@echo "compiling library..."
	@gcc $(FLAGS) -c $(SRC_LIB) -I ./include
	@mv $(OBJ) ./src_lib
	@ar -r $(NAME_LIB) $(OBJ_LIB)
	@ranlib $(NAME_LIB)
	@echo "library done"

$(NAME):
	@echo "compiling fillit..."
	@gcc $(FLAGS) $(SRC) -o $(NAME) -L. -lft  -I ./include
	@echo "fillit done"

clean :
	@echo "deleting objects..."
	@rm -f $(OBJ_LIB)
	@echo "deleting done"

fclean : clean
	@echo "deleting library and fillit..."
	@rm -f $(NAME)
	@rm -f $(NAME_LIB)
	@echo "deleting done"

re : fclean all

.PHONY : all clean fclean re
