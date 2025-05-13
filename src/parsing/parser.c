/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:31:33 by taung             #+#    #+#             */
/*   Updated: 2025/05/13 12:51:31 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	parser(char *filename, t_data *data)
{
	int		fd;
	char	*res;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("INVALID PATH\n", 2);
		return (0);
	}
	data->scene = malloc(sizeof(char *) * (count_row(filename) + 1));
	if (!data->scene)
		return (0);
	res = get_next_line(fd);
	while (res)
	{
		data->scene[i] = ft_strdup(res);
		free(res);
		res = get_next_line(fd);
		i++;
	}
	data->scene[i] = NULL;
	close(fd);
	return (1);
}
