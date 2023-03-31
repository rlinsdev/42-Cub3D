/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:24:17 by lucas             #+#    #+#             */
/*   Updated: 2023/03/30 08:03:05 by rlins            ###   ########.fr       */
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
	return (mlx_get_data_addr(img->img, &img->pixel_bits, &img->size_line,
			&img->endian));
}

void	ft_mlx_put_img(t_view *view, t_img *img, int x, int y)
{
	mlx_put_image_to_window(view->mlx, view->win, img->img, x, y);
}

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	if (img == NULL || x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	*(unsigned int *)(img->addr + (y * img->size_line + x * (img->pixel_bits
					/ BITS_PER_BYTE))) = color;
}
