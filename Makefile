CC = CC
CFLAGS = -Wall -Wextra -Werror -g
NAME = minitalk
CLT = client
SRC_CLT = client.c
SRV = server
SRC_SRV = server.c

all: $(NAME)

$(NAME): $(SRV) $(CLT)

$(SRV):
	$(CC) $(CFLAGS) $(SRC_SRV) -o $(SRV)

$(CLIENT):
	$(CC) $(CFLAGS) $(SRC_CLT) -o $(CLT)

clean:
	rm -f $(SRV)
	rm -f $(CLT)

fclean: clean

re: fclean all

.PHONY: all clean fclean re