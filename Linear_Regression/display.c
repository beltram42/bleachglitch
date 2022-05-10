/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:26:54 by alambert          #+#    #+#             */
/*   Updated: 2022/05/10 15:30:41 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lr.h"

void	ft_landmark(void *id[2])
{
	int		x = 100, y = 99;
	while (y++ <= 1000)
		mlx_pixel_put(id[0], id[1], x, y, 0x0009ae51); // function to light on a pixel in the window; parameters: init ID, window ID, cordinates, pixel colour 
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

void	ft_dotstrace(void *id[2])
{
	int	f;
	char	*str;
	char	**strs;
	int	i;
	t_tab *tab; 

	f = open("data.csv", O_RDONLY);
	i = 0;
	tab = (t_tab *)malloc(sizeof(t_tab));
	str = get_next_line(f);
	while (str != NULL)
	{
		strs = ft_split(str, ',');
		tab->km[i] = ft_atoi(strs[0]);
		tab->price[i] = ft_atoi(strs[1]);
		i++;
		str = get_next_line(f);
	}
	tab->count = i;
	i = 0;
	while (i < tab->count)
	{
		printf("%i / %i\n", tab->km[i], tab->price[i]);
		i++;
	}
    i = 0;
	tab->theta0 = 0;
	tab->theta1 = 0;
	tab->sum_price = 0;
	tab->mean_price = 0;
	tab->sum_km = 0;
	tab->mean_km = 0;
	tab->sum_sqr_price = 0;
	tab->sum_sqr_km = 0;
	for(i = 0; i < tab->count; i++)
	{
		tab->sum_km = tab->sum_km + tab->km[i];
		tab->mean_km = tab->sum_km / tab->count;
		tab->sum_price = tab->sum_price + tab->price[i];
		tab->mean_price = tab->sum_price / tab->count;
		tab->sqr_km[i] = (long)tab->km[i] * (long)tab->km[i];
		tab->sqr_price[i] = tab->price[i] * tab->price[i];
		tab->sum_sqr_km = (long)tab->sum_sqr_km + (long)tab->sqr_km[i];
		tab->sum_sqr_price = tab->sum_sqr_price + tab->sqr_price[i];
		tab->pdt[i] = (long)tab->km[i] * (long)tab->price[i];
		tab->sum_pdt = tab->sum_pdt + tab->pdt[i];
    }
	tab->theta1 = ((tab->mean_km * tab->sum_price) - (tab->sum_pdt)) / ((tab->mean_km * tab->sum_km) - (tab->sum_sqr_km));
	tab->theta0 = (tab->mean_price - (tab->theta1 * tab->mean_km));

	printf("sum_km : %d\n", tab->sum_km);
	printf("sum_price : %d\n", tab->sum_price);
	printf("mean_km : %f\n", tab->mean_km);
	printf("mean_price : %f\n", tab->mean_price);
	printf("sum_sqr_km : %ld\n", tab->sum_sqr_km);
	printf("sum_sqr_price : %ld\n", tab->sum_sqr_price);
	printf("sum_pdt : %ld\n", tab->sum_pdt);
	printf("theta1 = %f\n", tab->theta1);
	printf("theta0 = %f\n", tab->theta0);
/*
	i = tab->count;
	while (i > 0)
	{
		mlx_pixel_put(id[0], id[1], tab->km[i], tab->price[i], 0x00FFCCD9);
		mlx_pixel_put(id[0], id[1], tab->km[i] - 1, tab->price[i], 0x00FFCCD9);
		mlx_pixel_put(id[0], id[1], tab->km[i] + 1, tab->price[i], 0x00FFCCD9);
		mlx_pixel_put(id[0], id[1], tab->km[i], tab->price[i] - 1, 0x00FFCCD9);
		mlx_pixel_put(id[0], id[1], tab->km[i], tab->price[i] + 1, 0x00FFCCD9);
		i--;
	}*/
}

int	main(void)
{
	int fd;
	int	var[2][24];
	void	*id[2]; // ID pointers array, so we can pass them through mlx_key_hook parameters

	fd = open("data.csv", O_RDONLY);
	/*
	id[0] = mlx_init();
	id[1] = mlx_new_window(id[0], 2600, 1100, "Linear_Regression_1"); // takes parameters: mlx_init ID, window width and height, window title
	*/
	ft_landmark(id);
	ft_dotstrace(id);
	//mlx_key_hook(id[1], ft_key, id); // listener set, before to lauch the loop
	mlx_loop(id[0]); // mandatory loop to keep window open
}
