/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filesize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:02:38 by alambert          #+#    #+#             */
/*   Updated: 2022/07/19 00:00:12 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

void	ft_filesize(int fd, int count[2])
{
	int		len;
	char	*bin;

	count[0] = -1;
	count[1] = 1;
	bin = malloc(sizeof(char) + 1);
	if (!bin)
		return ;
	len = 1;
	while (len != 0)
	{
		len = read(fd, bin, 1);
		if (len == -1)
		{
			bin = ft_free(&bin);
			return ;
		}
		if (*bin == '\n')
			count[1] += 1;
		bin[1] = '\0';
		count[0] += 1;
	}
	bin = ft_free(&bin);
	if (bin)
		ft_free(&bin);
}

/* count[0] : char number,
count[1] : line number. */
