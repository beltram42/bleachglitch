/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:47:59 by alambert          #+#    #+#             */
/*   Updated: 2022/02/15 19:17:29 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strfbspn(const char *str, const char *set, int gear)
{
	const char	*p;
	const char	*s;
	int			len;

	p = str;
	len = ft_strlen(str);
	if (gear == -1)
		p += len - 1;
	while (*p)
	{
		s = set;
		s = ft_strchr(s, *p);
		if (s == 0)
			break ;
		if (gear == -1)
			p--;
		else if (gear == 1)
			p++;
	}
	return (p - str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		fspn;
	int		bspn;
	int		len;
	char	*s1trim;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	fspn = ft_strfbspn(s1, set, 1);
	if (len == fspn)
	{
		s1trim = malloc(sizeof(char) * 1);
		if (s1trim == NULL)
			return (NULL);
		*s1trim = '\0';
		return (s1trim);
	}
	bspn = ft_strfbspn(s1, set, -1);
	len = (bspn + 1) - fspn;
	s1trim = ft_substr(s1, fspn, len);
	return (s1trim);
}
