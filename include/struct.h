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

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
}					t_player;

typedef struct s_img
{
	void			*img;
	int				bpp;
	int				len_line;
	int				endian;
	char			*addr;
}					t_img;

typedef struct s_view
{
	void			*mlx;
	void			*win;
	int				screen_width;
	int				screen_height;
	int				**map_test;
	t_img			minimap;
	t_img			screen;

}					t_view;

typedef struct s_data
{
	void			*img_map;
	void			*img_screen;
	char			**map;
	t_view			view;
	t_player		player;
	t_map_det		map_det;
	t_texture_det	texture_det;
}					t_data;

#endif
