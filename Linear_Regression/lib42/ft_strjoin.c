/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:12:51 by alambert          #+#    #+#             */
/*   Updated: 2022/05/10 17:43:43 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		len1;
	int		len2;

	len2 = ft_strspncspn(s2, "", -1);
	res = NULL;
	len1 = ft_strspncspn(s1, "", -1);
	res = ft_malmove(s1, s2, len1, len2);
	return (res);
}
