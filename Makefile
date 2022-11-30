NAME = programa
CFLAGS = -Wall -Werror -Wextra
OBJS = $(SRCS:.c=.o)
SRCS = main.c
DELETE = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $(OBJS)

clean:
	$(DELETE) $(OBJS)

fclean: clean
	$(DELETE) $(NAME)