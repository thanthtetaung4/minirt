#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "gnl.h"
# include "vec3.h"
# include "win.h"
# include "structs.h"

# include <mlx.h>

// Main
int		init_data(t_data *data);
int		print_error(char *msg);

// Free
void	free_all(t_data *data);
void	free_scene(t_data *data);
void	free_split(char **split);

// Parsing
int		parser(char *filename, t_data *data);
int		count_row(const char *path);
int		parse_rgb(char *str, t_rgb *color);
int		parse_xyz(char *str, t_vec3 *origin, int vector);
int		parse_ambient(char *line, t_ambient *ambient);
int		parse_light(char *line, t_light *light);
int		parse_camera(char *line, t_camera *camera);
int		parse_plane(char *line, t_list **planes);
int		parse_sphere(char *line, t_list **spheres);
int		parse_cylinder(char *line, t_list **cylinders);
int		check_range(float value, float min, float max);

// Print
int		print_2d_array(char **arr);
void	print_xyz(t_vec3 origin);
void	print_rgb(t_rgb color);
void	print_ambient(t_ambient amb);
void	print_camera(t_camera camera);
void	print_light(t_light light);
void	print_sphere(void *data);
void	print_plane(void *data);
void	print_cylinder(void *data);
void	print_data(t_data data);

// Image
void	init_image(t_data *data);
void	img_pixel_put(t_data *data, int x, int y, int color);
void	put_image_back(t_data *data);

// Mouse
int		mouse_drag_draw(void *param);
int		mouse_drag(int (*funct)(), void *param);

// Draw
void	draw_circle(void *lst_data, void *data);
int		ft_color(t_rgb color);

#endif
