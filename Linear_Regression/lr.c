/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:35:14 by alambert          #+#    #+#             */
/*   Updated: 2022/06/06 12:12:48 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lr.h"
#include "myenums.h"

int	ft_exit(void *id[2])
{
	mlx_clear_window(id[0], id[1]);
	mlx_destroy_window(id[0], id[1]);
	mlx_destroy_display(id[0]);
	free(id[0]);
	free(id[1]);
	free(id);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(void)
{
	float		fdb[9][24];
	float		fv[24];
	void		*id[2];
	int			i;

	i = 0;
	ft_set0(fdb, fv);
	ft_getdata(fdb);
	ft_dset(fdb, fv);
	while (i < 24)
	{
		printf("fdb[km][%d] = %e\n", i, fdb[km][i]);
		printf("fdb[price]][%d] = %e\n", i, fdb[price][i]);
		printf("fdb[k][%d] = %e\n", i, fdb[k][i]);
		printf("fdb[p][%d] = %e\n", i, fdb[p][i]);
		printf("fdb[prod][%d] = %e\n", i, fdb[prod][i]);
		printf("fdb[sqkm][%d] = %e\n", i, fdb[sqkm][i]);
		printf("fdb[sqprice]][%d] = %e\n", i, fdb[sqprice][i]);
		printf("fdb[sqxmgap]][%d] = %e\n", i, fdb[sqxmgap][i]);
		printf("fdb[sqymgap]][%d] = %e\n", i, fdb[sqymgap][i]);
		printf("\n");
		i++;
	}
	printf("\n");
	printf("fv[iteration_cut] = %e\n", fv[iteration_cut]);
	printf("fv[sumkm] = %e\n", fv[sumkm]);
	printf("fv[sumprice] = %e\n", fv[sumprice]);
	printf("fv[sumprod] = %e\n", fv[sumprod]);
	printf("fv[sumsqkm] = %e\n", fv[sumsqkm]);
	printf("fv[sumsqprice] = %e\n", fv[sumsqprice]);
	printf("\n");
	fv[final_b] = fv[tt1] * 10000.0;
	fv[k_predict] = 10.0;
	printf("lf[k_predict] = %f\n", fv[k_predict]);
	printf("lf[learning_rate] = %f\n", fv[learning_rate]);
	printf("lf[meank] = %f\n", fv[meank]);
	printf("lf[meanp] = %f\n", fv[meanp]);
	printf("lf[t0] = %f\n", fv[t0]);
	printf("lf[t1] = %f\n", fv[t1]);
	printf("\n");
	ft_corr_rate(fv, fdb);
	printf("lf[r] = %f\n", fv[r]);
	printf("\n");
	ft_regr(fdb, fv);
	printf("lf[costa] = %f\n", fv[costa]);
	printf("lf[costb] = %f\n", fv[costb]);
	printf("lf[costc] = %f\n", fv[costc]);
	printf("lf[costd] = %f\n", fv[costd]);
	printf("lf[final_b] = %f\n", fv[final_b]);
	printf("lf[dtt0] = %f\n", fv[dtt0]);
	printf("lf[dtt1] = %f\n", fv[dtt1]);
	printf("lf[tt0] = %f\n", fv[tt0]);
	printf("lf[tt1] = %f\n", fv[tt1]);
	id[0] = mlx_init();
	id[1] = mlx_new_window(id[0], 1200, 1100, "LR_chart");
	ft_display0(id, fv, fdb);
	mlx_key_hook(id[1], ft_up_shell, fv);
	printf("lf[userkm] = %f\n", fv[userkm]);
	printf("lf[userprice] = %f\n", fv[userprice]);
	ft_display1(id, fv);
	mlx_hook(id[1], 17, 0, ft_exit, id);
	mlx_key_hook(id[1], ft_exit, id);
	mlx_loop(id[0]);
	return (0);
}

/*
int	ft_exit_shell(void *id[2])
{
	
	return (0);
}

int	esc_singleton(void);


void	*ft_mlx(void)
{
	static void	*mlx_ptr = (void *)0;

	if (!mlx_ptr)
	{
		id[0] = mlx_init();
		id[1] = mlx_new_window(id[0], 1200, 1100, "LR_chart");
	}
	return (mlx_ptr);
}
*/