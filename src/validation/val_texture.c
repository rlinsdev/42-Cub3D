/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:28:51 by rlins             #+#    #+#             */
/*   Updated: 2023/03/14 10:15:59 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	valid_texture(t_data *data, t_texture_det *text)
{
	if (!text->north || !text->south || !text->east || !text->west)
		return (error_msg(ERR_TEXT_MAP, 12));
	if (!text->ceiling || !text->floor)
		return (error_msg(ERR_TEXT_COL, 13));
	if (!val_file_path(text->north) || !val_file_path(text->south)
	 	|| !val_file_path(text->east) || !val_file_path(text->west))
		return (error_msg(ERR_TEXT_PATH, 14));

	return (0);
}
