/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:37:44 by alambert          #+#    #+#             */
/*   Updated: 2022/02/10 16:14:54 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (*s++ && len < maxlen)
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	nlen;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup("\0"));
	nlen = ft_strnlen(s, len);
	sub = malloc(sizeof(char) * (nlen + 1));
	if (sub == NULL)
		return (NULL);
	while (start--)
		s++;
	ft_memcpy(sub, s, nlen);
	ft_memcpy(sub + nlen, "\0", 1);
	return (sub);
}
