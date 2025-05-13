/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:31:33 by taung             #+#    #+#             */
/*   Updated: 2025/05/14 01:03:19 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	scene_parser(char *res, t_data *data)
{
	char	**split;

	printf("res: %s\n", res);
	split = ft_split(res, " \t\n");
	if (ft_strcmp(split[0], "A") == 0)
	{
		if (parse_ambient(res, &data->ambient))
			return (print_error("Error: Invalid ambient!\n"));
		data->ambient_count++;
	}
	else if (ft_strcmp(split[0], "c") == 0)
	{
		if (parse_camera(res, &data->camera))
			return (print_error("Error: Invalid camera!\n"));
		data->camera_count++;
	}
	else if (ft_strcmp(split[0], "l") == 0)
	{
		if (parse_light(res, &data->light))
			return (print_error("Error: Invalid light!\n"));
		data->light_count++;
	}
	free_split(split);
	return (0);
}

int	object_parser(char *res, t_data *data)
{
	char	**split;

	split = ft_split(res, " \t\n");
	if (ft_strcmp(split[0], "sp") == 0)
	{
		if (parse_sphere(res, &data->sphere))
			return (print_error("Error: Invalid sphere!\n"));
		data->sphere_count++;
	}
	else if (ft_strcmp(split[0], "pl") == 0)
	{
		if (parse_plane(res, &data->plane))
			return (print_error("Error: Invalid plane!\n"));
		data->plane_count++;
	}
	else if (ft_strcmp(split[0], "cy") == 0)
	{
		if (parse_cylinder(res, &data->cylinder))
			return (print_error("Error: Invalid cylinder!\n"));
		data->cylinder_count++;
	}
	free_split(split);
	return (0);
}

int	parser(char *filename, t_data *data)
{
	int		fd;
	char	*res;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (print_error("Error: Invalid path!\n"));
	res = get_next_line(fd);
	while (res)
	{
		if (scene_parser(res, data) != 0 || object_parser(res, data) != 0)
		{
			free(res);
			break;
		}
		free(res);
		res = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}
