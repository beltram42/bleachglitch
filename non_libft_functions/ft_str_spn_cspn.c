/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_spn_cspn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:51:11 by alambert          #+#    #+#             */
/*   Updated: 2022/07/11 17:48:17 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_str_spn_cspn(const char *str, const char *set, int gear)
{
	const char	*p;
	const char	*s;

	p = str;
	while (*p)
	{
		s = set;
		s = ft_strchr(s, *p);
		if (s == 0 && gear == 1)
			break ;
		if (s != 0 && gear == -1)
			break ;
		else
			p++;
	}
	return (p - str);
}

/*
Multi purpose span+len function:
	strspn : gear = 1 returns length of the first substr not containing any set characters
	strcspn : gear = -1 returns length of the first substr containing only set characters
	strlen : set = ""
*/
