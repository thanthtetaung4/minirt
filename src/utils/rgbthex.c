/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgbthex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:32:31 by taung             #+#    #+#             */
/*   Updated: 2025/06/21 15:05:16 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	rgbthex(t_rgb color, int *hex_color)
{
	char	hex_code[7] = "000000";
	double	tmp;
	double	fraction;


	tmp = (double)color.r / 16;
	printf("tmp: %f\n", tmp);
	fraction = modf(tmp, &fraction);
	printf("int: %d\n fraction: %.2f\n", (int)tmp, fraction);
	printf("0: %d\n1: %.2f\n", (int)tmp, fraction * 16);
	if ((int)tmp > 9)
		hex_code[0] = ((int)tmp - 10) + 'A';
	else
		hex_code[0] = (int)tmp + '0';
	if ((fraction * 16) > 9)
		hex_code[1] = ((int)(fraction * 16) - 10) + 'A';
	else
		hex_code[1] = (int)(fraction * 16) + '0';
	printf("hex: %s\n", hex_code);
	return;
}

int main()
{
	t_rgb	color;
	int		hex;

	// rgb(220, 20, 60)
	color.r = 220;
	color.g = 20;
	color.b = 60;

	// double number = 13.75;
	// double integer_part;
	// double fractional_part = modf(number, &integer_part);

	// printf("Original number: %.2f\n", number);
	// printf("Fractional part: %.2f\n", fractional_part);

	// return 0;
	rgbthex(color, &hex);
}
