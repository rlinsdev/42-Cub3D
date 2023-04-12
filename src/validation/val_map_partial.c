/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map_partial.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:38:36 by rlins             #+#    #+#             */
/*   Updated: 2023/04/12 12:19:27 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	pos_is_valid(t_data *data, char **map)
{
	int	i;
	int	j;

	i = (int)data->player.pos_y;
	j = (int)data->player.pos_x;
	if (ft_strlen(map[i - 1]) < (size_t)j || ft_strlen(map[i + 1]) < (size_t)j)
		return (FAILURE);
	return (SUCCESS);
}

bool	is_map_sur_walls2(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (i > 0 && !data->map[i - 1][j] && data->map[i][j] != C_WALL)
				return (false);
			else if (i < data->map_det.height -1 && !data->map[i + 1][j]
					&& data->map[i][j] != C_WALL)
				return (false);
		}
	}
	return (true);
}
