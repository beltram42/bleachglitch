/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbuf0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:29:48 by alambert          #+#    #+#             */
/*   Updated: 2022/07/11 12:21:06 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_getbuf0(int buf)
{
	char	*save;
	char	*bin;
	int		len;

	save = malloc(sizeof(char) * (buf + 1));
	bin = malloc(sizeof(char));
	if (!save)
		return (NULL);
	len = read(0, save, buf);
	if (len == -1)
	{
		save = ft_free(&save);
		return (NULL);
	}
	save[len] = '\0';
	if (save[len - 1] != '\n' && len == buf)
	{
		read(0, bin, 1);
		while (*bin != '\0' && *bin != '\n')
			len = read(0, bin, 1);
		bin = ft_free(&bin);
	}
	if (bin)
		ft_free(&bin);
	return ((char *)save);
}


/* Retrieves stdin's input in a pre-sized buf and 
discards what exceeds our buf size in read's buffer */