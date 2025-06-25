#ifndef STRUCTS_H
# define STRUCTS_H

# include "vec3.h"
# include "libft.h"

// Forward typedefs
typedef struct s_ray		t_ray;
typedef struct s_rgb		t_rgb;
typedef struct s_ambient	t_ambient;
typedef struct s_camera		t_camera;
typedef struct s_light		t_light;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_mouse		t_mouse;
typedef struct s_image		t_image;
typedef struct s_data		t_data;

struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
};

struct s_rgb
{
	int	r;
	int	g;
	int	b;
};

struct s_ambient
{
	float	ratio;
	t_rgb	color;
};

struct s_camera
{
	t_vec3	origin;
	t_vec3	v_origin;
	float	fov;
};

struct s_light
{
	t_vec3	origin;
	float	ratio;
	t_rgb	color;
};

struct s_sphere
{
	t_vec3	origin;
	float	diameter;
	t_rgb	color;
};

struct s_plane
{
	t_vec3	origin;
	t_vec3	v_origin;
	t_rgb	color;
};

struct s_cylinder
{
	t_vec3	origin;
	t_vec3	v_origin;
	float	diameter;
	float	height;
	t_rgb	color;
};

struct s_mouse
{
	int	x;
	int	y;
	int	mouse_drag;
	int	(*funct)(void *);
};

struct s_image
{
	void	*mlx_img;
	char	*mlx_img_data;
	int		bbp;
	int		size_line;
	int		endian;
};

struct s_data
{
	int			i;
	void		*mlx;
	void		*mlx_win;
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
	t_mouse		mouse;
	t_image		img;
};

#endif // STRUCTS_H
