/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:04:45 by dmaessen          #+#    #+#             */
/*   Updated: 2023/05/30 14:00:04 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_zoom(t_file *input, t_dot *dot)
{
	dot->x1 = (dot->x1 * input->zoom);
	dot->x2 = (dot->x2 * input->zoom);
	dot->y1 = (dot->y1 * input->zoom);
	dot->y2 = (dot->y2 * input->zoom);
}

void	center_drawing(double *x1, double *y1, double *x2, double *y2)
{
	*x1 += WIDTH / 2.8;
	*x2 += WIDTH / 2.8;
	*y1 += WIDTH / 2.8;
	*y2 += WIDTH / 2.8;
}

void	find_zoom(t_file *input)
{
	if (input->height > input->width)
		input->zoom = (HEIGHT / input->height) / 2;
	else
		input->zoom = (HEIGHT / input->width) / 2;
}

void	this_color(t_file *input)
{
	if (input->z1 > 0 && input->z2 > 0)
		input->color = 0x2792f5cc;
	else if (input->z1 > 0 || input->z2 > 0)
		input->color = 0x2660edcc;
	else
		input->color = 0x180ccfFF;
}
