/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 07:54:08 by rlins             #+#    #+#             */
/*   Updated: 2023/03/10 12:56:04 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static bool	is_map_sur_walls(t_data *data);

int	valid_map(t_data *data)
{
	if (!data->map)
		return (error_msg(ERR_MAP7, 7));
	if (is_map_sur_walls(data) == false)
		return (error_msg(ERR_MAP8, 8));
	return (0);
}

/**
 * @brief Validate the Walls surrounded in map.
 * First look to first line.
 * Then, look in the last (bottom) line
 * Then, verify the first and the last column in each line
 *
 * TODO:Lins - Ainda está dando erro quando há um espaço em branco na borda
 * do mapa, Entender como tratar isso aí. Ex de bottom:
 * 11111111 1111111 111111111111
 * @param data
 * @return true
 * @return false
 */
static bool	is_map_sur_walls(t_data *data)
{
	int	i;
	int	j;
	int col_size;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		col_size = ft_strlen(data->map[i]);
		while (data->map[i][j])
		{
			if (i == 0 && data->map[i][j] != '1')
				return (false);
			else if (i == data->map_det.height -1 && data->map[i][j] != '1')
				return (false);
			else if (j == 0 && data->map[i][j] != '1')
				return (false);
			else if (j == (col_size - 1) && data->map[i][j] != '1')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
