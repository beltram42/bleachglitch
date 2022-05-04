/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_estimate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:01:05 by lbenatta          #+#    #+#             */
/*   Updated: 2022/05/03 17:31:08 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	ft_atoi(const char *str);

int	get_estimated_price(int mileage, float theta0, float theta1)
{
	int est_price;

	if (!mileage)
		return (0);
	est_price = (theta1 * mileage) + theta0;
	return(est_price);
}

int main(int argc, char *argv[])
{
	int	i;
	int	est_price;
	float	t0;
	float	t1;

	if (argc = 0)
	{
		printf("one arg pls");
		return (0);
	}
	if (argc = 1)
		{
			i = ft_atoi(argv[1]);
			printf("mileage = %d\n", i);
		}
	t0 = 8498.679688;
	t1 = -0.021448;
	printf("t0 = %f, t1 = %f\n", t0, t1);
	est_price = get_estimated_price(i, t0, t1);
	printf("est_price = %d\n", est_price);
}
