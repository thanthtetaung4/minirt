/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:31:33 by taung             #+#    #+#             */
/*   Updated: 2025/06/26 05:15:09 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_rgb(char *str, t_rgb *color)
{
	char	**rgb;

	rgb = ft_split(str, ",");
	if (ft_strslen(rgb) != 3)
		return (free_strs(rgb), 1);
	if (ft_atoi_vali(rgb[0], &color->r) && !check_range(color->r, 0, 255))
	{
		if (ft_atoi_vali(rgb[1], &color->g) && !check_range(color->g, 0, 255))
		{
			if (ft_atoi_vali(rgb[2], &color->b) && !check_range(color->b, 0, 255))
				return (free_strs(rgb), 0);
		}
	}
	free_strs(rgb);
	return (1);
}

int	parse_xyz(char *str, t_vec3 *origin, int vector)
{
	char	**xyz;

	xyz = ft_split(str, ",");
	if (ft_strslen(xyz) != 3)
		return (free_strs(xyz), 1);
	if (ft_atof_vali(xyz[0], &origin->x) && ft_atof_vali(xyz[1], &origin->y) &&
		ft_atof_vali(xyz[2], &origin->z))
	{
		free_strs(xyz);
		if (vector)
		{
			if (check_range(origin->x, -1, 1) || check_range(origin->y, -1, 1)
			|| check_range(origin->z, -1, 1))
				return (free_strs(xyz), 1);
		}
		return (0);
	}
	free_strs(xyz);
	return (1);
}

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
		if (parse_sphere(res, &data->spheres))
			return (free_strs(split), print_error("Error: Invalid sphere!\n"));
		data->sphere_count++;
	}
	else if (ft_strcmp(split[0], "pl") == 0)
	{
		if (parse_plane(res, &data->planes))
			return (free_strs(split), print_error("Error: Invalid plane!\n"));
		data->plane_count++;
	}
	else if (ft_strcmp(split[0], "cy") == 0)
	{
		if (parse_cylinder(res, &data->cylinders))
			return (free_strs(split), print_error("Error: Invalid cylinder!\n"));
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
		if (*res != '\n' && (scene_parser(res, data) != 0 || object_parser(res, data) != 0))
		{
			free(res);
			free_all(data);
			return (close(fd) || 1);
		}
		free(res);
		res = get_next_line(fd);
		i++;
	}
	free(res);
	return (close(fd) && 0);
}
