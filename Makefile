##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## 101pong
##

SRC 	=	$(wildcard *.c)

NAME 	=	skala

all: $(NAME)

$(NAME):	$(SRC)
	gcc $(SRC) -o $(NAME) -lcsfml-window -lcsfml-graphics -lcsfml-graphics -lcsfml-system

clean:
	rm -f *#
	rm -f *~

fclean: clean
	rm -f $(NAME)

re:	fclean all
