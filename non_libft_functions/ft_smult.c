/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:57:26 by alambert          #+#    #+#             */
/*   Updated: 2022/07/11 14:03:02 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <errno.h>

long double	ft_smld(long double a, long double b)
{
	long double	ret;

	if ((a * b) > -LDBL_MIN && (a * b) < LDBL_MIN && (a * b) != 0)
	{
		if ((a * b) > 0)
			ret = LDBL_MIN;
		else
			ret = -LDBL_MIN;
		errno = ERANGE;
		return (ret);
	}
	else if ((a * b) > LDBL_MAX || (a * b) < -LDBL_MAX)
	{
		if ((a * b) > 0)
			ret = LDBL_MAX;
		else
			ret = -LDBL_MAX;
		errno = ERANGE;
		return (ret);
	}
	else
		return (a * b);
}

double	ft_smd(double a, double b)
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

float	ft_smf(float a, float b)
{
	float	ret;

	if ((a * b) > -FLT_MIN && (a * b) < FLT_MIN && (a * b) != 0)
	{
		if ((a * b) > 0)
			ret = FLT_MIN;
		else
			ret = -FLT_MIN;
		errno = ERANGE;
		return (ret);
	}
	else if ((a * b) > FLT_MAX || (a * b) < -FLT_MAX)
	{
		if ((a * b) > 0)
			ret = FLT_MAX;
		else
			ret = -FLT_MAX;
		errno = ERANGE;
		return (ret);
	}
	else
		return (a * b);
}

/*A set of safe multiply tools for complexes*/