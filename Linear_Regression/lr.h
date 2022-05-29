/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:04:32 by alambert          #+#    #+#             */
/*   Updated: 2022/05/29 21:04:55 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LR_H
# define LR_H

# include "./mlx/mlx.h"
# include "./lib42/lib42.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <ctype.h>
# include <math.h>
# include <sys/stat.h>

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
	userprice,
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


int	display(void);

#endif
