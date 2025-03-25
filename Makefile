
NAME_1 = server
NAME_2 = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = mandatory/server.c mandatory/client.c

SERVER_OBJ = mandatory/server.o
CLIENT_OBJ = mandatory/client.o

OBJS = $(SRCS:.c=.o)


all: $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJS)
	@$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(NAME_1)
	@echo "Mandatory done."
$(NAME_2): $(OBJS)
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(NAME_2)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -f $(OBJS)
	@echo "Clean done."
fclean: clean
	@rm -f $(NAME_1) $(NAME_2)
	@echo "Fclean done"

re: fclean all

.PHONY: all clean fclean re
