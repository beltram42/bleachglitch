/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:34:35 by alambert          #+#    #+#             */
/*   Updated: 2022/05/30 19:54:41 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
