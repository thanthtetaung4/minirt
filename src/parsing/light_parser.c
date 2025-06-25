/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 23:24:16 by taung             #+#    #+#             */
/*   Updated: 2025/06/10 05:54:19 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int parse_light(char *line, t_light *light)
{
	char	**split;

	split = ft_split(line, " \t\n");
	if (!split || !*split)
		return (1);
	if (ft_strslen(split) != 4 || parse_xyz(split[1], &light->origin, 0) ||
	!ft_atof_vali(split[2], &light->ratio) ||
	check_range(light->ratio, 0.0, 1.0) ||
	parse_rgb(split[3], &light->color)) 
		return (free_strs(split), 1);
	return (free_strs(split), 0);
}
