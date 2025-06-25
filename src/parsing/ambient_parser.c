/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 23:24:16 by taung             #+#    #+#             */
/*   Updated: 2025/06/26 05:15:05 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int parse_ambient(char *line, t_ambient *ambient)
{
	char	**split;

	split = ft_split(line, " \t\n");
	if (!split || !*split)
		return (1);
	if (ft_strslen(split) != 3 || !ft_atof_vali(split[1], &ambient->ratio) ||
		check_range(ambient->ratio, 0.0, 1.0))
		return (free_strs(split), 1);
	if (parse_rgb(split[2], &ambient->color))
		return (free_strs(split), 1);
	ambient->color.r /= 255.0f;
	ambient->color.g /= 255.0f;
	ambient->color.b /= 255.0f;
	free_strs(split);
	return (0);
}
