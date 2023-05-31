/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:22:20 by dmaessen          #+#    #+#             */
/*   Updated: 2023/05/31 10:39:01 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include "./MLX42/include/MLX42/MLX42_Input.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>

# define WIDTH 1080
# define HEIGHT 1080

typedef struct s_file
{
	int				width;
	int				height;
	double			**z_depth;
	double			x_width;
	double			y_height;
	double			z1;
	double			z2;
	int				zoom;
	int32_t			color;
	mlx_image_t		*image;
}	t_file;

typedef struct s_dot
{
	int				x;
	int				y;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
}	t_dot;

int		main(int argc, char **argv);

void	read_file(t_file *input, char **argv);
int		find_width(char **argv);
int		find_height(char **argv);
void	add_coordinates(double *z, char *line);
void	init_read(t_file *input, char **argv);

void	draw_map(t_file *input);
void	draw_line(t_file *input, t_dot *dot);
void	isometric_view(double *x, double *y, int z);
void	this_color(t_file *input);
void	find_zoom(t_file *input);
void	add_zoom(t_file *input, t_dot *dot);
void	center_drawing(double *x1, double *y1, double *x2, double *y2);
void	set_z(t_file *input, t_dot *dot);
void	is_linex(t_file *input, t_dot *dot);

void	free_str(char **str);
void	exit_error(char *str);

void	hook_esc(void *param);
double	abso(double nb);
int		max(int num1, int num2);

void	init_dots_y(t_dot *dot);
void	init_dots_x(t_dot *dot);

#endif

/*
while cloning for eval:
git clone --recurse-submodules <URL>

then:
~ cd MLX42
~ cmake -B build # build here refers to the outputfolder.
~ cmake --build build -j4 # or do make -C build -j4
*/