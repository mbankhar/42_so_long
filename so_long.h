/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:53:03 by mbankhar          #+#    #+#             */
/*   Updated: 2024/05/14 16:41:28 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH 1920
# define HEIGHT 1080

# include <time.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"

typedef struct s_fdf
{
	int				i;
	int				y;
	int				rows;
	int				columns;
	char			**map_dimen;
	char			play;
	char			ex;
	char			coll;
	int				monster_x;
	int				monster_y;
	int				player_x;
	int				player_y;
	char			**mapsize;
	mlx_t			*mlxpointer;
	mlx_t			*mlx;
	int				moves;
	int				monster;

	mlx_texture_t	*player_text;
	mlx_texture_t	*player_text_final;
	mlx_texture_t	*coll_text;
	mlx_texture_t	*wall_text;
	mlx_texture_t	*gate_text;
	mlx_texture_t	*ground_text;
	mlx_texture_t	*monster_text;

	mlx_image_t		*player_image;
	mlx_image_t		*player_image_final;
	mlx_image_t		*coll_image;
	mlx_image_t		*wall_image;
	mlx_image_t		*gate_image;
	mlx_image_t		*ground_image;
	mlx_image_t		*monster_image;

}	t_fdf;

void	move_monster(t_fdf *mapd, int x, int y);
void	monster(t_fdf *mapd);
void	read_map(int fd, t_fdf *mapd);
char	**parse_map(int fd, t_fdf mapd);
void	open_map(int argc, char **argv, t_fdf *mapd);
void	copy_map(t_fdf *mapd);
void	ft_free(char **str);
void	check_two(t_fdf *mapd);
void	check_forerrors(t_fdf *mapd);
void	floodfill(t_fdf mapd, int x, int y);
void	floodfillcheck(t_fdf mapd);
void	access_check(t_fdf mapd);
void	images(t_fdf *mapd);
void	texture_to_image(t_fdf *mapd);
void	ground(t_fdf *mapd);
void	placeimages(t_fdf *mapd);
void	player(t_fdf *mapd);
void	move_player(t_fdf *mapd, int x, int y);
void	game_over(t_fdf *mapd, int x, int y);
void	remove_db(t_fdf *mapd, int x, int y);
void	check_balls(t_fdf *mapd, int x, int y);
void	move(t_fdf *mapd, int x, int y);
void	move_up(t_fdf *mapd);
void	move_down(t_fdf *mapd);
void	move_left(t_fdf *mapd);
void	move_right(t_fdf *mapd);
void	commands(mlx_key_data_t keydata, void *param);
void	change_player(t_fdf *mapd, int x, int y);
void	freeforfuckssake(t_fdf mapd);
void	map_intact_check(t_fdf mapd);
void	map_error(t_fdf mapd);
void	make_mons_move(t_fdf *mapd);
void	check_line(char *line);
void	read_it(int fd);
#endif