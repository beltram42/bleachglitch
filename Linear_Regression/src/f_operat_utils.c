/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_operat_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:57:26 by alambert          #+#    #+#             */
/*   Updated: 2022/06/04 15:20:01 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lr.h"
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <errno.h>



double	a_f(double a, double b)
{
	double	ret;

	if ((a + b) > -DBL_MIN && (a + b) < DBL_MIN && (a + b) != 0)
	{
		if ((a + b) > 0)
			ret = DBL_MIN;
		else
			ret = -DBL_MIN;
		errno = ERANGE;
		return (ret);
	}
	else if ((a + b) > DBL_MAX || (a + b) < -DBL_MAX)
	{
		if (a > 0)
			ret = DBL_MAX;
		else
			ret = -DBL_MAX;
		errno = ERANGE;
		return (ret);
	}
	else
		return (a + b);
}

double m_f(double a, double b)
{
	double	ret;

	if ((a * b) > -DBL_MIN && (a * b) < DBL_MIN && (a * b) != 0)
	{
		if ((a * b) > 0)
			ret = DBL_MIN;
		else
			ret = -DBL_MIN;
		errno = ERANGE;
		return (ret);
	}
	else if ((a * b) > DBL_MAX || (a * b) < -DBL_MAX)
	{
		if ((a * b) > 0)
			ret = DBL_MAX;
		else
			ret = -DBL_MAX;
		errno = ERANGE;
		return (ret);
	}
	else
		return (a * b);
}

double d_f(double a, double b)
{
	double	ret;

	if ((a / b) > -DBL_MIN && (a / b) < DBL_MIN && (a / b) != 0)
	{
		if ((a / b) > 0)
			ret = DBL_MIN;
		else
			ret = -DBL_MIN;
		errno = ERANGE;
		return (ret);
	}
	else if ((a / b) > DBL_MAX || (a / b) < -DBL_MAX)
	{
		if ((a / b) > 0)
			ret = DBL_MAX;
		else
			ret = -DBL_MAX;
		errno = ERANGE;
		return (ret);
	}
	else
		return (a / b);
}









/*
static void test_a_f(double a, double b)
{
	errno = 0;
	printf("%e + %e = %e", a, b, a_f(a, b)); 
	printf(" (%s)\n", strerror(errno));
}

static void test_m_f(double a, double b)
{
	errno = 0;
	printf("%e * %e = %e", a, b, m_f(a, b)); 
	printf(" (%s)\n", strerror(errno));
}

static void test_d_f(double a, double b)
{
	errno = 0;
	printf("%e / %e = %e", a, b, d_f(a, b)); 
	printf(" (%s)\n", strerror(errno));
}

int main(void)
{
	printf("a_f\n");
	test_a_f(1, 1);
	test_a_f(5, -6);
	test_a_f(DBL_MIN, -3./2*DBL_MIN); // underflow 
	test_a_f(DBL_MAX, 1);
	test_a_f(DBL_MAX, -DBL_MAX);
	test_a_f(DBL_MAX, DBL_MAX); // overflow 
	test_a_f(-DBL_MAX, -1./2*DBL_MAX); // overflow 
	printf("m_f\n");
	test_m_f(1, 1);
	test_m_f(5, -6);
	test_m_f(0.5, DBL_MIN); // underflow 
	test_m_f(DBL_MAX, 1);
	test_m_f(DBL_MAX, -DBL_MAX);
	test_m_f(DBL_MAX, DBL_MAX); // overflow 
	test_m_f(-DBL_MAX, -1./2*DBL_MAX); /* overflow 
	printf("d_f\n");
	test_d_f(5, -6);
	test_d_f(DBL_MIN, 2); // underflow 
	test_d_f(DBL_MAX, 1);
	test_d_f(DBL_MAX, -DBL_MAX);
	test_d_f(DBL_MAX, DBL_MIN); // overflow 
	test_d_f(-DBL_MAX, -1./DBL_MAX); // overflow 
	return (0);
}
*/