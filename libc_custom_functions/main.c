/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:49:33 by alambert          #+#    #+#             */
/*   Updated: 2022/05/08 19:00:53 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strpbrk(const char *str, const char *set);

int ft_strspn(const char *str, const char *set);

int	main(void)
{
	const char 	*str = "Azur! nos bêtes sont bondées d’un cri !";
	const char	*set = " !";
	char	*ptr;
	int	v;

	ptr = ft_strpbrk(str, set);
	printf("ptr = %s", ptr);

	v = ft_strspn(str, set);
	printf("span = %d", v);
	
	return (0);
}