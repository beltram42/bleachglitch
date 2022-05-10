/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:04:32 by alambert          #+#    #+#             */
/*   Updated: 2022/05/10 14:03:32 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LR_H
# define LR_H

#include "./mlx/mlx.h"
#include "./lib42/lib42.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>

/*
typedef enum e_long
{
	km,
	price,
	km_sum,
	price_sum,
	meter,
	sqr_km,
	sqr_price,
	sqr_km_sum,
	sqr_price_sum,
	pdt,
	pdt_sum,
	ENUM_MAX
}			t_long;

typedef enum e_float
{
	mean_km,
	meam_price,

}			t_float
*/
typedef struct s_tab
{
	int	km[24];
	int	price[24];
	int	sum_price;
	int	sum_km;
	int	count;
	float	mean_price;
	float	mean_km;
	int	sqr_price[24];
	long	sqr_km[24];
	long	sum_sqr_price;
	long	sum_sqr_km;
	long	pdt[24];
	long	sum_pdt;
	float	theta0;
	float	theta1;
	
}       t_tab;


int	display(void);
/*
//double get_estimated_price(int mileage, double theta0, double theta1);
//void get_estimated_price(int data, float theta0, float theta1);
int get_estimated_price(int X, float theta0, float theta1);
void get_theta(float theta0, float theta1);
//void get_theta(float *theta0, float *theta1);
//void get_theta_from_data(char *data, float *theta0, float *theta1);
int valid_int(char *n);
char *read_next_line(int fd);
*/
#endif
