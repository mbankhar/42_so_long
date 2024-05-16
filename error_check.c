/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:10:42 by mbankhar          #+#    #+#             */
/*   Updated: 2024/05/14 15:00:21 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_two(t_fdf *mapd)
{
	int		i;
	int		y;

	i = -1;
	while (++i < mapd->columns)
	{
		y = -1;
		while (++y < mapd->rows)
		{
			if (mapd->map_dimen[i][y] != '1' && mapd->map_dimen[i][y] != 'E'
				&& mapd->map_dimen[i][y] != 'C'
					&& mapd->map_dimen[i][y] != '0'
						&& mapd->map_dimen[i][y] != 'P'
							&& mapd->map_dimen[i][y] != 'M')
			{
				printf("%c\n", mapd->map_dimen[i][y]);
				write(1, "Map error55", sizeof("Map error55"));
				exit(EXIT_FAILURE);
			}
		}
	}
}

void	check_forerrors(t_fdf *mapd)
{
	mapd->i = -1;
	mapd->play = 0;
	mapd->coll = 0;
	mapd->ex = 0;
	mapd->moves = 0;
	while (++mapd->i < mapd->columns)
	{
		mapd->y = -1;
		while (++mapd->y < mapd->rows)
		{
			if (mapd->map_dimen[mapd->i][mapd->y] == 'C')
				mapd->coll += 1;
			if (mapd->map_dimen[mapd->i][mapd->y] == 'E')
				mapd->ex += 1;
			if (mapd->map_dimen[mapd->i][mapd->y] == 'P')
				mapd->play += 1;
		}
	}
	check_two(mapd);
	if (mapd->play != 1 || mapd->ex != 1 || mapd->coll < 1)
	{
		write(1, "Error player exit or coll number", 33);
		ft_free(mapd->map_dimen);
		exit(EXIT_FAILURE);
	}
}

void	floodfill(t_fdf mapd, int x, int y)
{
	int	i;

	i = 0;
	if (x < 0 || y < 0 || x >= mapd.columns || y >= mapd.rows
		|| mapd.map_dimen[x][y] == '1' || mapd.map_dimen[x][y] == 'A')
		return ;
	if (mapd.map_dimen[x][y] == 'E')
	{
		mapd.map_dimen[x][y] = 'A';
		return ;
	}
	mapd.map_dimen[x][y] = '1';
	floodfill(mapd, x + 1, y);
	floodfill(mapd, x - 1, y);
	floodfill(mapd, x, y + 1);
	floodfill(mapd, x, y - 1);
}

void	floodfillcheck(t_fdf mapd)
{
	int	i;
	int	y;
	int	flag;

	i = -1;
	flag = 0;
	while (++i < mapd.columns && flag == 0)
	{
		y = -1;
		while (++y < mapd.rows && flag == 0)
			if (mapd.map_dimen[i][y] == 'P')
				flag = 1;
	}
	i--;
	y--;
	floodfill(mapd, i, y);
}

void	access_check(t_fdf mapd)
{
	int		i;
	int		y;

	i = -1;
	while (++i < mapd.columns)
	{
		y = -1;
		while (++y < mapd.rows)
		{
			if (mapd.map_dimen[i][y] != '1' && mapd.map_dimen[i][y] != '0'
				&& mapd.map_dimen[i][y] != 'A')
			{
				write(1, "Accessibility error", 20);
				ft_free(mapd.map_dimen);
				exit(EXIT_FAILURE);
			}
		}
	}
	ft_free(mapd.map_dimen);
}
