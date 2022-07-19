/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filesize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:02:38 by alambert          #+#    #+#             */
/*   Updated: 2022/07/19 15:24:38 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_filesize(char *filename, int count[2])
{
	int		fd;
	int		len;
	char	*bin;

	fd = open("data.csv", O_RDONLY);
	count[0] = -1;
	count[1] = 1;
	bin = malloc(sizeof(char) + 1);
	len = 1;
	while (len != 0)
	{
		len = read(fd, bin, 1);
		if (len == -1)
		{
			bin = ft_free(&bin);
			return ;
		}
		if (*bin == '\n')
			count[1] += 1;
		bin[1] = '\0';
		count[0] += 1;
	}
	bin = ft_free(&bin);
	close(fd);
}

/* count[0] : char number,
count[1] : line number. */
