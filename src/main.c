/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 02:39:59 by taung             #+#    #+#             */
/*   Updated: 2025/05/14 01:41:10 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../inc/print.h"

int	print_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_rgb	color;
	t_xyz	origin;
	// if (argc != 2 || !ft_strstr(argv[1], ".rt"))
	// 	return (print_error("Error: Invalid file!\n"));
	ft_bzero(&data, sizeof(data));
	if (parser_rgb("0,255,255", &color))
		return (print_error("shit\n"));
	print_rgb(color);
	if (parser_xyz("1.0, 0.0, -1.2", &origin, 0))
		return (print_error("shit\n"));
	print_xyz(origin);
	// if (parser("test.rt", &data) == 0)
	// 	return (print_error("Error: Invalid file!\n"));
	// print_data(data);
	// data.mlx = mlx_init();
	// data.mlx_win = mlx_new_window(data.mlx, 800, 600, "Hello World");
	// mlx_hook(data.mlx_win, DestroyNotify, NoEventMask, close_win, &data);
	// mlx_loop(data.mlx);
	// if (parse_ambient(data.scene[1], &data.ambient) == 0)
	// {
	// 	ft_putstr_fd("Error: Invalid ambient\n", 2);
	// 	free_all(&data);
	// 	return (1);
	// }

	// free_all(&data);
	return (0);
}
