/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:35:14 by alambert          #+#    #+#             */
/*   Updated: 2022/05/31 11:23:44 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lr.h"
#include "myenums.h"

int	main(void)
{
	long		ldb[6][24];
	long		lv[19];
	float		fdb[2][24];
	float		fv[5];
	void		*id[2];

	ft_setzero(fdb, fv, ldb, lv);
	ft_getdata(ldb);
	ft_dataset(fdb, fv, ldb, lv);
	ft_regr(fdb, fv, lv, ldb);
	lv[final_b] = lv[tt1] * 10000;
	fv[k_predict] = 10.0;
	ft_predict(fdb, lv);
	id[0] = mlx_init();
	id[1] = mlx_new_window(id[0], 1200, 1100, "LR_chart");
	ft_display0(id, ldb, lv);
	ft_userprice(long lv[19]);
	ft_display1(id, ldb, lv);
	mlx_key_hook(id[1], ft_key, id);
	mlx_loop(id[0]);
	ft_exit();
	return (0);
}
