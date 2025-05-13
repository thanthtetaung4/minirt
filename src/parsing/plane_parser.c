/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 23:24:16 by taung             #+#    #+#             */
/*   Updated: 2025/05/14 05:35:53 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int parse_plane(char *line, t_plane *plane)
{
	char	**split;

	split = ft_split(line, " \t\n");
	if (!split || !*split)
		return (1);
	if (ft_strslen(split) != 4 || parse_xyz(split[1], &plane->origin, 0) ||
		parse_xyz(split[2], &plane->v_origin, 0)||
		parse_rgb(split[3], &plane->color))
		return (free_strs(split), 1);
	free_strs(split);
	return (0);
}
