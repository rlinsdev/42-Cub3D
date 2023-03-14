/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:04:23 by rlins             #+#    #+#             */
/*   Updated: 2023/03/14 10:11:15 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static bool	val_file_ext(char *file, char c1, char c2, char c3);

// TODO: Chamar quando for executar os muros
bool	val_xpm_file(char *file)
{
	return (val_file_ext(file, 'x', 'p', 'm'));
}

bool	val_cub_file(char *file)
{
	return (val_file_ext(file, 'c', 'u', 'b'));
}

/**
 * @brief Generic method to validate any type of file. Will validate 4 last
 * char in a file, verifying if the file is greater than 4 size.
 * @param file file name
 * @param c1 char 1 in sentence
 * @param c2 char 2 in sentence
 * @param c3 char 3 in sentence
 * @return boolean. Validate or not
 */
static bool	val_file_ext(char *file, char c1, char c2, char c3)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4)
		return (false);
	if (file[len - 4] != '.' || file[len - 3] != c1 || file[len - 2] != c2
		|| file[len - 1] != c3)
		return (false);
	return (true);
}

bool	val_file_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}
