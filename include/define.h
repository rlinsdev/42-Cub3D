/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:34:05 by rlins             #+#    #+#             */
/*   Updated: 2023/04/12 15:00:22 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define A_KEY_CONST 'a'
# define S_KEY_CONST 's'
# define D_KEY_CONST 'd'
# define W_KEY_CONST 'w'
# define RIGHT_KEY_CONST 65361
# define LEFT_KEY_CONST 65363
# define R_KEY_CONST 114

# define ESC_KEY_CONST 65307

# define C_WALL '1'
# define C_BACK_G '0'
# define C_WHITE_S ' '

# define VALID_CHAR_MAP "01NSEW"
# define VALID_PLAYER_POS "NSEW"

# define ERR_ARGS "Invalid call. Must be: ./cub3D <map_path/map.cub>"
# define ERR_MALC "Problems in memory allocation!"
# define ERR_CUB "Error File. Expected .cub extension!"
# define ERR_MAP "Invalid map!"
# define ERR_MAP7 "Invalid map! Verify the specification in PDF Subject"
# define ERR_MAP8 "Map not surrounded by walls"
# define ERR_MAP_LAST "Map must to be the last element in file."
# define ERR_MAP_DIR "Map with no player direction set."
# define ERR_RGB  "Invalid RGB color format to Floor/Ceiling"
# define ERR_MAP9 "Map with invalid character. Check Subject for more details."
# define ERR_TEXT "Texture/map out of pattern. Check Subject for more details."
# define ERR_TEXT_MAP "Texture not found in file."
# define ERR_TEXT_COL "Color not found in file."
# define ERR_TEXT_PATH "Error in Texture. Invalid path."
# define ERR_RGB_VAL "Invalid RGB Value. Check the file passed by param."
# define ERR_PLA_POS "Invalid Player position"

# define ERR_MAP_CHAR "Character invalid in map."
# define ERR_SING_PLAYER "Map error. Just one player allowed."

# define ERR_MLX_IMG "MLX new Image error. Check the framework"
# define ERR_MLX_WIN "MLX new Window error. Check the framework"
# define ERR_MLX_INIT "MLX init error. Check the framework"

# define WIDTH 640
# define HEIGHT 480

# define BITS_PER_BYTE 8
# define TITLE "Cub3D"

# define X 0
# define Y 1

/**
 * @brief In this project, was used bitmaps that have the size of 64 by 64 pixels
 * This size is chosen because 64 by 64 is also the size of the cube facets that
 * we are using in our world
 */
# define TEX_SIZE 64

# define COLOR_MINIMAP 0x000000
# define COLOR_BORDER_MINIMAP 0xFFFFFF
# define COLOR_PLAYER 0x0000FF

# define MOVE_SPEED 0.05
# define ROTSPEED 0.05

# ifndef DEBUG_INFO
#  define DEBUG_INFO 1
# endif

#endif
