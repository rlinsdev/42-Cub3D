/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:56:07 by rlins             #+#    #+#             */
/*   Updated: 2022/12/18 16:56:39 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str, size_t size)
{
	char	*temp;

	if (!str)
		return (NULL);
	else
	{
		temp = (char *)malloc(sizeof(char) * (size));
		ft_strlcpy(temp, str, size + 1);
		free(str);
	}
	if (!temp)
		return (NULL);
	return (temp);
}
