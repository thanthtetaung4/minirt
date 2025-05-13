/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_ctrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 01:46:33 by taung             #+#    #+#             */
/*   Updated: 2025/05/13 20:11:32 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

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
