NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f

SRCS        = ft_printf.c \
              ft_print_utils.c \
              ft_print_hex.c

OBJS        = $(SRCS:.c=.o)

BONUS_SRCS  = ft_printf_bonus.c \
              ft_print_utils_bonus.c \
              ft_print_hex_bonus.c

BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: .bonus

.bonus: $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)
	@touch .bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) .bonus

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus