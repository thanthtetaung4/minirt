/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 05:45:58 by aoo               #+#    #+#             */
/*   Updated: 2025/06/26 05:52:18 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

// vector
void		print_vec3(t_vec3 vec3);
t_vec3		vec3_init(float x, float y, float z);
t_vec3		_vec3(t_vec3 vec3);
t_vec3		vec3_scale(t_vec3 vec3, float value);
float		vec3_len_sq(t_vec3 vec3);
float		vec3_length(t_vec3 vec3);
t_vec3		vec3_add(t_vec3 a, t_vec3 b);
t_vec3		vec3_sub(t_vec3 dst, t_vec3 src);
t_vec3		vec3_multi(t_vec3 a, t_vec3 b);
float		vec3_dot(t_vec3 a, t_vec3 b);
t_vec3		vec3_cross(t_vec3 a, t_vec3 b);
t_vec3		vec3_unit(t_vec3 vec3);

#endif