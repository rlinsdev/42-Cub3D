/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:20:05 by rlins             #+#    #+#             */
/*   Updated: 2023/04/04 10:08:38 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	debug_player(t_player *p);
static void	debug_ray(t_ray *r);
static void	debug_text(t_texture_det *t);

/**
 * @brief Show the values of variables in player structure
 * @param p Player structure
 */
static void	debug_player(t_player *p)
{
	printf("\n****Player****\n");
	printf("dir: %c\n", p->dir);
	printf("pos_x: %f\n", p->pos_x);
	printf("pos_y: %f\n", p->pos_y);
	printf("dir_x: %f\n", p->dir_x);
	printf("dir_y: %f\n", p->dir_y);
	printf("plane_x: %f\n", p->plane_x);
	printf("plane_y: %f\n", p->plane_y);
	printf("move_x: %d\n", p->move_x);
	printf("move_y: %d\n", p->move_y);
	printf("has_moved: %d\n", p->has_moved);
	printf("rotate: %d\n", p->rotate);
}

/**
 * @brief Show the values of variables in ray structure
 * @param r Ray Structure
 */
static void	debug_ray(t_ray *r)
{
	printf("\n****Ray****\n");
	printf("multiplier: %f\n", r->multiplier);
	printf("dir_x: %f\n", r->dir_x);
	printf("dir_y: %f\n", r->dir_y);
	printf("map_x: %d\n", r->map_x);
	printf("map_y: %d\n", r->map_y);
	printf("step_x: %d\n", r->step_x);
	printf("step_y: %d\n", r->step_y);
	printf("side_dist_x:%f\nside_dist_y:%f\n", r->side_dist_x, r->side_dist_y);
	printf("delta_dist_x: %f\n", r->delta_dist_x);
	printf("delta_dist_y: %f\n", r->delta_dist_y);
	printf("perp_dist: %f\n", r->perp_dist);
	printf("wall_x: %f\n", r->wall_x);
	printf("hit_side: %d\n", r->hit_side);
	printf("line_height: %d\n", r->line_height);
	printf("draw_start: %d\n", r->draw_start);
	printf("draw_end: %d\n", r->draw_end);
}

static void	debug_text(t_texture_det *t)
{
	printf("\n****Texture****\n");
	printf("North Path: %s\n", t->north);
	printf("South Path: %s\n", t->south);
	printf("East Path: %s\n", t->east);
	printf("West Path: %s\n", t->west);
	printf("floor: %i, %i, %i\n", t->floor[0], t->floor[1], t->floor[2]);
	printf("ceil: %i, %i, %i\n", t->ceiling[0], t->ceiling[1], t->ceiling[2]);
	printf("hex_floor: %ld\n", t->hex_floor);
	printf("hex_ceiling: %ld\n", t->hex_ceiling);
	printf("index: %i\n", t->index);
	printf("step: %f\n", t->step);
}

void	debug(t_data *data)
{
	debug_text(&data->texture_det);
	debug_player(&data->player);
	debug_ray(&data->ray);
}
