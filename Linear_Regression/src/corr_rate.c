/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corr_rate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:09:48 by alambert          #+#    #+#             */
/*   Updated: 2022/06/04 16:19:41 by alambert         ###   ########.fr       */
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

void	ft_corr_rate(float fv[5], long ldb[6][24], long lv[19])
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
