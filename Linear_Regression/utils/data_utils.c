/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:18:37 by anthonylamb       #+#    #+#             */
/*   Updated: 2022/05/29 19:21:59 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lr.h>

void	ft_splitandconvert(char *str, long ldb[8][24])
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

void	ft_getdata(long ldb[8][24])
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

void	ft_scantol(long lv[18])
{
	char	*str;
	char	*endptr;

	str = ft_malgets(6);
	endptr = str;
	lv[userkm] = ft_strtol(str, &endptr, 10);
	if (endptr == str || lv[userkm] > 397134)
	{
		printf("km must be less than 397134");
		lv[userkm] = 397135;
	}
	else
		printf("km is in the range");
	free(str);
}

void	ft_dataset(float fdb[2][24], float[5], long ldb[8][24], long lv[18])
{
	int	j;
	
	j = 0;
	while (j < lv[i])
	{
		lv[sumkm] += ldb[km][j];
		fv[meank] = (float)(ldb[sumkm] / lv[i]);
		lv[sumprice] += ldb[price][j];
		fv[meanp] = (float)(ldb[sumprice] / lv[i]);
		ldb[sqkm][j] = ldb[km][j] * ldb[km][j];
		ldb[sqprice][j] = ldb[price][j] * ldb[price][j];
		lv[sumsqkm] += ldb[sqkm][j];
		lv[sumsqprice] += ldb[sqprice][j];
		ldb[prod][j] = ldb[km][j] * ldb[price][j];
		lv[sumprod] += ldb[prod][j];
		fdb[k][j] = (float)ldb[km][j] / 10000.0;
		fdb[p][j] = (float)ldb[price][j] / 10000.0;
	}
}