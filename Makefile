CC = cc
CFLAGS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER) $(LIBFT)

$(CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re