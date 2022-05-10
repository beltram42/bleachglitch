/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:12:51 by alambert          #+#    #+#             */
/*   Updated: 2022/05/08 21:23:42 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

static char	*ft_malmove(const char *s1, const char *s2, int len1, int len2)
{
	char	*res;

	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	ft_memmove((void *)(res), (void *)s1, len1);
	ft_memmove((void *)(res + len1), (void *)(s2), len2 + 1);
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		len1;
	int		len2;

	res = NULL;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = ft_malmove(s1, s2, len1, len2);
	return (res);
}
