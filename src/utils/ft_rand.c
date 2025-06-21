/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:14:19 by taung             #+#    #+#             */
/*   Updated: 2025/06/21 13:34:00 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	ft_rand(int min, int max)
{
	unsigned int	seed;
	int				rd_num;

	seed = time(0);
	rd_num = rand_r(&seed) % (max - min + 1) + min;
	printf("%d ", rd_num);
	return (rd_num);
}
