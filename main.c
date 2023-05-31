/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:53:04 by domi              #+#    #+#             */
/*   Updated: 2023/05/31 10:47:23 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_file	input;
	mlx_t	*mlx;

	if (argc == 2)
		read_file(&input, argv);
	else
		exit_error("Error: invalid number of arguments.\n");
	mlx = mlx_init(WIDTH, HEIGHT, argv[1], true);
	if (!mlx)
		exit_error("Error: initializing mlx\n");
	input.image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!input.image)
		exit_error("Error: creating new image\n");
	draw_map(&input);
	if (mlx_image_to_window(mlx, input.image, 0, 0) < 0)
		exit_error("Error: image to window\n");
	mlx_loop_hook(mlx, hook_esc, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	exit(EXIT_SUCCESS);
}
