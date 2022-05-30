/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_define.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:25:59 by alambert          #+#    #+#             */
/*   Updated: 2022/05/30 16:52:34 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define PI 3.1415
#define circleArea(r) (PI*r*r)

int	main(void)
{
	float	radius;
	float	area;

	printf("Enter the radius: ");
	scanf("%f", &radius);
	area = circleArea(radius);
	printf("Area = %.2f\n", area);
	return (0);
}