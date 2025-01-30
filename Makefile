##
## EPITECH PROJECT, 2024
## B-PSU-100-LYN-1-1-mytop-alexis.drago-beltran
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)	\
		$(wildcard lib/my/*.c)	\
		$(wildcard src/*.c)	\
		$(wildcard src/flags/*.c)	\
		$(wildcard src/security/*.c)	\

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

EXEC	=	my_sudo

CFLAGS	+=	-Wall -g3 -I./include -lcrypt

all:	${EXEC}

$(EXEC):	${OBJ}
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS)

clean:
	rm -f vgcore.* $(OBJ) *.gch

fclean:	clean
	rm -f $(EXEC)

re:	fclean	all

.PHONY:	all	clean	fclean	re
