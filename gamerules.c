/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamerules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:27:48 by mbankhar          #+#    #+#             */
/*   Updated: 2024/05/15 11:40:31 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_fdf *mapd, int x, int y)
{
	if (mapd->mapsize[y][x] == 'E')
		mapd->mapsize[y][x] = 'P';
	if (mapd->moves == 0)
		mapd->mapsize[mapd->player_y][mapd->player_x] = '0';
	mapd->player_x = x;
	mapd->player_y = y;
	mapd->player_image->instances->x = x * 65;
	mapd->player_image->instances->y = y * 65;
	if (mapd->monster == 1)
		make_mons_move(mapd);
}

void	game_over(t_fdf *mapd, int x, int y)
{
	move_player(mapd, x, y);
	mapd->moves++;
	write(1, "Moves:", 7);
	ft_putnbr_fd(mapd->moves, 1);
	write(1, "\n", 1);
	write(1, "You win", 8);
	exit(0);
}

void	remove_db(t_fdf *mapd, int x, int y)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (i <= mapd->coll + 200)
	{
		if (mapd->coll_image->instances[i].x == x * 65
			&& mapd->coll_image->instances[i].y == y * 65)
		{
			mapd->coll_image->instances[i].enabled = false;
			mapd->mapsize[y][x] = '0';
			mapd->coll--;
			break ;
		}
		i++;
	}
	if (mapd->coll == 0 && k == 0)
	{
		change_player(mapd, x, y);
		k++;
	}
}

void	check_balls(t_fdf *mapd, int x, int y)
{
	remove_db(mapd, x, y);
	move_player(mapd, x, y);
	mapd->moves++;
	write(1, "Moves:", 7);
	ft_putnbr_fd(mapd->moves, 1);
	write(1, "\n", 1);
	write(1, "Dragon balls left:", 19);
	ft_putnbr_fd(mapd->coll, 1);
	write(1, "\n", 1);
}

void	move(t_fdf *mapd, int x, int y)
{
	if (mapd->mapsize[y][x] == 'E' && mapd->coll == 0)
	{
		game_over(mapd, x, y);
		return ;
	}
	if (mapd->mapsize[y][x] == '0' || mapd->mapsize[y][x] == 'P')
	{
		move_player(mapd, x, y);
		mapd->moves++;
		write(1, "Moves: ", 8);
		ft_putnbr_fd(mapd->moves, 1);
		write(1, "\n", 1);
	}
	if (mapd->mapsize[y][x] == 'C')
	{
		check_balls(mapd, x, y);
	}
	if (mapd->mapsize[y][x] == 'M')
	{
		write(1, "Game over\n", 11);
		exit(0);
		return ;
	}
}
