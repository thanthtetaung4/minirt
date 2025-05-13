/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 02:39:59 by taung             #+#    #+#             */
/*   Updated: 2025/05/13 22:03:01 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../inc/print.h"

int	error_exit()
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

int	main(int argc, char **argv)
{
	// if (argc != 2 || !ft_strstr(argv[1], ".rt"))
		// return (error_exit());
	t_data	data;
	ft_bzero(&data, sizeof(data));
	print_data(data);
	// if (parser("./scene/test.rt", &data) == 0)
	// {
	// 	ft_putstr_fd("Error: Invalid file\n", 2);
	// 	return (1);
	// }
	// print_2d_array(data.scene);
	// data.mlx = mlx_init();
	// data.mlx_win = mlx_new_window(data.mlx, 800, 600, "Hello World");
	// mlx_hook(data.mlx_win, DestroyNotify, NoEventMask, close_win, &data);
	// mlx_loop(data.mlx);

	// free_all(&data);
	return (0);
}
