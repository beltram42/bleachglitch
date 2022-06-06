/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:48:14 by alambert          #+#    #+#             */
/*   Updated: 2022/06/06 08:32:00 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lr.h"
#include "../myenums.h"

int	ft_up_shell(long lv[6])
{
	ft_userprice(lv);
	return (0);
}

void	ft_userprice(long lv[6])
{
	char	*str;
	char	*endptr;

	printf("please enter #km from 0 to 397134:\n");
	str = ft_malgets(6);
	endptr = str;
	fv[userkm] = ft_strtol(str, &endptr, 10);
	if (endptr == str || fv[userkm] > 397134)
	{
		printf("#km should be less than 397134\n");
		fv[userkm] = 397135;
		str = ft_free(&str);
		fv[userprice] = 0;
		printf("car price for more than 397134km is: 0\n");
		return ;
	}
	else
	{
		printf("#km is in the range\n");
		str = ft_free(&str);
		fv[userprice] = fv[t0] + (fv[t1] * fv[userkm]);
		printf("car price for %ld km is: %ld\n", (long)fv[userkm], (long)fv[userprice]);
	}
}
