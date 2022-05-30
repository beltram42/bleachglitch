
#include <stdio.h>

void	ft_bzero(void *s, int n)
{
	int				i;
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

void	ft_setzero(int array[2][10])
{
	ft_bzero(array, sizeof(int) * 2 * 10);
}

int	main(void)
{
	int	array[2][10];
	int	i;

	i = 0;
	while (i < 10)
	{
		printf("array[0][%d] = %d\n", i, array[0][i]);
		printf("array[1][%d] = %d\n", i, array[1][i]);
		i++;
	}
	ft_setzero(array);
	i = 0;
	while (i < 10)
	{
		printf("array[0][%d] = %d\n", i, array[0][i]);
		printf("array[1][%d] = %d\n", i, array[1][i]);
		i++;
	}
	return (0);
}