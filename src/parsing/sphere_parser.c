/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 23:24:16 by taung             #+#    #+#             */
/*   Updated: 2025/05/15 12:51:16 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int parse_sphere(char *line, t_list **spheres)
{
	char	**split;
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	split = ft_split(line, " \t\n");
	if (!split || !*split)
		return (1);
	if (ft_strslen(split) != 4 || parse_xyz(split[1], &sphere->origin, 0) ||
		!ft_atof_vali(split[2], &sphere->diameter) ||
		sphere->diameter <= 0 ||
		parse_rgb(split[3], &sphere->color))
		return (free_strs(split), 1);
	ft_lstadd_back(spheres, ft_lstnew(sphere));
	free_strs(split);
	return (0);
}
