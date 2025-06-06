/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 02:39:59 by taung             #+#    #+#             */
/*   Updated: 2025/06/07 07:07:51 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	print_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (1);
}

int	key_handle(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	printf("%d\n", keycode);
	if (keycode == 65307)
		close_win(data);
	else if (keycode == 32)
	{
		mlx_destroy_image(data->mlx, data->img.mlx_img);
		create_image(data);
	}
	return (0);
}

// Image test
void	put_image_back(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.mlx_img, 0, 0);
}

void	img_pixel_put(t_data *data, int x, int y, int color)
{
	int	pos;

	if (x < 0 || x > data->win_width || y < 0 || y > data->win_height)
		return ;
    pos = y * data->img.size_line + x * (data->img.bbp / 8);
    *(unsigned int *)(data->img.mlx_img_data + pos) = color;
	put_image_back(data);
}

void	create_image(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	data->img.mlx_img_data = mlx_get_data_addr(data->img.mlx_img, &data->img.bbp, &data->img.size_line, &data->img.endian);
	put_image_back(data);
}

// Mouse Test
int	test_mouse_drag(void *param)
{
	t_mouse	mouse;

	mouse = ((t_data *)param)->mouse;
	printf("x : %d, y : %d\n", mouse.x, mouse.y);
	if (!((t_data *)param)->img.mlx_img)
		return (0);
	img_pixel_put((t_data *)param, mouse.x, mouse.y, 0xFF0000);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_rgb	color;
	t_xyz	origin;
	// if (argc != 2 || !ft_strstr(argv[1], ".rt"))
	// 	return (print_error("Error: Invalid file!\n"));
	ft_bzero(&data, sizeof(data));
	data.win_width = 1500;
	data.win_height = 800;
	if (parser("test.rt", &data))
		return (free_all(&data), print_error("Error: Parsing!\n"));
	print_data(data);
	// data.mlx = mlx_init();
	// data.mlx_win = mlx_new_window(data.mlx, data.win_width, data.win_height, "Hello World");
	// create_image(&data);
	// // DestoryNotify 17, NoEventMask 0
	// mlx_hook(data.mlx_win, 17, 0, close_win, &data);
	// mlx_key_hook(data.mlx_win, key_handle, &data);

	// ft_lstiter_param(data.spheres, draw_circle, &data);
	// // printf("x : %f, y : %f\n", ((t_sphere *)data.spheres->data)->origin.x, ((t_sphere *)data.spheres)->origin.y);
	// // circle(&data);
	// // Test
	// // mouse_drag(test_mouse_drag, &data);

	// mlx_loop(data.mlx);
	// if (parse_ambient(data.scene[1], &data.ambient) == 0)
	// {
	// 	ft_putstr_fd("Error: Invalid ambient\n", 2);
	// 	free_all(&data);
	// 	return (1);
	// }
	free_all(&data);
	return (0);
}
