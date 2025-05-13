/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:37:25 by taung             #+#    #+#             */
/*   Updated: 2025/05/13 12:37:36 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	count_row(const char *path)
{
	int		fd;
	char	*res;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("INVALID PATH\n", 2);
		return (0);
	}
	res = get_next_line(fd);
	if (!res)
		return (0);
	while (res)
	{
		free(res);
		res = NULL;
		i++;
		res = get_next_line(fd);
	}
	close(fd);
	free(res);
	return (i);
}
