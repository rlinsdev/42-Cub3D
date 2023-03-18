/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:24:23 by lucas             #+#    #+#             */
/*   Updated: 2023/03/18 04:56:13 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handles_all_hooks(t_data *data)
{
	// não é necessário, mas depois quero tentar fazer o resize funcionar
	// mlx_expose_hook(data->view.win, handle_hook_resize, data);

		mlx_hook(data->view.win, 17, 1L << 17, handle_hook_close, data);
	mlx_hook(data->view.win, 2, 1L << 0, handle_hook_key, data);
	mlx_loop_hook(data->view.mlx, ray_loop, data);

}

void 	ft_mlx_init_img(t_view	*view)
{
	view->screen.img = mlx_new_image(view->mlx, WIDTH, HEIGHT);
	view->minimap.img = mlx_new_image(view->mlx, WIDTH, HEIGHT);
	view->minimap.addr = ft_mlx_get_addr(&view->minimap);
	view->screen.addr = ft_mlx_get_addr(&view->screen);
}

void ft_mlx_render(t_data *data)
{
	t_view	*view;

	view = &data->view;
	mlx_put_image_to_window(view->mlx, view->win, view->screen.img, 0, 0);
	mlx_put_image_to_window(view->mlx, view->win, view->minimap.img, 0, 0);

}

void	ft_mlx_init(t_data *data)
{
	t_view	*view;

	view = &data->view;
	view->mlx = mlx_init();
	view->win = mlx_new_window(view->mlx, WIDTH, HEIGHT, "Cub3D");
	ft_mlx_init_img(view);

	handles_all_hooks(data);
}
