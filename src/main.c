/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:20:20 by taung             #+#    #+#             */
/*   Updated: 2025/06/21 14:33:28 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int	pos;

	if (x < 0 || x > data->win_width || y < 0 || y > data->win_height)
		return ;
	pos = y * data->img.size_line + x * (data->img.bbp / 8);
	*(unsigned int *)(data->img.mlx_img_data + pos) = color;
}


int	main(void) {
	// printf("random number is: %d", ft_rand(0, 255));

	t_data	data;

	data.win_height = 800;
	data.win_width = 800;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.win_width, data.win_height, "Random Colors");
	data.img.mlx_img = mlx_new_image(data.mlx, data.win_width, data.win_height);
	data.img.mlx_img_data = mlx_get_data_addr(data.img.mlx_img, &data.img.bbp, &data.img.size_line, &data.img.endian);
	printf("image details\nbpp: %d\nsize_line: %d\nendian: %d\n", data.img.bbp, data.img.size_line, data.img.endian);
	for (int i = 0; i <= 800; i++)
	{
		for (int j = 0; j <= 800; j++)
		{
			if (j < 200)
				my_mlx_pixel_put(&(data), i, j, 0x00FF00);
			else if (j >= 200 && j <= 400)
				my_mlx_pixel_put(&(data), i, j, 0xFF0000);
			else if (j >= 400 && j <= 600)
				my_mlx_pixel_put(&(data), i, j, 0x0000FF);
			else
				my_mlx_pixel_put(&(data), i, j, 0xFFFFFF);
		}
	}
	// my_mlx_pixel_put(&(data), 5, 5, 0x00FF0000);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.mlx_img, 0, 0);
	mlx_loop(data.mlx);
}
