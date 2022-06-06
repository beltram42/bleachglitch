/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regression_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:09:09 by alambert          #+#    #+#             */
/*   Updated: 2022/06/06 08:32:09 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lr.h"
#include "../myenums.h"

enum e_fr
{
	l,
	m,
	n,
	o
};

void	ft_grad_dsc(float fdb[2][24], float fv[16], long lv[6])
{
	int	j;

	fv[dtt0] = 0;
	fv[dtt1] = 0;
	fv[costa] = 0;
	j = 0;
	while (j < lv[num_data])
	{
		fv[costa] += ((fv[tt0] * fdb[k][j] + fv[tt1]) \
				- fdb[p][j] * (fv[tt0] * fdb[k][j] + fv[tt1]) \
				- fdb[p][j]) / (2 * 24);
		fv[dtt1] += ((fv[tt0] * fdb[k][j] + fv[tt1]) \
				- fdb[p][j]) / 24;
		fv[dtt0] += ((fv[tt0] * fdb[k][j] + fv[tt1]) \
		- (fdb[p][j]) * ((fdb[k][j])) / 24);
		j++;
	}
	fv[tt0] = fv[tt0] - (fv[learning_rate] * fv[dtt0]);
	fv[tt1] = fv[tt1] - (fv[learning_rate] * fv[dtt1]);
}

void	ft_regr(float fdb[2][24], float fv[16], long lv[6], long ldb[7][24])
{
	int	j;

	fv[costb] = 0;
	fv[costc] = 0;
	j = 0;
	while (ft_absf(fv[costb] - fv[costc]) > 0.0000001)
	{
		ft_grad_dsc(fdb, fv, lv);
		fv[costd] = fv[costa];
		if (j % 2 == 0)
			fv[costc] = fv[costd];
		if (j % 2 == 1)
			fv[costb] = fv[costd];
		j++;
	}
	printf("iteration# = %d", j);
}

void	ft_corr_rate(float fv[16], long ldb[7][24], long lv[6])
{
	float	fr[4];
	int		j;

	ft_bzero(fr, sizeof(float) * 4);
	j = 0;
	while (j < 24)
	{
		fr[l] += (ldb[km][j] - fv[meank]) * (ldb[price][j] - fv[meanp]);
		fr[m] += (ldb[km][j] - fv[meank]) * (ldb[km][j] - fv[meank]);
		fr[n] += (ldb[price][j] - fv[meanp]) * (ldb[price][j] - fv[meanp]);
	}
	fr[o] = sqrtf(fr[m] * fr[n]);
	fv[r] = fr[l] / fr[o];
}