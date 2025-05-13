/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 23:24:16 by taung             #+#    #+#             */
/*   Updated: 2025/05/14 00:16:51 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

// int	parser_helper(char **color_split, t_rgb *color)
// {
// 	if (ft_atoi_vali(color_split[0], (&color->r)) == 0 ||
// 		ft_atoi_vali(color_split[1], (&color->g)) == 0 ||
// 		ft_atoi_vali(color_split[2], (&color->b)) == 0)
// 	{
// 		free_split(color_split);
// 		return (0);
// 	}
// 	return (1);
// }

// void free_helper(char **split, char **color_split)
// {
// 	free_split(split);
// 	free_split(color_split);
// }

int parse_light(char *line, t_light *light)
{
	// char	**split;
	// char	**color_split;

	// split = ft_split(line, " \t");
	// color_split = ft_split(split[2], ",");
	// if (!split)
	// 	return (1);
	// if (ft_strcmp(split[0], "A") != 0 || !split[1] || !split[2])
	// {
	// 	free_helper(split, color_split);
	// 	return (1);
	// }
	// ambient->ratio = ft_atof(split[1]);
	// if (ambient->ratio < 0 || ambient->ratio > 1)
	// {
	// 	free_helper(split, color_split);
	// 	return (1);
	// }
	// if (parser_helper(color_split, &ambient->color) == 0)
	// {
	// 	free_helper(split, color_split);
	// 	return (1);
	// }
	// free_helper(split, color_split);
	return (0);
}
