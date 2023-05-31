/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:49:13 by domi              #+#    #+#             */
/*   Updated: 2023/05/31 10:38:49 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_file *input, t_dot *dot)
{
	int		max_steps;
	int		i;

	set_z(input, dot);
	find_zoom(input);
	add_zoom(input, dot);
	isometric_view(&dot->x1, &dot->y1, input->z1);
	isometric_view(&dot->x2, &dot->y2, input->z2);
	center_drawing(&dot->x1, &dot->y1, &dot->x2, &dot->y2);
	input->x_width = (dot->x2 - dot->x1);
	input->y_height = (dot->y2 - dot->y1);
	max_steps = (int)max(abso(input->x_width), abso(input->y_height));
	input->x_width /= max_steps;
	input->y_height /= max_steps;
	i = 0;
	while (i < max_steps)
	{
		this_color(input);
		if ((dot->x1 >= 0 && dot->x1 < WIDTH)
			&& (dot->y1 >= 0 && dot->y1 < HEIGHT))
			mlx_put_pixel(input->image, dot->x1, dot->y1, input->color);
		dot->x1 += input->x_width;
		dot->y1 += input->y_height;
		i++;
	}
}

void	set_z(t_file *input, t_dot *dot)
{
	input->z1 = input->z_depth[(int)dot->y1][(int)dot->x1];
	input->z2 = input->z_depth[(int)dot->y2][(int)dot->x2];
}

void	isometric_view(double *x, double *y, int z)
{
	*x = (*x - *y) * cos(45 * (M_PI / 180));
	*y = (*x + *y) * sin(45 * (M_PI / 180)) - z;
}

void	is_linex(t_file *input, t_dot *dot)
{
	if (dot->x < input->width - 1)
	{
		init_dots_x(dot);
		draw_line(input, dot);
	}
}

void	draw_map(t_file *input)
{
	t_dot	*dot;

	dot = (t_dot *)malloc(sizeof(t_dot));
	if (!dot)
		exit_error("Error: malloc input\n");
	dot->y = 0;
	while (dot->y < input->height)
	{
		dot->x = 0;
		while (dot->x < input->width)
		{
			is_linex(input, dot);
			if (dot->y < input->height - 1)
			{
				init_dots_y(dot);
				draw_line(input, dot);
			}
			dot->x++;
		}
		dot->y++;
	}
	free(dot);
}
