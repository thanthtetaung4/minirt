/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 05:55:48 by aoo               #+#    #+#             */
/*   Updated: 2025/06/26 05:59:14 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_add(t_vec3 a, t_vec3 b)
{
	return (vec3_init(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vec3	vec3_sub(t_vec3 a, t_vec3 b)
{
	return (vec3_init(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_vec3	vec3_multi(t_vec3 a, t_vec3 b)
{
	return (vec3_init(a.x * b.x, a.y * b.y, a.z * b.z));
}

float	vec3_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec3	vec3_cross(t_vec3 a, t_vec3 b)
{
	return (vec3_init(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x));
}
