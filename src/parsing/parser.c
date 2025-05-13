/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:31:33 by taung             #+#    #+#             */
/*   Updated: 2025/05/13 22:22:19 by taung            ###   ########.fr       */
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

int	parser_helper(char **color_split, t_rgb *color)
{
	if (ft_atoi_vali(color_split[0], (&color->r)) == 0 ||
		ft_atoi_vali(color_split[1], (&color->g)) == 0 ||
		ft_atoi_vali(color_split[2], (&color->b)) == 0)
	{
		free_split(color_split);
		return (0);
	}
	return (1);
}

void free_helper(char **split, char **color_split)
{
	free_split(split);
	free_split(color_split);
}

int parse_ambient(char *line, t_ambient *ambient)
{
	char	**split;
	char	**color_split;

	split = ft_split(line, " ");
	color_split = ft_split(split[2], ",");
	if (!split)
		return (0);
	if (ft_strcmp(split[0], "A") != 0 || !split[1] || !split[2])
	{
		free_helper(split, color_split);
		return (0);
	}
	ambient->ratio = ft_atof(split[1]);
	if (ambient->ratio < 0 || ambient->ratio > 1)
	{
		free_helper(split, color_split);
		return (0);
	}
	if (parser_helper(color_split, &ambient->color) == 0)
	{
		free_helper(split, color_split);
		return (0);
	}
	free_helper(split, color_split);
	return (1);
}
