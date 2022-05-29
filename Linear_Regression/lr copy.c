/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:35:14 by alambert          #+#    #+#             */
/*   Updated: 2022/05/29 20:57:31 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lr.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/stat.h>


/*
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
*/

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
*/

enum	e_ldb
{
	km,
	price,
	sqkm,
	sqprice,
	sqxmgap,
	sqymgap
};
enum	e_lvar
{
	i,
	iteration_cut,
	num_data,
	sumkm,
	sumprice,
	sumprod,
	sumsqkm,
	sumsqprice,
	userkm,
	userprice,
	cost0,
	cost1,
	final_b,
	dtempt0,
	dtempt1,
	t0,
	t1,
	tempt0,
	tempt1
};
enum	e_fdb
{
	k,
	p
};
enum	e_fvar
{
	k_predict,
	learning_rate,
	meank,
	meanp,
	r
};

int	main(void)
{
	long		ldb[7][24];
	long		lv[19];
	float		fdb[2][24];
	float		fv[5];

	ft_bzero(ldb, sizeof(long) * 7 * 24);
	ft_bzero(lv, sizeof(long) * 19);
	ft_bzero(fdb, sizeof(float) * 2 * 24);
	ft_bzero(fv, sizeof(float) * 5);
	ft_getdata(ldb);
	ft_dataset(fdb, fv, ldb, lv);
	ft_regr(fdb, fv, lv, ldb);
	lv[final_b] = lv[tt1] * 10000;
	fv[k_predict] = 10.0;
	ft_predict(fdb, lv);
	ft_userprice(long lv[19])
	//ft_display(d)
	return (0);
}
