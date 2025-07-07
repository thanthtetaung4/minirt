
#include "minirt.h"

int	print_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (1);
}

int init_data(t_data *data)
{
	ft_bzero(data, sizeof(*data));
	if (parser("test.rt", data))
		return (print_error("Error: Parsing!\n"));
	// print_data(*data);
	if (init_win(data))
		return (1);
	return (0);
}

// Mouse Test

int	main(int argc, char **argv)
{
	t_data	data;

	// if (argc != 2 || !ft_strstr(argv[1], ".rt"))
	// 	return (print_error("Error: Invalid file!\n"));
	if (init_data(&data))
		return (free_all(&data), print_error("data initialtion failed!\n"));
	print_data(data);
	init_image(&data);
	put_image_back(&data);
	// mouse_drag(mouse_drag_draw, &data);
	mlx_loop(data.mlx);
	// create_image(&data);
	// // DestoryNotify 17, NoEventMask 0
	// mlx_hook(data.mlx_win, 17, 0, close_win, &data);
	// mlx_key_hook(data.mlx_win, key_handle, &data);

	// ft_lstiter_param(data.spheres, draw_circle, &data);
	// printf("x : %f, y : %f\n", ((t_sphere *)data.spheres->data)->origin.x, ((t_sphere *)data.spheres)->origin.y);
	// circle(&data);
	// Test
	// mouse_drag(test_mouse_drag, &data);

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
