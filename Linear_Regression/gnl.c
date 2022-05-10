/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:40:14 by alambert          #+#    #+#             */
/*   Updated: 2022/05/10 18:15:27 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./lib42/lib42.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
/*
int	main(void)
{
	int fd;
	int fd1;

	fd = open("sjp1.txt", O_RDONLY);
	fd1 = open("sjp2.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
	return (0);
}
*/
/*
int	main(int ac, char **av)
{
	int fd;
	char *line = "ok";

	(void)ac;
	fd = open(av[1], O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
 	       free(line);
	}
	free(line);
	return (0);
}
*/
int	main(void)
{
	int fd;
	char *line = "ok";

	fd = open("sjp1.txt", O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
 	    free(line);
	}
	free(line);
	return (0);
}

