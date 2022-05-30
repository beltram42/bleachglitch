/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:27:25 by alambert          #+#    #+#             */
/*   Updated: 2022/05/25 16:27:56 by alambert         ###   ########.fr       */
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

void	ft_landmark(void *id[2])
{
	int		x;
	int		y;
	
	x = 100;
	y = 99
	while (y++ <= 1000)
		mlx_pixel_put(id[0], id[1], x, y, 0x0009ae51);
	y =99;
	while (y++ <= 1000)
		if (y == (y / 100) *100)
		{
			mlx_pixel_put(id[0], id[1], x - 1, y, 0x0009ae51);
			mlx_pixel_put(id[0], id[1], x + 1, y, 0x0009ae51);
		}
	x = 99, y = 1000;
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

int	main(void)
{
	void	*id[2];
	int		x, y;

	id[0] = mlx_init();
	id[1] = mlx_new_window(id[0], 360, 640, "square room");
	ft_landmark(id);

	mlx_loop(id[0]); // mandatory loop to keep window open
}

/*	TO COMPILE
	MacOS
	gcc -framework OpenGL -framework AppKit -lmlx filename.c
	Linux
	gcc -L./minilibx-linux -lmlx -lXext -lX11 filename.c
*/
