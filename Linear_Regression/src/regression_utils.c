/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regression_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:09:09 by anthonylamb       #+#    #+#             */
/*   Updated: 2022/05/31 14:43:33 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lr.h"

void	ft_grad_dsc(float fdb[2][24], float fv[5], long lv[19])
{
	int	j;

	lv[dtt0] = 0;
	lv[dtt1] = 0;
	lv[cost1] = 0;
	j = 0;
	while (j < lv[num_data])
	{
		lv[cost1] += (long)((lv[tt0] * fdb[k][j] + lv[tt1])
				- fdb[p][j] * (lv[tt0] * fdb[k][j] + lv[tt1])
				- fdb[p][j]) / (2 * lv[num_data]);
		lv[dtt1] += (long)((lv[tt0] * fdb[k][j] + lv[tt1])
				- fdb[p][j]) / lv[num_data];
		lv[dtt0] += (long)((lv[tt0] * fdb[k][i] + lv[tt1])
				- fdb[p][j]) * fdb[k][i] / lv[num_data];
		j++;
	}
	lv[tt0] = lv[tt0] - (long)(fv[learning_rate] * lv[dtt0]);
	lv[tt1] = lv[tt1] - (long)(fv[learning_rate] * lv[dtt1]);
}

void	ft_regr(float fdb[2][24], float fv[5], long lv[19], long ldb[6][24])
{
	int	j;

	j = 0;
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
