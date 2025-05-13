/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:52:09 by taung             #+#    #+#             */
/*   Updated: 2025/05/13 20:59:36 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float	parse_fractional_part(const char *str, int *i)
{
	float	result;
	float	decimal_place;

	result = 0.0f;
	decimal_place = 1.0f;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			result = result * 10 + (str[*i] - '0');
			decimal_place *= 10.0f;
			(*i)++;
		}
	}
	return (result / decimal_place);
}

float	ft_atof(const char *str)
{
	int		i;
	float	sign;
	float	result;

	i = 0;
	sign = 1.0f;
	result = 0.0f;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1.0f;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result += parse_fractional_part(str, &i);
	return (result * sign);
}
