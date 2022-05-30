/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regression_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:09:09 by anthonylamb       #+#    #+#             */
/*   Updated: 2022/05/30 14:14:59 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lr.h"

void	ft_grad_dsc(float fdb[2][24], float fv[5], long lv[19])
{
	int	i;

	lv[dtt0] = 0;
	lv[dtt1] = 0;
	lv[cost1] = 0;
	i = 0;
	while (i < lv[num_data])
	{
		lv[cost1] += (long)((lv[tt0] * fdb[k][i] + lv[tt1]) 
				- fdb[p][i] * (lv[tt0] * fdb[k][i] + lv[tt1]) 
				- fdb[p][i]) / (2 * lv[num_data]);
		lv[dtt1] += (long)((lv[tt0] * fdb[k][i] + lv[tt1])
				- fdb[p][i]) / lv[num_data];
		lv[dtt0] += (long)((lv[tt0] * fdb[k][i] + lv[tt1]) 
				- fdb[p][i]) * fdb[k][i] / lv[num_data];
		i++;
	}
	lv[tt0] = lv[tt0] - (long)(fv[learning_rate] * lv[dtt0]);
	lv[tt1] = lv[tt1] - (long)(fv[learning_rate] * lv[dtt1]);
}

void	ft_regr(float fdb[2][24], float fv[5], long lv[19], long ldb[6][24])
{
	//static long double *cost; // ??
	int	j;

	//free(cost); ??
	j = 0;
	//ldb[cost0] = malloc(sizeof(long double) * lv[iteration_cut]); // ??
	//cost[i++] = grad_dsc(fdb, fv, lv, lv); ?? cost[i++] ??
	//cost[i++] = grad_dsc(fdb, fv, lv, lv); ??
	while (j < lv[iteration_cut])
	{
		ft_grad_dsc(fdb, fv, lv, lv);
		lv[cost0] = lv[cost1];
		j++;
	}
}

void	ft_predict(float fdb[2][24], long lv[19])
{
	fdb[p][0] = (lv[tt0] * fdb[k] + lv[tt1]) * 10000;
}
