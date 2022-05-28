/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:18:37 by anthonylamb       #+#    #+#             */
/*   Updated: 2022/05/28 18:19:33 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_splitandconvert(char *str, long ldata[6][24])
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
		token = ft_strtok_r(NULL, ",\n", &ptr);
		if (!token)
			break ;
		ldata[0][i] = ft_strtol(token, (char **) NULL, 10);
		token = ft_strtok_r(NULL, ",\n", &ptr);
		if (!token)
			break ;
		ldata[1][i] = ft_strtol(token, (char **) NULL, 10);
		i++;
	}
}

void	ft_getdata(long ldata[6][24])
{
	int		fd;
	char	*save;
	int		len;
	struct stat sb;
	
	if (stat("data.csv", &sb) == -1)
		return ;
	len = sb.st_size;
	ldata[0][0] = 0;
	fd = open("data.csv", O_RDONLY);
	if (fd == -1)
		return ;
	save = malloc(sizeof(char) * (len + 1));
	if (!save)
		return ;
	len = read(fd, save, len);
	save[len] = '\0';
	close(fd);
	ft_splitandconvert(save, ldata);
	save = ft_free(&save);
}