/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:20:05 by rlins             #+#    #+#             */
/*   Updated: 2023/03/28 10:25:35 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	debug_ray(t_ray *r)
{
	printf("pos[0]: %f\n", r->pos[0]);
	printf("pos[1]: %f\n", r->pos[1]);
	printf("dir[0]: %f\n", r->dir[0]);
	printf("dir[1]: %f\n", r->dir[1]);
	printf("plane[0]: %f\n", r->plane[0]);
	printf("plane[1]: %f\n\n", r->plane[1]);

	// r->plane[0] = 0;
	// r->plane[1] = 0.66;
}
