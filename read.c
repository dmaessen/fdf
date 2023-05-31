/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:35:49 by domi              #+#    #+#             */
/*   Updated: 2023/05/30 20:40:12 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	find_width(char **argv)
{
	int		width;
	int		fd;
	char	*line;
	char	**temp;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_error("Error: opening file\n");
	line = get_next_line_exit(fd);
	if (!line)
		exit_error("Error: failing finding width\n");
	temp = ft_split(line, ' ');
	if (temp == NULL)
		exit_error("Error: spliting line\n");
	width = 0;
	while (temp[width] != NULL)
		width++;
	free(line);
	free_str(temp);
	close(fd);
	return (width);
}

int	find_height(char **argv)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_error("Error: opening file\n");
	height = 0;
	while (1)
	{
		line = get_next_line_exit(fd);
		if (line == NULL)
			break ;
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

void	add_coordinates(double *z, char *line)
{
	char	**data;
	int		i;

	data = ft_split(line, ' ');
	if (data == NULL)
		exit_error("Error: spliting line for coords\n");
	i = 0;
	while (data[i])
	{
		z[i] = ft_atoi(data[i]);
		i++;
	}
	free_str(data);
}

void	init_read(t_file *input, char **argv)
{
	int	i;

	input->height = find_height(argv);
	input->width = find_width(argv);
	input->z_depth = (double **)malloc(sizeof(double *) * (input->height + 1));
	if (!input->z_depth)
		exit_error("Error: malloc z_depth\n");
	i = 0;
	while (i < input->height)
	{
		input->z_depth[i] = malloc(sizeof(double) * (input->width));
		if (!input->z_depth[i])
			exit_error("Error: malloc z_depth\n");
		i++;
	}
}

void	read_file(t_file *input, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	init_read(input, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_error("Error: opening file\n");
	i = 0;
	while (1)
	{
		line = get_next_line_exit(fd);
		if (line == NULL)
			break ;
		add_coordinates(input->z_depth[i], line);
		free(line);
		i++;
	}
	input->z_depth[i] = NULL;
	close(fd);
}
