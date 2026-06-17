
// cabeçalho

NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f

SRCS        = ft_printf.c \
              ft_parser.c \
              ft_utils.c \
              ft_print_char.c \
              ft_print_str.c \
              ft_print_ptr.c \
              ft_print_int.c \
              ft_print_uint.c \
              ft_print_hex.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re