/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:20:05 by rlins             #+#    #+#             */
/*   Updated: 2023/03/30 16:05:54 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	debug_player(t_player *p);
static void	debug_ray(t_ray *r);


//TODO:L Implementar
static void	debug_player(t_player *p)
{
	printf("\n****Player****\n");
	printf("pos_x: %f\n", p->pos_x);
}

/**
 * @brief
 *
 * @param r
 */
static void	debug_ray(t_ray *r)
{
	printf("\n****Ray****\n");
	printf("HitSide: %s\n", r->hit_side ? "true" : "false");
}

void	debug(t_data *data)
{
	debug_player(&data->player);
	debug_ray(&data->ray);
}
