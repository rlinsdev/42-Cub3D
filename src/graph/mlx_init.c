/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:24:23 by lucas             #+#    #+#             */
/*   Updated: 2023/03/30 11:40:58 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void 	ft_mlx_init_img(t_view	*view)
{
	view->screen.img = mlx_new_image(view->mlx, WIDTH, HEIGHT);
	view->screen.addr = (int *)ft_mlx_get_addr(&view->screen);
}

void	ft_mlx_init(t_data *data)
{
	t_view	*view;

	view = &data->view;
	view->mlx = mlx_init();
	init_textures(data); //TODO:L Ver se é necessário inicializar as texturas mesmo ou só o BZero ta de boas
	set_player_direction(&data->player);
	view->win = mlx_new_window(view->mlx, WIDTH, HEIGHT, TITLE);
	ft_mlx_init_img(view);
	render_images(data);
	handles_all_hooks(data);
}
