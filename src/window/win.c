/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 01:46:33 by taung             #+#    #+#             */
/*   Updated: 2025/06/26 07:29:27 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_win(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (print_error("mlx initiation failed!\n"));
	data->mlx_win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Hello World");
	if (!data->mlx_win)
		return (print_error("mlx window initiation failed!\n"));
	mlx_hook(data->mlx_win, 17, 0, close_win, data);
	mlx_key_hook(data->mlx_win, key_handle, data);
	return (0);
}

int	close_win(t_data *data)
{
	if (data->mlx && data->mlx_win)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		data->mlx_win = NULL;
		ft_putstr_fd("U CLOSE THE WINDOW!\n", 1);
		free_all(data);
		exit(0);
	}
	return (0);
}

int	key_handle(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	printf("%d\n", keycode);
	if (keycode == 65307 || keycode == 53)
		close_win(data);
	else if (keycode == 32)
	{
		mlx_destroy_image(data->mlx, data->img.mlx_img);
		init_image(data);
	}
	return (0);
}
