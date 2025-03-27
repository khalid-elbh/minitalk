
NAME_1 = server
NAME_2 = client
NAME_3 = server_bonus
NAME_4 = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = mandatory/server.c mandatory/client.c mandatory/utils.c
BONUS_SRCS = bonus/server_bonus.c bonus/client_bonus.c bonus/utils_bonus.c

SERVER_OBJ = mandatory/server.o
UTILS_OBJ = mandatory/utils.o
CLIENT_OBJ = mandatory/client.o
BONUS_SERVER_OBJ = bonus/server_bonus.o
BONUS_UTILS_OBJ = bonus/utils_bonus.o
BONUS_CLIENT_OBJ = bonus/client_bonus.o
FT_PRINTF = ft_printf/libftprintf.a

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME_1) $(NAME_2)

bonus: $(NAME_3) $(NAME_4)

$(NAME_1): $(OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(UTILS_OBJ) -o $(NAME_1) $(FT_PRINTF)

$(NAME_2): $(OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(UTILS_OBJ) -o $(NAME_2) $(FT_PRINTF)

$(NAME_3): $(BONUS_OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(BONUS_SERVER_OBJ) $(BONUS_UTILS_OBJ) -o $(NAME_3) $(FT_PRINTF)

$(NAME_4): $(BONUS_OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(BONUS_CLIENT_OBJ) $(BONUS_UTILS_OBJ) -o $(NAME_4) $(FT_PRINTF)

$(FT_PRINTF):
	@make -C ft_printf

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@make -C ft_printf clean
	@echo "Clean done."

fclean: clean
	@rm -f $(NAME_1) $(NAME_2) $(NAME_3) $(NAME_4)
	@make fclean -C ft_printf
	@echo "Fclean done"

re: fclean all

.PHONY: all clean fclean re bonus
