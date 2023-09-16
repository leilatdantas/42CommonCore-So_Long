/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:44:26 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/16 13:58:28 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	quit(t_game *game)
{
	if (game->map->map_bytes[game->next.y][game->next.x] == DOOR)
		ft_printf(GREEN"🥳 Congrats! You win! 🥳\n"RESET);
	else
		ft_printf(CYAN"Game interrupted by the user. So sad! 😢\n" RESET);
	if (game)
		destroy_game(game);
#ifdef __linux__
	if (game->mlx)
		mlx_destroy_display(game->mlx);
#endif
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	free(game->mlx);
	exit(0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		quit(game);
	if (keycode == UP || keycode == W)
		game->next = (t_point){game->current.x, game->current.y - 1};
	if (keycode == DOWN || keycode == S)
		game->next = (t_point){game->current.x, game->current.y + 1};
	else if (keycode == LEFT || keycode == A)
		game->next = (t_point){game->current.x - 1, game->current.y};
	else if (keycode == RIGHT || keycode == D)
		game->next = (t_point){game->current.x + 1, game->current.y};
	return (keycode);
}
