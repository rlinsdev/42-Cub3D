/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:04:51 by rlins             #+#    #+#             */
/*   Updated: 2023/04/06 17:16:58 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_raycast(t_data *data)
{
	int	pixel;

	pixel = 0;
	while (pixel < WIDTH)
	{
		setup_raycast_info(pixel, &data->ray, &data->player);
		calc_dda(&data->ray, &data->player);
		perform_dda(data, &data->ray);
		calculate_line_height(&data->ray, &data->player);
		update_text_pixels(data, &data->texture_det, &data->ray, pixel);
		pixel++;
	}
}

static void	render_frame(t_data *d)
{
	d->view.y = 0;
	while (d->view.y < HEIGHT)
	{
		d->view.x = 0;
		while (d->view.x < WIDTH)
		{
			if (d->texture_pixels[d->view.y][d->view.x] > 0)
				d->view.color = d->texture_pixels[d->view.y][d->view.x];
			else if (d->view.y < HEIGHT / 2)
				d->view.color = d->texture_det.hex_ceiling;
			else if (d->view.y < HEIGHT - 1)
				d->view.color = d->texture_det.hex_floor;
			set_image_pixel(&d->view.screen, d->view.x, \
			d->view.y, d->view.color);
			d->view.x++;
		}
		d->view.y++;
	}
}

int	render_images(t_data *data)
{
	init_texture_pixels(data);
	calc_raycast(data);
	render_frame(data);
	mlx_put_image_to_window(data->view.mlx, \
	data->view.win, data->view.screen.img, 0, 0);
	return (0);
}
