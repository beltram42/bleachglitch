/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:35:14 by alambert          #+#    #+#             */
/*   Updated: 2022/05/29 21:08:22 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lr.h"

int	main(void)
{
	long		ldb[7][24];
	long		lv[19];
	float		fdb[2][24];
	float		fv[5];

	ft_setzero(fdb, fv, ldb, lv);
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
