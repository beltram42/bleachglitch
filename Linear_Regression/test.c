/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:29:48 by alambert          #+#    #+#             */
/*   Updated: 2022/05/13 19:42:00 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//#include "lib42.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF 1

int	ft_getchar(void)
{
	char	*save;
	char	c;

	if (read(0, save, BUF) == -1)
		return (0);
	c = *save;
	return ((int)c);
}

char	*ft_getstr_0(void)
{
	static char	*buffer;

	while (ft_getchar() != '\n')
		*buffer++ = (char)ft_getchar();
	*buffer = '\0';
	return (buffer);
}

int	main(void)
{
	char	c;
	char	*test;

	c = (char)ft_getchar();
	printf("stdin c = %c\n", c);
	/*test = ft_getstr_0();
	printf("stdin str = %s\n", test);*/
	return (0);
}


/*
int	ft_getchar(void)
{
	int	len;
	char	*save;
	char	c;

	save = malloc(sizeof(char) * (BUF + 1));
	if (!save)
		return (0);
	len = 1;
	len = read(0, s, BUF);
	if (len == -1)
	{
		free(save);
		return (0);
	}
	save[len] = '\0';
	c = *save;
	free(save);
	return (c);
}
*/
