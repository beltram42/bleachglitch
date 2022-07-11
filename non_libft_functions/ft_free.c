/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:27:55 by alambert          #+#    #+#             */
/*   Updated: 2022/07/11 13:41:03 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_free(char **str)
{
	if (!*str)
		return (NULL);
	free(*str);
	*str = NULL;
	return (NULL);
}

/*Frees and puts the str to NULL;
in order to prevent it from being reachable*/