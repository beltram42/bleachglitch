/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:24:41 by alambert          #+#    #+#             */
/*   Updated: 2022/07/11 11:22:27 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long double	ft_absld(long double i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

double	ft_absd(double i)
{
	return ((double)ft_absld(i));
}

float	ft_absf(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}
