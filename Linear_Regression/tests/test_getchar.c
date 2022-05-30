/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:29:48 by alambert          #+#    #+#             */
/*   Updated: 2022/05/23 12:11:33 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//#include "./lib42/lib42.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//#define BUF 128
/*
int	ft_getchar()
{
	char	save[2];
	char	c;

	if (read(0, save, 1) == -1)
		return (0);
	c = *save;
	return ((int)c);
}

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}
*/
char	*ft_free(char **str)
{
	if (!*str)
		return (NULL);
	free(*str);
	*str = NULL;
	return (NULL);
}


void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*startd;
	const char	*starts;
	const char	*ends;
	char		*endd;

	starts = (const char *)src;
	startd = (char *)dest;
	ends = starts + (n - 1);
	endd = startd + (n - 1);
	//if (dest == NULL && src == NULL)
	//	return (NULL);
	if (startd < starts)
		while (n--)
			*startd++ = *starts++;
	else
		while (n--)
			*endd-- = *ends--;
	return (dest);
}

/*
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	if (n == 0)
		return ;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	s = str;
}

int	ft_fgetc(FILE *fp)
{
	char c;
/
	if (fp->ungetcflag)
	{
		fp->ungetcflag = 0;
		return (fp->ungetchar);
	}
	if (read (fp->fd, &c, 1) == 0)
		return (EOF);
	return (c);
}

char	*ft_fgets(char *s, int n, FILE *fp)
{
	int c;
	char *cs;

	c = 0;
	cs = s;

	while (--n > 0 && (c = ft_fgetc(fp)) != EOF) {
		*cs++ = c;
		if (c == '\n')
			break;
	}
	if (c == EOF && cs == s)
		return (NULL);

	*cs++ = '\0';
	return (s);
}
*/
char	*ft_getstr_stdin(int buf)
{
	char	*save;
	//char	*str;
	int	len;
	
	save = malloc(sizeof(char) * (buf + 1));
	if (!save)
		return (NULL);
	len = read(0, save, buf);
	if (len == -1)
	{
		save = ft_free(&save);
		return (NULL);
	}
	save[len] = '\0';
	//ft_memmove((void *)str, (void *)save, len + 1);
	//save = ft_free(&save);
	return ((char *)save);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int	main(void)
{
	//char	c;
	char	*test;
	test = NULL;

	//c = (char)ft_getchar();
	//printf("stdin c = %c\n", c);
	test = ft_getstr_stdin(128);
	ft_putstr(test);
	free(test);
	//test = ft_fgets(test, 128, stdin);
	//printf("stdin str = %s\n", test);
	//free(test);
	return (0);
}
