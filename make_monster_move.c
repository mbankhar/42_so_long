/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_monster_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:19:41 by mbankhar          #+#    #+#             */
/*   Updated: 2024/05/16 11:36:10 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right_monster(t_fdf *mapd)
{
	if (mapd->mapsize[mapd->monster_y][mapd->monster_x + 1] == '1')
		return ;
	move_monster(mapd, mapd->monster_x + 1, mapd->monster_y);
}

void	make_mons_move(t_fdf *mapd)
{
	int	i;

	srand(time(NULL));
	i = rand() % 4;
	if (i == 0)
	{
		if (mapd->mapsize[mapd->monster_y - 1][mapd->monster_x] == '1')
			return ;
		move_monster(mapd, mapd->monster_x, mapd->monster_y - 1);
	}
	if (i == 1)
	{
		if (mapd->mapsize[mapd->monster_y + 1][mapd->monster_x] == '1')
			return ;
		move_monster(mapd, mapd->monster_x, mapd->monster_y + 1);
	}
	if (i == 2)
	{
		if (mapd->mapsize[mapd->monster_y][mapd->monster_x - 1] == '1')
			return ;
		move_monster(mapd, mapd->monster_x - 1, mapd->monster_y);
	}
	if (i == 3)
		move_right_monster(mapd);
}

void	move_monster_step(t_fdf *mapd, int x, int y)
{
	mapd->mapsize[y][x] = 'M';
	mapd->mapsize[mapd->monster_y][mapd->monster_x] = '0';
	mapd->monster_x = x;
	mapd->monster_y = y;
	mapd->monster_image->instances->x = x * 65;
	mapd->monster_image->instances->y = y * 65;
}

void	move_monster(t_fdf *mapd, int x, int y)
{
	if (mapd->mapsize[y][x] == 'P')
	{
		write(1, "Game over\n", 11);
		exit(0);
		return ;
	}
	if (mapd->mapsize[y][x] == '0')
		move_monster_step(mapd, x, y);
}
