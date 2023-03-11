/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:02:27 by rlins             #+#    #+#             */
/*   Updated: 2023/03/10 22:47:10 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/minilibx-linux/mlx.h"
# include "./libft.h"
# include <X11/X.h>      // Type event em mask that hooks call
# include <X11/keysym.h> // Type key code pressed
# include <errno.h>      // errno
# include <fcntl.h>      // To Open a file
# include <math.h>       // math lib
# include <stdbool.h>    // boolean
# include <stdio.h>

# define A_KEY_CONST 'a'
# define S_KEY_CONST 's'
# define D_KEY_CONST 'd'
# define W_KEY_CONST 'w'

# define ERR_ARGS "Invalid call. Must be: ./cub3D <map_path/map.cub>"
# define ERR_MALC "Problems in memory allocation!"
# define ERR_CUB "Error File. Expected .cub extension!"
# define ERR_MAP "Invalid map!"

# define HEIGHT 600
# define WIDTH 800

# define TITLE "Cub3D"

typedef struct s_map_detail
{
	int			fd;
	int			lines_count;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			start_i_map;
	int			end_i_map;
}				t_map_det;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_img
{
	void		*img;
	int			bpp;
	int			len_line;
	int			endian;
	char		*addr;
}				t_img;

typedef struct s_view
{
	void		*mlx;
	void		*win;
	t_img		map;
	t_img		screen;

}				t_view;

typedef struct s_data
{
	void		*img_map;
	void		*img_screen;
	char		**map;
	t_view		view;
	t_player	player;
	t_map_det	map_det;
}				t_data;

enum			e_output
{
	SUCCESS = 0,
	FAILURE = 1,
	// ERROR = 2,
	BREAK = 3,
	CONTINUE = 4
};

/**
 * @brief Handle error message in program
 * @param msg Message to be exposed
 * @param status_code Status code to be returned
 * @return int
 */
int				error_msg(char *msg, int status_code);

/**
 * @brief Initialize all variables in data structure
 * @param data Data structure passed by param
 */
void			init_data(t_data *data);

/**
 * @brief Initialize map Detail structure
 */
void			init_map_handler(t_data *data, char *path);

/**
 * @brief Responsible to free a pointer and refer to null the original variable
 * @param ptr Pointer to be freed
 */
void			free_ptr(void *ptr);

/**
 * @brief Release a memory from a Array of char (String)
 * @param arr_str string to be freed
 */
void			free_array_str(char **arr_str);

/**
 * @brief Will clean up all Data structure.
 * @return ExitFailure (1)
 */
int				free_data(t_data *data);

/**
 * @brief Validation extension of file. .xpm files
 * @param file file name
 * @return boolean
 */
bool			val_xpm_file(char *file);

/**
 * @brief Validation extension of file. .cub files / map file
 * @param file file name
 * @return boolean
 */
bool			val_cub_file(char *file);

/**
 * @brief Handle the data passed by file to program. Will handle with enum
 * to handle if will necessary to keep going through map, or we must stop BREAK
 * @param data Data structure
 */
int				file_to_variable(t_data *data);

/**
 * @brief Parse the map in the file to variable
 * @param data Data structure
 * @return boolean
 */
bool			create_map(t_data *data);
void			create_graphic(t_data *data);

#endif
