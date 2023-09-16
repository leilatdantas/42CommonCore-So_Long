/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:50:04 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/16 13:45:52 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

void	map_matrix_delete(char **map_bytes)
{
	int	i;

	i = 0;
	while (map_bytes[i])
	{
		free(map_bytes[i]);
		i++;
	}
	free(map_bytes[i]);
	free(map_bytes);
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
			if (game->map->map_bytes[i][j] == 'P')
				game->current = (t_point){j, i};
			else if (game->map->map_bytes[i][j] == 'E')
				game->exit = (t_point){j, i};
			j++;
		}
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