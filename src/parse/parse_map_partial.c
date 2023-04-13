/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_partial.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 07:59:46 by rlins             #+#    #+#             */
/*   Updated: 2023/04/13 11:50:32 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static bool	space_with_wall(char **map, int i, int j)
{
	if (map[i][j] == '0' && (map[i][j + 1] == ' ' || map[i][j - 1] == ' '))
		return (true);
	return (false);
}

static bool	is_surrounded_by_spaces(char **map, int i, int j, int rows, int cols)
{
	if (map == NULL || i < 0 || j < 0)
	{
		return (false);
	}
	if (map[i][j] != '0')
	{
		return (false);
	}
	if (i + 1 >= rows || j + 1 >= cols || i - 1 < 0 || j - 1 < 0)
	{
		return (false);
	}
	if (map[i + 1][j] == ' ' || map[i][j + 1] == ' ' || map[i][j - 1] == ' '
		|| map[i - 1][j] == ' ')
	{
		return (true);
	}
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
			if (is_surrounded_by_spaces(data->map, i, j, data->map_det.height,
					data->map_det.width) == true)
				exit_cube(data, error_msg("Map is not closed", 0));
			j++;
		}
		i++;
	}
}
