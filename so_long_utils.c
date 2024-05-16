/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:37:50 by mbankhar          #+#    #+#             */
/*   Updated: 2024/05/15 11:41:53 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_player(t_fdf *mapd, int x, int y)
{
	mapd->player_image->instances[0].enabled = false;
	mlx_delete_texture(mapd->player_text);
	mapd->player_text = mlx_load_png("./images/player_final.png");
	if (!mapd->player_text)
		write(1, "Error loading player image\n", 27);
	mapd->player_image = mlx_texture_to_image(mapd->mlxpointer,
			mapd->player_text);
	if (!mapd->player_image)
		write(1, "Error converting player tex to img", 34);
	mlx_image_to_window(mapd->mlxpointer, mapd->player_image,
		x * 65, y * 65);
	mapd->player_x = x;
	mapd->player_y = y;
}

void	monster(t_fdf *mapd)
{
	int	x;
	int	y;

	y = 0;
	mapd->monster = 0;
	while (y < mapd->columns)
	{
		x = 0;
		while (x < mapd->rows)
		{
			if (mapd->mapsize[y][x] == 'M')
			{
				mlx_image_to_window(mapd->mlxpointer, mapd->monster_image,
					x * 65, y * 65);
				mapd->monster_x = x;
				mapd->monster_y = y;
				mapd->monster += 1;
			}
			x++;
		}
		y++;
	}
	if (mapd->monster > 1)
		exit(1);
}

void	freeforfuckssake(t_fdf mapd)
{
	mlx_delete_texture(mapd.player_text);
	mlx_delete_texture(mapd.coll_text);
	mlx_delete_texture(mapd.wall_text);
	mlx_delete_texture(mapd.ground_text);
	mlx_delete_texture(mapd.gate_text);
	mlx_delete_texture(mapd.monster_text);
	mlx_delete_image(mapd.mlxpointer, mapd.player_image);
	mlx_delete_image(mapd.mlxpointer, mapd.coll_image);
	mlx_delete_image(mapd.mlxpointer, mapd.wall_image);
	mlx_delete_image(mapd.mlxpointer, mapd.ground_image);
	mlx_delete_image(mapd.mlxpointer, mapd.gate_image);
	mlx_delete_image(mapd.mlxpointer, mapd.monster_image);
	mlx_terminate(mapd.mlxpointer);
}

void	map_intact_check(t_fdf mapd)
{
	int	i;

	i = -1;
	while (++i < mapd.columns)
	{
		if (mapd.mapsize[i][0] != '1' || mapd.mapsize[i][mapd.rows -1] != '1')
			map_error(mapd);
	}
	i = -1;
	while (++i < mapd.rows)
	{
		if (mapd.mapsize[0][i] != '1'
			|| mapd.mapsize[mapd.columns -1][i] != '1')
			map_error(mapd);
	}
}

void	map_error(t_fdf mapd)
{
	write(1, "Map not walled up", 18);
	ft_free(mapd.mapsize);
	exit(EXIT_FAILURE);
}
