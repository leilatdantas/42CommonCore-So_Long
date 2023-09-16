/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:37:47 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/16 13:50:37 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map_caracters	pos(t_game *game, t_point pos)
{
	return (game->map->map_bytes[pos.y][pos.x]);
}

void	move_player(t_game *game)
{
	if (pos(game, game->next) == COL || pos(game, game->next) == PLATE)
	{
		if (pos(game, game->next) == COL)
			game->map->collectables--;
		game->map->map_bytes[game->next.y][game->next.x] = PLAYER_PLATE;
	}
	else if (pos(game, game->next) == EXIT)
		game->map->map_bytes[game->next.y][game->next.x] = PLAYER_EXIT;
	else if (pos(game, game->next) == DOOR)
		quit(game);
	else
		game->map->map_bytes[game->next.y][game->next.x] = PLAYER;
	if (game->map->map_bytes[game->current.y][game->current.x] == PLAYER_PLATE
		|| game->map->map_bytes[game->current.y][game->current.x] == COL)
		game->map->map_bytes[game->current.y][game->current.x] = PLATE;
	else if (game->map->map_bytes[game->current.y][game->current.x] ==
		PLAYER_EXIT)
		game->map->map_bytes[game->current.y][game->current.x] = EXIT;
	else
		game->map->map_bytes[game->current.y][game->current.x] = FLOOR;
	put_images(game, game->current);
	put_images(game, game->next);
	game->current = game->next;
}

int	check_move(t_game *game, t_point next)
{
	if (game->map->map_bytes[next.y][next.x] == WALL)
		return (0);
	else if (next.y == game->current.y && next.x == game->current.x)
		return (0);
	return (1);
}

int	put_game(t_game *game)
{
	if (!check_move(game, game->next))
		return (0);
	game->moves++;
	ft_printf("NUMBER OF MOVES = %d\n", game->moves);
	move_player(game);
	return (0);
}
