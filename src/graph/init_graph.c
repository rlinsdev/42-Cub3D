#include <cub3d.h>

int	handle_hook_close(t_data *data)
{
	mlx_destroy_window(data->view.mlx, data->view.win);
	mlx_destroy_display(data->view.mlx);
	free_data(data);
	free(data->view.mlx);
	exit(SUCCESS);
}

void	pix_put_to_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->len_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	handle_hooks(t_data *data)
{
	mlx_hook(data->view.win, 17, 1L << 17, handle_hook_close, data);
}

char	*get_data_addr(t_img *img)
{
	return (mlx_get_data_addr(img->img, &img->bpp, &img->len_line,
			&img->endian));
}

void	create_graphic(t_data *data)
{
	t_view	*view;

	view = &data->view;
	view->mlx = mlx_init();
	view->win = mlx_new_window(view->mlx, WIDTH, HEIGHT, TITLE);
	view->screen.img = mlx_new_image(view->mlx, WIDTH, HEIGHT);
	view->screen.addr = get_data_addr(&view->screen);
	mlx_put_image_to_window(view->mlx, view->win, view->screen.img, 0, 0);
	handle_hooks(data);
}
