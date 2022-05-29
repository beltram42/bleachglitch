/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regression_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:09:09 by anthonylamb       #+#    #+#             */
/*   Updated: 2022/05/29 20:36:42 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum	e_ldb
{
	km,
	price,
	sqkm,
	sqprice,
	sqxmgap,
	sqymgap
};
enum	e_lvar
{
	i,
	iteration_cut,
	num_data,
	sumkm,
	sumprice,
	sumprod,
	sumsqkm,
	sumsqprice,
	userkm,
	userprice
	cost0,
	cost1,
	final_b,
	dtempt0,
	dtempt1,
	t0,
	t1,
	tempt0,
	tempt1
};
enum	e_fdb
{
	k,
	p
};
enum	e_fvar
{
	k_predict,
	learning_rate,
	meank,
	meanp,
	r
};

void	ft_grad_dsc(float fdb[2], float fv[5], long lv[19])
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

void	ft_regr(float fdb[2][24], float fv[5], long lv[19], long ldb[7][24])
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
		ldb[cost0] = lv[cost1];
	}
}

void	ft_predict(float fdb[2], long lv[18])
{
	fdb[p][0] = (lv[tt0] * fdb[k] + lv[tt1]) * 10000;
}
