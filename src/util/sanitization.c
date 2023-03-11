/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:27:20 by rlins             #+#    #+#             */
/*   Updated: 2023/03/11 08:43:55 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	free_map(t_data *data);

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
		free_map(data);
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
