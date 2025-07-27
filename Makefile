NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = apply.c \
       assign_index.c \
       costing.c \
       error.c \
       find.c \
       large_sort.c \
       main.c \
       parsing.c \
       push.c \
       reverse_rotate_operations.c \
       rotate_operations.c \
       small_sort.c \
       swap.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) 
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft  -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR)  -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re