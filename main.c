#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"
/*
int		main(int ac, char **av)
{
	char	*line;
	int		nb_line;
	int		fd;
	int		fd2;
	int		fd3;

	if (ac < 2)
		return (0);
	nb_line = 1;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		printf("le fichier n'existe pas.");
	line = NULL;
	while ((line = get_next_line(fd)) > 0)
	{
		printf("line[%d]: %s\n", nb_line, line);
		free(line);
		line = NULL;
		nb_line++;
	}
	printf("line[%d]: %s\n", nb_line, line);
	free(line);
	
	return (0);
}*/

int	main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		i;

	if (ac < 2)
		return (0);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		printf("Le fichier n'existe pas.");
	line = NULL;

	while (i < 52)
	{
		line = get_next_line(fd);
		printf("[%d]", i);
		printf("%s\n", line);
		free(line);
		i++;
	}
	return (0);
}
