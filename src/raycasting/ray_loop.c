#include "cub3d.h"

// remove esse map e use o map do data
// documentar o codigo!!!



void	calc_raycast(t_data *data)
{
	int	pixel;

	pixel = 0;
	while (pixel < WIDTH)
	{
		calc_camera(&data->ray, pixel);
		calc_delta(&data->ray);
		calc_side_x(&data->ray);
		calc_side_y(&data->ray);
		calc_dda(&data->ray, &data->view, data->map);
		calc_perpendicular(&data->ray);
		draw_wall(data, pixel);
		pixel++;
	}
	ft_mlx_put_img(&data->view, &data->view.screen, 0, 0);
}

int	ray_loop(t_data *data)
{
	draw_ceiling(data);
	draw_floor(data);
	calc_raycast(data);
	return (SUCCESS);
}
