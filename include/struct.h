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

typedef struct s_ray
{
	double			pos[2];
	double			dir[2];
	double			plane[2];
	double			ray_dir[2];
	double			delta[2];
	int				wall_pos[2];
	double			dist_to_side[2];
	double			step[2];
	double			dda_line_size[2];
	double			wall_dist[2];
	double			perpendicular;
	double			speed;
	int				line_size[2];
	bool			hit_side;
}					t_ray;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				data[3];
}					t_img;

typedef struct s_view
{
	void			*mlx;
	void			*win;
	int				**map_test;
	int				color;
	int				map[24][24];
	t_img			screen;
}					t_view;

typedef struct s_data
{
	char			**map;
	t_view			view;
	t_ray			ray;
	t_map_det		map_det;
	t_texture_det	texture_det;
}					t_data;

#endif
