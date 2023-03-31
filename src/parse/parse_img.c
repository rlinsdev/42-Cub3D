/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:50:10 by rlins             #+#    #+#             */
/*   Updated: 2023/03/30 22:13:17 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_img(t_data *data, t_img *i, int width, int height)
{
	i->img = mlx_new_image(data->view.mlx, width, height);
	if (i->img == NULL)
		exit_and_free(data, error_msg(ERR_MLX_IMG, 20));
	i->addr = (int *)mlx_get_data_addr(i->img, &i->pixel_bits,
			&i->size_line, &i->endian);
	return ;
}

void	init_texture_img(t_data *data, t_img *image, char *path)
{
	image->img = mlx_xpm_file_to_image(data->view.mlx, path,
			&data->texture_det.size, &data->texture_det.size);
	if (image->img == NULL)
		exit_and_free(data, error_msg(ERR_MLX_IMG, 21));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

