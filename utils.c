/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:37:37 by dmaessen          #+#    #+#             */
/*   Updated: 2023/05/31 10:36:47 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hook_esc(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

double	abso(double nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

int	max(int nb1, int nb2)
{
	if (nb1 > nb2)
		return (nb1);
	else
		return (nb2);
}
