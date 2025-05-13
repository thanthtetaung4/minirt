/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 02:40:16 by taung             #+#    #+#             */
/*   Updated: 2025/05/13 13:09:35 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
#define MINI_RT_H

#include <stdio.h>
#include "../libft/libft.h"
#include "../src/get_next_line/get_next_line.h"
#include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_data
{
	int	i;
	void	*mlx;
	void	*mlx_win;
	int	win_width;
	int	win_height;
	char	**scene;
}	t_data;

int	handle_keypress(int keysym, t_data *data);
int	close_win(t_data *data);

// Free functions
void	free_all(t_data *data);
void	free_scene(t_data *data);

// Parsing functions
int	parser(char *filename, t_data *data);
int	count_row(const char *path);

// Utility functions
int	print_2d_array(char **arr);

#endif
