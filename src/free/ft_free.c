/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:07:39 by taung             #+#    #+#             */
/*   Updated: 2025/05/13 14:51:30 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	free_scene(t_data *data)
{
	int	i;

	i = 0;
	if (data->scene)
	{
		while (data->scene[i])
		{
			free(data->scene[i]);
			data->scene[i] = NULL;
			i++;
		}
		free(data->scene);
		data->scene = NULL;
	}
}

void	free_mlx(t_data *data)
{
	if (data->mlx)
	{
		if (data->mlx_win)
			mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
		data->mlx_win = NULL;
	}
}

void	free_all(t_data *data)
{
	if (data->mlx)
		free_mlx(data);
	if (data->scene)
		free_scene(data);
}
