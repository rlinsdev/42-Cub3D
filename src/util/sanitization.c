/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:27:20 by rlins             #+#    #+#             */
/*   Updated: 2023/03/11 10:33:13 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	free_map(t_data *data);
static void	free_textures(t_texture_det *text_det);

void	free_ptr(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_array_str(char **arr_str)
{
	int	i;

	i = 0;
	if (arr_str)
	{
		while (arr_str[i])
		{
			if (arr_str[i])
			{
				free_ptr(arr_str[i]);
				arr_str[i] = NULL;
			}
			i++;
		}
		free(arr_str);
		arr_str = NULL;
	}
}

int	free_data(t_data *data)
{
	if (data)
	{
		free_textures(&data->texture_det);
		free_map(data);
	}
	return (EXIT_FAILURE);
}

/**
 * @brief Garbage collector to handle map detail variables
 * @param data Data structure (passed by ref)
 */
static void	free_map(t_data *data)
{
	if (data->map_det.fd > 0)
		close(data->map_det.fd);
	if (data->map_det.file)
		free_array_str(data->map_det.file);
	if (data->map)
		free_array_str(data->map);
}

/**
 * @brief Free the textures structure
 * @param text_det Texture Structure
 */
static void	free_textures(t_texture_det *text_det)
{
	if (text_det->north)
		free_ptr(text_det->north);
	if (text_det->south)
		free_ptr(text_det->south);
	if (text_det->west)
		free_ptr(text_det->west);
	if (text_det->east)
		free_ptr(text_det->east);
	if (text_det->floor)
		free_ptr(text_det->floor);
	if (text_det->ceiling)
		free_ptr(text_det->ceiling);
}
