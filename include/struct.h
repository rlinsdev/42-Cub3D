/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:27:45 by rlins             #+#    #+#             */
/*   Updated: 2023/03/30 12:44:58 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/**
 * @brief Texture structure. First, all variables captured by files. Then,
 * variables to handle the texture wall
 * @param size até pos: //TODO:L documentar
 */
typedef struct s_texture
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}					t_texture_det;

typedef struct s_map_detail
{
	int				fd;
	int				lines_file;
	char			*path;
	char			**file;
	int				height;
	int				width;
	int				start_i_map;
	int				end_i_map;
}					t_map_det;

/**
 * @brief Player structure.
 * @param dir: Player Direction (NEWS), Position (x/y)
 * TODO:L Colocar mais coisa?
 */
typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

/**
 * @brief Ray Structure
 * @param mapX and mapY represent the current square of the map the ray is in.
 * @param sideDistX and sideDistY get incremented with deltaDistX with every
 * jump in their direction, and mapX and mapY get incremented with stepX e stepY
 * respectively. Later in the code they will be incremented while steps was did.
 * @param deltaDistX and deltaDistY are the distance the ray has to travel to go
 * from 1 x-side to the next x-side, or from 1 y-side to the next y-side.
 * deltaDistX = abs(|rayDir| / rayDirX)*/
typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	wall_dist;
	double	wall_x;
	bool	hit_side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}					t_ray;

/**
 * @brief Img Structure
 * @param pixel_bits, size_line, endian: Used in MLX commands. Passed b y param.
 * @param addr: Address of memory in MLX to handle pixel (Used in texture)
 * @param img: Used to get information from MLX (handle images)
 */
typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}					t_img;

typedef struct s_view
{
	void			*mlx;
	void			*win;
	t_img			screen;
}					t_view;
/**
 * @brief Data Structure. Principal Structure in project
 * @param texture_pixels: Pixel by pixel to draw the texture
 * @param textures: The 4 side array of integer, represented by enum (NSWE).
 * 4 side of textures
 */
typedef struct s_data
{
	char			**map;
	t_view			view;
	t_ray			ray;
	t_map_det		map_det;
	t_texture_det	texture_det;
	t_player		player;
	int				**texture_pixels;
	int				**textures;
}					t_data;

#endif
