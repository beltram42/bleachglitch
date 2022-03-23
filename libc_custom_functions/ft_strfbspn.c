/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfbspn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:25:22 by alambert          #+#    #+#             */
/*   Updated: 2022/02/21 16:25:44 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*
 forward (gear = 1) or backward (gear = -1) span
 returns the length of the sub string that:
 . begins at *str or, if gear = -1, at *str + strlen - 1
 . stops when the first occurrence of a character contained in *set is found
 */
