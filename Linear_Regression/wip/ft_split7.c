/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split7.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatta <lbenatta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:31:13 by lbenatta          #+#    #+#             */
/*   Updated: 2022/04/27 19:31:13 by lbenatta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lr.h"

static int	ft_charset(char charset, char a)
{
	if(charset == a)
		return(1);
	else
		return(0);
}

static int	ft_word(char sep, char *str)
{
	int	i;
	int wd;

	i = 0;
	wd = 0;
	while (ft_charset(sep, str[i]) == 1 && str[i])
		i++;
	while (str[i])
	{
		wd++;
		while (ft_charset(sep, str[i]) == 0 && str[i])
		i++;
		while (ft_charset(sep, str[i]) == 1 && str[i])
			i++;
	}
	return (wd);
}

static char	*ft_strdupi(const char *str, char sep)
{
	int          i;
	int          v;
	char       *res;

	i = 0;
	v = 0;
	while (str[i] && ft_charset(sep, str[i]) == 0)
		i++;
	res = (char *)malloc((i + 1) * sizeof (char));
	i = 0;
	if (!res)
	return (0);
	while (ft_charset(sep, str[i]) == 1 && str[i])
		i++;
	while (ft_charset(sep, str[i]) == 0 && str[i])
	{
		res[v] = str[i];
		i++;
	v++;
	}
	res[v] = '\0';
	return (res);
}

char	**ft_split(char   const *s, char c)
{
	int          i;
	int          v;
	char       **split;

	split = (char **)malloc((ft_word(c, ((char *)s)) + 1) * sizeof(char *));
	if (!split)
		return(0);
	v = 0;
	i = 0;
	while (ft_charset(c, s[i]) == 1 && s[i])
		i++;
	while (s[i])
	{
		split[v] = ft_strdupi(&s[i], c);
	if (!split[v])
		return (0);
	while (ft_charset(c, s[i]) == 0 && s[i])
		i++;
	while (ft_charset(c, s[i]) == 1 && s[i])
		i++;
		v++;
	}
	split[ft_word(c, ((char *)s))] = 0;
	return (split);
}

int	main(void)
{
	int	f;
	char	*str;
	char	**strs;
	int	i;
	t_tab *tab;   

	f = open("data.csv", O_RDONLY);

	i = 0;
	tab = (t_tab *)malloc(sizeof(t_tab));
	/*str = get_next_line(f);
	free(str);*/
	str = get_next_line(f);
	while (str != NULL)
	{
		strs = ft_split(str, ',');
		tab->km[i] = ft_atoi(strs[0]);
		tab->price[i] = ft_atoi(strs[1]);
		i++;
		str = get_next_line(f);
	}

	tab->count = i;

	i = 0;
	while (i < tab->count)
	{
		printf("%i / %i\n", tab->km[i], tab->price[i]);
		i++;
	}

    i = 0;
	tab->theta0 = 0;
	tab->theta1 = 0;
	tab->sum_price = 0;
	tab->mean_price = 0;
	tab->sum_km = 0;
	tab->mean_km = 0;
	tab->sum_sqr_price = 0;
	tab->sum_sqr_km = 0;
	
	for(i = 0; i < tab->count; i++)
	{
		tab->sum_km = tab->sum_km + tab->km[i];
		tab->mean_km = tab->sum_km / tab->count;
		tab->sum_price = tab->sum_price + tab->price[i];
		tab->mean_price = tab->sum_price / tab->count;
		tab->sqr_km[i] = (long)tab->km[i] * (long)tab->km[i];
		tab->sqr_price[i] = tab->price[i] * tab->price[i];
		tab->sum_sqr_km = (long)tab->sum_sqr_km + (long)tab->sqr_km[i];
		tab->sum_sqr_price = tab->sum_sqr_price + tab->sqr_price[i];
		tab->pdt[i] = (long)tab->km[i] * (long)tab->price[i];
		tab->sum_pdt = tab->sum_pdt + tab->pdt[i];
    }

	tab->theta1 = ((tab->mean_km * tab->sum_price) - (tab->sum_pdt)) / ((tab->mean_km * tab->sum_km) - (tab->sum_sqr_km));
	tab->theta0 = (tab->mean_price - (tab->theta1 * tab->mean_km));


	printf("sum_km : %d\n", tab->sum_km);
	printf("sum_price : %d\n", tab->sum_price);
	printf("mean_km : %f\n", tab->mean_km);
	printf("mean_price : %f\n", tab->mean_price);
	printf("sum_sqr_km : %ld\n", tab->sum_sqr_km);
	printf("sum_sqr_price : %ld\n", tab->sum_sqr_price);
	printf("sum_pdt : %ld\n", tab->sum_pdt);
	printf("theta1 = %f\n", tab->theta1);
	printf("theta0 = %f\n", tab->theta0);

	test(tab);
	//free(tab);
	return(0);
}

void test(t_tab *tab)
{
	printf("TOTAL_X_km : %d\n", tab->sum_km);
	printf("TOTAL_Y_price : %d\n", tab->sum_price);
	printf("TOTAL_X2_sqr_km : %ld\n", tab->sum_sqr_km);
	printf("TOTAL_Y2_sqr_price : %ld\n", tab->sum_sqr_price);
	printf("TOTAL_XY_prod : %ld\n", tab->sum_pdt);
	printf("theta1 = %f\n", tab->theta1);
	printf("theta0 = %f\n", tab->theta0);
}

