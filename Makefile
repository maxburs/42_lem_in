
CHECKER = checker

PUSH_SWAP = push_swap

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft/

SRC = 

OBJ = $(SRC:.c=.o)

HEADERS = -I ./src -I ./src/libft

CFLAGS = -Wall -Wextra -Werror

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(LIBFT) $(CHECKER_OBJ)
	gcc $(CFLAGS) -o $@ $^

$(PUSH_SWAP): $(LIBFT) $(PUSH_SWAP_OBJ)
	gcc $(CFLAGS) -o $@ $^

%.o: %.c
	gcc $(CFLAGS) $(HEADERS) -c -o $@ $<

$(LIBFT): force
	@echo building libft
	cd ./libft && $(MAKE)

force:
	@true

clean:
	rm -f $(CHECKER_OBJ) $(PUSH_SWAP_OBJ)
	cd ./libft && $(MAKE) fclean
fclean: clean
	rm -f $(CHECKER) $(PUSH_SWAP)
re: fclean all

.PHONY: all clean fclean re
