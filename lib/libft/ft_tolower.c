/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:23:10 by rlins             #+#    #+#             */
/*   Updated: 2022/04/03 20:23:44 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int argument)
{
	if (argument >= 'A' && argument <= 'Z')
		argument = argument + 32;
	return (argument);
}
