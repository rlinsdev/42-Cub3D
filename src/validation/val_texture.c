/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:28:51 by rlins             #+#    #+#             */
/*   Updated: 2023/03/14 09:44:59 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	valid_texture(t_data *data, t_texture_det *text)
{
	if (!text->north || !text->east || !text->east || !text->west)
		return (error_msg(ERR_TEXT_MAP, 12));


	return (0);
}
