#include "minirt.h"

void	init_image(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img.mlx_img_data = mlx_get_data_addr(data->img.mlx_img, &data->img.bbp, &data->img.size_line, &data->img.endian);
}

void	put_image_back(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.mlx_img, 0, 0);
}

void	img_pixel_put(t_data *data, int x, int y, int color)
{
	int	pos;

	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
		return ;
    pos = y * data->img.size_line + x * (data->img.bbp / 8);
    *(unsigned int *)(data->img.mlx_img_data + pos) = color;
	put_image_back(data);
}
