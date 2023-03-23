/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:21:54 by rlins             #+#    #+#             */
/*   Updated: 2023/03/23 11:00:18 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void init_ray(t_ray *r, t_data *data);

/**
 * @brief
 *
 * @param r
 */
static void init_ray(t_ray *r, t_data *data)
{
	// TODO: Must to do: Atribuir corretamente a posição do player nos eixos X e Y. Hj cravado em 5
	// Tentei atribuir a inicialização do mapa, mas ainda deu problema. No mapa '1-simple-map.cub' da merda.
	// r->pos[X] = data->ray.dir_char;
	// r->pos[Y] = data->ray.dir_char;
	r->pos[0] = 5;
	r->pos[1] = 5;
	r->dir[0] = 0;
	r->dir[1] = -1;
	r->plane[0] = 0.66;
	r->plane[1] = 0;
	r->speed = 0.1;
}

void	init_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	init_ray(&data->ray, data);

}
