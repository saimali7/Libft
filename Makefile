# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 17:27:07 by sali              #+#    #+#              #
#    Updated: 2021/10/06 18:07:15 by sali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= libft.a

SRCS					= ft_atoi.c \
					  ft_bzero.c \
					  ft_calloc.c \
					  ft_isalnum.c \
					  ft_isalpha.c \
					  ft_isascii.c \
					  ft_isdigit.c \
					  ft_isprint.c \
					  ft_memchr.c \
					  ft_memcmp.c \
					  ft_memcpy.c \
					  ft_memmove.c \
					  ft_memset.c \
					  ft_strchr.c \
					  ft_strdup.c \
					  ft_strlcat.c \
					  ft_strlcpy.c \
					  ft_strlen.c \
					  ft_strncmp.c \
					  ft_strnstr.c \
					  ft_strrchr.c \
					  ft_tolower.c \
					  ft_toupper.c

BNS_SRCS				= ft_lstsize.c \
					  ft_lstadd_back.c \
					  ft_lstadd_front.c \
					  ft_lstclear.c \
					  ft_lstdelone.c \
					  ft_lstiter.c \
					  ft_lstlast.c \
					  ft_lstmap.c \
					  ft_lstnew.c

OBJS					= $(SRCS:%.c=%.o)

BNS_OBJS				= $(BNS_SRCS:%.c=%.o)

FLAGS					= -Wall -Wextra -Werror

$(NAME)		:	$(OBJS)
			gcc $(FLAGS) -c $(SRCS)
			ar rc $(NAME) $(OBJS)

all	:	$(NAME)

bonus	:	$(NAME)
		gcc $(FLAGS) -c $(BNS_SRCS) -I./
		ar rc $(NAME) $(BNS_OBJS)

clean	:
		rm -f $(OBJS) $(BNS_OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
