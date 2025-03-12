CC = cc
CFLAGS = -Wall -Wextra -Werror
SERVER = server
SERVER_BONUS = server_bonus
CLIENT = client
CLIENT_BONUS = client_bonus
SRCS_SERVER = server.c
SRCS_SERVER_B = server_bonus.c
SRCS_CLIENT = client.c
SRCS_CLIENT_B = client_bonus.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_B:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_B:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(SERVER) $(CLIENT)

bonus: $(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

$(SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER) $(LIBFT)

$(CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT) $(LIBFT)

$(SERVER_BONUS): $(OBJS_SERVER_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(OBJS_SERVER_BONUS) $(LIBFT)

$(CLIENT_BONUS): $(OBJS_CLIENT_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(OBJS_CLIENT_BONUS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	rm -f $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	rm -f $(SERVER_BONUS) $(CLIENT_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
