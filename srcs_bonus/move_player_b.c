/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:47:15 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/16 18:49:03 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	set(t_game *game, t_point p, t_type type)
{
	game->map->map_bytes[p.y][p.x] = type;
}

t_type	pos(t_game *game, t_point pos)
{
	return (game->map->map_bytes[pos.y][pos.x]);
}

void	render_tile(t_game *g, t_point p)
{
	t_img	*img;

	img = &g->image[E2];
	if (pos(g, p) == DOOR)
		img = &g->image[E2];
	else if (pos(g, p) == EXIT)
		img = &g->image[E1];
	else if (pos(g, p) == FLOOR)
		img = &g->image[F1];
	else if (pos(g, p) == PLAYER)
		img = &g->player_sp[g->player.dir].frames[0];
	else if (pos(g, p) == COL)
		img = &g->melon_sp.frames[0];
	else if (pos(g, p) == ENEMY)
		img = &g->enemies_sp.frames[0];
	else
		return ;
	render(g, img, p);
}

void	collect_melon(t_game *game)
{
	unsigned int	i;

	i = 0;
	game->collected++;
	while (i < game->map->collectables)
	{
		if (is_same_point(game->melon[i].pos, game->player.next))
		{
			game->melon[i].pos = (t_point){game->map->columns
				- game->collected, game->map->rows};
		}
		i++;
	}
}

void	move_player(t_game *game)
{
	set(game, game->player.pos, FLOOR);
	if (pos(game, game->player.next) == COL)
		collect_melon(game);
	if (pos(game, game->player.next) == ENEMY)
		game_over(game, game->image[GO]);
	else
	{
		if (pos(game, game->player.next) == DOOR)
			game_over(game, game->image[YW]);
		else
		{
			if (game->map->collectables == game->collected)
				set(game, game->exit, DOOR);
			else
				set(game, game->exit, EXIT);
			set(game, game->player.next, PLAYER);
			render_tile(game, game->exit);
			render_tile(game, game->player.pos);
			render_tile(game, game->player.next);
			game->player.pos = game->player.next;
		}
	}
}
