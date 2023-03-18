/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:24:17 by lucas             #+#    #+#             */
/*   Updated: 2023/03/18 04:37:22 by lucas            ###   ########.fr       */
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
	return (mlx_get_data_addr(img->img, &img->data[0], &img->data[1],
			&img->data[2]));
}

void	ft_mlx_put_img(t_view *view, t_img *img, int x, int y)
{
	mlx_put_image_to_window(view->mlx, view->win, img->img, x, y);
}

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	static char	*dst;

	dst = img->addr + (y * img->data[1] + x * (img->data[0] / 8));
	*(unsigned int *)dst = color;
}
