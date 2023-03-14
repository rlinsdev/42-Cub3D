#include "cub3d.h"

void	set_backgound(t_data *data)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	color = ft_mlx_rgb_to_int(190, 190, 255);
	while (x < data->view.screen_width)
	{
		y = 0;
		while (y < data->view.screen_height)
		{
			ft_mlx_pixel_put(&data->view.screen, x, y, color);
			y++;
		}
		x++;
	}
}

void	draw_rectangle(t_data *data, int size[2], int pos[2])
{
	int	x;
	int	y;

	x = 0;
    int color;

    color = ft_mlx_rgb_to_int(102, 102, 102);
	while (x < size[0])
	{
		y = 0;
		while (y < size[1])
		{
			ft_mlx_pixel_put(&data->view.screen, pos[0] + x, pos[1] + y, color);
			y++;
		}
		x++;
	}
}

void	draw_minimap(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map_det.width)
	{
		y = 0;
		while (y < data->map_det.height)
		{
			if (data->map[y][x] == '1')
			{
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						ft_mlx_pixel_put(&data->view.screen, x * 10 + i, y * 10
								+ j, 0x00FF0000);
					}
				}
			}
			y++;
		}
		x++;
	}
}

int	ray_loop(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	set_backgound(data);
	draw_rectangle(data, (int[2]){WIDTH, HEIGHT / 2}, (int[2]){0, HEIGHT / 2});
	ft_mlx_put_img(&data->view, &data->view.screen, 0, 0);
	return (SUCCESS);
}
