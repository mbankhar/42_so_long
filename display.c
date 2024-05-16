/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:32:28 by mbankhar          #+#    #+#             */
/*   Updated: 2024/05/14 11:18:09 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images(t_fdf *mapd)
{
	mapd->wall_text = mlx_load_png("./images/wall.png");
	if (!mapd->wall_text)
		write(1, "Error loading wall image\n", 25);
	mapd->ground_text = mlx_load_png("./images/background.png");
	if (!mapd->ground_text)
		write(1, "Error loading floor image\n", 26);
	mapd->coll_text = mlx_load_png("./images/coll.png");
	if (!mapd->coll_text)
		write(1, "Error loading collectable image\n", 31);
	mapd->player_text = mlx_load_png("./images/player.png");
	if (!mapd->player_text)
		write(1, "Error loading player image\n", 27);
	mapd->gate_text = mlx_load_png("./images/gate.png");
	if (!mapd->gate_text)
		write(1, "Error loading exit image\n", 25);
	mapd->monster_text = mlx_load_png("./images/monster.png");
	if (!mapd->monster_text)
		write(1, "Error loading exit image\n", 25);
}

void	texture_to_image(t_fdf *mapd)
{
	mapd->wall_image = mlx_texture_to_image(mapd->mlxpointer,
			mapd->wall_text);
	if (!mapd->wall_image)
		write(1, "Error converting wall tex to img", 32);
	mapd->ground_image = mlx_texture_to_image(mapd->mlxpointer,
			mapd->ground_text);
	if (!mapd->ground_image)
		write(1, "Error converting floor tex to img", 33);
	mapd->coll_image = mlx_texture_to_image(mapd->mlxpointer,
			mapd->coll_text);
	if (!mapd->coll_image)
		write(1, "Error converting collectable tex to img", 38);
	mapd->player_image = mlx_texture_to_image(mapd->mlxpointer,
			mapd->player_text);
	if (!mapd->player_image)
		write(1, "Error converting player tex to img", 34);
	mapd->gate_image = mlx_texture_to_image(mapd->mlxpointer,
			mapd->gate_text);
	if (!mapd->gate_image)
		write(1, "Error converting exit tex to img", 32);
	mapd->monster_image = mlx_texture_to_image(mapd->mlxpointer,
			mapd->monster_text);
	if (!mapd->monster_image)
		write(1, "Error converting exit tex to img", 32);
}

void	ground(t_fdf *mapd)
{
	int	x;
	int	y;

	y = 0;
	while (y < mapd->columns)
	{
		x = 0;
		while (x < mapd->rows)
		{
			if (mapd->mapsize[y][x] == 'P' || mapd->mapsize[y][x] == 'M')
				mlx_image_to_window(mapd->mlxpointer, mapd->ground_image,
					x * 65, y * 65);
			else if (mapd->mapsize[y][x] == 'C')
				mlx_image_to_window(mapd->mlxpointer, mapd->ground_image,
					x * 65, y * 65);
			x++;
		}
		y++;
	}
}

void	placeimages(t_fdf *mapd)
{
	int	x;
	int	y;

	y = 0;
	while (y < mapd->columns)
	{
		x = 0;
		while (x < mapd->rows)
		{
			if (mapd->mapsize[y][x] == '1')
				mlx_image_to_window(mapd->mlxpointer, mapd->wall_image,
					x * 65, y * 65);
			else if (mapd->mapsize[y][x] == '0')
				mlx_image_to_window(mapd->mlxpointer, mapd->ground_image,
					x * 65, y * 65);
			else if (mapd->mapsize[y][x] == 'C')
				mlx_image_to_window(mapd->mlxpointer, mapd->coll_image,
					x * 65, y * 65);
			else if (mapd->mapsize[y][x] == 'E')
				mlx_image_to_window(mapd->mlxpointer, mapd->gate_image,
					x * 65, y * 65);
			x++;
		}
		y++;
	}
}

void	player(t_fdf *mapd)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (y < mapd->columns)
	{
		x = 0;
		while (x < mapd->rows)
		{
			if (mapd->mapsize[y][x] == 'P')
			{
				mlx_image_to_window(mapd->mlxpointer, mapd->player_image,
					x * 65, y * 65);
				mapd->player_x = x;
				mapd->player_y = y;
			}
			x++;
		}
		y++;
	}
}
