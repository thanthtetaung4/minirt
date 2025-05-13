/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:06:36 by taung             #+#    #+#             */
/*   Updated: 2025/05/13 14:48:12 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	print_2d_array(char **arr)
{
	int i = 0;

	printf("Printing 2D array:\n");
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	return (1);
}
