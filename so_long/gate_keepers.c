/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gate_keepers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:47:40 by alambert          #+#    #+#             */
/*   Updated: 2022/04/07 15:21:13 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	arg_gate_keeper(int argc, char **argv)
{}

void	map_walls_keeper(char **map)
{

}


int	map_lines_length(char **map)
{
	int	l1;

	l1 = ft_strlen(**map);
	while (**map++)
		if (ft_strlen(**map) != l1)
			return (0);
	return (1);
}

void	map_elts_keeper(char *smap)
{}

void	map_fd_error_keeper(void)
{
	
}

















