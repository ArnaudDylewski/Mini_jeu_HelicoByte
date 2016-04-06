CC =	gcc
NAME =	helicobyte
SRC =	fonc_lib.c 			\
		readline.c 			\
		fonc_lib2.c 		\
		initialisation.c 	\
		obstacle.c 			\
		map.c 				\
		main.c
		

OBJ = 	$(SRC:%.c=%.o)
CFLAGS = -W -Wall -Werror -Wextra -pedantic
RM =	rm -f
$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) 

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:			clean
		$(RM) $(NAME)

re:		fclean all