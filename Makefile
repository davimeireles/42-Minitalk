NAME = server client
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
LIBFT_DIR = libft/
SERVER = server
SERVER_SRCS = server.c server_utils.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT = client
CLIENT_SRCS = client.c client_utils.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

# Variáveis de texo
GREEN = \033[92m

all: $(NAME)
	@echo "$(GREEN)[SUCCESS]Compilation successful."

$(NAME): $(LIBFT) $(SERVER_OBJS) $(CLIENT_OBJS)
	$(CC) $(FLAGS) -o $(SERVER) $(SERVER_OBJS) $(LIBFT)
	$(CC) $(FLAGS) -o $(CLIENT) $(CLIENT_OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(GREEN)**[SUCCESS]Objects removed.**"

fclean: clean
	rm -rf $(CLIENT) $(SERVER)
	rm -rf $(LIBFT)
	@echo "$(GREEN)**[SUCCESS]Static Library removed.**"

re: fclean all
