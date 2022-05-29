/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:18:37 by anthonylamb       #+#    #+#             */
/*   Updated: 2022/05/29 21:22:27 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lr.h>

static void	ft_splitandconvert(char *str, long ldb[7][24])
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
		ldb[0][i] = ft_strtol(token, (char **) NULL, 10);
		token = ft_strtok_r(NULL, ",\n", &ptr);
		if (!token)
			break ;
		ldb[1][i] = ft_strtol(token, (char **) NULL, 10);
		i++;
	}
}

void	ft_getdata(long ldb[7][24])
{
	int		fd;
	char	*save;
	int		len;
	struct stat sb;

	if (stat("data.csv", &sb) == -1)
		return ;
	len = sb.st_size;
	fd = open("data.csv", O_RDONLY);
	if (fd == -1)
		return ;
	save = malloc(sizeof(char) * (len + 1));
	if (!save)
		return ;
	len = read(fd, save, len);
	save[len] = '\0';
	close(fd);
	ft_splitandconvert(save, ldb);
	save = ft_free(&save);
}

void	ft_setzero(float fdb[2][24], float fv[5], long ldb[7][24], long lv[19])
{
	ft_bzero(ldb, sizeof(long) * 7 * 24);
	ft_bzero(lv, sizeof(long) * 19);
	ft_bzero(fdb, sizeof(float) * 2 * 24);
	ft_bzero(fv, sizeof(float) * 5);
}

void	ft_dataset(float fdb[2][24], float fv[5], long ldb[7][24], long lv[19])
{
	int	j;

	j = 0;
	while (j < 24)
	{
		lv[sumkm] += ldb[km][j];
		fv[meank] = (float)(ldb[sumkm] / 24);
		lv[sumprice] += ldb[price][j];
		fv[meanp] = (float)(ldb[sumprice] / 24);
		ldb[sqkm][j] = ldb[km][j] * ldb[km][j];
		ldb[sqprice][j] = ldb[price][j] * ldb[price][j];
		lv[sumsqkm] += ldb[sqkm][j];
		lv[sumsqprice] += ldb[sqprice][j];
		ldb[prod][j] = ldb[km][j] * ldb[price][j];
		lv[sumprod] += ldb[prod][j];
		fdb[k][j] = (float)ldb[km][j] / 10000.0;
		fdb[p][j] = (float)ldb[price][j] / 10000.0;
	}
	lv[t1] = (long)(((fv[meank] * lv[sumprice]) - lv[sumprod])
			/ ((fv[meank] * lv[sumkm]) - lv[sumsqkm]));
	lv[t0] = (long)(fv[meanp] - (lv[t1] * fv[meank]));
	fv[learning_rate] = 0.0001;
	lv[iteration_cut] = 27500;
	lv[num_data] = 24;
}

void	ft_userprice(long lv[19])
{
	char	*str;
	char	*endptr;

	printf("please enter #km from 0 to 397134:\n");
	str = ft_malgets(6);
	endptr = str;
	lv[userkm] = ft_strtol(str, &endptr, 10);
	if (endptr == str || lv[userkm] > 397134)
	{
		printf("#km should be less than 397134\n");
		lv[userkm] = 397135;
		str = ft_free(&str);
		lv[userprice] = 0;
		printf("car price for more than 397134km is: 0\n");
		return ;
	}
	else
	{
		printf("#km is in the range\n");
		str = ft_free(&str);
		lv[userprice] = lv[t0] + (lv[t1] * lv[userkm]);
		printf("car price for %ld km is: %ld\n", lv[userkm], lv[userprice]);
	}
}
