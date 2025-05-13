/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 23:24:16 by taung             #+#    #+#             */
/*   Updated: 2025/05/14 06:03:21 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

// int parse_sphere(char *line, t_sphere **sphere)
// {
// 	char	**split;

// 	split = ft_split(line, " \t\n");
// 	if (!split || !*split)
// 		return (1);
// 	if (ft_strslen(split) != 4 || parse_xyz(split[1], &sphere->origin, 0) || 
// 		!ft_atof_vali(split[2], &sphere->diameter) ||
// 		parse_rgb(split[3], &sphere->color))
// 		return (free_strs(split), 1);
// 	free_strs(split);
// 	return (0);
// }

int parse_sphere(char *line, t_list **spheres)
{
	char		**split;
	t_sphere 	sphere;
	t_sphere	*new_sphere;

	split = ft_split(line, " \t\n");
	if (!split || !*split)
		return (1);
	if (ft_strslen(split) != 4 || parse_xyz(split[1], &sphere.origin, 0) || 
		!ft_atof_vali(split[2], &sphere.diameter) ||
		parse_rgb(split[3], &sphere.color))
		return (free_strs(split), 1);
	free_strs(split);
	new_sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!new_sphere)
		return (1);
	*new_sphere = sphere;
	ft_lstadd_back(spheres, ft_lstnew(new_sphere));
	return (0);
}
