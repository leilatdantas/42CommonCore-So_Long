/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:14:56 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/17 12:24:06 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	destroy_map(t_map *map)
{
	if (!map)
		return ;
	if (map->map_bytes)
		map_matrix_delete(map->map_bytes);
	free(map);
}

void	destroy_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < NUM_IMAGES)
	{
		mlx_destroy_image(game->mlx, game->image[i].img);
		i++;
	}
	free(game->image);
}

void	destroy_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		destroy_map(game->map);
	if (game->image)
		destroy_images(game);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
}
