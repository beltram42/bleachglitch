/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:35:14 by alambert          #+#    #+#             */
/*   Updated: 2022/05/23 15:36:35 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lr.h"

int main(void) {

        char str[]="y.o.u,a.r.e,h.e.r.e";
        const char *p=",",*q=".";
        char *a,*b,*c,*d;

        for( a=strtok_r(str,p,&c) ; a!=NULL ; a=strtok_r(NULL,p,&c) ) {
                printf("%s\n",a);

                for( b=strtok_r(a,q,&d) ; b!=NULL ; b=strtok_r(NULL,q,&d) )
                        printf("%s\n",b);
        }

        return 0;
}

static int	**ft_wordmeter(char *str, const char *set)
{
	const char	*ptr;
	int	len[2][13];
	int	i;

	ptr = (const char *)str;
	i = 0;
	while (ptr, i < 12)
	{
		ptr += len[0][i - 1] + len[1][i - 1] + 2;
		len[0][i] = ft_strspncspn(ptr, set, - 1);
		len[1][i] = ft_strspncspn(ptr, set, - 1);
		len[0][12] += 1;
	}
}

char	**ft_minisplit(char *str)
{
	const char	*sep1;
	const char	*sep2;
	char	*token1;
	char	*token2;
	char	*ptr1;
	char	*ptr2;

	int	ft_isdigit(int c)



}

void	ft_readandsave(int fd)
{
	char	*save;


}

int	main(void)
{
	int	fd;

	fd = open("data.csv", O_RDONLY);



}