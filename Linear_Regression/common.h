/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatta <lbenatta@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:10:22 by lbenatta          #+#    #+#             */
/*   Updated: 2022/05/09 11:10:26 by lbenatta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_FD
#  define MAX_FD 256
# endif

typedef struct t_tab
{
	int		km[24];
	int		price[24];
	int		sum_price;
	int		sum_km;
	int		count;
	float	mean_price;
	float	mean_km;
	int		sqr_price[24];
	long	sqr_km[24];
	long	sum_sqr_price;
	long	sum_sqr_km;
	long	pdt[24];
	long	sum_pdt;
	float	theta0;
	float	theta1;
	float	k[24];
	float	p[24];
	
}       t_tab;

int		ft_atoi(const char *str);

char	*get_next_line(int fd);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int n);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char    **ft_split(char   const *s, char c);

size_t	ft_strlen(const char *str);

void	test(t_tab *tab);

//Determines cost and adjusts
long doublebatch_gradient_descent(float*, float*, int, float, float, float);
long double* regression(float*, float*, int, float, int, long double*, long double*);
float predict(float, long double, long double);

#endif