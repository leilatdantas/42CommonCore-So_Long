/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 23:31:21 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/16 15:29:15 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	map_retangular(t_map *map)
{
	size_t	columns;
	int		i;

	i = 0;
	columns = ft_strlen(map->map_bytes[i]);
	while (map->map_bytes[i])
	{
		if (ft_strlen(map->map_bytes[i]) != columns)
			return (0);
		i++;
	}
	map->columns = columns;
	return (1);
}

int	map_components(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map->map_bytes[++i])
	{
		j = -1;
		while (game->map->map_bytes[i][++j])
		{
			if (game->map->map_bytes[i][j] == 'C')
				game->map->collectables++;
			else if (game->map->map_bytes[i][j] == 'P')
				game->map->player++;
			else if (game->map->map_bytes[i][j] == 'E')
				game->map->exits++;
		}
	}
	map_components2(game);
	if (game->map->collectables >= 1 && game->map->exits == 1
		&& game->map->player == 1)
		return (1);
	return (0);
}

int	map_walls(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (map->map_bytes[i])
	{
		j = 0;
		if (i == 0 || i == map->rows)
		{
			while (map->map_bytes[i][j])
			{
				if (map->map_bytes[i][j] != WALL)
					return (0);
				j++;
			}
		}
		else
		{
			if (map->map_bytes[i][0] != WALL ||
				map->map_bytes[i][map->columns - 1] != WALL)
				return (0);
		}
		i++;
	}
	return (1);
}

int	map_path(t_game *game)
{
	char	**matrix_map;
	int		i;

	i = 0;
	matrix_map = malloc(sizeof(char *) * (game->map->rows + 1));
	if (!matrix_map)
		exit_message(game, "Mamory allocation fail!\n");
	while (game->map->map_bytes[i])
	{
		matrix_map[i] = ft_strdup(game->map->map_bytes[i]);
		i++;
	}
	matrix_map[i] = NULL;
	floodfill(game, matrix_map, game->player.pos);
	destroy_matrix(matrix_map);
	return (game->path == 1 && game->path_collect == game->map->collectables);
}

void	valid_map(t_game *game)
{
	if (!game->map->map_bytes[0])
		exit_message(game, "Map is empty!\n");
	if (!map_retangular(game->map))
		exit_message(game, "Map is not retangular!\n");
	if (!map_components(game))
		exit_message(game, "Map doesn't have the correct components!\n");
	if (!map_walls(game->map))
		exit_message(game, "Map isn't completely surrounded by walls!\n");
	if (!map_path(game))
		exit_message(game, "Map doesn't have a valid path!\n");
	game->map->width = game->map->columns * SIZE;
	game->map->height = game->map->rows * SIZE;
}
