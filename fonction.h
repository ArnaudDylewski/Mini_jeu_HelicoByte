#ifndef _FONCTION_H_
#define _FONCTION_H_

struct s_player
{
	char*	name;
	int		score;
};
typedef struct s_player t_player;

struct s_helico
{
	int 	x;
	int 	y;
	int 	los;
};
typedef struct s_helico t_helico;

void		my_putchar(char c);
void		my_putstr(char *str);
int			my_strlen(char *str);
int 		my_strcmp(char *s1, char *s2);
void		my_put_nbr(int n);

t_player 	start(int argc , char **argv);
void 		verif_start(t_player one);
char		*readLine();
t_helico 	pos(char map[5][5]);
char 		obstacle(char map[5][5]);
int 		score(int score, char map[5][5]);
char 		mv_obstacle(char map[5][5]);
t_helico 	win(char map[5][5]);
char 		down(char map[5][5]);
char 		up(char map[5][5]);
void 		aff_map(char map[5][5]);
void 		play(char *read, char map[5][5],t_player one, t_helico coco);
void 		map(t_player one);



#endif
