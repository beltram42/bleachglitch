/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:12:51 by alambert          #+#    #+#             */
/*   Updated: 2022/05/18 13:46:59 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*swap;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (NULL);
	swap = ft_strdup(s1);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	s1 = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!s1)
		return (NULL);
	ft_memcpy((void *)(s1), (const void *)swap, (s1len + 1));
	ft_memcpy((void *)(s1 + s1len), (const void *)s2, (s2len + 1));
	free(swap);
	return ((char *)s1);
}
