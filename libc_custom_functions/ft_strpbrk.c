/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:53:00 by alambert          #+#    #+#             */
/*   Updated: 2022/05/08 18:33:33 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char  *ft_strpbrk(const char *str, const char *set)
{
	const char  *s;
	while (*str != '\0')
	{
		s = set;
		while (*s != '\0')
			if (*s++ == *str)
				return (char *)str;
		++str;
	}
	return 0;
}