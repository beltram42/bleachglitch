
#include "mlx.h"
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_key(int key, void *id[2])
{
	int	x, y;

	ft_putchar('X');
	y = 80;
	while (y <= 280)
	{
		x = 80;
		while (x <= 280)
		{
			mlx_pixel_put(id[0], id[1], x, y, 0x00000000);
			x++;
		}
		y++;
	}
	return 0;
}

int	main(void)
{
	void	*id[2];
	int		x, y;

	id[0] = mlx_init();
	id[1] = mlx_new_window(id[0], 360, 640, "test");
	y = 60;
	while (y <= 300)
	{
		x = 60;
		while (x <= 300)
		{
			mlx_pixel_put(id[0], id[1], x, y, 0x00ffffff);
			x++;
		}
		y++;
	}
	mlx_key_hook(id[1], ft_key, id);
	mlx_loop(id[0]);
}
