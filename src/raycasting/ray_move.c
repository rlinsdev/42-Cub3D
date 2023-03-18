#include "cub3d.h"

int	ray_rotate(t_ray *r, int keycode)
{
	if (keycode == RIGHT_KEY_CONST)
	{
		r->dir[0] = r->dir[0] * cos(0.1) - r->dir[1] * sin(0.1);
		r->dir[1] = r->dir[0] * sin(0.1) + r->dir[1] * cos(0.1);
		r->plane[0] = r->plane[0] * cos(0.1) - r->plane[1] * sin(0.1);
		r->plane[1] = r->plane[0] * sin(0.1) + r->plane[1] * cos(0.1);
	}
	if (keycode == LEFT_KEY_CONST)
	{
		r->dir[0] = r->dir[0] * cos(-0.1) - r->dir[1] * sin(-0.1);
		r->dir[1] = r->dir[0] * sin(-0.1) + r->dir[1] * cos(-0.1);
		r->plane[0] = r->plane[0] * cos(-0.1) - r->plane[1] * sin(-0.1);
		r->plane[1] = r->plane[0] * sin(-0.1) + r->plane[1] * cos(-0.1);
	}
}

int	ray_move(t_ray *r, int keycode)
{
	if (keycode == W_KEY_CONST)
	{
		r->pos[0] += r->dir[0] * 0.1;
		r->pos[1] += r->dir[1] * 0.1;
	}
	if (keycode == S_KEY_CONST)
	{
		r->pos[0] -= r->dir[0] * 0.1;
		r->pos[1] -= r->dir[1] * 0.1;
	}
	if (keycode == A_KEY_CONST)
	{
		r->pos[0] -= r->plane[0] * 0.1;
		r->pos[1] -= r->plane[1] * 0.1;
	}
	if (keycode == D_KEY_CONST)
	{
		r->pos[0] += r->plane[0] * 0.1;
		r->pos[1] += r->plane[1] * 0.1;
	}
}
