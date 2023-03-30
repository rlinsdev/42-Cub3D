#include "cub3d.h"


/*
We initialize the set up for the rays
- camera_x -> Where is the camera (-1 = left, 0 = center, 1 = right)
- dir_x/y = direction of the ray
- map_x/y = current square of the ray
- deltadist_x/y = distance to go to the next x or y.
*/

//TODO:L Ver se precisa deste código mesmo
void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}
//TODO:L
//TODO:L Trocar o nome de Init pra SetUp ou algo assim
static void	init_raycasting_info(int x, t_ray *ray, t_player *player)
{
	init_ray(ray);
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->deltadist_x = fabs(1 / ray->dir_x); //fabs() function of math.h header file in C programming is used to get the absolute value of a floating point number. This function returns the absolute value in double.
	ray->deltadist_y = fabs(1 / ray->dir_y);
}

/*
- We are doing the initial set up for the dda
- dda algorithm will jump one square in each loop eiter in a x or y direction
- ray->sidedist_x or y = distance from the ray start position to the
	next x or y position
- if x or y < 0 go the next x or y to the left
- if x or y > 0 go the next x or y to the right
*/
//TODO:L Colocar lá na classe de Calculo DDA se p´a...
static void	set_dda(t_ray *ray, t_player *player) // **calculate step and initial sideDist
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltadist_y;
	}
}

/*
- We implement the DDA algorithm -> the loop will increment 1 square
-   until we hit a wall
- If the sidedistx < sidedisty, x is the closest point from the ray
*/
//TODO:L
static void	perform_dda(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		// **//jump to next map square, either in x-direction, or in y-direction
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25
			|| ray->map_x < 0.25
			|| ray->map_y > data->map_det.height - 0.25
			|| ray->map_x > data->map_det.width - 1.25)
			break ;
		// **//Check if ray has hit a wall
		else if (data->map[ray->map_y][ray->map_x] > '0')
			hit = 1;
	}
}
//TODO:L
static void	calculate_line_height(t_ray *ray, t_data *data, t_player *player)
{
	// **//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
		// **//Calculate height of line to draw on screen
	ray->line_height = (int)(data->win_height / ray->wall_dist);
	// **//calculate lowest and highest pixel to fill in current stripe
	ray->draw_start = -(ray->line_height) / 2 + data->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->win_height / 2;
	if (ray->draw_end >= data->win_height)
		ray->draw_end = data->win_height - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}


void	calc_raycast(t_data *data)
{
	int	pixel;
	t_ray	ray;
	t_player player; //TODO:L Se faltar linha, passar o objeto direto do data mesmo.

	pixel = 0;
	ray = data->ray;
	player = data->player;
	while (pixel < WIDTH)
	{
		init_raycasting_info(pixel, &ray, &player);
		set_dda(&ray, &player);
		perform_dda(data, &ray);
		calculate_line_height(&ray, data, &player);
		update_texture_pixels(data, &data->texture_det, &ray, pixel);
		//TODO:L Vou deixar como histórico, porque pode me ajudar a me encontrar onde colocar o código.
		// calc_camera(&data->ray, pixel);
		// calc_delta(&data->ray);
		// calc_side(&data->ray);
		// calc_dda(&data->ray, &data->view, data->map);
		// calc_perpendicular(&data->ray);
		// draw_wall(data, pixel);
		pixel++;
	}
	// ft_mlx_put_img(&data->view, &data->view.screen, 0, 0);
}
//TODO:L
void	set_image_pixel(t_img *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_line / 4) + x;
	image->addr[pixel] = color;
}

//TODO:L Documentar que o proiemri oé pra textura, os outros 2 pro chão e ceu
static void	set_frame_image_pixel(t_data *data, t_img *image, int x, int y)
{
	if (data->texture_pixels[y][x] > 0)
		// printf("oi");
		set_image_pixel(image, x, y, data->texture_pixels[y][x]);
	else if (y < data->win_height / 2)
		set_image_pixel(image, x, y, data->texture_det.hex_ceiling); // Todo: Aqui está botando o céu e o chão
	else if (y < data->win_height -1)
		set_image_pixel(image, x, y, data->texture_det.hex_floor);  // Todo: Aqui está botando o céu e o chão
}
//TODO:L Ver se precisa disso mesmo
void	init_img_clean(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
}

//TODO:L Setup, não init
void	init_texture_img(t_data *data, t_img *image, char *path)
{
	init_img_clean(image);
	image->img = mlx_xpm_file_to_image(data->view.mlx, path, &data->texture_det.size, &data->texture_det.size);
	if (image->img == NULL)
		// clean_exit(data, err_msg("mlx", ERR_MLX_IMG, 1)); //TODO:L
		printf("Erro aqui");
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits, &image->size_line, &image->endian);
	return ;
}

void	init_img(t_data *data, t_img *image, int width, int height)
{
	init_img_clean(image);
	image->img = mlx_new_image(data->view.mlx, width, height);
	if (image->img == NULL)
		// clean_exit(data, err_msg("mlx", ERR_MLX_IMG, 1)); //TODO:L
		printf("Erro aqui");
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

static void	render_frame(t_data *data) // draw wall
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	init_img(data, &image, data->win_width, data->win_height);
	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			set_frame_image_pixel(data, &image, x, y);
			x++;

			// // Código lins
			// if (x % 100)
			// 	mlx_put_image_to_window(data->mlx, data->win, image.img, 0, 0); // Esse é o cara que coloca a imagem na tela
			// 	// Deixar ele aqui, faz com que vá renderizando devagarzinho, pixel por pixel
			// // Código lins
		}
		y++;
	}
	mlx_put_image_to_window(data->view.mlx, data->view.win, image.img, 0, 0); // Esse é o cara que coloca a imagem na tela
	mlx_destroy_image(data->view.mlx, image.img);
}

//TODO:L
static void	render_raycast(t_data *data)
{
	init_texture_pixels(data);
	init_ray(&data->ray);
	// raycasting(&data->player, data);
	calc_raycast(data);
	render_frame(data);
}

//TODO:L
void	render_images(t_data *data)
{
	render_raycast(data);
}

int	ray_loop(t_data *data)
{
	data->player.has_moved += move_player(data);
	if (data->player.has_moved == 0)
		return (0);
	render_images(data);

	// draw_ceiling(data); //TODO:L
	// draw_floor(data);
	//draw_minimap(data);
	return (SUCCESS);
}
