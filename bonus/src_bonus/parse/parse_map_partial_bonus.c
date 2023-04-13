/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_partial_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 07:59:46 by rlins             #+#    #+#             */
/*   Updated: 2023/04/13 17:06:46 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	space_with_wall(char **map, int i, int j)
{
	if (map[i][j] == '0' && (map[i][j + 1] == ' ' || map[i][j - 1] == ' '))
		return (true);
	return (false);
}

static bool	is_surrounded_by_spaces(t_data *d, int i, int j)
{
	if (d->map == NULL || i < 0 || j < 0)
		return (false);
	if (d->map[i][j] != '0')
		return (false);
	if (i + 1 >= d->map_det.height || j + 1 >= d->map_det.width
		|| i - 1 < 0 || j - 1 < 0)
		return (false);
	if (is_white_space(d->map[i + 1][j]) || is_white_space(d->map[i][j + 1])
		|| is_white_space(d->map[i][j - 1]) || is_white_space(d->map[i - 1][j]))
		return (true);
	return (false);
}

void	spaces_to_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (space_with_wall(data->map, i, j) == true)
				exit_cube(data, error_msg("Map is not closed", 0));
			if (is_surrounded_by_spaces(data, i, j) == true)
				exit_cube(data, error_msg("Map is not closed", 0));
			j++;
		}
		i++;
	}
}
