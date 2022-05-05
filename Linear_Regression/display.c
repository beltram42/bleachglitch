/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:26:54 by alambert          #+#    #+#             */
/*   Updated: 2022/05/05 15:21:10 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	void	*id[2]; // ID pointers array, so we can pass them through mlx_key_hook parameters
	int		x, y, a;

	id[0] = mlx_init();
	id[1] = mlx_new_window(id[0], 2440, 940, "Linear_Regression_1"); // takes parameters: mlx_init ID, window width and height, window title
	x = 20;
	y = 19;
	while (y++ <= 920)
		mlx_pixel_put(id[0], id[1], x, y, 0x00ffffff); // function to light on a pixel in the window; parameters: init ID, window ID, cordinates, pixel colour 
	y =20;
	while (y++ <= 920)
		if (y == (y / 100) *100)
		{
			mlx_pixel_put(id[0], id[1], x - 1, y, 0x00ffffff);
			mlx_pixel_put(id[0], id[1], x + 1, y, 0x00ffffff);
		}
	x = 19;
	y = 920;
	while (x++ <= 2420)
		mlx_pixel_put(id[0], id[1], x, y, 0x00ffffff);
	x = 20;
	while (x++ <= 2401)
	{
		if (x == (x / 1000) * 1000)
		{
			a = 0;
			while (a <= 10)
				mlx_pixel_put(id[0], id[1], x, y - 5 + a, 0x00ffffff);
		}
	}
	//mlx_key_hook(id[1], ft_key, id); // listener set, before to lauch the loop
	mlx_loop(id[0]); // mandatory loop to keep window open
}
