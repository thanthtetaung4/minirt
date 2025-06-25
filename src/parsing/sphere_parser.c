/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 23:24:16 by taung             #+#    #+#             */
/*   Updated: 2025/06/26 07:10:57 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int parse_sphere(char *line, t_list **spheres)
{
	char	**split;
	t_sphere	*m_sphere;
	t_sphere	sphere;

	split = ft_split(line, " \t\n");
	if (!split || !*split)
		return (1);
	if (ft_strslen(split) != 4 || parse_xyz(split[1], &sphere.origin, 0) ||
		!ft_atof_vali(split[2], &sphere.diameter) ||
		sphere.diameter <= 0 ||
		parse_rgb(split[3], &sphere.color))
		return (free_strs(split), 1);
	free_strs(split);
	m_sphere = malloc(sizeof(t_sphere));
	if (!m_sphere)
		return (1);
	*m_sphere = sphere;
	printf("done\n");
	ft_lstadd_back(spheres, ft_lstnew(m_sphere));
	return (0);
}
