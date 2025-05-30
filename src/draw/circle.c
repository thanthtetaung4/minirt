#include "../inc/minirt.h"

#include <math.h>  // make sure this is included

void	circle(t_data *data)
{
	t_sphere	*sphere;
	float		x;
	float		y;
	float		rad;

	sphere = ((t_sphere *)data->spheres);

	for (float i = 0; i < 360; i += 0.5)
	{
		rad = i * M_PI / 180.0;  // convert degrees to radians
		x = sphere->origin.x + (sphere->diameter / 2 * cos(rad));
		y = sphere->origin.y + (sphere->diameter / 2 * sin(rad));
		printf("org : %f", sphere->origin.x);
		printf("x : %f, y : %f, rad : %f\n", x, y, rad);
		img_pixel_put(data, x, y, 0xff0000);
	}
	put_image_back(data);
}
