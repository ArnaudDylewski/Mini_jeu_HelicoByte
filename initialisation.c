#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "fonction.h"

t_player start(int argc , char **argv)
{
	t_player player;

	if (argv[1] && (my_strcmp(argv[1], "-n") == 0) && argc == 3)
	{
		player.name = argv[2];
		player.score = 0;
	}
	else 
	{
		player.name = '\0';
		player.score = 0;
	}
	return (player);
}

void verif_start(t_player one)
{
	if (one.name != '\0')
	{
		my_putstr("Bienvenue dans helicobyte ");
		my_putstr(one.name);
		my_putchar('\n');
		map(one);
	}
	else
	{
		my_putstr("Entrez l'option -n [login] pour lancer le jeu");
		my_putchar('\n');
	}
}
