/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:59:44 by anthonylamb       #+#    #+#             */
/*   Updated: 2022/05/29 21:05:56 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lr.h"

void	ft_landmark(void *id[2])
{
	int		x;
	int		y;
	
	x = 100;
	y = 99;
	while (y++ <= 1000)
		mlx_pixel_put(id[0], id[1], x, y, 0x0009ae51);
	y = 99;
	while (y++ <= 1000)
		if (y == (y / 100) *100)
		{
			mlx_pixel_put(id[0], id[1], x - 1, y, 0x0009ae51);
			mlx_pixel_put(id[0], id[1], x + 1, y, 0x0009ae51);
		}
	x = 99;
	y = 1000;
	while (x++ <= 2500)
		mlx_pixel_put(id[0], id[1], x, y, 0x0009ae51);
	x = 99;
	while (x++ <= 2500)
	{
		if ((x - 100) == ((x - 100) / 200) * 200)
		{
			mlx_pixel_put(id[0], id[1], x, y - 1, 0x0009ae51);
			mlx_pixel_put(id[0], id[1], x, y + 1, 0x0009ae51);
		}
	}
}

/*
void	ft_display(long ldata[5][24])
{
	void	*id[2];
	int		x;
	int		y;

	id[0] = mlx_init();
	id[1] = mlx_new_window(id[0], 1200, 1100, "LR_display");
	ft_landmark(id);
}
