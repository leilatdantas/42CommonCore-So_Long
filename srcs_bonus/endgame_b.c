/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:14:56 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/16 18:57:01 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

/*DESTROY*/

void	exit_message(t_game *game, char *message)
{
	if (game)
		destroy_game(game);
	ft_printf(message);
	exit(1);
}

int	quit(t_game *game)
{
	if (game->map->map_bytes[game->player.next.y][game->player.next.x] == DOOR)
		ft_printf(GREEN "Congrats! You win! 🥳\n" RESET);
	else if (game->game_over == 1)
		ft_printf(RED "YOU LOSE! Try again...\n" RESET);
	else
		ft_printf(MAGENTA "Game interrupted by the user.\n" RESET);
	destroy_game(game);
	exit(0);
}

void	game_over(t_game *game, t_img img)
{
	mlx_clear_window(game->mlx, game->window);
	mlx_put_image_to_window(game->mlx, game->window, img.img_ptr,
		game->map->width / 2 - img.w / 2,
		game->map->height / 2 - img.h / 2);
	game->game_over = 1;
}
