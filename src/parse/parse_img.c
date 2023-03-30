/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:50:10 by rlins             #+#    #+#             */
/*   Updated: 2023/03/30 18:15:37 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_img_clean(t_img *img);

void	init_img(t_data *data, t_img *i, int width, int height)
{
	init_img_clean(i);
	i->img = mlx_new_image(data->view.mlx, width, height);
	if (i->img == NULL)
		exit_and_free(data, error_msg(ERR_MLX_IMG, 20));
	i->addr = (int *)mlx_get_data_addr(i->img, &i->pixel_bits,
			&i->size_line, &i->endian);
	return ;
}

//TODO:L Setup, não init
void	init_texture_img(t_data *data, t_img *image, char *path)
{
	init_img_clean(image);
	image->img = mlx_xpm_file_to_image(data->view.mlx, path, &data->texture_det.size, &data->texture_det.size);
	if (image->img == NULL)
		exit_and_free(data, error_msg(ERR_MLX_IMG, 21));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits, &image->size_line, &image->endian);
	return ;
}

//TODO:L Ver se precisa disso mesmo
static void	init_img_clean(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
}
