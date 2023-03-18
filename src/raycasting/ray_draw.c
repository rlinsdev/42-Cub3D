#include "cub3d.h"

int		worldMap[10][10] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 0, 1, 0, 0, 0, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void	draw_backgound(t_data *data)
{
	int	pixel_x;
	int	pixel_y;
	int	color;

	pixel_x = 0;
	color = ft_mlx_rgb_to_int(190, 190, 255);
	while (pixel_x < WIDTH)
	{
		pixel_y = 0;
		while (pixel_y < HEIGHT)
		{
			ft_mlx_pixel_put(&data->view.screen, pixel_x, pixel_y, color);
			pixel_y++;
		}
		pixel_x++;
	}
}

void	draw_ground(t_data *data)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = 0;
	while (pixel_x < WIDTH)
	{
		pixel_y = HEIGHT / 2;
		while (pixel_y < HEIGHT)
		{
			ft_mlx_pixel_put(&data->view.screen, pixel_x, pixel_y,
					COLOR_GROUND);
			pixel_y++;
		}
		pixel_x++;
	}
}

void	draw_minimap_square(t_img *img, int x, int y, int color)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = 0;
	while (pixel_x < 10)
	{
		pixel_y = 0;
		while (pixel_y < 10)
		{
			ft_mlx_pixel_put(img, x * 10 + pixel_x, y * 10 + pixel_y, color);
			pixel_y++;
		}
		pixel_x++;
	}
}

void	draw_minimap(t_data *data)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = 0;
	while (pixel_x < 10)
	{
		pixel_y = 0;
		while (pixel_y < 10)
		{
			if (worldMap[pixel_y][pixel_x])
				draw_minimap_square(&data->view.screen, pixel_x, pixel_y,
						COLOR_MINIMAP);
			else if (!worldMap[pixel_y][pixel_x])
				draw_minimap_square(&data->view.screen, pixel_x, pixel_y,
						COLOR_BORDER_MINIMAP);
			pixel_y++;
		}
		pixel_x++;
	}
}

void	draw_wall(t_data *data, int pixel)
{
	int	pixel_y;
	int	color;

	if (data->ray.hit_side == 0)
		color = ft_mlx_rgb_to_int(255, 0, 0);
	else
		color = ft_mlx_rgb_to_int(128, 0, 0);
	pixel_y = data->ray.line_size[0];
	while (pixel_y < data->ray.line_size[1])
	{
		ft_mlx_pixel_put(&data->view.screen, pixel, pixel_y, color);
		pixel_y++;
	}
}
