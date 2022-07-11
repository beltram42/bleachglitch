/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_spn_fb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:25:22 by alambert          #+#    #+#             */
/*   Updated: 2022/07/11 17:47:41 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_spn_fb(const char *str, const char *set, int gear)
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
	returns the length of the sub string which:
 	. begins at *str or, if gear = -1, at *str + strlen - 1
	. contains only characters from set
 	. stops when the first occurrence of a character not contained in *set is found
	function equals to strlen if gear = 1 and set = "" 
 */
