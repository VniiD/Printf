NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f
AR          = ar rcs

SRCS        = ft_printf_bonus.c \
              ft_printf_processor_bonus.c \
              ft_printf_text_bonus.c \
              ft_printf_nbr_bonus.c \
              ft_printf_hex_bonus.c \
              ft_printf_nbr_utils_bonus.c \
              ft_printf_parse_utils_bonus.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Regra exigida explicitamente no Capítulo II e IV do Subject
bonus: $(NAME)

%.o: %.c ft_printf_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
