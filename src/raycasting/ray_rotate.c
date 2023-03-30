#include "cub3d.h"
//TODO:LTalvez não exita mais esta classe... quem rotaciona é o player...

// int	ray_rotate_right(t_ray *r)
// {
// 	double	old_var;

// 	old_var = r->dir[0];
// 	r->dir[0] = r->dir[0] * cos(-0.1) - r->dir[1] * sin(-0.1);
// 	r->dir[1] = old_var * sin(-0.1) + r->dir[1] * cos(-0.1);
// 	old_var = r->plane[0];
// 	r->plane[0] = r->plane[0] * cos(-0.1) - r->plane[1] * sin(-0.1);
// 	r->plane[1] = old_var * sin(-0.1) + r->plane[1] * cos(-0.1);
// 	return (EXIT_SUCCESS);
// }

// int	ray_rotate_left(t_ray *r)
// {
// 	double	old_var;

// 	old_var = r->dir[0];
// 	r->dir[0] = r->dir[0] * cos(0.1) - r->dir[1] * sin(0.1);
// 	r->dir[1] = old_var * sin(0.1) + r->dir[1] * cos(0.1);
// 	old_var = r->plane[0];
// 	r->plane[0] = r->plane[0] * cos(0.1) - r->plane[1] * sin(0.1);
// 	r->plane[1] = old_var * sin(0.1) + r->plane[1] * cos(0.1);
// 	return (EXIT_SUCCESS);
// }

// // TODO: Remover - não usado em nenhum lugar
// int	ray_resert(t_ray *r)
// {
// 	r->pos[0] = 5;
// 	r->pos[1] = 5;
// 	r->dir[0] = 0;
// 	r->dir[1] = -1;
// 	r->plane[0] = 0.66;
// 	r->plane[1] = 0;
// 	return (EXIT_SUCCESS);
// }
