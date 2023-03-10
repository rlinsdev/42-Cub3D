/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:46:34 by rlins             #+#    #+#             */
/*   Updated: 2023/03/09 21:14:06 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	get_map_height(t_data *data);
static bool	get_map_info(t_data *data);
static int	get_map_width(t_map_det *map_det);
static bool	fill_map_tab(t_map_det *map_det, char **map_tab);

bool	create_map(t_data *data)
{
	bool result = get_map_info(data);
	// TODO: Add aqui a mudança de espaço em branco em muro
	return (result);
}

/**
 * @brief Get the map info. Call method to fill map info (start/end) and
 * fill the map variable
 * @param data Data info
 * @return boolean - Success or not
 */
static bool get_map_info(t_data *data)
{
	get_map_height(data);
	data->map = ft_calloc(data->map_det.height + 1, sizeof(char *));
	if (!data->map)
		return (error_msg(ERR_MALC, 2));
	if (fill_map_tab(&data->map_det, data->map) == false)
		return (false);
	return (true);
}

/**
 * @brief Will fill the matrix with the data of map
 * @param map_det Map detail structure
 * @param map_tab Matrix of map
 * @return boolean: Success or not
 */
static bool	fill_map_tab(t_map_det *map_det, char **map_tab)
{
	int		i;
	int		j;
	int		index;

	index = map_det->start_i_map;
	i = 0;
	map_det->width = get_map_width(map_det);
	while (i < map_det->height)
	{
		j = 0;
		map_tab[i] = ft_calloc(map_det->width + 1, sizeof(char));
		if (!map_tab[i])
			return (error_msg(ERR_MALC, 2));
		while (map_det->file[index][j] && map_det->file[index][j] != '\n')
		{
			map_tab[i][j] = map_det->file[index][j];
			j++;
		}
		while (j < map_det->width)
			map_tab[i][j++] = '\0';
		i++;
		index++;
	}
	map_tab[i] = NULL;
	return (true);
}

/**
 * @brief [OK] Get the map width. Some times, the map is not a rectangle, for
 * this, we will look for the highest size here
 * @param map_det Map details structure
 * @return int - Width/size of map
 */
static int	get_map_width(t_map_det *map_det)
{
	int	len;
	int	i;

	i = map_det->start_i_map;
	len = ft_strlen(map_det->file[i]);
	while (map_det->file[i])
	{
		if (ft_strlen(map_det->file[i]) > len)
			len = ft_strlen(map_det->file[i]);
		i++;
	}
	return (len);
}

/**
 * @brief [OK] Get the map height. Update the variable Start/end Index Map too
 * @param data Data structure
 * @return int
 */
static void	get_map_height(t_data *data) // TODO: Eu acho que aqui preciso validar se é cercado de 1
{
	int	i;

	i = data->map_det.start_i_map;
 	while (data->map_det.file[i])
		i++;
	data->map_det.end_i_map = i;
	data->map_det.height = i - data->map_det.start_i_map;
}
