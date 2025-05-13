/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 02:40:16 by taung             #+#    #+#             */
/*   Updated: 2025/05/13 20:04:09 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
#define MINI_RT_H

#include <stdio.h>
#include "../libft/libft.h"
#include "../src/get_next_line/get_next_line.h"
#include <unistd.h>
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
	int	i;
	void	*mlx;
	void	*mlx_win;
	int	win_width;
	int	win_height;
	char	**scene;
	t_ambient	ambient;
	t_camera	camera;
	t_light	light;
	t_sphere	sphere;
	t_plane	plane;
	t_cylinder	cylinder;
	int	ambient_count;
	int	camera_count;
	int	light_count;
}	t_data;

int	handle_keypress(int keysym, t_data *data);
int	close_win(t_data *data);

// Free functions
void	free_all(t_data *data);
void	free_scene(t_data *data);

// Parsing functions
int	parser(char *filename, t_data *data);
int	count_row(const char *path);

// Utility functions
int	print_2d_array(char **arr);

#endif
