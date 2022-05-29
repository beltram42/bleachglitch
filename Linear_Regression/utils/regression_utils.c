/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regression_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:09:09 by anthonylamb       #+#    #+#             */
/*   Updated: 2022/05/29 19:06:03 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum	e_ldb
{
	cost0,
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
	umprice,
	sumprod,
	sumsqkm,
	sumsqprice,
	userkm,
	userprice
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

void	grad_dsc(float fdb[2], float fv[5], long lv[18])
{
	int	i;

	lv[dtt0] = 0;
	lv[dtt1] = 0;
	lv[cost1] = 0;
	i = 0;
	while (i < lv[num_data])
	{
		lv[cost1] += ((lv[tt0] * fdb[k][i] + lv[tt1]) 
				- fdb[p][i] * (lv[tt0] * fdb[k][i] + lv[tt1]) 
				- fdb[p][i]) / (2 * lv[num_data]);
		lv[dtt1] += ((lv[tt0] * fdb[k][i] + lv[tt1])
				- fdb[p][i]) / lv[num_data];
		lv[dtt0] += ((lv[tt0] * fdb[k][i] + lv[tt1]) 
				- fdb[p][i]) * fdb[k][i] / lv[num_data];
		i++;
	}
	lv[tt0] = lv[tt0] - (fv[learning_rate] * lv[dtt0]);
	lv[tt1] = lv[tt1] - (fv[learning_rate] * lv[dtt1]);
}

void	ft_regr(float fdb[2], float fv[5], long lv[18], long ldb[7])
{
	//static long double *cost; // ??
	int	i;

	//free(cost); ??
	i = 0;
	//ldb[cost0] = malloc(sizeof(long double) * lv[iteration_cut]); // ??
	//cost[i++] = grad_dsc(fdb, fv, lv, lv); ?? cost[i++] ??
	//cost[i++] = grad_dsc(fdb, fv, lv, lv); ??
	while (i < lv[iteration_cut])
	{
		grad_dsc(fdb, fv, lv, lv);
		ldb[cost0][i] = lv[cost1];
	}
}

void predict(float fdb[2], long lv[18])
{
	fdb[p][0] = (lv[tt0] * fdb[k] + lv[tt1]) * 10000;
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
