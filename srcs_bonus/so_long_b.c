/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:11:56 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/16 18:44:32 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	render(t_game *g, t_img *img, t_point p)
{
	mlx_put_image_to_window(g->mlx, g->window, img->img_ptr, \
		p.x * img->w, p.y * img->h);
}

int	is_same_point(t_point p1, t_point p2)
{
	return (p1.x == p2.x && p1.y == p2.y);
}

void	put_counter(t_game *game)
{
	char	*moves;

	game->moves++;
	moves = ft_itoa(game->moves);
	put_background(game, SIZE / 2);
	mlx_string_put(game->mlx, game->window, SIZE + SIZE / 2,
		game->map->height + SIZE / 2, 0x000000, moves);
	mlx_string_put(game->mlx, game->window, SIZE,
		game->map->height + SIZE, 0x00000, "MOVES");
	free(moves);
}

int	check_move(t_game *game, t_point next)
{
	if (game->map->map_bytes[next.y][next.x] == WALL)
		return (0);
	else if (next.y == game->player.pos.y && next.x == game->player.pos.x)
		return (0);
	return (1);
}

int	put_game(t_game *game)
{
	if (!game->game_over)
	{
		animate(game, &game->player, game->player_sp, 1);
		animate(game, game->enemies, &game->enemies_sp, game->map->enemies);
		animate(game, game->melon, &game->melon_sp, game->map->collectables);
		move_enemies(game);
		if (check_move(game, game->player.next))
		{
			put_counter(game);
			move_player(game);
		}
	}
	return (0);
}
