/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:22:49 by rlins             #+#    #+#             */
/*   Updated: 2023/03/08 10:02:18 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	args_handler(t_data *data, char **argv);

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (error_msg(ERR_ARGS, 1));
	init_data(&data);
	args_handler(&data, argv);
	free_data(&data);
	return (0);
}

/**
 * @brief Will populate structures by params / handler arguments
 * @param data Data structure
 * @param argv Argument vector
 */
static void	args_handler(t_data *data, char **argv)
{
	init_map_handler(data, argv[1]);
}
