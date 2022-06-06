/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:18:37 by alambert          #+#    #+#             */
/*   Updated: 2022/06/06 12:17:49 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lr.h"
#include "../myenums.h"

void	ft_splitandconvert(char *str, float fdb[9][24])
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
		fdb[km][i] = ft_strtol(token, (char **) NULL, 10);
		token = ft_strtok_r(NULL, ",\n", &ptr);
		if (!token)
			break ;
		fdb[price][i] = ft_strtol(token, (char **) NULL, 10);
		i++;
	}
}

void	ft_getdata(float fdb[9][24])
{
	int			fd;
	char		*save;
	int			len;
	struct stat	sb;

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
	ft_splitandconvert(save, fdb);
	save = ft_free(&save);
}

void	ft_set0(float fdb[9][24], float fv[24])
{
	ft_bzero(fdb, sizeof(float) * 2 * 24);
	ft_bzero(fv, sizeof(float) * 5);
}

void	ft_dset(float fdb[9][24], float fv[24])
{
	int	j;

	j = 0;
	while (j < 24)
	{
		fv[sumkm] += fdb[km][j];
		fv[meank] = fv[sumkm] / 24.0;
		fv[sumprice] += fdb[price][j];
		fv[meanp] = fv[sumprice] / 24.0;
		fdb[sqkm][j] = cpowf(fdb[km][j], 2);
		fdb[sqprice][j] = cpowf(fdb[price][j], 2);
		fv[sumsqkm] += fdb[sqkm][j];
		fv[sumsqprice] += fdb[sqprice][j];
		fdb[prod][j] = fdb[km][j] * fdb[price][j];
		fv[sumprod] += fdb[prod][j];
		fdb[k][j] = fdb[km][j] / 10000.0;
		fdb[p][j] = fdb[price][j] / 10000.0;
		fdb[sqxmgap][j] = cpowf(fdb[km][j] - fv[meank], 2);
		fdb[sqymgap][j] = cpowf(fdb[price][j] - fv[meanp], 2);
		j++;
	}
	fv[t1] = ((fv[meank] * fv[sumprice]) - fv[sumprod]) \
			/ ((fv[meank] * fv[sumkm]) - fv[sumsqkm]);
	fv[t0] = (fv[meanp] - (fv[t1] * fv[meank]));
	fv[learning_rate] = 0.0001;
	fv[iteration_cut] = 27500.0;
}
