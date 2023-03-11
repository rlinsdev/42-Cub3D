/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 04:01:41 by rlins             #+#    #+#             */
/*   Updated: 2023/03/11 00:55:54 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hexa(unsigned int nbr, char spec)
{
	int		count;
	char	*str;

	if (spec == 'x')
		str = ft_itoa_base(nbr, HEX_BASE_LOWER);
	else
		str = ft_itoa_base(nbr, HEX_BASE_UPPER);
	count = ft_putstr(str);
	ft_free(str);
	return (count);
}
