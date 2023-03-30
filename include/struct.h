#ifndef STRUCT_H
# define STRUCT_H

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
	// New TODO:L
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
 *
 */
typedef struct s_player
{
	char	dir;
	double	pos_x; // TODO:L Deixar 1 var só?
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

//TODO:L Remover estes comentários. Pensar em colocar em outro lugar...
typedef struct s_ray
{
	double	camera_x;
	// **rayDirX é o 'rayDirX' na documentação
	double	dir_x; // dir[0]
	double	dir_y;// dir[1]
	int		map_x; // **mapX and mapY represent the current square of the map the ray is in.
	int		map_y; // **mapX and mapY represent the current square of the map the ray is in.
	// **sideDistX and sideDistY get incremented with deltaDistX with every jump in their direction, and mapX and mapY get incremented with stepX and stepY respectively.
	int		step_x;
	int		step_y;
	// **sideDistX and sideDistY are initially the distance the ray has to travel from its start position to the first x-side and the first y-side.
	// **Later in the code they will be incremented while steps are taken.
	double	sidedist_x;
	double	sidedist_y;
	// **deltaDistX and deltaDistY are the distance the ray has to travel to go from 1 x-side to the next x-side, or from 1 y-side to the next y-side.
	// **deltaDistX = abs(|rayDir| / rayDirX)
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist; //** perpWallDist
	double	wall_x;
	int		side;		//hit_side
	int		line_height; //**  lineHeight
	int		draw_start;
	int		draw_end;

	// double			pos[2]; // TODO Vai morrer PLAYER
	// double			dir[2];  // TODO Vai morrer PLAYER
	// double			plane[2];  // TODO Vai morrer PLAYER
	// double			ray_dir[2];
	// double			delta[2];
	// double			wall_pos[2];
	// double			dist_to_side[2];
	// double			step[2];
	// double			dda_line_size[2];
	// double			wall_dist[2];
	// double			perp;
	// double			speed;
	// double 			multiplier;
	// int				line_size[2];
	// char 			dir_char;
	// bool			hit_side;

}					t_ray;


//TODO:L Remover comentários. Ver as 3 variáveis agoar q nao são mais um array de 3
typedef struct s_img
{
	// void			*img;
	// char			*addr;
	// int				data[3];
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
	// int				**map_test; // TODO: Remover
	// int				color;
	// int				map[24][24]; // TODO: Rever este index cravado
	t_img			screen;
}					t_view;

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
	int			win_height; // //TODO:L testar sem
	int			win_width; //TODO:L Testar sem estas variaveis aqui
}					t_data;

#endif
