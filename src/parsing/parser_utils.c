/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:37:25 by taung             #+#    #+#             */
/*   Updated: 2025/06/26 05:26:23 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	res = gnl(fd);
	if (!res)
		return (0);
	while (res)
	{
		free(res);
		res = NULL;
		i++;
		res = gnl(fd);
	}
	close(fd);
	free(res);
	return (i);
}

int	check_range(float value, float min, float max)
{
	if (value < min || value > max)
		return (1);
	return (0);
}
