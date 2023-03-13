/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 09:36:11 by rlins             #+#    #+#             */
/*   Updated: 2023/03/13 08:16:38 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static char	*parse_text_path(char *row, int i);
static int	*parse_rgb_color(char *row);
static int	*parse_arr_color(char **str_rgb, int *rgb);

bool	parse_tex_dir(t_texture_det *text_det, char *row, int i)
{
	if (row[2] != C_WHITE_S)
		return (false);
	if (row[i] == 'N' && row[i + 1] == 'O' && text_det->north == NULL)
		text_det->north = parse_text_path(row, (i + 3));
	else if (row[i] == 'S' && row[i + 1] == 'O' && text_det->south == NULL)
		text_det->south = parse_text_path(row, (i + 3));
	else if (row[i] == 'W' && row[i + 1] == 'E' && text_det->west == NULL)
		text_det->west = parse_text_path(row, (i + 3));
	else if (row[i] == 'E' && row[i + 1] == 'A' && text_det->east == NULL)
		text_det->east = parse_text_path(row, (i + 3));
	else
		return (false); // TODO: Testar dando erro aqui, como que se comportará
	return (true);
}

bool	parse_tex_color(t_texture_det *text_det, char *row, int i)
{
	if (row[i + 1] != C_WHITE_S)
	{
		error_msg(ERR_RGB, 10);
		return (false);
	}
	if (row[i] == 'C' && text_det->ceiling == NULL)
	{
		text_det->ceiling = parse_rgb_color(row + i + 1);
		if (text_det->ceiling == 0)
			error_msg(ERR_RGB, 10);
	}
	else if (row[i] == 'F' && text_det->floor == NULL)
	{
		text_det->floor = parse_rgb_color(row + i + 1);
		if (text_det->floor == 0)
			error_msg(ERR_RGB, 10);
	}
	else
	{
		error_msg(ERR_RGB, 10);
		return (false);
	}
	return (true);
}

/**
 * @brief Will handle the lines of ceiling and floor. Will receive the line
 * with this information, and will set the structure variables corresponding to
 * this value.
 * @param row Row to be handle in file
 * @return int* pointer to int with the information about the RGB color
 */
static int	*parse_rgb_color(char *row)
{
	char	**str_rgb;
	int		i;
	int		*rgb;

	i = 0;
	str_rgb = ft_split(row, ',');
	while (str_rgb[i])
		i++;
	if (i != 3)
	{
		free_array_str(str_rgb);
		return (0);
	}
	rgb = ft_calloc(3, sizeof(int));
	if (!rgb)
	{
		error_msg(ERR_MALC, 0);
		return (0);
	}
	return (parse_arr_color(str_rgb, rgb));
}

/**
 * @brief Will parse the array string (with 3 number, represented to RGB color)
 * to a integer array
 * @param str_rgb array of rgb color
 * @param rgb rgb pointer integer parsed
 */
static int	*parse_arr_color(char **str_rgb, int *rgb)
{
	int	i;

	i = 0;
	while (str_rgb[i])
	{
		rgb[i] = ft_atoi(str_rgb[i]); // TODO: Testar passando letra aqui pra ver o q acontece / tratar exception
		i++;
	}
	free_array_str(str_rgb);
	return (rgb);
}

/**
 * @brief Extract the path of the Texture to be used. Calloc of -3 (2 char and
 * white space, but +1 to end string)
 * @param string
 * @param i Start index in a row with the value of texture
 * @return char* = Row with a value of texture
 */
static char	*parse_text_path(char *row, int i)
{
	int		len;
	char	*path;
	int		j;

	j = 0;
	// TODO: Pensar se tem que tratar espaço,q uebra de linha do usuário
	len = ft_strlen(row);
	path = ft_calloc(len - 2, sizeof(char));
	if (!path)
		return (NULL);
	while (row[i] && (is_white_space(row[i]) == false))
		path[j++] = row[i++];
	path[j] = '\0';
	return (path);
}
