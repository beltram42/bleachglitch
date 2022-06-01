/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:59:44 by anthonylamb       #+#    #+#             */
/*   Updated: 2022/06/01 14:38:54 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lr.h"
#include "../myenums.h"

enum e_ivar
{
	x0,
	y0,
	x1,
	y1
};

enum e_imax
{
	x,
	y,
};

void	ft_originfix(int iv[4])
{
	iv[x1] = iv[x0] + 100;
	iv[y1] = 1000 - iv[y0];
}

void	ft_tr_landmark(void *id[2], int iv[4])
{
	ft_bzero(iv, sizeof(int) * 4);
	while (iv[y0] <= 900)
	{
		ft_originfix(iv);
		mlx_pixel_put(id[0], id[1], iv[x1], iv[y1], 0x0009ae51);
		if (iv[y0] > 0 && iv[y1] == (iv[y1] / 100) * 100)
		{
			mlx_pixel_put(id[0], id[1], iv[x1] - 1, iv[y1], 0x0009ae51);
			mlx_pixel_put(id[0], id[1], iv[x1] + 1, iv[y1], 0x0009ae51);
		}
		iv[y0] += 1;
	}
	ft_bzero(iv, sizeof(int) * 4);
	while (iv[x0] <= 1000)
	{
		ft_originfix(iv);
		mlx_pixel_put(id[0], id[1], iv[x1], iv[y1], 0x0009ae51);
		if (iv[x0] > 0 && iv[x1] == (iv[x1] / 100) * 100)
		{
			mlx_pixel_put(id[0], id[1], iv[x1], iv[y1] - 1, 0x0009ae51);
			mlx_pixel_put(id[0], id[1], iv[x1], iv[y1] + 1, 0x0009ae51);
		}
		iv[x0] += 1;
	}
}

void	ft_tr_dots(void *id[2], long ldb[6][24], long lv[19], int iv[4])
{
	int	j;
	int	d;

	j = 0;
	while (j < 24)
	{
		iv[x0] = (int)(ldb[km][j] / 400);
		iv[y0] = (int)(ldb[price][j] / 10);
		ft_originfix(iv);
		d = -1;
		while (d <= 1)
		{
			mlx_pixel_put(id[0], id[1], iv[x1] + d, iv[y1], 0x0009ae51);
			mlx_pixel_put(id[0], id[1], iv[x1], iv[y1] + d, 0x0009ae51);
			d++;
		}
		j++;
	}
}

void	ft_tr_line(void *id[2], int iv[4], long lv[19])
{
	ft_bzero(iv, sizeof(int) * 4);
	while (iv[y0] >= 0)
	{
		iv[y0] = (int)(lv[t0] + (lv[t1] * iv[x0]));
		ft_originfix(iv);
		mlx_pixel_put(id[0], id[1], iv[x1], iv[y1], 0x0009ae51);
		iv[x0] += 1;
	}
}

void	ft_tr_userparam(void *id[2], int iv[4], long lv[19], int max[2])
{
	iv[x0] = lv[userkm] / 400;
	iv[y0] = lv[userprice] / 10;
	ft_originfix(iv);
	max[x] = iv[x1];
	max[y] = iv[y1];
	ft_bzero(iv, sizeof(int) * 4);
	ft_originfix(iv);
	while (iv[x1] <= max[x] && iv[y1] <= max[y])
	{
		ft_originfix(iv);
		while (iv[x1] <= max[x])
		{
			if ((iv[x1] % 2) == 1)
				mlx_pixel_put(id[0], id[1], iv[x1], max[y], 0x0009ae51);
			iv[x0] += 1;
		}
		while (iv[y1] <= y)
		{
			if ((y % 2) == 1)
				mlx_pixel_put(id[0], id[1], max[x], iv[y1], 0x0009ae51);
			iv[y0] += 1;
		}
	}
}
