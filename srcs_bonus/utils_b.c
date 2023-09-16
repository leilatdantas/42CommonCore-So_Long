/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:50:04 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/16 18:58:31 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	floodfill(t_game *game, char **matrix, t_point cur)
{
	if (matrix[cur.y][cur.x] == '1')
		return ;
	else if (matrix[cur.y][cur.x] == 'C')
		game->path_collect++;
	else if (matrix[cur.y][cur.x] == 'E')
		game->path = 1;
	matrix[cur.y][cur.x] = '1';
	floodfill(game, matrix, (t_point){cur.x + 1, cur.y});
	floodfill(game, matrix, (t_point){cur.x - 1, cur.y});
	floodfill(game, matrix, (t_point){cur.x, cur.y + 1});
	floodfill(game, matrix, (t_point){cur.x, cur.y - 1});
}

void	map_components2(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->map_bytes[i])
	{
		j = 0;
		while (game->map->map_bytes[i][j])
		{
			if (game->map->map_bytes[i][j] == PLAYER)
				game->player.pos = (t_point){j, i};
			else if (game->map->map_bytes[i][j] == EXIT)
				game->exit = (t_point){j, i};
			else if (game->map->map_bytes[i][j] == ENEMY)
				game->map->enemies++;
			else if (game->map->map_bytes[i][j] != FLOOR
					&& game->map->map_bytes[i][j] != WALL
					&& game->map->map_bytes[i][j] != COL)
				exit_message(game, "Map has invalid character!\n");
			j++;
		}
		i++;
	}
}

t_img	new_file_image(t_game *g, char *path)
{
	t_img	img;

	if (path)
		img.img_ptr = mlx_xpm_file_to_image(g->mlx, \
			path, &(img.w), &(img.h));
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, \
		&img.line_len, &img.endian);
	return (img);
}

int	ft_tochar(int c)
{
	if (c >= 0 && c <= 9)
		return (c + '0');
	return (c);
}

void	load_xpm(t_game *g, t_sprite *s, char *prefix, int n)
{
	size_t	len;
	int		i;
	char	path[200];

	i = 0;
	ft_bzero(path, 200);
	ft_strlcpy(path, prefix, ft_strlen(prefix) + 1);
	ft_strlcat(path, "00.xpm", 200);
	len = ft_strlen(path);
	while (i < n)
	{
		path[len - 6] = ft_tochar((i + 1) / 10);
		path[len - 5] = ft_tochar((i + 1) % 10);
		s->frames[i] = new_file_image(g, path);
		i++;
	}
}

/************************************************************/
// void	map_print(t_map *map)
// {
// 	int	i;

// 	i = 0;
// 	ft_printf("Rows: %d\n", map->rows);
// 	ft_printf("Columns: %d\n", map->columns);
// 	ft_printf("Collectables: %d\n", map->collectables);
// 	ft_printf("Players: %d\n", map->player);
// 	ft_printf("Exits: %d\n", map->exits);
// 	while (map->map_bytes[i])
// 		ft_printf("%s\n", map->map_bytes[i++]);
// }
