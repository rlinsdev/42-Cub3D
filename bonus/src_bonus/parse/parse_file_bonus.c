/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:32:47 by rlins             #+#    #+#             */
/*   Updated: 2023/04/07 20:46:51 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	handle_file_infos(t_data *data, char **file, int i, int j);

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
			while (data->map_det.file[i][j] == '\n')
				i++;
			ret = handle_file_infos(data, data->map_det.file, i, j);
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
 * map. Check if the value is ray position. Check if is the value color to
 * floor or ceiling. Check if is a map data.
 * @param data Data structure
 * @param file File passed by param in program
 * @param i Index of line
 * @param j Index of next value in line
 * @return int Integer to handle if we must continue in loop, exit, go to next
 * line.
 */
static int	handle_file_infos(t_data *data, char **file, int i, int j)
{
	while (is_white_space(file[i][j]) == true)
		j++ ;
	if (ft_isdigit(file[i][j]) == false)
	{
		if (file[i][j + 1] != C_WHITE_S && file[i][j + 1])
		{
			if (parse_tex_dir(&data->texture_det, file[i], j) == false)
				return (error_msg(ERR_TEXT, FAILURE));
			return (BREAK);
		}
		else
		{
			if (parse_tex_color(&data->texture_det, file[i], j) != 0)
				return (FAILURE);
			return (BREAK);
		}
	}
	else if (ft_isdigit(file[i][j]) == true)
	{
		data->map_det.start_i_map = i;
		if (create_map(data) == false)
			return (error_msg(ERR_MAP, 6));
		return (SUCCESS);
	}
	return (CONTINUE);
}

bool	is_white_space(char c)
{
	if (c == C_WHITE_S || c == '\t' || c == '\n')
		return (true);
	return (false);
}
