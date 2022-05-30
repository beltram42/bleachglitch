/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_reg_estimate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatta <lbenatta@42.fr>                    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:35:31 by lbenatta          #+#    #+#             */
/*   Updated: 2022/05/24 13:36:05 by lbenatta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

//static int	ft_charset(char charset, char a)
//static int	ft_word(char sep, char *str)
//static char	*ft_strdupi(const char *str, char sep)
//char       **ft_split(char   const *s, char c)
/*
void test(t_tab *tab)
{
	//printf("k : %f\n", tab->k[]);
	//printf("p : %f\n", tab->p[]);
	printf("TOTAL_X_km : %d\n", tab->sum_km);
	printf("TOTAL_Y_price : %d\n", tab->sum_price);
	printf("TOTAL_X2_sqr_km : %ld\n", tab->sum_sqr_km);
	printf("TOTAL_Y2_sqr_price : %ld\n", tab->sum_sqr_price);
    printf("TOTAL_XY_prod : %ld\n", tab->sum_pdt);
	printf("theta1 = %f\n", tab->theta1);
    printf("theta0 = %f\n", tab->theta0);
}
*/
int main(void)
{
	int	f;
	char	*str;
	char	**strs;
	int	i;
	t_tab *tab;
	
    f = open("data.csv", O_RDONLY);
	i = 0;
	tab = (t_tab *)malloc(sizeof(t_tab));
	str = get_next_line(f);
	free(str);
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
    /*
	i = 0;
	while (i < tab->count)
	{
		printf("%i / %i\n", tab->km[i], tab->price[i]);
		i++;
	}
	*/
	i = 0;
    tab->theta0 = 0;
	tab->theta1 = 0;
	tab->sum_price = 0;
    tab->mean_price = 0;
	tab->sum_km = 0;
    tab->mean_km = 0;
	tab->sum_sqr_price = 0;
	tab->sum_sqr_km = 0;

	for(i=0; i < tab->count; i++)
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
		tab->k[i] = tab->km[i] / 10000.0;
		tab->p[i] = tab->price[i] / 10000.0;
    
		//printf("%f / %f\n", tab->k[i], tab->p[i]);
		//i++;
	}
    if (i == tab->count)
    {
        tab->theta1 = ((tab->mean_km * tab->sum_price) - (tab->sum_pdt)) / ((tab->mean_km * tab->sum_km) - (tab->sum_sqr_km));
        tab->theta0 = (tab->mean_price - (tab->theta1 * tab->mean_km)); 
    } /*
	printf("sum_km : %d\n", tab->sum_km);
	printf("sum_price : %d\n", tab->sum_price);
    printf("mean_km : %f\n", tab->mean_km);
	printf("mean_price : %f\n", tab->mean_price);
	printf("sum_sqr_km : %ld\n", tab->sum_sqr_km);
	printf("sum_sqr_price : %ld\n", tab->sum_sqr_price);
	printf("sum_pdt : %ld\n", tab->sum_pdt);*/
    printf("theta1 = %f\n", tab->theta1);
    printf("theta0 = %f\n", tab->theta0); 
	
	int nombre = 0;
    int resultat = 0;
    
    printf("Entrez le nombre de km:");
    scanf("%d", &nombre);
    
    resultat = (tab->theta0 + (tab->theta1 * nombre));
    printf("Le prix_estime est %d\n", resultat);
    free(tab);
	return(0);
}
