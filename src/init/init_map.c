/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:33:53 by rlins             #+#    #+#             */
/*   Updated: 2023/03/08 09:53:53 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_load_map_var(int *row, int *i, int *coll);
static int	lines_count(char *path);
static void	load_map(t_data *data);

void	init_map_handler(t_data *data, char *path)
{
	data->map_det.lines_count = lines_count(path);
	data->map_det.path = path;
	// TODO: Dar free neste cara depois
	data->map_det.file = ft_calloc(data->map_det.lines_count + 1,
			sizeof(char *));
	if (!data->map_det.file)
	{
		error_msg(ERR_MALC, 2);
		return ;
	}
	data->map_det.fd = open(path, O_RDONLY);
	if (data->map_det.fd < 0)
		error_msg(strerror(errno), 3);
	else
	{
		load_map(data);
		close(data->map_det.fd);
	}
}

/**
 * @brief Handle the number of lines of the map files.
 * @param path Path of the map
 * @return int Number of lines of the map
 */
static int	lines_count(char *path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_msg(strerror(errno), 3);
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free_ptr(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (line_count);
}

/**
 * @brief Initialize variables passed by ref. Just to avoid norminette:
 * functions huge
 * @param row 'row' variable
 * @param i 'i' variable
 * @param coll 'coll' variable
 */
static void	init_load_map_var(int *row, int *i, int *coll)
{
	*row = 0;
	*i = 0;
	*coll = 0;
}

/**
 * @brief Responsible to read the path, by GNL, and populate the map matrix
 * @param data Data Structure by ref
 */
static void	load_map(t_data *data)
{
	int		coll;
	int		i;
	int		row;
	char	*line;

	init_load_map_var(&row, &i, &coll);
	line = get_next_line(data->map_det.fd);
	while (line != NULL)
	{
		data->map_det.file[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->map_det.file[row])
		{
			error_msg(ERR_MALC, 2);
			return (free_array_str(data->map_det.file));
		}
		while (line[i] != '\0')
			data->map_det.file[row][coll++] = line[i++];
		data->map_det.file[row++][coll] = '\0';
		coll = 0;
		i = 0;
		free_ptr(line);
		line = get_next_line(data->map_det.fd);
	}
	data->map_det.file[row] = NULL;
}
