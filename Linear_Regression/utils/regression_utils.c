/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regression_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:09:09 by anthonylamb       #+#    #+#             */
/*   Updated: 2022/05/28 19:22:50 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum ldb { km, price, sqkm, sqprice, sqxmgap, sqymgap};
enum lvar { kmsum, pricesum, counter, sqkmsum, sqpricesum, prodsum};
enum fdb { k, p};
enum fvar { meank, meanp, t0, t1, r};

long double grad_desc(float k[], float p[], int num_data, float learning_rate, long double *tempt0, long double *tempt1)
{
	long double dtempt1 = 0.0;
	long double dtempt0 = 0.0;
	long double cost = 0.0;
	int count = 0;

	while (count < num_data)
	{
		cost += ((*tempt0 * k[count] + *tempt1) - p[count] * (*tempt0 * k[count] + *tempt1) - p[count]) / (2 * num_data);
		dtempt1 += ((*tempt0 * k[count] + *tempt1) - p[count]) / num_data;
		dtempt0 += ((*tempt0 * k[count] + *tempt1) - p[count]) * k[count] / num_data;
		count++;
	}
	*tempt0 = *tempt0 - (learning_rate * dtempt0);
	*tempt1 = *tempt1 - (learning_rate * dtempt1);
	return (cost);
}

long double *regression(float k[], float p[], int num_data, float learning_rate, int max_num_iterations, long double *tempt0, long double *tempt1)
{
	static long double *cost;
	free(cost);
	cost = (long double *)malloc(sizeof(long double) * max_num_iterations);
	int		count = 0;
	cost[count++] = batch_gradient_descent(k, p, num_data, learning_rate, tempt0, tempt1);
	cost[count++] = batch_gradient_descent(k, p, num_data, learning_rate, tempt0, tempt1);
    while (count < max_num_iterations)
	{
	    cost[count++] = batch_gradient_descent(k, p, num_data, learning_rate, tempt0, tempt1);
	}
	return (cost);
}

float predict(float k, long double tempt0, long double tempt1)
{
	float p = (tempt0 * k + tempt1) * 10000;
	return (p);
}
