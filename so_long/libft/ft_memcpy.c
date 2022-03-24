/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:38:31 by alambert          #+#    #+#             */
/*   Updated: 2022/02/09 14:36:25 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*strd;
	const char	*strs;

	strd = (char *)dst;
	strs = (const char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n--)
		*strd++ = *strs++;
	return (dst);
}
