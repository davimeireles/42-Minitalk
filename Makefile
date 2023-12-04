NAME = server client
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
LIBFT_DIR = libft/
SERVER = server
SERVER_SRCS = server.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT = client
CLIENT_SRCS = client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

# Variáveis de texo
GREEN = \033[92m
RESET	= \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(SERVER_OBJS) $(CLIENT_OBJS)
	$(CC) $(FLAGS) -o $(SERVER) $(SERVER_OBJS) $(LIBFT)
	$(CC) $(FLAGS) -o $(CLIENT) $(CLIENT_OBJS) $(LIBFT)
	@echo "[$(GREEN)SUCCESS$(RESET)]Compilation successful."

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "[$(GREEN)SUCCESS$(RESET)]Objects removed."

fclean: clean
	rm -rf $(CLIENT) $(SERVER)
	rm -rf $(LIBFT)
	@echo "[$(GREEN)SUCCESS$(RESET)]Static Library and Executables removed."

re: fclean all

.SILENT:

.PHONY: all clean fclean re
