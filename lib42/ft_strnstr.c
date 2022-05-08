/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:49:57 by alambert          #+#    #+#             */
/*   Updated: 2022/05/08 20:14:02 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(haystack);
	len2 = ft_strlen(needle);
	if (!len2)
		return ((char *)haystack);
	if (*haystack == '\0' && len2)
		return (NULL);
	while (len >= len2)
	{
		if (!ft_memcmp(haystack, needle, len2))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
