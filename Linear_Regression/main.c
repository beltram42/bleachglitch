#include <stdio.h>

int	ft_atoi(const char *str);

int	main(void)
{
	char	*str = "123456+4";
	int	i;

	i = ft_atoi(str);

	printf("str = %s", str);
	printf("int = %d", i);
}
