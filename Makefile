NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra -g 
HEADER = philosophers.h
SRCS = philosophers_main.c\
	   philosophers_utils.c
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
