#ifndef PROTOTYPE_H
# define PROTOTYPE_H

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
int		free_data(t_data *data);

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
int		file_to_variable(t_data *data);

/**
 * @brief Parse the map in the file to variable
 * @param data Data structure
 * @return boolean
 */
bool	create_map(t_data *data);

/**
 * @brief Initialize the mlx and create the window
 * @param data Data structure
 */
void	ft_mlx_init(t_data *data);


/**
 * @brief Put a pixel on the screen
 *
 * @param img The image to draw on
 * @param x The x coordinate of the pixel
 * @param y The y coordinate of the pixel
 * @param color The color of the pixel
 */
void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);

/**
 * @brief Alias to mlx_get_data_addr
 *
 * @param img The image to get the address from
 * @return char* The address of the image
 */
char	*ft_mlx_get_addr(t_img *img);

/**
 * @brief Close the window and free all memory
 * @param data Data structure
 */
int	handle_hook_close(t_data *data);

/**
 * @brief Handle the key pressed
 * @param keycode Key pressed
 * @param data Data structure
 * @return int
 */
int handle_hook_key(int keycode, t_data *data);

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

/**
 * @brief
 *
 * @param text_det
 * @param row
 * @param i
 * @return true
 * @return false
 */
bool parse_tex_color(t_texture_det *text_det, char *row, int i);

#endif
