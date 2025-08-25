NAME        = libftprintf.a

SRC = ft_printf.c handle_format.c parse_format.c print_char.c print_str.c print_int.c \
      print_unsigned.c print_hex.c print_pointer.c
	  
BONUS_SRC   = handle_format_bonus.c parse_format_bonus.c print_char_bonus.c \
              print_str_bonus.c print_int_bonus.c print_unsigned_bonus.c \
              print_hex_bonus.c print_pointer_bonus.c print_binary_bonus.c \
              print_n_bonus.c print_reverse_bonus.c

OBJ         = $(SRC:.c=.o)
BONUS_OBJ   = $(BONUS_SRC:.c=.o)

LIBFT       = libft/libft.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f

# Compilación estándar
all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(AR) $(NAME) $(OBJ) $(LIBFT)

# Compilación con bonus
bonus: $(OBJ) $(BONUS_OBJ)
	make -C libft
	$(AR) $(NAME) $(OBJ) $(BONUS_OBJ) $(LIBFT)

# Limpieza
clean:
	$(RM) $(OBJ) $(BONUS_OBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all