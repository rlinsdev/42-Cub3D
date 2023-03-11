/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:02:27 by rlins             #+#    #+#             */
/*   Updated: 2023/03/11 11:51:04 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/minilibx-linux/mlx.h"
# include "./libft.h"
# include <fcntl.h> // To Open a file
# include <X11/keysym.h> // Type key code pressed
# include <X11/X.h> // Type event em mask that hooks call
# include <stdio.h>
# include <errno.h> // errno
# include <math.h> // math lib
# include <stdbool.h> // boolean

# define A_KEY_CONST	'a'
# define S_KEY_CONST	's'
# define D_KEY_CONST	'd'
# define W_KEY_CONST	'w'

# define C_WALL		'1'
# define C_BACK_G 	'0'
// # define C_NSEW 	'X'

# define ERR_ARGS "Invalid call. Must be: ./cub3D <map_path/map.cub>"
# define ERR_MALC "Problems in memory allocation!"
# define ERR_CUB "Error File. Expected .cub extension!"
# define ERR_MAP "Invalid map!"
# define ERR_MAP7 "Invalid map! Verify the specification in PDF Subject"
# define ERR_MAP8 "Map not surrounded by walls"
# define ERR_TEXT "Texture out of pattern. Check Subject for more details."

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		*floor;
	int		*ceiling;
}	t_texture_det;

typedef struct s_map_detail
{
	int			fd;
	int			lines_file;
	char		*path;
	char		**file; // Matrix of all file in this variable
	int			height;
	int			width;
	int			start_i_map;
	int			end_i_map;
}	t_map_det;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	char			**map;
	t_map_det		map_det;
	t_texture_det	texture_det;
}	t_data;

enum e_output
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
int		error_msg(char *msg, int status_code);

/**
 * @brief Initialize all variables in data structure
 * @param data Data structure passed by param
 */
void	init_data(t_data *data);

/**
 * @brief Initialize map Detail structure
 */
void	init_map_handler(t_data *data, char *path);

/**
 * @brief Responsible to free a pointer and refer to null the original variable
 * @param ptr Pointer to be freed
 */
void	free_ptr(void *ptr);

/**
 * @brief Release a memory from a Array of char (String)
 * @param arr_str string to be freed
 */
void	free_array_str(char **arr_str);

/**
 * @brief Will clean up all Data structure.
 * @return ExitFailure (1)
 */
int	free_data(t_data *data);

/**
 * @brief Validation extension of file. .xpm files
 * @param file file name
 * @return boolean
 */
bool	val_xpm_file(char *file);

/**
 * @brief Validation extension of file. .cub files / map file
 * @param file file name
 * @return boolean
 */
bool	val_cub_file(char *file);

/**
 * @brief Handle the data passed by file to program. Will handle with enum
 * to handle if will necessary to keep going through map, or we must stop BREAK
 * @param data Data structure
 */
int	file_to_variable(t_data *data);

/**
 * @brief Parse the map in the file to variable
 * @param data Data structure
 * @return boolean
 */
bool	create_map(t_data *data);

/**
 * @brief Will handle all possibles errors in map. This method jus call others
 * to do this management.
 * @param data structure
 * @return int. 0 Success. Otherwise error
 */
int	valid_map(t_data *data);

/**
 * @brief Exit program.
 *TODO: Depois receberá comandos do MLX para limpeza das imgs e destroy
 * @param data Sta structure to be cleaned
 * @param exit_code Status code to exit
 */
void	exit_cube(t_data *data, int exit_code);

/**
 * @brief Responsible to parse the Texture in file to a respective variable,
 * with the path of texture.
 * Row is a current row to be handle.
 * i is the column / index in this row (avoiding white space)
 * @return bool - Parse with success
 */
bool parse_tex_dir(t_texture_det *text_det, char *row, int i);

/**
 * @brief Verify if the current char is a white space or similar
 * @param c Char to verify
 * @return boolean
 */
bool	is_white_space(char c);

#endif
