#include "../inc/minirt.h"

void	draw_circle(void *lst_data, void *param)
{
	t_sphere	*sphere;
	t_data		*data;
	float		radius;
	float		i;

	i = 0;
	sphere = (t_sphere *)lst_data;
	data = (t_data *)param;
	radius = sphere->diameter / 2;
	while (i < 360)
	{
		img_pixel_put(data, sphere->origin.x + radius * cos(i * M_PI / 180.0), \
							sphere->origin.y + radius * sin(i * M_PI / 180.0), \
							color(sphere->color));
		i += 0.1;
	}
	put_image_back(data);
}
