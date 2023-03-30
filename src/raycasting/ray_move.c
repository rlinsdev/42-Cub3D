#include "cub3d.h"

//TODO:L Essa classe acho q vai de  base.... O raio não mexe... Melhor deixar na estrutura do player movendo, não o raio

// int	ray_move_left(t_ray *r, char **map)
// {
// 	int	new_pos[2];

// 	new_pos[X] = r->pos[X] - r->plane[X] * r->speed;
// 	new_pos[Y] = r->pos[Y] - r->plane[Y] * r->speed;
// 	if (map[new_pos[X]][new_pos[Y]] == C_BACK_G)
// 	{
// 		r->pos[X] -= r->plane[X] * r->speed;
// 		r->pos[Y] -= r->plane[Y] * r->speed;
// 	}
// 	return (EXIT_SUCCESS);
// }

// int	ray_move_right(t_ray *r, char **map)
// {
// 	int	new_pos[2];

// 	new_pos[X] = r->pos[X] + r->plane[X] * r->speed;
// 	new_pos[Y] = r->pos[Y] + r->plane[Y] * r->speed;
// 	if (map[new_pos[X]][new_pos[Y]] == C_BACK_G)
// 	{
// 		r->pos[X] += r->plane[X] * r->speed;
// 		r->pos[Y] += r->plane[Y] * r->speed;
// 	}
// 	return (EXIT_SUCCESS);
// }

// int	ray_move_up(t_ray *r, char **map)
// {
// 	int	new_pos[2];

// 	new_pos[X] = r->pos[X] + r->dir[X] * r->speed;
// 	new_pos[Y] = r->pos[Y] + r->dir[Y] * r->speed;
// 	if (map[new_pos[X]][new_pos[Y]] == C_BACK_G)
// 	{
// 		r->pos[X] += r->dir[X] * r->speed;
// 		r->pos[Y] += r->dir[Y] * r->speed;
// 	}
// 	return (EXIT_SUCCESS);
// }

// int	ray_move_down(t_ray *r, char **map)
// {
// 	int	new_pos[2];

// 	new_pos[X] = r->pos[X] - r->dir[X] * r->speed;
// 	new_pos[Y] = r->pos[Y] - r->dir[Y] * r->speed;
// 	if (map[new_pos[X]][new_pos[Y]] == C_BACK_G)
// 	{
// 		r->pos[X] -= r->dir[X] * r->speed;
// 		r->pos[Y] -= r->dir[Y] * r->speed;
// 	}
// 	return (EXIT_SUCCESS);
// }
