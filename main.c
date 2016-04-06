#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
int		main(int argc, char **argv)
{
	verif_start(start(argc , argv));
	return(0);
}
