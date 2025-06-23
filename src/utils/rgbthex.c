/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgbthex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:32:31 by taung             #+#    #+#             */
/*   Updated: 2025/06/23 19:08:32 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	rgbthex(t_rgb color, int *hex_color)
{
	*hex_color = color.r << 16 | color.g << 8 | color.b;
}

// int main()
// {
// 	t_rgb	color;
// 	int		hex;

// 	// rgb(220, 20, 60)
// 	color.r = 220;
// 	color.g = 20;
// 	color.b = 60;

// 	// double number = 13.75;
// 	// double integer_part;
// 	// double fractional_part = modf(number, &integer_part);

// 	// printf("Original number: %.2f\n", number);
// 	// printf("Fractional part: %.2f\n", fractional_part);

// 	// return 0;
// 	rgbthex(color, &hex);
// 	printf("color: %d, %d\n", hex, 0xdc143c);
// }
