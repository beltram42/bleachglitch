/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:48:14 by alambert          #+#    #+#             */
/*   Updated: 2022/06/05 18:48:26 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lr.h"
#include "../myenums.h"

int	ft_up_shell(long lv[12])
{
	ft_userprice(lv);
	return (0);
}

void	ft_userprice(long lv[12])
{
	char	*str;
	char	*endptr;

	printf("please enter #km from 0 to 397134:\n");
	str = ft_malgets(6);
	endptr = str;
	lv[userkm] = ft_strtol(str, &endptr, 10);
	if (endptr == str || lv[userkm] > 397134)
	{
		printf("#km should be less than 397134\n");
		lv[userkm] = 397135;
		str = ft_free(&str);
		lv[userprice] = 0;
		printf("car price for more than 397134km is: 0\n");
		return ;
	}
	else
	{
		printf("#km is in the range\n");
		str = ft_free(&str);
		lv[userprice] = lv[theta0] + (lv[theta1] * lv[userkm]);
		printf("car price for %ld km is: %ld\n", lv[userkm], lv[userprice]);
	}
}
