/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:35:14 by alambert          #+#    #+#             */
/*   Updated: 2022/05/24 21:44:10 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lr.h"
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

int	**ft_splitandconvert(char *str, int data[2][24])
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
		token = strtok_r(NULL, ",\n", &ptr);
		if (!token)
			break ;
		data[0][i] = ft_atoi(token);
		token = strtok_r(NULL, ",\n", &ptr);
		if (!token)
			break ;
		data[1][i] = ft_atoi(token);
		i++;
	}
	return (data);
}

int	**ft_getdata(void)
{
	int		fd;
	char	*save;
	int		data[2][24];
	int		len;

	data[0][0] = 0;
	fd = open("data.csv", O_RDONLY);
	save = malloc(sizeof(char) * (281 + 1));
	if (!save)
		return (NULL);
	len = read(fd, save, 281);
	save[len] = '\0';
	close(fd);
	data = ft_splitandconvert(save, data);
	save = ft_free(&save);
	return (data);
}

/*
v2
int	**ft_minisplit(char *str, int data[2][24])
{
	char	*token;
	char	*ptr1;
	char	*ptr2;
	int		i;
	int		j;

	ptr1 = NULL;
	token = ft_strtok_r(str, ",", &ptr1);
	ptr2 = ptr1 + 1;
	token = ft_strtok_r(str, ",", &ptr2);
	ptr1 = ptr2 + 1;
	i = -1;
	j = -1;
	while (token && i++ < 24)
	{
		token = strtok_r(NULL, ",", &ptr1);
		data[0][i] = ft_atoi(token);
		while (token && j++ < 24)
		{
		token = strtok_r(NULL, "", &ptr2);
		data[1][j] = ft_atoi(token);
		}
	}
	return (data);
}

v1
char	**ft_minisplit(char *str, int data[2][12], int w)
{
	char	*token;
	char	*ptr1;
	char	*ptr2;
	int		i;
	int		j;

	ptr1 = NULL;
	token = ft_strtok_r(str, ",", &ptr1);
	ptr2 = ptr1 + 1;
	token = ft_strtok_r(str, ",", &ptr2);
	ptr1 = ptr2 + 1;
	i = 0;
	j = 0;
	while (token)
	{
		token = strtok_r(NULL, ",", &ptr1);
		data[0][i] = ft_atoi(token);
		ptr2 = ptr1 + 1;
		token = ft_strtok_r(NULL, "\n", &ptr2);
		data[1][j] = ft_atoi(token);
		ptr1 = ptr2 + 1;
		i++;
		j++;
	}
	return (data);
}

int main(void)
{
        char str[] = "y.o.u,a.r.e,h.e.r.e";
        const char *p =",", *q = ".";
        char *a, *b, *c, *d;

        for(a = strtok_r(str, p, &c) ; a != NULL ; a = strtok_r(NULL, p, &c))
		{
                printf("%s\n",a);

                for( b=strtok_r(a,q,&d) ; b!=NULL ; b=strtok_r(NULL,q,&d) )
                        printf("%s\n",b);
        }
        return 0;
}
*/