#include "cub3d.h"

void	handles_all_hooks(t_data *data)
{
	mlx_hook(data->view.win, 17, 1L << 17, handle_hook_close, data);
	mlx_key_hook(data->view.win, handle_hook_key, data);
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
	view->win = mlx_new_window(view->mlx, WIDTH, HEIGHT, TITLE);
	ft_mlx_init_img(view);
	mlx_put_image_to_window(view->mlx, view->win, view->screen.img, 0, 0);
	mlx_put_image_to_window(view->mlx, view->win, view->minimap.img, 0, 0);
	handles_all_hooks(data);
}
