/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:21:54 by rlins             #+#    #+#             */
/*   Updated: 2023/03/17 16:28:50 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>


void init_ray(t_ray *r)
{
	r->pos[0] = 6;
	r->pos[1] = 6;
	r->dir[0] = -1;
	r->dir[1] = 0;
	r->plane[0] = 0.66;
	r->plane[1] = 0;


}

void	init_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	init_ray(&data->ray);

}
