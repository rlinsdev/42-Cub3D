# ifndef DEFINE_H
# define DEFINE_H

# define A_KEY_CONST 'a'
# define S_KEY_CONST 's'
# define D_KEY_CONST 'd'
# define W_KEY_CONST 'w'
# define ESC_KEY_CONST 65307

# define C_WALL		'1'
# define C_BACK_G 	'0'
# define C_WHITE_S	' '
// # define C_NSEW 	'X'

# define VALID_CHAR_MAP "01NSEW"
# define VALID_PLAYER_POS "NSEW"

# define ERR_ARGS "Invalid call. Must be: ./cub3D <map_path/map.cub>"
# define ERR_MALC "Problems in memory allocation!"
# define ERR_CUB "Error File. Expected .cub extension!"
# define ERR_MAP "Invalid map!"
# define ERR_MAP7 "Invalid map! Verify the specification in PDF Subject"
# define ERR_MAP8 "Map not surrounded by walls"
# define ERR_RGB  "Invalid RGB color format to Floor/Ceiling"
# define ERR_MAP9 "Map with invalid character. Check Subject for more details."
# define ERR_TEXT "Texture out of pattern. Check Subject for more details."
# define ERR_TEXT_MAP "Texture not found in file."
# define ERR_TEXT_COL "Color not found in file."
# define ERR_TEXT_PATH "Error in Texture. Invalid path."
# define ERR_RGB_VAL "Invalid RGB Value. Check the file passed by param."

# define ERR_MAP_CHAR "Character invalid in map."
# define ERR_SING_PLAYER "Map error. Just one player allowed"

# define HEIGHT 600
# define WIDTH 800
# define TITLE "Cub3D"


# endif
