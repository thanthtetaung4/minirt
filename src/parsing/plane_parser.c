/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 23:24:16 by taung             #+#    #+#             */
/*   Updated: 2025/06/10 05:54:25 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int parse_plane(char *line, t_list **planes)
{
	char	**split;
	t_plane	*m_plane;
	t_plane	plane;

	split = ft_split(line, " \t\n");
	if (!split || !*split)
	return (1);
	if (ft_strslen(split) != 4 || parse_xyz(split[1], &plane.origin, 0) ||
		parse_xyz(split[2], &plane.v_origin, 0)||
		parse_rgb(split[3], &plane.color))
		return (free_strs(split), 1);
	m_plane = malloc(sizeof(t_plane));
	if (!m_plane)
		return (1);
	*m_plane = plane;
	ft_lstadd_back(planes, ft_lstnew(m_plane));
	free_strs(split);
	return (0);
}
