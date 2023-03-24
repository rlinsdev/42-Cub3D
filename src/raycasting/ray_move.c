#include "cub3d.h"



int	ray_rotate(t_ray *r, int keycode)
{
	if (keycode == RIGHT_KEY_CONST)
	{
		r->dir[0] = r->dir[0] * cos((4.9 * M_PI) / 180) + r->dir[1] * -sin((4.9 * M_PI) / 180);
		r->dir[1] = r->dir[0] * sin((4.9 * M_PI) / 180) + r->dir[1] * cos((4.9 * M_PI) / 180);
		r->plane[0] = r->plane[0] * cos((4.9 * M_PI) / 180) + r->plane[1] * -sin((4.9 * M_PI) / 180);
		r->plane[1] = r->plane[0] * sin((4.9 * M_PI) / 180) + r->plane[1] * cos((4.9 * M_PI) / 180);
	}
	else if (keycode == LEFT_KEY_CONST)
	{
		r->dir[0] = r->dir[0] * cos((-4.9 * M_PI) / 180) + r->dir[1] * -sin((-4.9 * M_PI) / 180);
		r->dir[1] = r->dir[0] * sin((-4.9 * M_PI) / 180) + r->dir[1] * cos((-4.9 * M_PI) / 180);
		r->plane[0] = r->plane[0] * cos((-4.9 * M_PI) / 180) + r->plane[1] * -sin((-4.9 * M_PI) / 180);
		r->plane[1] = r->plane[0] * sin((-4.9 * M_PI) / 180) + r->plane[1] * cos((-4.9 * M_PI) / 180);
	}
	return (true);
}

int	check_collision(t_ray *r, float dx, float dy, char **map)
{
	int	map_x;
	int	map_y;

	map_x = (int)(r->pos[0] + dx);
	map_y = (int)(r->pos[1] + dy);
	if (map[map_x][map_y] == C_BACK_G)
	{
		r->pos[0] += dx;
		r->pos[1] += dy;
		return (true);
	}
	return (false);
}

int	ray_move(t_ray *r, int keycode, char **map)
{
	if (keycode == W_KEY_CONST)
		check_collision(r, r->dir[0] * r->speed, r->dir[1] * r->speed, map);
	else if (keycode == S_KEY_CONST)
		check_collision(r, -r->dir[0] * r->speed, -r->dir[1] * r->speed, map);
	else if (keycode == A_KEY_CONST)
		check_collision(r, -r->plane[0] * r->speed, -r->plane[1] * r->speed, map);
	else if (keycode == D_KEY_CONST)
		check_collision(r, r->plane[0] * r->speed, r->plane[1] * r->speed, map);
	return (0);
}

int	ray_resert(t_ray *r)
{
	r->dir[0] = 0;
	r->dir[1] = -1;
	r->plane[0] = 0.66;
	r->plane[1] = 0;
}
