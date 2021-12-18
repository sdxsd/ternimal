CC = clang
CFLAGS = -g -o
NAME = ternimal

all: $(NAME)

$(NAME):
	$(CC) src/*.c $(CFLAGS) $(NAME)
	@echo "COMPILED TERNIMAL"

re: clean $(NAME)
	@echo "RECOMPILING"

clean:
	@rm -f $(NAME)
	@rm -f $(NAME).dSYM
	@echo "FULLY CLEANED"
