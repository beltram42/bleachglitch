/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:35:14 by alambert          #+#    #+#             */
/*   Updated: 2022/05/25 19:06:12 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lr.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
/*
static int	ft_wordmeter(char *str, const char *set)
{
	char	*ptr;
	int		w;

	ptr = str;
	w = 0;
	while (ptr)
	{
		ptr = ft_strpbrk(ptr, set);
		ptr++;
		w++;
	}
	return (w);
}*/

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

char	*ft_free(char **str)
{
	if (!*str)
		return (NULL);
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return ((char *)s);
}

char	*ft_strtok_r(char *str, const char *sep, char **saveptr)
{
	char	*start;

	if (!str)
		str = *saveptr;
	while (*str && ft_strchr(sep, *str))
		++str;
	if (*str)
	{
		start = (char *)str;
		*saveptr = start + 1;
		while (**saveptr && !ft_strchr(sep, **saveptr))
			++*saveptr;
		if (**saveptr)
		{
			**saveptr = '\0';
			++*saveptr;
		}
		return (start);
	}
	return (NULL);
}

typedef enum e_var
{
	SIGN,
	BASE,
	DGT,
	ANY,
	RES,
	CUT,
	MOD,
	MOVE,
	ENUM_MAX
}			t_var;

static long	ft_basecheck(const char *s, long base, long val[8])
{
	long	c;

	c = val[DGT];
	if (((base == 0 || base == 2) && c == 48 && (*s == 66 || *s == 98))
		|| ((base == 0 || base == 16) && c == 48 && (*s == 88 || *s == 120)))
	{
		if ((base == 0 || base == 2) && c == 48 && (*s == 66 || *s == 98))
			base = 2;
		else
			base = 16;
	}
	else if (base == 0)
	{
		base = 10;
		if (c == 48)
			base = 8;
	}
	return (base);
}

static long	*ft_cvbase(const char *s, long val[8])
{
	val[RES] = 0;
	while (*s++)
	{
		val[MOVE] += 1;
		if (ft_isalpha(val[DGT]) && val[DGT] > 96)
			val[DGT] -= 87;
		else if (ft_isalpha(val[DGT]) && val[DGT] < 91)
			val[DGT] -= 55;
		else if (ft_isdigit(val[DGT]))
			val[DGT] -= 48;
		else
			break ;
		if (val[DGT] >= val[BASE])
			break ;
		if (val[ANY] < 0 || ((unsigned long)val[RES] > (unsigned long)val[CUT])
			|| (val[RES] == val[CUT] && val[DGT] > val[MOD]))
			val[ANY] = -1;
		else
		{
			val[ANY] = 1;
			val[RES] = (val[RES] * val[BASE]) + val[DGT];
		}
		val[DGT] = *s;
	}
	return (val);
}

static long	ft_ltobase(const char *s, long val[8])
{
	val[MOVE] = 0;
	val[ANY] = 0;
	if (val[SIGN] == -1)
		val[CUT] = -(unsigned long)LONG_MIN;
	if (val[BASE] == 2 || val[BASE] == 16)
	{
		s += 2;
		val[MOVE] = 2;
	}
	if (val[BASE] == 8)
	{
		s += 1;
		val[MOVE] = 1;
	}
	val[DGT] = *s;
	val = ft_cvbase(s, val);
	if (val[ANY] < 0)
	{
		val[RES] = LONG_MAX;
		if (val[SIGN] == -1)
			val[RES] = LONG_MIN;
	}
	else if (val[SIGN] == -1)
		val[RES] *= val[SIGN];
	return (val[RES]);
}

long	ft_strtol(const char *str, char **endptr, int base)
{
	const char	*s;
	long		val[8];

	s = str;
	val[SIGN] = 1;
	while (*s == 9 || *s == 10 || *s == 11 || *s == 12 || *s == 13 || *s == 32)
		s++;
	val[DGT] = *s++;
	if (!(ft_isdigit((int)val[DGT]) || ft_isalpha((int)val[DGT])
			|| val[DGT] == 43 || val[DGT] == 45))
		return (0);
	if (val[DGT] == 43 || val[DGT] == 45)
	{
		if (val[DGT] == 45)
			val[SIGN] = -1;
		val[DGT] = *s++;
	}
	val[BASE] = ft_basecheck(s, base, val);
	val[CUT] = LONG_MAX;
	val[MOD] = val[CUT] % (unsigned long)val[BASE];
	s--;
	val[RES] = ft_ltobase(s, val);
	if ((endptr != 0) && val[ANY] != 0)
		*endptr = (char *)(s + val[MOVE] - 1);
	return ((long)val[RES]);
}

int	ft_atoi(const char *str)
{
	return ((int )ft_strtol(str, (char **) NULL, 10));
}

/*---------------------------------------------------------------------*/

void	ft_splitandconvert(char *str, long ldata[6][24])
{
	char	*token;
	char	*ptr;
	int		i;

	ptr = NULL;
	token = ft_strtok_r(str, ",\n", &ptr);
	token = ft_strtok_r(NULL, ",\n", &ptr);
	i = 0;
	while (i < 24)
	{
		token = ft_strtok_r(NULL, ",\n", &ptr);
		if (!token)
			break ;
		ldata[0][i] = ft_strtol(token, (char **) NULL, 10);
		token = ft_strtok_r(NULL, ",\n", &ptr);
		if (!token)
			break ;
		ldata[1][i] = ft_strtol(token, (char **) NULL, 10);
		i++;
	}
}

void	ft_getdata(long ldata[6][24])
{
	int		fd;
	char	*save;
	int		len;

	ldata[0][0] = 0;
	fd = open("data.csv", O_RDONLY);
	save = malloc(sizeof(char) * (281 + 1));
	if (!save)
		return ;
	len = read(fd, save, 281);
	save[len] = '\0';
	close(fd);
	ft_splitandconvert(save, ldata);
	save = ft_free(&save);
}

/*
void	ft_landmark(void *id[2])
{
	int		x;
	int		y;
	
	x = 100;
	y = 99;
	while (y++ <= 1000)
		mlx_pixel_put(id[0], id[1], x, y, 0x0009ae51);
	y = 99;
	while (y++ <= 1000)
		if (y == (y / 100) *100)
		{
			mlx_pixel_put(id[0], id[1], x - 1, y, 0x0009ae51);
			mlx_pixel_put(id[0], id[1], x + 1, y, 0x0009ae51);
		}
	x = 99;
	y = 1000;
	while (x++ <= 2500)
		mlx_pixel_put(id[0], id[1], x, y, 0x0009ae51);
	x = 99;
	while (x++ <= 2500)
	{
		if ((x - 100) == ((x - 100) / 200) * 200)
		{
			mlx_pixel_put(id[0], id[1], x, y - 1, 0x0009ae51);
			mlx_pixel_put(id[0], id[1], x, y + 1, 0x0009ae51);
		}
	}
}
*/

/*
void	ft_display(long ldata[5][24])
{
	void	*id[2];
	int		x;
	int		y;

	id[0] = mlx_init();
	id[1] = mlx_new_window(id[0], 1200, 1100, "LR_display");
	ft_landmark(id);
}
*/

int	main(void)
{
	long	ldb[6][24];
	long	lvar[6];
	float	fdb[2][24];
	float	fvar[5];
	int		i;

	ft_getdata(ldb);
	i = 0;
	while (i < 24)
	{
		printf("d[0][%d] = %lu, d[1][%d] = %lu\n", i, ldb[0][i], i, ldb[1][i]);
		i++;
	}
	//ft_display(d)
	return (0);
}
