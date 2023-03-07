/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:33:53 by rlins             #+#    #+#             */
/*   Updated: 2023/03/07 14:03:35 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void init_map_handler(t_data *data, char *path)
{
	data->map_det.lines_count = 10; // TODO Calcular isso depois
	data->map_det.path = path;
	// TODO: Dar free neste cara depois
	data->map_det.file = malloc(data->map_det.lines_count + 1 * sizeof(char *));
	if (!data->map_det.file)
	{
		error_msg(ERR_MALL, 2);
		return ;
	}
	data->map_det.fd = open(path, O_RDONLY);
	if (data->map_det.fd < 0)
		error_msg(strerror(errno), 3);
	else
	{
		// TODO: LoadMap
		close(data->map_det.fd);
	}
}
