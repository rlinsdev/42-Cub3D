/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:24:17 by lucas             #+#    #+#             */
/*   Updated: 2023/03/11 12:28:25 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	*ft_mlx_get_addr(t_img *img)
{
	if (!img->img)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Failed to create image\n", STDERR_FILENO);
		return (NULL);
	}
	return (mlx_get_data_addr(img->img, &img->bpp, &img->len_line,
			&img->endian));
}

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->len_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
