/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_regression_train.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:36:26 by lbenatta          #+#    #+#             */
/*   Updated: 2022/05/25 18:44:47 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

long double batch_gradient_descent(float k[], float p[], int num_data, float learning_rate, long double *tempt0, long double *tempt1)
{
	long double dtempt1 = 0.0; // derivative of cost func with respect to bias = temp theta1
	long double dtempt0 = 0.0; // derivative of cost func with respect to weights == temp theta0
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
	//float	min;
	cost[count++] = batch_gradient_descent(k, p, num_data, learning_rate, tempt0, tempt1);
	cost[count++] = batch_gradient_descent(k, p, num_data, learning_rate, tempt0, tempt1);
    //cost[count++] = batch_gradient_descent(k, p, num_data, learning_rate, w, b);
	//while (cost[count] > min) //&& count < max_num_iterations)
    while (count < max_num_iterations)
	//while (((cost[count - 1] - cost[count - 2]) < 0.0000001) && (count < max_num_iterations)) // version : tant que pente n'est pas proche de zero on continue;
	//while (((cost[count - 1] < cost[count - 2])) && (count < max_num_iterations))
	//while (((cost[count - 1] - cost[count - 2]) / (cost[count - 2]) > 0.0000001) && (count < max_num_iterations))
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

int main()
{
	int f;
	char *str;
	char **strs;
	int i;
	t_tab *tab;
	
    f = open("data.csv", O_RDONLY);

	i = 0;
	tab = (t_tab*)malloc(sizeof(t_tab));
	free(str);
	str = get_next_line(f);
	while (str != NULL)
	{
		strs = ft_split(str, ',');
		tab->km[i] = ft_atoi(strs[0]);
		tab->price[i] = ft_atoi(strs[1]);
       	tab->k[i] = (float)tab->km[i] / 10000.0;
		tab->p[i] = (float)tab->price[i] / 10000.0;
		i++;
		str = get_next_line(f);
	}
	/*
	tab->count = i;
	i = 1;
	while(i < tab->count)
    {
		printf("%f / %f\n", tab->k[i], tab->p[i]);
		i++;
	}*/
	float learning_rate = 0.0001;
	int max_num_iterations = 27500; // > 2
	printf("\nlearning_rate :: %f num_it :: %d\n\n", learning_rate, max_num_iterations);

	long double theta0 = 0.0;
	long double theta1 = 0.0;
	long double tempt0 = 0.0;
	long double tempt1 = 0.0;
	printf("Inital Value Of w %Lf \n", theta0);
	printf("Initial Value Of b %Lf \n", theta1);

	int 	num_data = 24;
	long double *cost = regression(tab->k, tab->p, num_data, learning_rate, max_num_iterations, &tempt0, &tempt1);
	long double final_b =  tempt1 * 10000.0;
	printf("Final Value Of theta0 %Lf \n", tempt0);
    printf("Final Value Of theta1 %Lf \n \n", final_b);

	float k_predict = 10.0;
	printf("Predicted Value For %f is %f \n", k_predict, predict(k_predict, tempt0, tempt1));
	printf("Final Cost: %Lf\n", cost[max_num_iterations - 1]);
	//printf("Final Cost: %Lf\n", cost[max_num_iterations]);
	free(cost);
	free(tab);
	return(0);
}

