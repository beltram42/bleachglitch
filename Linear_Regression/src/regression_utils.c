/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regression_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:09:09 by alambert          #+#    #+#             */
/*   Updated: 2022/06/06 18:37:25 by alambert         ###   ########.fr       */
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

void	ft_grad_dsc(float fdb[9][24], float fv[24])
{
	int	j;

	fv[dtt0] = 0.0;
	fv[dtt1] = 0.0;
	fv[costa] = 0.0;
	j = 0;
	while (j < 24)
	{
		fv[costa] += ((fv[tt0] * fdb[k][j] + fv[tt1]) \
				- fdb[p][j] * (fv[tt0] * fdb[k][j] + fv[tt1]) \
				- fdb[p][j]) / (2 * 24);
		fv[dtt1] += ((fv[tt0] * fdb[k][j] + fv[tt1]) \
				- fdb[p][j]) / 24;
		fv[dtt0] += ((fv[tt0] * fdb[k][j] + fv[tt1]) \
		- fdb[p][j]) * fdb[k][j] / 24;
		j++;
	}
	fv[tt0] = fv[tt0] - (fv[learning_rate] * fv[dtt0]);
	fv[tt1] = fv[tt1] - (fv[learning_rate] * fv[dtt1]);
	printf("fv[costa] = %e\n", fv[costa]);
	printf("fv[dtt0] = %e\n", fv[dtt0]);
	printf("fv[dtt1] = %e\n", fv[dtt1]);
	printf("fv[tt0] = %e\n", fv[tt0]);
	printf("fv[tt1] = %e\n", fv[tt1]);
}

void	ft_regr(float fdb[9][24], float fv[24])
{
	int		j;
	float	diff;

	j = 0;
	ft_grad_dsc(fdb, fv);
	fv[costd] = fv[costa];
	fv[costc] = fv[costd];
	ft_grad_dsc(fdb, fv);
	fv[costd] = fv[costa];
	fv[costb] = fv[costd];
	diff = ft_absf(fv[costb] - fv[costc]);
	printf("diff0 = %e", diff);
	while (diff > 0.000002)
	{
		ft_grad_dsc(fdb, fv);
		fv[costd] = fv[costa];
		if (j % 2 == 0)
			fv[costc] = fv[costd];
		if (j % 2 == 1)
			fv[costb] = fv[costd];
		diff = ft_absf(fv[costb] - fv[costc]);
		j++;
	}
	printf("diffn = %e\n", diff);
	printf("iteration# = %d\n", j);
}

void	ft_corr_rate(float fv[24], float fdb[9][24])
{
	float	fr[4];
	int		j;

	ft_bzero(fr, sizeof(float) * 4);
	j = 0;
	while (j < 24)
	{
		fr[l] += (fdb[km][j] - fv[meank]) * (fdb[price][j] - fv[meanp]);
		fr[m] += (fdb[km][j] - fv[meank]) * (fdb[km][j] - fv[meank]);
		fr[n] += (fdb[price][j] - fv[meanp]) * (fdb[price][j] - fv[meanp]);
	}
	fr[o] = sqrtf(fr[m] * fr[n]);
	fv[r] = fr[l] / fr[o];
}