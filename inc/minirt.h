/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 02:40:16 by taung             #+#    #+#             */
/*   Updated: 2025/06/10 06:15:46 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "get_next_line.h"
# include <mlx.h>
// # include <X11/keysym.h>
// # include <X11/X.h>
# include <math.h>

typedef struct s_xyz
{
	float	x;
	float	y;
	float	z;
}	t_xyz;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_ambient
{
	float	ratio;
	t_rgb	color;
}	t_ambient;

typedef struct s_camera
{
	t_xyz	origin;
	t_xyz	v_origin;
	float	fov;
}	t_camera;

typedef struct s_light
{
	t_xyz	origin;
	float	ratio;
	t_rgb	color;
}	t_light;

typedef struct s_sphere
{
	t_xyz	origin;
	float	diameter;
	t_rgb	color;
}	t_sphere;

typedef struct s_plane
{
	t_xyz	origin;
	t_xyz	v_origin;
	t_rgb	color;
}	t_plane;

typedef struct s_cylinder
{
	t_xyz	origin;
	t_xyz	v_origin;
	float	diameter;
	float	height;
	t_rgb	color;
}	t_cylinder;

// Test
typedef	struct	s_mouse
{
	int	x;
	int	y;
	int	mouse_drag;
	int	(*funct)(void*);
}	t_mouse;

typedef	struct s_image
{
	void	*mlx_img;
	char	*mlx_img_data;
	int		bbp;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_data
{
	int			i;
	void		*mlx;
	void		*mlx_win;
	int			win_width;
	int			win_height;
	char		**scene;
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_list		*spheres;
	t_list		*planes;
	t_list		*cylinders;
	int			ambient_count;
	int			camera_count;
	int			light_count;
	int			sphere_count;
	int			plane_count;
	int			cylinder_count;

	//Test
	t_mouse		mouse;
	t_image		img;
}	t_data;

int	handle_keypress(int keysym, t_data *data);
int	close_win(t_data *data);

// Free functions
void	free_all(t_data *data);
void	free_scene(t_data *data);
void	free_split(char **split);

// Parsing functions
int	parse_rgb(char *str, t_rgb *color);
int	parse_xyz(char *str, t_xyz *origin, int vector);

int	parser(char *filename, t_data *data);
int	count_row(const char *path);
int parse_ambient(char *line, t_ambient *ambient);
int parse_light(char *line, t_light *light);
int parse_camera(char *line, t_camera *camera);
int parse_plane(char *line, t_list **planes);
int parse_sphere(char *line, t_list **spheres);
int parse_cylinder(char *line, t_list **cylinders);

//	Parsing Utility
int	check_range(float value, float min, float max);

// Utility functions
int	print_2d_array(char **arr);

// Error
int	print_error(char *msg);

// Print data
void	print_xyz(t_xyz origin);
void	print_rgb(t_rgb color);
void	print_ambient(t_ambient amb);
void	print_camera(t_camera camera);
void	print_light(t_light light);
void	print_sphere(void *data);
void	print_plane(void *data);
void	print_cylinder(void *data);
void	print_data(t_data data);

//Image
void	create_image(t_data *data);

// Test mouse_drag;
int		mouse_drag(int (*funct)(), void *param);

void	img_pixel_put(t_data *data, int x, int y, int color);
void	put_image_back(t_data *data);

// Draw
void	draw_circle(void *lst_data, void *data);
int		ft_color(t_rgb color);

#endif
