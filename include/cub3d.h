/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:02:27 by rlins             #+#    #+#             */
/*   Updated: 2023/03/14 02:00:23 by lucas            ###   ########.fr       */
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
# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include "./enum.h"
# include "./define.h"
# include "./struct.h"
# include "./prototype.h"

#endif
