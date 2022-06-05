/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myenums.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:29:34 by alambert          #+#    #+#             */
/*   Updated: 2022/06/05 18:48:00 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYENUMS_H
# define MYENUMS_H

typedef enum e_ldb
{
	km,
	price,
	sqkm,
	sqprice,
	sqxmgap,
	sqymgap
}		t_ldb;

typedef enum e_lvar
{
	iteration_cut,
	num_data,
	prod,
	sumkm,
	sumprice,
	sumprod,
	sumsqkm,
	sumsqprice,
	userkm,
	userprice,
	theta0,
	theta1
}		t_lvar;

typedef enum e_fdb
{
	k,
	p
}		t_fdb;

typedef enum e_fvar
{
	k_predict,
	learning_rate,
	meank,
	meanp,
	r,
	costa,
	costb,
	costc,
	costd,
	final_b,
	dtt0,
	dtt1,
	t0,
	t1,
	tt0,
	tt1
}		t_fvar;
#endif