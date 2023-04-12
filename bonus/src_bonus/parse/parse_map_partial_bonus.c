/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_partial_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 07:59:46 by rlins             #+#    #+#             */
/*   Updated: 2023/04/12 12:23:33 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	spaces_to_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (is_white_space(data->map[i][j]) == true)
			j++;
		while (data->map[i][j])
		{
			if (data->map[i][j] == C_WHITE_S)
				data->map[i][j] = C_WALL;
			j++;
		}
		i++;
	}
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
