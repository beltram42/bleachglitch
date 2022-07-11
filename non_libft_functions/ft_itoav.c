/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoav.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:01:58 by alambert          #+#    #+#             */
/*   Updated: 2022/07/11 13:35:10 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_itoav(int i, char buf[12])
{
	char	*p;
	long	j;

	j = (long)i;
	p = buf + 11;
	*p = '\0';
	if (j == 0)
		*--p = '0';
	while (j != 0)
	{
		*--p = '0' + (ft_absl(j) % 10);
		j /= 10;
	}
	if (i < 0)
		*--p = '-';
}

/*a new void itoa with no malloc;
if needed, add p as a param as **p*/