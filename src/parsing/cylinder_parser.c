/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 23:24:16 by taung             #+#    #+#             */
/*   Updated: 2025/05/14 05:05:11 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int parse_cylinder(char *line, t_cylinder *cylinder)
{
	char	**split;

	split = ft_split(line, " \t\n");
	if (!split || !*split)
		return (1);
	if (ft_strslen(split) != 6 || parse_xyz(split[1], &cylinder->origin, 0) ||
		parse_xyz(split[2], &cylinder->v_origin, 0)||
		!ft_atof_vali(split[3], &cylinder->diameter)||
		cylinder->diameter <= 0 ||
		!ft_atof_vali(split[4], &cylinder->height)||
		cylinder->height > 0 ||
		parse_rgb(split[5], &cylinder->color))
		return (free_strs(split), 1);
	free_strs(split);
	return (0);
}
