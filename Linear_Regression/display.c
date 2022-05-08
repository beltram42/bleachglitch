/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:26:54 by alambert          #+#    #+#             */
/*   Updated: 2022/05/08 21:30:27 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <unistd.h>
#include <stdio.h>

void	ft_landmark(void *id[2])
{
	int		x = 100, y = 99;
	while (y++ <= 1000)
		mlx_pixel_put(id[0], id[1], x, y, 0x00ffffff); // function to light on a pixel in the window; parameters: init ID, window ID, cordinates, pixel colour 
	y =99;
	while (y++ <= 1000)
		if (y == (y / 100) *100)
		{
			mlx_pixel_put(id[0], id[1], x - 1, y, 0x00ffffff);
			mlx_pixel_put(id[0], id[1], x + 1, y, 0x00ffffff);
		}
	x = 99, y = 1000;
	while (x++ <= 2500)
		mlx_pixel_put(id[0], id[1], x, y, 0x00ffffff);
	x = 99;
	while (x++ <= 2500)
	{
		if ((x - 100) == ((x - 100) / 200) * 200)
		{
			mlx_pixel_put(id[0], id[1], x, y - 1, 0x00ffffff);
			mlx_pixel_put(id[0], id[1], x, y + 1, 0x00ffffff);
		}
	}
}

void	ft_dots_trace(void *id[2])
{
	
}

int	main(void)
{
	int fd;
	int	var[2][24];
	void	*id[2]; // ID pointers array, so we can pass them through mlx_key_hook parameters

	fd = open("data.csv", O_RDONLY);
	
	id[0] = mlx_init();
	id[1] = mlx_new_window(id[0], 2600, 1100, "Linear_Regression_1"); // takes parameters: mlx_init ID, window width and height, window title
	ft_landmark(id);
	//mlx_key_hook(id[1], ft_key, id); // listener set, before to lauch the loop
	mlx_loop(id[0]); // mandatory loop to keep window open
}
