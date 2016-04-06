#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

void aff_map(char map[5][5])
{
	int i;
	int j;

	i = 0;
	j = 0;
	my_putstr("-----\n");
	while(i < 5)
	{
		while(j < 5)
		{
			my_putchar(map[i][j]);
			j++;
		}
		my_putchar('\n');
		j=0;
		i++;
	}
	my_putstr("-----\n");

}

t_helico pos(char map[5][5])
{
	t_helico pos;
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < 5)
	{
		while(j < 5)
		{
			if (map[i][j] == '*')
				{
					pos.x = i;
					pos.y = j;
				}
			j++;
		}
		j=0;
		i++;
	}
	return(pos);
}

char up(char map[5][5])
{
	int x;
	int y;
	t_helico position;
	position = pos(map);
	x = position.x;
	y = position.y;
	if (x != 0)
	{
		map[x-1][y] = '*';
		map[x][y] = ' ';
	}
	return(**map);

}
char down(char map[5][5])
{
	int x;
	int y;
	t_helico position;
	position = pos(map);
	x = position.x;
	y = position.y;
	if (x != 4)
	{
		map[x+1][y] = '*';
		map[x][y] = ' ';
	}
	return(**map);

}

void map(t_player one)
{
	t_helico coco;
	char* read;
	char map[5][5] = {
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '}
	};
	map[2][0] = '*';
	read = "rien";
	play(read, map, one, coco);
}
