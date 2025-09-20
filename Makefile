NAME = philosophers
CC = cc
CFLAGS = -Wall -Werror -Wextra -g 
HEADER = philosophers.h
SRCS = philoshophers_main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c Makefile $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
