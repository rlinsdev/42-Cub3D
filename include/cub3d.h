/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:02:27 by rlins             #+#    #+#             */
/*   Updated: 2023/03/11 13:11:14 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// includes system
# include <X11/X.h>      // Type event em mask that hooks call
# include <X11/keysym.h> // Type key code pressed
# include <errno.h>      // errno
# include <fcntl.h>      // To Open a file
# include <math.h>       // math lib
# include <stdbool.h>    // boolean
# include <stdio.h>

// includes local
# include "../lib/libft/include/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include "./enum.h"
# include "./define.h"
# include "./struct.h"
# include "./prototype.h"

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
