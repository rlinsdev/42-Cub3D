#include "cub3d.h"

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
	int		pixel_x;
	int		pixel_y;
	int		color;
	double	multiplier;

	pixel_x = 0;
	color = ft_mlx_rgb_to_int(34, 139, 34);
	while (pixel_x < WIDTH)
	{
		multiplier = 2 * (double)pixel_x / (double)WIDTH - 1;
		pixel_y = HEIGHT / 2;
		while (pixel_y < HEIGHT)
		{

			ft_mlx_pixel_put(&data->view.screen, pixel_x, pixel_y, color);
			pixel_y++;
		}
		pixel_x++;
	}
}

static void	draw_minimap_square(t_data *data, int x, int y, int color, int size)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = 0;
	while (pixel_x < size)
	{
		pixel_y = 0;
		while (pixel_y < size)
		{
			ft_mlx_pixel_put(&data->view.minimap, x * size + pixel_x, y * size + pixel_y, color);
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
	while (pixel_x < data->map_det.width)
	{
		pixel_y = 0;
		while (pixel_y < data->map_det.height)
		{
			if (data->map[pixel_y][pixel_x] == '1')
				draw_minimap_square(data, pixel_x, pixel_y, ft_mlx_rgb_to_int(0,
							255, 0), 5);
			else if (data->map[pixel_y][pixel_x] == '2')
				draw_minimap_square(data, pixel_x, pixel_y,
						ft_mlx_rgb_to_int(255, 0, 0), 5);
			pixel_y++;
		}
		pixel_x++;
	}
}

void draw_wall(t_data *data, int pixel)
{
	int	pixel_y;
	int	color;

	if (data->ray.hit_side == 0)
		color = ft_mlx_rgb_to_int(255, 0, 0);
	else
		color = ft_mlx_rgb_to_int(128, 0, 0);

	pixel_y = data->ray.line_start;
	while (pixel_y < data->ray.line_end)
	{
		ft_mlx_pixel_put(&data->view.screen, pixel, pixel_y, color);
		pixel_y++;
	}
}
