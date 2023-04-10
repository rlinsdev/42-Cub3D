/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:27:45 by rlins             #+#    #+#             */
/*   Updated: 2023/04/10 15:23:14 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

/**
 * @brief Texture structure. First: all variables captured by files. Then,
 * variables to handle the texture wall
 * @param north, south, west, east: Path of textures
 * @param ceiling, floor - array[3] integer representation of RGB color
 * @param hex_floor, hex_ceiling - Representation in int of RGB Color
 * @param size - Fixed in 64. Check details in define.h file
 * @param index - Work with Enum texture. Identify what texture is (NSWE)
 * @param step - Each step took, is a step based on the height of the line
 * @param pos - Texture position that changes, with each step that is taken
 * [texPos]
 * @param x, y: - Texture X and Y coordinate [texX]
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
/**
 * @brief Map Structure. Centralize all infos of Mas
 * @param fd: File descriptor
 * @param lines_file: Lines of file
 * @param path: path of .cub file
 * @param file: all file passed by param in this variable
 * @param height, width - Size of window
 * @param start_i_map, end_i_map: Start/end index of map
 */
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
 * @param dir: Player Direction (NEWS)
 * @param pos_x, pos_y: Position of player
 * @param dir_x, dir_y: Player direction
 * @param plane_x, plane_y: The 2d ray-caste version of camera plane
 * @param has_moved -Player moving. Will be always incremented when clicked
 * @param move_x -1 when 'A' clicked +1 when 'D' clicked
 * @param move_y -1 when 'W' clicked +1 when 'S' clicked
 * @param rotate: -1 when 'left arrow' clicked. +1 when 'right arrow' clicked
 *
 * @hint: dir an plane just change when in rotation.
 */
typedef struct s_player
{
	char			dir;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				has_moved;
	int				move_x;
	int				move_y;
	int				rotate;
}					t_player;

/**
 * @brief Ray Structure
 * @param multiplier: Formula to get all the pixels in the all width, range
 * from -1 until 1 (range of POV)
 * @param dir_x/y = direction of the ray. Ray from the Player until the small
 * peace of plane [rayDirX]
 * @param map_x and map_y represent the current square of the map the ray is in.
 * @param stepX and stepY: //what direction to step in x or y-direction
 * (either +1 or -1)
 * @param side_dist_x and side_dist_y get incremented with deltaDistX with every
 * jump in their direction, and mapX and mapY get incremented with stepX e stepY
 * respectively. Later in the code they will be incremented while steps was did.
 * [sideDistX]
 * @param delta_dist_x and delta_dist_y are the distance the ray has to travel
 * to go from 1 x-side to the next x-side, or from 1 y-side to the next y-side.
 * deltaDistX = abs(|rayDir| / rayDirX) [deltaDistX]
 * @param perp_dist: Calculate to avoid fisheye effect!
 * @param wall_x: Point where the lightning hit the wall
 * @param hit_side Indicated if the ray hit a side
 * @param line_height height of line to draw on screen
 * @param draw_start/draw_end: Calculate lowest and highest pixel to fill in
 * current stripe
 * */
typedef struct s_ray
{
	double			multiplier;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_dist;
	double			wall_x;
	bool			hit_side;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_ray;

/**
 * @brief Img Structure
 * @param img: Used to get information from MLX (handle images)
 * @param addr: Address of memory in MLX to handle pixel (Used in texture)
 * @param pixel_bits, size_line, endian: Used in MLX commands. Passed b y param.
 */
typedef struct s_img
{
	void			*img;
	int				*addr;
	int				pixel_bits;
	int				size_line;
	int				endian;
}					t_img;

/**
 * @brief Structure View
 * @param: mlx to MLX initialization
 * @param: win to work with MLX
 */
typedef struct s_view
{
	int				x;
	int				y;
	int				i;
	int				j;
	int				color;
	void			*mlx;
	void			*win;
	t_img			screen;
}					t_view;
/**
 * @brief Data Structure. Principal Structure in project. Will content all the
 * other  structures in project
 * @param: map: Map of project
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
