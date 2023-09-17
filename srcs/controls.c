/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:44:26 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/17 12:26:13 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_message(t_game *game, char *message)
{
	if (game)
		destroy_game(game);
	if (game->window)
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_printf(message);
	exit(1);
}

int	quit(t_game *game)
{
	if (game->map->map_bytes[game->next.y][game->next.x] == DOOR)
		ft_printf(GREEN "Congrats! You win! 🥳\n" RESET);
	else
		ft_printf(MAGENTA "Game interrupted by the user.\n" RESET);
	destroy_game(game);
	exit(0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC || keycode == Q)
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
