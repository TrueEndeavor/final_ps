NAME = push_swap
BONUS_NAME = checker
LIBFTNAME = libft.a

CC = cc -g3
CCFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = -rcs

LIBFT_DIR = ./include/libft_combined

INCLUDES = -I./include -I$(LIBFT_DIR)/include

SRCS = src/mandatory/push_swap.c \
		src/mandatory/operations/generic_ops.c \
		src/mandatory/operations/wrapper_push.c \
		src/mandatory/operations/wrapper_reverse_rotate.c \
		src/mandatory/operations/wrapper_rotate.c \
		src/mandatory/operations/wrapper_swap.c	\
		src/mandatory/utils/error.c \
		src/mandatory/utils/free_all.c \
		src/mandatory/utils/print_stack_debug.c \
		src/mandatory/parsing/parsing.c \
		src/mandatory/parsing/parse_utils.c \
		src/mandatory/sort/sort_two.c	\
		src/mandatory/sort/sort_three.c \
		src/mandatory/algo/algo_start.c	\
		src/mandatory/algo/algo_utils.c	\
		src/mandatory/algo/inbound_transfer1.c \
		src/mandatory/algo/inbound_transfer2.c	\
		src/mandatory/algo/outbound_transfer.c

BONUS_SRCS = src/bonus/checker.c
				
OBJS = $(SRCS:%.c=%.o)

BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

$(NAME): $(LIBFT_DIR)/$(LIBFTNAME) $(OBJS)
	$(CC) $(CCFLAGS) $(SRCS) $(LIBFT_DIR)/$(LIBFTNAME) $(INCLUDES) -o ${NAME}

$(BONUS_NAME): $(LIBFT_DIR)/$(LIBFTNAME) $(BONUS_OBJS)
	$(CC) $(CCFLAGS) $(BONUS_SRCS) $(LIBFT_DIR)/$(LIBFTNAME) $(INCLUDES) -o ${BONUS_NAME}

$(LIBFT_DIR)/$(LIBFTNAME):
	make -C $(LIBFT_DIR)

%.o: %.c $(HEADERS)
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

bonus: $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	cd $(LIBFT_DIR) && make clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	cd $(LIBFT_DIR) && make fclean

re: fclean
	make

.PHONY: all clean fclean re
