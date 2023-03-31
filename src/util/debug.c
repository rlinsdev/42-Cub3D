/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:20:05 by rlins             #+#    #+#             */
/*   Updated: 2023/03/31 18:14:30 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	debug_player(t_player *p);
static void	debug_ray(t_ray *r);

/**
 * @brief Show the values of variables in player structure
 * @param p Player struucture
 */
static void	debug_player(t_player *p)
{
	printf("\n****Player****\n");
	printf("dir: %d\n", p->dir);
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
	printf("HitSide: %d\n", r->hit_side);
}

void	debug(t_data *data)
{
	debug_player(&data->player);
	debug_ray(&data->ray);
}
