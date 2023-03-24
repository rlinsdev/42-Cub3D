/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:21:54 by rlins             #+#    #+#             */
/*   Updated: 2023/03/24 12:33:38 by rlins            ###   ########.fr       */
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
	r->dir[0] = 0;
	r->dir[1] = 0;
	r->plane[0] = 0;
	r->plane[1] = 0;
	r->speed = 0.1;
}

void	init_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	init_ray(&data->ray, data);

}
