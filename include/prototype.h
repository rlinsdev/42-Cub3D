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

#endif
