/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:03:10 by dmaessen          #+#    #+#             */
/*   Updated: 2023/05/31 10:31:24 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_dots_x(t_dot *dot)
{
	dot->x1 = dot->x;
	dot->x2 = dot->x + 1;
	dot->y1 = dot->y;
	dot->y2 = dot->y;
}

void	init_dots_y(t_dot *dot)
{
	dot->x1 = dot->x;
	dot->x2 = dot->x;
	dot->y1 = dot->y;
	dot->y2 = dot->y + 1;
}
