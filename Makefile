NAME = main.c
C ?= "update:general"
CC = cc
FLAGS = -Wall -Wextra -Werror -lpthread
SRCS = coders/main.c \
	   coders/parsing.c \
	   coders/utils.c \
	   coders/time.c

all:
	$(CC) $(FLAGS) $(SRCS)

clean:
	rm *.o

fclean:
	rm a.out

send:
	git add .
	git commit -m $(C)
	git push


re: fclean all

.PHONY: all clean fclean re