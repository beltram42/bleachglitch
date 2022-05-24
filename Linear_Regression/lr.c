/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:35:14 by alambert          #+#    #+#             */
/*   Updated: 2022/05/24 14:04:04 by alambert         ###   ########.fr       */
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

static int	ft_wordmeter(char *str, const char *set)
{
	char	*ptr;
	int	w;

	ptr = str;
	w = 0;
	while (ptr)
	{
		ptr = ft_strpbrk(ptr, const char *set);
		ptr++;
		w++;
	}
	return (w);
}

char	**ft_minisplit(char *str, int data[2][12], int w)
{
	char	*token1;
	char	*token2;
	char	*ptr1;
	char	*ptr2;
	int		len;

	int	ft_isdigit(int c)



}

char	*ft_readandsave(int fd)
{
	char	*save;
	

	return (save);
}

int	main(void)
{
	int	fd;
	int	w;
	char	*str;
	int	data[2][12];

	data[0][0] = 0;
	fd = open("data.csv", O_RDONLY);
	str = ft_readandsave(fd);
	clode(fd);
	w = ft_wordmeter(str, ",\n");



	
}