NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c
OBJ := $(SRC:%.c=%.o)

LIBFT_PATH = ../libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_PATH)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -I. -I$(LIBFT_PATH) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

main: re
	$(CC) $(FLAGS) main.c -L. -lftprintf -I. -Ilibft -o main

re: fclean all
