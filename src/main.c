/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 02:39:59 by taung             #+#    #+#             */
/*   Updated: 2025/05/13 22:11:01 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	main(void)
{
	printf("hello\n");
	t_data	data;
	if (parser("./scene/test.rt", &data) == 0)
	{
		ft_putstr_fd("Error: Invalid file\n", 2);
		return (1);
	}
	print_2d_array(data.scene);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 800, 600, "Hello World");
	mlx_hook(data.mlx_win, DestroyNotify, NoEventMask, close_win, &data);
	mlx_loop(data.mlx);
	if (parse_ambient(data.scene[1], &data.ambient) == 0)
	{
		ft_putstr_fd("Error: Invalid ambient\n", 2);
		free_all(&data);
		return (1);
	}

	free_all(&data);
	return (0);
}
