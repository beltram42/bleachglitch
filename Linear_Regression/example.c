/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:27:25 by alambert          #+#    #+#             */
/*   Updated: 2022/05/08 16:59:03 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_key(int key, void *id[2])
{
	int	x, y;

	ft_putchar('X'); // X print in shell window, to make sure the listener works
	y = 80;
	while (y <= 280)
	{
		x = 80;
		while (x <= 280)
		{
			mlx_pixel_put(id[0], id[1], x, y, 0x00000000);
			x++;
		}
		y++;
	}
	return 0;
}

int	main(void)
{
	void	*id[2]; // ID pointers array, so we can pass them through mlx_key_hook parameters
	int		x, y;

	id[0] = mlx_init();
	id[1] = mlx_new_window(id[0], 360, 640, "square room"); // takes parameters: mlx_init ID, window width and height, window title
	y = 60;
	while (y <= 300)
	{
		x = 60;
		while (x <= 300)
		{
			mlx_pixel_put(id[0], id[1], x, y, 0x00ffffff); // function to light on a pixel in the window; parameters: init ID, window ID, cordinates, pixel colour 
			x++;
		}
		y++;
	}
	mlx_key_hook(id[1], ft_key, id); // listener set, before to lauch the loop
	mlx_loop(id[0]); // mandatory loop to keep window open
}

/*	TO COMPILE
	MacOS
	gcc -framework OpenGL -framework AppKit -lmlx filename.c
	Linux
	gcc -L./minilibx-linux -lmlx -lXext -lX11 filename.c
*/
