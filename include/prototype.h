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
 * @brief Alias to mlx_put_image_to_window
 *
 * @param view The structure containing the window and the image
 * @param img The image to draw on the window
 * @param x The x coordinate of the image
 * @param y The y coordinate of the image
 */
void	ft_mlx_put_img(t_view *view, t_img *img, int x, int y);

/**
 * @brief transform a rgb color to an int
 * @param r red
 * @param g green
 * @param b blue
 * @return color in int
*/
int		ft_mlx_rgb_to_int(int r, int g, int b);

/**
 * @brief Close the window and free all memory
 * @param data Data structure
 */
int		handle_hook_close(t_data *data);

/**
 * @brief Handle the key pressed
 * @param keycode Key pressed
 * @param data Data structure
 * @return int
 */
int		handle_hook_key(int keycode, t_data *data);

/**
 * @brief Will handle all possibles errors in map. This method jus call others
 * to do this management.
 * @param data structure
 * @return int. 0 Success. Otherwise error
 */

int		handle_hook_resize(t_data *data);

int		valid_map(t_data *data);

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
bool	parse_tex_dir(t_texture_det *text_det, char *row, int i);

/**
 * @brief Verify if the current char is a white space or similar
 * @param c Char to verify
 * @return boolean
 */
bool	is_white_space(char c);

/**
 * @brief Will parse the file information: Celling and floor values into
 * variables
 * @param text_det Texture Details structure
 * @param row row in file
 * @param i index to check; verify the information
 * @return int - 0 OK. Otherwise error
 */

int	parse_tex_color(t_texture_det *text_det, char *row, int i);


/**
 * @brief Change white space into wall in map. First, PDF tell us that just
 * some type of char is valid in map. Then, 'spaces are valid, but must be
 * handle'.
 * @param data data structure
 */
void	spaces_to_wall(t_data *data);


// TODO: documentar as funções abaixo
int		ray_loop(t_data *data);

void	draw_ceiling(t_data *data);
void	draw_floor(t_data *data);
void	draw_wall(t_data *data, int pixel);
void	draw_minimap(t_data *data);
int		ray_rotate_left(t_ray *r);
int		ray_rotate_right(t_ray *r);
int     ray_move_left(t_ray *r, char **map);
int     ray_move_right(t_ray *r, char **map);
int     ray_move_up(t_ray *r, char **map);
int     ray_move_down(t_ray *r, char **map);
int		ray_resert(t_ray *r);
void	calc_perpendicular(t_ray *ray);
void	handles_all_hooks(t_data *data);

void	calc_camera(t_ray *ray, int pixel);
void	calc_delta(t_ray *r);
void	calc_side(t_ray *r);
void	calc_dda(t_ray *r, t_view *v, char **map);

/**
 * @brief Validate Textures. Check if it is following the pattern
 * @param data Data Structure
 * @param text Texture Structure
 * @return int. 0 if It's OK. Otherwise: Error
 */
int	valid_texture(t_data *data, t_texture_det *text);

/**
 * @brief Validate path of program. Initially, will validate the path of
 * texture in file.
 * @param path Path to be validate
 * @return boolean.
 */
bool	val_file_path(char *path);

/**
 * @brief Responsible to handle the player direction. Will get from map what
 * value was passed: NSEW. according with this, the player will be point to
 * this direction.
 * @param r Ray structure
 */
void player_dir_handler(t_ray *r);

#endif
