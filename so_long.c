/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:52:55 by mbankhar          #+#    #+#             */
/*   Updated: 2024/05/16 10:58:25 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_line(char *line)
{
	if (line[0] == '\n')
	{
		write(1, "Map error", 10);
		exit(EXIT_FAILURE);
	}
}

void	read_it(int fd)
{
	char	*line;

	line = get_next_line(fd);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		free(line);
	}
	free(line);
}

// void	leaks(void)
// {
// 	system("leaks so_long");
// }
	// atexit(leaks);

int	main(int argc, char **argv)
{
	t_fdf	mapd;

	open_map(argc, argv, &mapd);
	check_forerrors(&mapd);
	copy_map(&mapd);
	floodfillcheck(mapd);
	access_check(mapd);
	map_intact_check(mapd);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mapd.mlxpointer = mlx_init(mapd.rows * 64,
			mapd.columns * 64, "so_long", true);
	if (!mapd.mlxpointer)
		exit(1);
	images(&mapd);
	texture_to_image(&mapd);
	ground(&mapd);
	placeimages(&mapd);
	player(&mapd);
	monster(&mapd);
	mlx_key_hook(mapd.mlxpointer, commands, &mapd);
	mlx_loop(mapd.mlxpointer);
	freeforfuckssake(mapd);
	ft_free(mapd.mapsize);
}
