#include "../inc/minirt.h"

int	print_2d_array(char **arr)
{
	int i = 0;
	while (arr && arr[i])
	{
		printf("\t%s\n", arr[i]);
		i++;
	}
	return (1);
}

void	print_xyz(t_xyz origin)
{
	printf("xyz - [%f, %f, %f]", origin.x, origin.y, origin.z);
}

void	print_rgb(t_rgb color)
{
	printf("rgb - [%d, %d, %d]", color.r, color.g, color.b);
}

void	print_ambient(t_ambient amb)
{
	printf("ambient : ratio - %f, ", amb.ratio);
	print_rgb(amb.color);
	printf("\n");
}

void	print_camera(t_camera camera)
{
	printf("camera : ");
	print_xyz(camera.origin);
	printf(", ");
	print_xyz(camera.v_origin);
	printf(", fov - %f\n", camera.fov);
}

void	print_light(t_light light)
{
	printf("light : ");
	print_xyz(light.origin);
	printf(", ratio - %f, ", light.ratio);
	print_rgb(light.color);
	printf("\n");
}

void	print_sphere(void *sphere)
{
	printf("sphere : ");
	print_xyz(((t_sphere *)sphere)->origin);
	printf(", diameter - %f, ", ((t_sphere *)sphere)->diameter);
	print_rgb(((t_sphere *)sphere)->color);
	printf("\n");
}

void	print_plane(void *plane)
{
	printf("plane : ");
	print_xyz(((t_plane*)plane)->origin);
	printf(", ");
	print_xyz(((t_plane*)plane)->v_origin);
	printf(", ");
	print_rgb(((t_plane*)plane)->color);
	printf("\n");
}

void	print_cylinder(void *cylinder)
{
	printf("cylinder : ");
	print_xyz(((t_cylinder*)cylinder)->origin);
	printf(", ");
	print_xyz(((t_cylinder*)cylinder)->v_origin);
	printf(", diameter - %f, height - %f, ", ((t_cylinder*)cylinder)->diameter, ((t_cylinder*)cylinder)->height);
	print_rgb(((t_cylinder*)cylinder)->color);
	printf("\n");
}

void	print_data(t_data data)
{
	printf("index : %d\nwin_width : %d\nwin_height : %d\n", data.i, data.win_width, data.win_height);
	printf("mlx : %p\n", data.mlx);
	printf("mlx_win : %p\n", data.mlx_win);
	printf("scene : \n");
	print_2d_array(data.scene);
	print_ambient(data.ambient);
	print_camera(data.camera);
	print_light(data.light);
	ft_lstiter(data.spheres, print_sphere);
	ft_lstiter(data.planes, print_plane);
	ft_lstiter(data.cylinders, print_cylinder);
	printf("ambient_count : %d\ncamera_count : %d\nlight_count : %d\n", data.ambient_count, data.camera_count, data.light_count);
}
