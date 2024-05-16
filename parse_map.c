/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:06:54 by mbankhar          #+#    #+#             */
/*   Updated: 2024/05/14 16:48:47 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(int fd, t_fdf *mapd)
{
	char	*line;

	mapd->columns = 0;
	line = get_next_line(fd);
	check_line(line);
	mapd->rows = ft_strlen_newline(line);
	mapd->columns++;
	free(line);
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		if ((int)ft_strlen_newline(line) != mapd->rows
			&& ft_strlen_newline(line) != 0)
		{
			write(1, "Map size error", 15);
			exit(EXIT_FAILURE);
		}
		mapd->columns++;
		free(line);
	}
	free(line);
	read_it(fd);
}

char	**parse_map(int fd, t_fdf mapd)
{
	char	*line;
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (mapd.columns + 1));
	if (!map)
		free(map);
	i = -1;
	while (++i < mapd.columns)
	{
		line = get_next_line(fd);
		map[i] = malloc(sizeof(char) * (mapd.rows + 1));
		if (!map[i])
			ft_free(map);
		ft_strcpy(map[i], line);
		free(line);
	}
	map[mapd.columns] = NULL;
	return (map);
}

void	open_map(int argc, char **argv, t_fdf *mapd)
{
	int	fd;

	if (argc != 2)
	{
		write(1, "arg error", 10);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	read_map(fd, mapd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	mapd->map_dimen = parse_map(fd, *mapd);
	close(fd);
}

void	copy_map(t_fdf *mapd)
{
	int	i;

	mapd->mapsize = (char **)malloc(sizeof(char *) * (mapd->columns + 1));
	if (!mapd->mapsize)
		free(mapd->mapsize);
	i = -1;
	while (++i < mapd->columns)
	{
		mapd->mapsize[i] = (char *)malloc(sizeof(char) * mapd->rows + 1);
		if (!mapd->mapsize[i])
			ft_free(mapd->mapsize);
		ft_strcpy(mapd->mapsize[i], mapd->map_dimen[i]);
	}
	mapd->mapsize[mapd->columns] = NULL;
}

void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		free(str[i]);
	}
	free(str);
}
