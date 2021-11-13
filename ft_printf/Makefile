SRC_NAME = ft_putchar.c\
ft_strlen.c\
ft_strchr.c\
ft_putnbr.c\
ft_putbase.c\
char.c\
string.c\
pointer.c\
int.c\
unsigned.c\
hex.c\
caphex.c\
percent.c\
ft_printf.c

OBJ_NAME = $(SRC_NAME:.c=.o)
CFLAG = -Wall -Wextra -Werror
NAME = libftprintf.a
${NAME}:
	gcc -c $(CFLAG) $(SRC_NAME)
	ar -rc $(NAME) $(OBJ_NAME)

all: ${NAME}

bonus: ${NAME}

clean:
	rm -rf ${OBJ_NAME}
fclean: clean
	rm -f ${NAME}
re: fclean all
