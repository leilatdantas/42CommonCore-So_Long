/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:17:06 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/17 12:30:08 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	destroy_map(t_map *map)
{
	if (!map)
		return ;
	if (map->map_bytes)
		destroy_matrix(map->map_bytes);
	free(map);
}

void	destroy_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < NUM_IMAGES)
	{
		mlx_destroy_image(game->mlx, game->image[i].img_ptr);
		i++;
	}
	free(game->image);
	destroy_walls(game);
}

void	destroy_sprites(t_game *game, t_sprite *sprite)
{
	int	j;

	j = 0;
	while (j < sprite->nframes)
	{
		if (sprite->frames[j].img_ptr)
			mlx_destroy_image(game->mlx, sprite->frames[j].img_ptr);
		j++;
	}
	free(sprite->frames);
}

void	destroy_players(t_game *game)
{
	int	i;

	i = -1;
	while (++i < NUM_PLAYER_VERSIONS)
	{
		if (game->player_sp)
			destroy_sprites(game, &game->player_sp[i]);
	}
	free(game->player_sp);
}

void	destroy_game(t_game *game)
{
	if (!game)
		return ;
	free(game->melon);
	free(game->enemies);
	destroy_sprites(game, &game->melon_sp);
	destroy_sprites(game, &game->enemies_sp);
	destroy_players(game);
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
