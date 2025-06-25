/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 06:01:53 by aoo               #+#    #+#             */
/*   Updated: 2025/06/26 06:02:04 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_vec3(t_vec3 vec3)
{
	printf("x : %f, y : %f, z : %f\n", vec3.x, vec3.y, vec3.z);
}

t_vec3	vec3_init(float x, float y, float z)
{
	t_vec3	vec3;

	vec3.x = x;
	vec3.y = y;
	vec3.z = z;
	return (vec3);
}

t_vec3	vec3_scale(t_vec3 vec3, float value)
{
	return (vec3_init(vec3.x * value, vec3.y * value, vec3.z * value));
}

t_vec3	_vec3(t_vec3 vec3)
{
	return (vec3_scale(vec3, -1));
}
