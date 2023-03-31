/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map_partial.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:38:36 by rlins             #+#    #+#             */
/*   Updated: 2023/03/31 17:43:42 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_position_is_valid(t_data *data, char **map)
{
	int	i;
	int	j;

	i = (int)data->player.pos_y;
	j = (int)data->player.pos_x;
	if (ft_strlen(map[i - 1]) < (size_t)j || ft_strlen(map[i + 1]) < (size_t)j)
		return (FAILURE);
	return (SUCCESS);
}
