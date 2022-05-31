/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:34:35 by alambert          #+#    #+#             */
/*   Updated: 2022/05/31 12:23:20 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lr.h"

void_ft_exit(void)
{
	int	temp;

	temp = mlx_clear_window();
	temp = mlx_destroy_window();
	temp = mlx_destroy_display();
}

void	ft_leave(void)
{}

void	ft_display0(void *id[2], long ldb[6][24], long lv[19])
{
	int		iv[4];

	ft_bzero(iv, sizeof(int) * 4);
	ft_landmark(id, iv);
	ft_dots(id, ldb, lv, iv);
	ft_trline(id, iv, lv);
}

void	ft_display1(void *id[2], long ldb[6][24], long lv[19])
{
	int		iv[4];

	ft_bzero(iv, sizeof(int) * 4);
	ft_spotuserparam(id, iv, lv);
}
