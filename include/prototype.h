/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:32:47 by rlins             #+#    #+#             */
/*   Updated: 2023/04/03 08:49:00 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
 * @brief Release a memory from a Array. Void to be generic. Will clean
 * string, array of int, etc.
 * @param arr Array to be freed
 */
void	free_array_gen(void **arr);

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

/**
 * @brief Responsible to validate the map loaded by param
 * @param data Data Structure
 * @return int. 0 OK. otherwise problem
 */
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

int		parse_tex_color(t_texture_det *text_det, char *row, int i);

/**
 * @brief Change white space into wall in map. First, PDF tell us that just
 * some type of char is valid in map. Then, 'spaces are valid, but must be
 * handle'.
 * @param data data structure
 */
void	spaces_to_wall(t_data *data);

/**
 * @brief This is the MLX loop method called. Any game must be a while (true)
 * code to render the screen. MLX have your call to do this. And, this was the
 * method called to do this work
 * @param data Data Structure
 * @return int
 */
int		ray_loop(t_data *data);

void	calc_perpendicular(t_ray *ray);
void	handles_all_hooks(t_data *data);

// void	calc_camera(t_ray *ray, int pixel);
// void	calc_delta(t_ray *r);
// void	calc_side(t_ray *r);

/**
 * @brief calculate step and initial sideDist.
 * Will apply the DDA calculation
 * if x or y < 0 go the next x or y to the left
 * if x or y > 0 go the next x or y to the right
 * @param ray
 * @param player
 */
void	calc_dda(t_ray *ray, t_player *player);

/**
 * @brief Implement the DDA algorithm -> the loop will increment 1 square
 * until we hit a wall
 * If the side_dist_x < side_dist_y, x is the closest point from the ray
 * In first 'if', jump to next map square, either in x-direction, or in
 * y-direction.
 * Handle which side of the wall the ray strikes
 * @param data Data Structure
 * @param ray Ray Structure
 */
void	perform_dda(t_data *data, t_ray *ray);

/**
 * @brief Validate Textures. Check if it is following the pattern
 * @param data Data Structure
 * @param text Texture Structure
 * @return int. 0 if It's OK. Otherwise: Error
 */
int		valid_texture(t_data *data, t_texture_det *text);

/**
 * @brief Validate path of program. Initially, will validate the path of
 * texture in file.
 * @param path Path to be validate
 * @return boolean.
 */
bool	val_file_path(char *path);

/**
 * @brief Show the values of some structure.
 * @param data data structure
 */
void	debug(t_data *data);

/**
 * @brief Set the player direction object. Accord with the Char Direction (NSWE)
 * point the camera to some side
 * @param p player structure
 */
void	set_player_direction(t_player *p);

/**
 * @brief Identify if user move forward, back, left, right or rotation.
 * Call the
 * @hint: Effect to 'keep going' and 'turn fluid' is able keeping 'if'
 * condition. else if will exclusive direction
 * @param data
 * @return int
 */
int		move_player(t_data *data);
int		rotate_player(t_data *data, double rotdir);
void	init_texture_pixels(t_data *data);

/**
 * @brief Handle all the calc to update the texture of a pixel.
 * @int: North and East texture will received a effect of grey. If you
 * run a map with the same texture in all dir, North and East will got this
 * effect
 * Will draw to start ray until the draw end ray.
 * @param data Data structure
 * @param tex Texture details structure
 * @param ray Ray structure
 * @param x pixel
 */
void	update_text_pixels(t_data *data, t_texture_det *tex, t_ray *ray, int x);

/**
 * @brief Responsible to render all images. This method will be called in the
 * begin of program (render the screen in user position vision) and will be
 * called any time the player move.
 * @param data Data Structure
 */
void	render_images(t_data *data);

/**
 * @brief Initialize each texture. North South East West.
 * Will call the method xpm_to_image, passing the path os texture by param
 * @param data Data Structure
 */
void	setup_textures(t_data *data);

/**
 * @brief Validate the move. If is a invalid move (out of window game)
 * If it's a valid move, change the player position
 * @param data Data structure
 * @param new_x New PosX to player
 * @param new_y new PosY to player
 * @return int
 */
int		validate_move(t_data *data, double new_x, double new_y);

void	init_texture_img(t_data *data, t_img *image, char *path);
void	init_img(t_data *data, t_img *i, int width, int height);

/**
 * @brief Exi the program, but free all memory allocation
 * @param data data Structure
 * @param s_code Status code of exit
 */
void	exit_and_free(t_data *data, int s_code);

/**
 * @brief Validate if player is in a valid position. Check if he is inside the
 * map, not out of range
 * @param data Data structure
 * @param map pointer to pointer - map
 * @return int - valid or not valid
 */
int		pos_is_valid(t_data *data, char **map);

/**
 * @brief Calculate distance projected on camera direction (Euclidean distance
 * would give fisheye effect!)
 * @hint: line_height: Calculate height of line to draw on screen
 * @hint: Calculate lowest and highest pixel to fill in current stripe
 * @param ray Ray Structure
 * @param data Data Structure
 * @param player Player Structure
 */
void	calculate_line_height(t_ray *ray, t_data *data, t_player *player);

/**
 * @brief Responsible put the color in exact pixel. Each pixel will pass here
 * @hint: If we going to generate the minimap, we probably will use this
 * func.
 * @param image image structure
 * @param x X axis
 * @param y y axis
 * @param color integer color to put in pixel
 */
void	set_image_pixel(t_img *image, int x, int y, int color);

/**
 * @brief Formula to get all the pixels in the all width, range from -1 until 1
 * range of POV)
 * @hint: fabs: This function returns the absolute value in double.
 * @param x pixel
 * @param ray Ray structure
 * @param player Player
 */
void	setup_raycast_info(int x, t_ray *ray, t_player *player);

#endif
