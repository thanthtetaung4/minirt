#include "minirt.h"

// void	draw_circle(void *lst_data, void *param)
// {
// 	t_sphere	*sphere;
// 	t_data		*data;
// 	float		radius;
// 	float		i;

// 	i = 0;
// 	sphere = (t_sphere *)lst_data;
// 	data = (t_data *)param;
// 	radius = sphere->diameter / 2;
// 	while (i < 360)
// 	{
// 		img_pixel_put(data, sphere->origin.x + radius * cos(i * M_PI / 180.0), \
// 							sphere->origin.y + radius * sin(i * M_PI / 180.0), \
// 							color(sphere->color));
// 		i += 0.1;
// 	}
// 	put_image_back(data);
// }


void	draw_circle_line(t_sphere *sphere, t_data *data, int x, int y)
{
	int	origin_x;
	int	origin_y;
	int	color;

	origin_x = sphere->origin.x;
	origin_y = sphere->origin.y;
	color = ft_color(sphere->color);
	img_pixel_put(data, origin_x + x, origin_y + y, color);
	img_pixel_put(data, origin_x - x, origin_y + y, color);
	img_pixel_put(data, origin_x + x, origin_y - y, color);
	img_pixel_put(data, origin_x - x, origin_y - y, color);
	img_pixel_put(data, origin_x + y, origin_y + x, color);
	img_pixel_put(data, origin_x - y, origin_y + x, color);
	img_pixel_put(data, origin_x + y, origin_y - x, color);
	img_pixel_put(data, origin_x - y, origin_y - x, color);
}

// void	draw_circle(void *lst_data, void *param)
// {
// 	t_sphere	*sphere;
// 	t_data		*data;
// 	float		radius;
// 	float		i;

// 	i = 0;
// 	sphere = (t_sphere *)lst_data;
// 	data = (t_data *)param;
// 	radius = sphere->diameter / 2;
// 	while (i < 360)
// 	{
// 		img_pixel_put(data, sphere->origin.x + radius * cos(i * M_PI / 180.0), \
// 							sphere->origin.y + radius * sin(i * M_PI / 180.0), \
// 							color(sphere->color));
// 		i += 0.1;
// 	}
// 	put_image_back(data);
// }


// void	draw_circle_line(t_sphere *sphere, t_data *data, int x, int y)
// {
// 	int	origin_x;
// 	int	origin_y;
// 	int	color;

// 	origin_x = sphere->origin.x;
// 	origin_y = sphere->origin.y;
// 	color = ft_color(sphere->color);
// 	img_pixel_put(data, origin_x + x, origin_y + y, color);
// 	img_pixel_put(data, origin_x - x, origin_y + y, color);
// 	img_pixel_put(data, origin_x + x, origin_y - y, color);
// 	img_pixel_put(data, origin_x - x, origin_y - y, color);
// 	img_pixel_put(data, origin_x + y, origin_y + x, color);
// 	img_pixel_put(data, origin_x - y, origin_y + x, color);
// 	img_pixel_put(data, origin_x + y, origin_y - x, color);
// 	img_pixel_put(data, origin_x - y, origin_y - x, color);
// }

void	draw_circle(void *lst_data, void *param)
{
	t_sphere	*sphere;
	int			x;
	int			y;
	int			d;

	sphere = (t_sphere *)lst_data;
	x = 0;
	y = sphere->diameter / 2;
	d = 3 - (sphere->diameter);
	while (x <= y)
	{
		draw_circle_line(sphere, (t_data *)param, x, y);
		if (d < 0)
			d += 4 * x + 6;
		else
		{
			d += 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
	put_image_back((t_data *)param);
}
 