/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 23:08:48 by alambert          #+#    #+#             */
/*   Updated: 2022/05/08 18:54:55 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (s++, len < maxlen)
	{
		if (!*s)
			break;
		len++;
	}
	return (len);
}