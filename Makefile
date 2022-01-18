CC = CC
CFLAGS = -Wall -Wextra -Werror
NAME = minitalk
SRC_CLT = client.c
SRC_SRV = server.c
CLT = client
SRV = server
LIBFT_DIR = ./libft/
INCLUDES = -I$(LIBFT_DIR)
LIB = -lft -L $(LIBFT_DIR)

all: $(NAME)

$(NAME): libft $(SRV) $(CLT)

$(SRV):
	$(CC) $(LIB) $(INCLUDES) $(CFLAGS) $(SRC_SRV) -o $(SRV)
$(CLT):
	$(CC) $(LIB) $(INCLUDES) $(CFLAGS) $(SRC_CLT) -o $(CLT)
libft:
	@$(MAKE) -sC $(LIBFT_DIR)
clean:
	rm -f $(SRV)
	rm -f $(CLT)
	$(MAKE) clean -sC $(LIBFT_DIR)
fclean: clean
	$(MAKE) fclean -sC $(LIBFT_DIR)
re: fclean all

.PHONY: all clean fclean re libft