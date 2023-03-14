/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:07:38 by rlins             #+#    #+#             */
/*   Updated: 2022/12/16 08:11:27 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
