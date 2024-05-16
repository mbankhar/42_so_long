/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:49:12 by mbankhar          #+#    #+#             */
/*   Updated: 2024/05/13 12:40:50 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_fdf *mapd)
{
	if (mapd->mapsize[mapd->player_y - 1][mapd->player_x] == '1')
		return ;
	move(mapd, mapd->player_x, mapd->player_y - 1);
}

void	move_down(t_fdf *mapd)
{
	if (mapd->mapsize[mapd->player_y + 1][mapd->player_x] == '1')
		return ;
	move(mapd, mapd->player_x, mapd->player_y + 1);
}

void	move_left(t_fdf *mapd)
{
	if (mapd->mapsize[mapd->player_y][mapd->player_x - 1] == '1')
		return ;
	move(mapd, mapd->player_x - 1, mapd->player_y);
}

void	move_right(t_fdf *mapd)
{
	if (mapd->mapsize[mapd->player_y][mapd->player_x + 1] == '1')
		return ;
	move(mapd, mapd->player_x + 1, mapd->player_y);
}

void	commands(mlx_key_data_t keydata, void *param)
{
	t_fdf	*mapd;

	mapd = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mapd->mlxpointer);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(mapd);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(mapd);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_down(mapd);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_up(mapd);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_left(mapd);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_down(mapd);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(mapd);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move_right(mapd);
}
