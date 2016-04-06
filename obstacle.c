#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"

char obstacle(char map[5][5])
{
	int i;

	srand(time(NULL));
	i = rand()%5;
	map[i][4] = 'H';
	return(**map);
}
char mv_obstacle(char map[5][5])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < 5)
	{
		while(j < 5)
		{
			if (map[i][j] == 'H')
				{
					if (j-1 != -1)
					{
						map[i][j-1] = 'H';
						map[i][j] = ' ';
					}
					else
						map[i][j] = ' ';
				}
			j++;
		}
		j=0;
		i++;
	}
	return(**map);
}
int score(int score, char map[5][5])
{
	int i;

	i = 0;
	while(i < 5)
	{
		if (map[i][0] == 'H')
		{
			score++;
		}
		i++;
	}
	return(score);
}
t_helico win(char map[5][5])
{
	t_helico coco;
	int x;
	int y;

	coco = pos(map);
	x = coco.x;
	y = coco.y;
	if (map[x][y+1] == 'H')
		coco.los = 1;
	else
		coco.los = 0;
	return(coco);
}

void play(char *read, char map[5][5],t_player one, t_helico coco)
{
	while(my_strcmp(read, "quit") != 0)
	{

		my_putstr("Votre score est de : ");
		my_put_nbr(one.score);
		my_putchar('\n');
		aff_map(map);
		if (coco.los != 1)
		{
			read = readLine();
			one.score = score(one.score , map);
			if (my_strcmp(read, "up") == 0)
				up(map);
			else if (my_strcmp(read, "down") == 0)
				down(map);
		}
		else
		{
			read = "quit";
			my_putstr("Votre helicobyte a été touché, vous avez perdu avec un score de ");
			my_put_nbr(one.score);
			my_putchar('\n');
		}
		obstacle(map);
		coco = win(map);
		mv_obstacle(map);
	}
}
