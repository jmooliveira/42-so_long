/*utils.c*/

#include "so_long.h"

int	ft_ptrlen(char **ptr)
{
	int	i;
	
	i = 0;
	while (ptr[i] != NULL)
	i++;
	return (i);
}