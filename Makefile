NAME = main.c
C ?= "update:general"
CC = cc
FLAGS = -Wall -Wextra -Werror -lpthread
SRCS = coders/main.c \
	   coders/parsing.c \
	   coders/utils.c \
	   coders/arg_check.c

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


# .PHONY all clean fclean