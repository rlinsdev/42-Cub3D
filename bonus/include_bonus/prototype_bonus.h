/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:32:47 by rlins             #+#    #+#             */
/*   Updated: 2023/04/12 12:23:10 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_BONUS_H
# define PROTOTYPE_BONUS_H

/**
 * @brief Handle error message in program
 * @param msg Message to be exposed
 * @param status_code Status code to be returned
 * @return int
 */
int		error_msg(char *msg, int status_code);

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
 * @brief Close the window and free all memory (esc or 'X' in window will call
 * it)
 * @param data Data structure
 */
int		handle_hook_close(t_data *data);

/**
 * @brief Responsible to validate the map loaded by param
 * @param data Data Structure
 * @return int. 0 OK. otherwise problem
 */
int		valid_map(t_data *data);

/**
 * @brief Exit program.
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
 * handle'... Nobody nows rs
 * @param data data structure
 */
void	spaces_to_wall(t_data *data);

/**
 * @brief calculate step and initial sideDist.
 * Will apply the DDA calculation
 * if x or y < 0 go the next x or y to the left
 * if x or y > 0 go the next x or y to the right
 * @param ray Ray Structure
 * @param player Player structure
 */
void	calc_dda(t_ray *ray, t_player *player);

/**
 * @brief Here is the implementation of DDA algorithm:
 * The loop will increment 1 square until we hit a wall
 * If the side_dist_x < side_dist_y, x is the closest point from the ray
 * In first 'if', jump to next map square, either in x-direction, or in
 * y-direction.
 * Handle which side of the wall the ray strikes
 * @hint: Validations 0.25 avoid seg fault. Must to do this because the speed
 * is a variable defined previous.
 * @param data Data Structure
 * @param ray Ray Structure
 */
void	perform_dda(t_data *data, t_ray *ray);

/**
 * @brief Validate Textures. Check if it is following the pattern
 * @param text Texture Structure
 * @return int. 0 if It's OK. Otherwise: Error
 */
int		valid_texture(t_texture_det *text);

/**
 * @brief Validate path of program. Initially, will validate the path of
 * texture in file.
 * @param path Path to be validate
 * @return boolean.
 */
bool	val_file_path(char *path);

/**
 * @brief Show the values of the most important structures.
 * @param data data structure
 */
void	debug(t_data *data);

/**
 * @brief Set the player direction object. Accord with the Char Direction (NSWE)
 * point the camera to some side
 * @param p player structure
 */
int		set_player_direction(t_player *p);

/**
 * @brief Responsible to initialize the 'init_texture_pixels' variable, to
 * draw pixel by pixel of texture
 * @param data Data structure
 */
void	init_texture_pixels(t_data *data);

/**
 * @brief Handle all the calc to update the texture of a pixel.
 * @hint: North and East texture will received a effect of grey. If you
 * run a map with the same texture in all dir, North and East will got this
 * effect
 * @hint: Will draw to start ray until the draw end ray.
 * @hint: https://lodev.org/: 'make color darker for y-sides: R, G and B byte
 * each divided through two with a "shift" and an "and"
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
int		render_images(t_data *data);

/**
 * @brief Initialize each texture. North South East West.
 * Will call the method xpm_to_image, passing the path os texture by param
 * @param data Data Structure
 */
void	setup_textures(t_data *data);

/**
 * @brief Validate the move. If is a invalid move (out of window game) just
 * return a value to output message error.
 * If it's a valid move, change the player position
 * @param data Data structure
 * @param new_x New PosX to player
 * @param new_y new PosY to player
 * @return int indicating success or not
 */
int		validate_move(t_data *data, double new_x, double new_y);

/**
 * @brief Initialize images, base on Textures (Wall textures) passed by param
 * @param data Data Structure
 * @param image Img structure
 * @param path Path of wall textures
 */
void	init_texture_img(t_data *data, t_img *image, char *path);

/**
 * @brief Initialize Img and Address from Image structure
 * @param data Data Structure
 * @param i Image structure
 * @param width Size of screen
 * @param height Size of screen
 */
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
 * @hint: negative draw start will seg fault.
 * @param ray Ray Structure
 * @param player Player Structure
 */
void	calculate_line_height(t_ray *ray, t_player *player);

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
 * @brief Initialize Setup for the rays.
 * Apply the formula to get all the pixels in the all width, range from -1
 * until 1 range of POV)
 * @hint: fabs: This function returns the absolute value in double.
 * @param x pixel
 * @param ray Ray structure
 * @param player Player
 */
void	setup_raycast_info(int x, t_ray *ray, t_player *player);

int		move(t_data *d, double dx, double dy);
int		rotate(double *x, double *y, double angle);
int		starting_game(t_data *data);
bool	is_map_sur_walls2(t_data *data);

#endif
