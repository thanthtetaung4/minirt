/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoo <aoo@student.42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 06:01:38 by aoo               #+#    #+#             */
/*   Updated: 2025/06/26 06:02:38 by aoo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

float	vec3_len_sq(t_vec3 vec3)
{
	return ((vec3.x * vec3.x) + (vec3.y * vec3.y) + (vec3.z * vec3.z));
}

float	vec3_length(t_vec3 vec3)
{
	return (sqrt(vec3_len_sq(vec3)));
}

t_vec3	vec3_unit(t_vec3 vec3)
{
	float	len;

	len = vec3_length(vec3);
	if (len == 0)
		return (vec3);
	return (vec3_scale(vec3, 1 / len));
}
