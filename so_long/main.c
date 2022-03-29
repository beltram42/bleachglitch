/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:25:37 by alambert          #+#    #+#             */
/*   Updated: 2022/03/29 19:00:23 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;

	mlx = mlx_init();
	//mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	//mlx_loop(mlx);
	img = mlx_new_image(mlx, 1920, 1080);
}*/

/*
#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(void)
{
	void	*mlx;
	t_data	img;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
}*/

#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
/*
#include <stdlib.h>
#include <mlx.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
    mlx_loop(mlx_ptr);
	//mlx_destroy_window(mlx_ptr, win_ptr);
	//mlx_destroy_display(mlx_ptr);
	//free(mlx_ptr);
}
*/
/*
#include <stdlib.h>
#include <mlx.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

#define MLX_ERROR 1

int main(void)
{
    void    *mlx_ptr;
    void    *win_ptr;

    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
        return (MLX_ERROR);
    win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
    if (win_ptr == NULL)
    {
        free(win_ptr);
        return (MLX_ERROR);
    }
    while (1)
        ;
    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
}
*/