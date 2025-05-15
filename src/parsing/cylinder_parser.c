/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 23:24:16 by taung             #+#    #+#             */
/*   Updated: 2025/05/15 13:30:13 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int parse_cylinder(char *line, t_list **cylinders)
{
	char	**split;
	t_cylinder	*m_cylinder;
	t_cylinder	cylinder;

	split = ft_split(line, " \t\n");
	if (!split || !*split)
	return (1);
	if (ft_strslen(split) != 6 || parse_xyz(split[1], &cylinder.origin, 0) ||
	parse_xyz(split[2], &cylinder.v_origin, 0)||
	!ft_atof_vali(split[3], &cylinder.diameter)||
		cylinder.diameter <= 0 ||
		!ft_atof_vali(split[4], &cylinder.height)||
		cylinder.height <= 0 ||
		parse_rgb(split[5], &cylinder.color))
		return (free_strs(split), 1);
	m_cylinder = malloc(sizeof(t_cylinder));
	if (!m_cylinder)
		return (1);
	*m_cylinder = cylinder;
	ft_lstadd_back(cylinders, ft_lstnew(m_cylinder));
	free_strs(split);
	return (0);
}
