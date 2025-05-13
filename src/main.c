/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 02:39:59 by taung             #+#    #+#             */
/*   Updated: 2025/05/14 01:03:51 by taung            ###   ########.fr       */
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

	// if (argc != 2 || !ft_strstr(argv[1], ".rt"))
	// 	return (error_exit("Error: Invalid file!\n"));
	ft_bzero(&data, sizeof(data));

	if (parser("test.rt", &data))
		return (print_error("Error: Parsing!\n"));
	print_data(data);
	printf("%f, %d, %d ,%d\n", data.ambient.ratio, data.ambient.color.r, data.ambient.color.g, data.ambient.color.b);
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
