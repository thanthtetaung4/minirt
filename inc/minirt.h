/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 02:40:16 by taung             #+#    #+#             */
/*   Updated: 2025/05/14 00:24:07 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../src/get_next_line/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
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
	float	radius;
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
	float	radius;
	float	height;
	t_rgb	color;
}	t_cylinder;

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
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
	int			ambient_count;
	int			camera_count;
	int			light_count;
	int			sphere_count;
	int			plane_count;
	int			cylinder_count;
}	t_data;

int	handle_keypress(int keysym, t_data *data);
int	close_win(t_data *data);

// Free functions
void	free_all(t_data *data);
void	free_scene(t_data *data);
void	free_split(char **split);

// Parsing functions
int	parser(char *filename, t_data *data);
int	count_row(const char *path);
int parse_ambient(char *line, t_ambient *ambient);
int parse_light(char *line, t_light *light);
int parse_camera(char *line, t_camera *camera);
int parse_plane(char *line, t_plane *plane);
int parse_sphere(char *line, t_sphere *sphere);
int parse_cylinder(char *line, t_cylinder *cylinder);

// Utility functions
int	print_2d_array(char **arr);


// Error
int	print_error(char *msg);

#endif
