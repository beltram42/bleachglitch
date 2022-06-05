/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:35:14 by alambert          #+#    #+#             */
/*   Updated: 2022/06/05 18:44:19 by alambert         ###   ########.fr       */
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
	long		ldb[6][24];
	long		lv[12];
	float		fdb[2][24];
	float		fv[16];
	void		*id[2];

	ft_set0(fdb, fv, ldb, lv);
	ft_getdata(ldb);
	ft_dset(fdb, fv, ldb, lv);
	ft_regr(fdb, fv, lv, ldb);
	fv[final_b] = fv[tt1] * 10000;
	fv[k_predict] = 10.0;
	ft_corr_rate(fv, ldb, lv);
	id[0] = mlx_init();
	id[1] = mlx_new_window(id[0], 1200, 1100, "LR_chart");
	ft_display0(id, ldb, lv, fv);
	mlx_key_hook(id[1], ft_up_shell, lv);
	ft_display1(id, ldb, lv);
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