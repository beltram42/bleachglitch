/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatta <lbenatta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:58:32 by lbenatta          #+#    #+#             */
/*   Updated: 2022/04/05 12:05:01 by lbenatta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

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

char	*get_next_line(int fd);
int	ft_atoi(const char *str);
void	test(t_tab *tab);
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