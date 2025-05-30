#include "../inc/minirt.h"

// void	draw_circle(t_data *data)
// {
// 	t_sphere	*sphere;
// 	float		x;
// 	float		y;
// 	float		rad;

// 	sphere = ((t_sphere *)data->spheres->data);

// 	// printf("x: %f, y : %f\n", x, y);
// 	for (float i = 0; i < 360; i += 1)
// 	{
// 		rad = i * M_PI / 180.0;  // convert degrees to radians
// 		x = ((data->win_width / 2) - 100) + (sphere->diameter * 40 / 2 * cos(rad));
// 		y = ((data->win_height / 2) - 100) + (sphere->diameter * 40 / 2 * sin(rad));
// 		printf("x : %f, y : %f, rad : %f\n", x, y, rad);
// 		img_pixel_put(data, x, y, 0xff0000);
// 	}

// 	for (float i = 0; i < 360; i += 0.1)
// 	{
// 		rad = i * M_PI / 180.0;  // convert degrees to radians
// 		x = ((data->win_width / 2) + 100) + (sphere->diameter * 40 / 2 * cos(rad));
// 		y = ((data->win_height / 2) + 100) + (sphere->diameter * 40 / 2 * sin(rad));
// 		printf("x : %f, y : %f, rad : %f\n", x, y, rad);
// 		img_pixel_put(data, x, y, 0x00ff00);
// 	}
// 	put_image_back(data);
// }

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
							0xff0000);
		i += 0.1;
	}
	put_image_back(data);
}

// void	draw_circle(void *data)
// {
// 	t_sphere	*sphere;
// 	float		x;
// 	float		y;
// 	float		rad;

// 	sphere = (t_sphere *)data;
// 	for (float i = 0; i < 360; i += 1)
// 	{
// 		rad = i * M_PI / 180.0;  // convert degrees to radians
// 		x = ((data->win_width / 2) - 100) + (sphere->diameter * 40 / 2 * cos(rad));
// 		y = ((data->win_height / 2) - 100) + (sphere->diameter * 40 / 2 * sin(rad));
// 		printf("x : %f, y : %f, rad : %f\n", x, y, rad);
// 		img_pixel_put(data, x, y, 0xff0000);
// 	}

// 	for (float i = 0; i < 360; i += 0.1)
// 	{
// 		rad = i * M_PI / 180.0;  // convert degrees to radians
// 		x = ((data->win_width / 2) + 100) + (sphere->diameter * 40 / 2 * cos(rad));
// 		y = ((data->win_height / 2) + 100) + (sphere->diameter * 40 / 2 * sin(rad));
// 		printf("x : %f, y : %f, rad : %f\n", x, y, rad);
// 		img_pixel_put(data, x, y, 0x00ff00);
// 	}
// 	put_image_back(data);
// }