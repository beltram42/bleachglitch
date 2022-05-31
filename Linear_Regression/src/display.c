/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:34:35 by alambert          #+#    #+#             */
/*   Updated: 2022/05/31 17:47:43 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lr.h"
#include "myenums.h"

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
	int		max[2];
	int		len;
	char	*s1;
	char	*s2;

	s1 = ft_itoa(lv[userkm]);
	len = strlen(s1);
	*(s1 + len) = ',';
	*(s1 + len +1) = ' ';
	*(s1 + len + 2) = '\0';
	s2 = ft_itoa(lv[userprice]);
	s1 = ft_strjoin(s1, s2);
	ft_bzero(iv, sizeof(int) * 4);
	ft_tr_userparam(id, iv, lv, max);
	mlx_string_put(id[0], id[1], max[x], iv[y1], 0x0009ae51, s1);
	s1 = ft)free(s1);
}
