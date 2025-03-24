/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_ctrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 01:46:33 by taung             #+#    #+#             */
/*   Updated: 2025/03/25 02:44:09 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	close_win(t_data *data)
{
	if (data->mlx && data->mlx_win)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		data->mlx_win = NULL;
		ft_putstr_fd("U QUIT GAME OVER!\n", 1);
		free_all(data);
		exit(0);
	}
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		data->mlx_win = NULL;
		ft_putstr_fd("YOU QUIT GAME OVER!\n", 1);
	}
	else
	{
		if (keysym == XK_w)
			move_player(data, 0, -1);
		else if (keysym == XK_a)
			move_player(data, -1, 0);
		else if (keysym == XK_s)
			move_player(data, 0, 1);
		else if (keysym == XK_d)
			move_player(data, 1, 0);
		else
			ft_putstr_fd("PRESS WASD!\n", 1);
	}
	return (0);
}
