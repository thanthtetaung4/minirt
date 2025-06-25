/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:50:09 by taung             #+#    #+#             */
/*   Updated: 2025/06/26 05:39:08 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void init_data(t_data *data)
{
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->scene = NULL;

}

void	init_win(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->win_height, "Hello World");
	// create_image(&data);
	// // DestoryNotify 17, NoEventMask 0
	mlx_hook(data.mlx_win, 17, 0, close_win, &data);
	// mlx_key_hook(data.mlx_win, key_handle, &data);

	// ft_lstiter_param(data.spheres, draw_circle, &data);
	// printf("x : %f, y : %f\n", ((t_sphere *)data.spheres->data)->origin.x, ((t_sphere *)data.spheres)->origin.y);
	// circle(&data);
	// Test
	// mouse_drag(test_mouse_drag, &data);

	// mlx_loop(data.mlx);
	// if (parse_ambient(data.scene[1], &data.ambient) == 0)
	// {
	// 	ft_putstr_fd("Error: Invalid ambient\n", 2);
	// 	free_all(&data);
	// 	return (1);
	// }
}
