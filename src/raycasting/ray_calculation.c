#include "cub3d.h"

int		worldMap2[10][10] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,0,0,1,0,0,0,0,1},
    {1,0,0,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,0,0,0,0,0,0,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,0,0,1,0,0,0,1,1},
    {1,1,1,1,1,1,1,1,1,1}
};

void	calc_ray(t_ray *ray, int pixel)
{
	double	multiplier;

	multiplier = 2 * pixel / (double)WIDTH - 1;
	ray->ray_dir[X] = ray->dir[X] + ray->plane[X] * multiplier;
	ray->ray_dir[Y] = ray->dir[Y] + ray->plane[Y] * multiplier;
}

void	calc_wall_map_pos(t_ray *ray)
{
	ray->wall_map_pos[X] = (int)ray->pos[X];
	ray->wall_map_pos[Y] = (int)ray->pos[Y];
}

void	calc_delta_dist(t_ray *r)
{
	if (r->ray_dir[X] == 0)
	{
		r->delta_dist[X] = 1;
		r->delta_dist[Y] = 0;
	}
	else if (r->ray_dir[Y] == 0)
	{
		r->delta_dist[X] = 0;
		r->delta_dist[Y] = 1;
	}
	else
	{
		r->delta_dist[X] = fabs(1 / r->ray_dir[X]);
		r->delta_dist[Y] = fabs(1 / r->ray_dir[Y]);
	}
}

void	calc_side(t_ray *r)
{
	if (r->ray_dir[X] < 0)
	{
		r->dist_to_side[X] = (r->pos[X] - r->wall_map_pos[X]) * r->delta_dist[X];
		r->step[X] = -1;
	}
	else
	{
		r->dist_to_side[X] = (r->wall_map_pos[X] + 1.0 - r->pos[X])
			* r->delta_dist[X];
		r->step[X] = 1;
	}
	if (r->ray_dir[Y] < 0)
	{
		r->dist_to_side[Y] = (r->pos[Y] - r->wall_map_pos[Y])
			* r->delta_dist[Y];
		r->step[Y] = -1;
	}
	else
	{
		r->dist_to_side[Y] = (r->wall_map_pos[Y] + 1.0 - r->pos[Y])
			* r->delta_dist[Y];
		r->step[Y] = 1;
	}
}

void	calc_dda_line_size(t_ray *r)
{
	r->dda_line_size[X] = r->dist_to_side[X];
	r->dda_line_size[Y] = r->dist_to_side[Y];
}

void	calc_wall_dist(t_ray *r)
{
	r->wall_dist[X] = r->wall_map_pos[X];
	r->wall_dist[Y] = r->wall_map_pos[Y];
}

void	calc_perpendicular_dist(t_ray *r)
{
	if (r->hit_side == false)
		r->perpendicular_dist = abs((r->wall_map_pos[X] - r->pos[X]
					+ (1 - r->step[X]) / 2) / r->ray_dir[X]);
	else
		r->perpendicular_dist = abs((r->wall_map_pos[Y] - r->pos[Y]
					+ (1 - r->step[Y]) / 2) / r->ray_dir[Y]);
	r->wall_line_height = HEIGHT / r->perpendicular_dist;
	r->line_start = HEIGHT / 2 - r->wall_line_height / 2;
	r->line_end = HEIGHT / 2 + r->wall_line_height / 2;

}

void	calc_hit(t_ray *r, t_view *v)
{
	while (true)
	{
		if (r->dda_line_size[X] < r->dda_line_size[Y])
		{
			r->wall_map_pos[X] += r->step[X];
			r->dda_line_size[X] += r->delta_dist[X];
			r->hit_side = false;
		}
		else
		{
			r->wall_map_pos[Y] += r->step[Y];
			r->dda_line_size[Y] += r->delta_dist[Y];
			r->hit_side = true;
		}
		printf("wall_map_pos = %d, %d \n", r->wall_map_pos[X], r->wall_map_pos[Y]);
		if (worldMap2[r->wall_map_pos[X]][r->wall_map_pos[Y]] > 0)
		{
			r->hit = true;
			break ;
		}
	}
}

void	ray_calc(t_data *data)
{
	int		pixel;
	t_ray	*ray;

	pixel = 0;
	ray = &data->ray;
	while (pixel < WIDTH)
	{
		calc_ray(ray, pixel);
		calc_wall_map_pos(ray);
		calc_delta_dist(ray);
		calc_side(ray);
		calc_dda_line_size(ray);
		calc_wall_dist(ray);
		calc_hit(ray, &data->view);
		calc_perpendicular_dist(ray);
		draw_wall(data, pixel);
		pixel++;
	}
}

int	ray_loop(t_data *data)
{
	draw_backgound(data);
	draw_ground(data);
	draw_minimap(data);
	ray_calc(data);
	ft_mlx_put_img(&data->view, &data->view.screen, 0, 0);
	return (SUCCESS);
}
