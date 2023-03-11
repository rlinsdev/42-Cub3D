/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:32:47 by rlins             #+#    #+#             */
/*   Updated: 2023/03/11 11:52:12 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	ignore_whitespaces_get_info(t_data *data, int i, int j);

int	file_to_variable(t_data *data)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (data->map_det.file[i] != NULL)
	{
		j = 0;
		while (data->map_det.file[i][j])
		{
			ret = ignore_whitespaces_get_info(data, i, j);
			if (ret == BREAK)
				break ;
			else if (ret == FAILURE)
				return (FAILURE);
			else if (ret == SUCCESS)
				return (SUCCESS);
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * @brief If map start with blank space, just keep going to the next item in
 * map. Check if the value is Player position. Check if is the value color to
 * floor or ceiling. Check if is a map data.
 * @param data Data structure
 * @param i Index of line
 * @param j Index of next value in line
 * @return int Integer to handle if we must continue in loop, exit, go to next
 * line.
 */
static int	ignore_whitespaces_get_info(t_data *data, int i, int j)
{
	if (is_white_space(data->map_det.file[i][j]) == true)
		j++ ;
	if (!ft_isdigit(data->map_det.file[i][j]))
	{
		if (data->map_det.file[i][j + 1])
		{
			if (parse_tex_dir(&data->texture_det, data->map_det.file[i], j) == false)
				return (error_msg(ERR_TEXT, 9));
			return (BREAK);
		}
		else
		{
			// ISCollorTextureCellFloor
			return (BREAK);
		}
	}
	else if (ft_isdigit(data->map_det.file[i][j]))
	{
		bool	result;

		data->map_det.start_i_map = i;
		result = create_map(data);
		if (result == false)
			return (error_msg(ERR_MAP, 6));
		return (SUCCESS); // TODO: Ver se isso não vai dar merda qdo o mapa estiver fora de ordem.
	}
	return (CONTINUE);
}

bool	is_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (true);
	return (false);
}
