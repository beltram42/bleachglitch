/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corr_rate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:09:48 by alambert          #+#    #+#             */
/*   Updated: 2022/06/01 17:00:25 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lr.h"
#include "../myenums.h"

enum e_fr
{
	k,
	l,
	m,
	n
};

void	ft_corr_rate(float fv[5], long ldb[6][24], long lv[19])
{
	float	fr[4];
	int		j;

	ft_bzero(fr, sizeof(float) * 4);
	j = 0;
	while (j < 24)
	{
		fr[k] += (ldb[km][j] - fv[meank]) * (ldb[price][j] - fv[meanp]);
		fr[l] += (ldb[km][j] - fv[meank]) * (ldb[km][j] - fv[meank]);
		fr[m] += (ldb[price][j] - fv[meanp]) * (ldb[price][j] - fv[meanp]);
	}
	fr[n] = sqrtf(fr[l] * fr[m]);
	fv[r] = fr[k] / fr[n];
}
