/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:00:35 by alambert          #+#    #+#             */
/*   Updated: 2022/05/18 12:01:56 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*res;
	int	len1;
	int	len2;

	len2 = ft_strspncspn(s2, "", -1);
	res = NULL;
	len1 = ft_strspncspn(s1, "", -1);
	res = ft_malmovebis(s1, s2, len1, len2);
	free(s1);
	return (res);
}
