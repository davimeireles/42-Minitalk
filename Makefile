NAME = server client
NAME_BONUS = server_bonus client_bonus
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
LIBFT_DIR = libft/
SERVER = server
SERVER_SRCS = server.c utils.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
SERVER_BONUS = server_bonus
SERVER_SRCS_BONUS = server_bonus.c
SERVER_OBJS_BONUS = $(SERVER_SRCS_BONUS:.c=.o)
CLIENT = client
CLIENT_SRCS = client.c utils.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
CLIENT_BONUS = client_bonus
CLIENT_SRCS_BONUS = client_bonus.c
CLIENT_OBJS_BONUS = $(CLIENT_SRCS_BONUS:.c=.o)

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

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)
	$(CC) $(FLAGS) -o $(SERVER_BONUS) $(SERVER_OBJS_BONUS) $(LIBFT)
	$(CC) $(FLAGS) -o $(CLIENT_BONUS) $(CLIENT_OBJS_BONUS) $(LIBFT)
	@echo "[$(GREEN)SUCCESS$(RESET)]Compilation Bonus successful."

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "[$(GREEN)SUCCESS$(RESET)]Objects removed."

fclean: clean
	rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	rm -rf $(LIBFT)
	@echo "[$(GREEN)SUCCESS$(RESET)]Static Library and Executables removed."

re: fclean all

.SILENT:

.PHONY: all clean fclean re
