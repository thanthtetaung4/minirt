/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_drag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 03:09:50 by aoo               #+#    #+#             */
/*   Updated: 2025/05/24 03:45:34 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	mouse_click(int btn, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	// printf("click got in\n");
	if (btn == 1)
	{
		data->mouse.mouse_drag = !data->mouse.mouse_drag;
		if (data->mouse.mouse_drag)
			printf("mouse pressed\n");
		else
			printf("mouse released\n");
	}
	return (0);
}

int	mouse_release(int btn, int x, int y, void *param)
{
	t_data	*data;
	
	data = (t_data *)param;
	if (btn == 1)
		printf("mouse released\n");
	return (0);
}

int mouse_move(int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->mouse.mouse_drag && data->mouse.funct)
	{
		data->mouse.x = x;
		data->mouse.y = y;
		data->mouse.funct(param);
	}
    return (0);
}

int	mouse_drag(int (*funct)(), void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->mouse.funct = funct;
	mlx_hook(data->mlx_win, 4, 1L << 2, mouse_click, param);	// ButtonPress
	mlx_hook(data->mlx_win, 5, 1L << 3, mouse_click, param);	// ButtonRelease
	mlx_hook(data->mlx_win, 6, 1L << 6, mouse_move, param);		// MotionNotify
	return (0);
}
