/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:02:27 by rlins             #+#    #+#             */
/*   Updated: 2023/03/07 08:17:29 by rlins            ###   ########.fr       */
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

# define A_KEY_CONST	'a'
# define S_KEY_CONST	's'
# define D_KEY_CONST	'd'
# define W_KEY_CONST	'w'


/**
 * @brief First method in game.
 * It'll be called by main / app.cs
 * @param argc Arguments count
 * @param argv Arguments Vector
 * @return int
 */
int	start(int argc, char **argv);


/**
 * @brief Handle error message in program
 * @param msg Message to be exposed
 * @param status_code Status code to be returned
 * @return int
 */
int	error_msg(char *msg, int status_code);

#endif
