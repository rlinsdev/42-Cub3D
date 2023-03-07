/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:33:53 by rlins             #+#    #+#             */
/*   Updated: 2023/03/07 14:50:16 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_load_map_var(int *row, int *i, int *coll);

void	init_map_handler(t_data *data, char *path)
{
	data->map_det.lines_count = 10; // TODO Calcular isso depois
	data->map_det.path = path;
	// TODO: Dar free neste cara depois
	data->map_det.file = malloc(data->map_det.lines_count + 1 * sizeof(char *));
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
		// TODO: LoadMap
		close(data->map_det.fd);
	}
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
	row = 0;
	i = 0;
	coll = 0;
}

/**
 * @brief Responsible to read the path, by GNL, and populate the map matrix
 * @param data Data Structure by ref
 */
static void	load_map(t_data *data)
{
	int		row;
	int		i;
	int		coll;
	char	*line;

	init_load_map_var(&row, &i, &coll);
	line = get_next_line(data->map_det.fd);
	if (!line)
	{
		data->map_det.file[row] = malloc(ft_strlen(line) + 1 * sizeof(char));
		if (!data->map_det.file[row])
		{
			error_msg(ERR_MALC, 2);
			return ; // TODO: Aqui tem que dar free nas alocações anteriores
		}
		while (line[i] != '\0')
			data->map_det.file[row][coll++] = line[i++];
		data->map_det.file[row++][coll] = '\0';
		coll = 0;
		i = 0;
		free(line);
		line = get_next_line(data->map_det.fd);
	}
	data->map_det.file[row] = NULL;
}
