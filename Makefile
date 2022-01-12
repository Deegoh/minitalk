CC = CC
CFLAGS = -Wall -Wextra -Werror
NAME = minitalk
SRC_CLT = client.c
SRC_SRV = server.c
SRC = utils.c
OBJ = $(SRC:.c=.o)
CLT = client
SRV = server

all: $(NAME)

$(NAME): $(OBJ) $(SRV) $(CLT)

$(SRV):
	$(CC) $(CFLAGS) $(SRC_SRV) $(OBJ) -o $(SRV)

$(CLT):
	$(CC) $(CFLAGS) $(SRC_CLT) $(OBJ) -o $(CLT)

clean:
	rm -f $(SRV)
	rm -f $(CLT)
	rm -f $(OBJ)

fclean: clean

re: fclean all

.PHONY: all clean fclean re