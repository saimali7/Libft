SRC_NAME = ft_atoi.c\
        ft_bzero.c\
        ft_calloc.c\
        ft_isalnum.c\
        ft_isalpha.c\
        ft_isascii.c\
        ft_isdigit.c\
        ft_isprint.c\
        ft_memchr.c\
        ft_memchr.c\
        ft_memcmp.c\
        ft_memcpy.c\
        ft_memmove.c\
        ft_memset.c\
        ft_strchr.c\
        ft_strrchr.c\
        ft_strdup.c\
        ft_strlcat.c\
        ft_strlcpy.c\
        ft_strlen.c\
        ft_strncmp.c\
        ft_strnstr.c\
        ft_tolower.c\
        ft_toupper.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c

OBJ_NAME = $(SRC_NAME:.c=.o)
HEADER = ./includes/
CFLAG = -Wall -Wextra -Werror
NAME = libft.a
all: ${NAME}
${NAME}:
	gcc -c $(CFLAG) $(SRC_NAME)
	ar -rc $(NAME) $(OBJ_NAME)
	ranlib $(NAME)
clean:
	rm -rf ${OBJ_NAME}
fclean: clean
	rm -f ${NAME}
re: fclean all
