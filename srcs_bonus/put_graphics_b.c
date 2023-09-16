/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_graphics_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:19:03 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/16 19:00:31 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	put_walls(t_game *game, t_point pos)
{
	t_img	sprite;

	sprite = get_walls(game, (t_point){pos.x, pos.y});
	mlx_put_image_to_window(game->mlx, game->window, sprite.img_ptr,
		(SIZE * pos.x), (SIZE * pos.y));
}

void	put_background(t_game *game, int size)
{
	int	i;
	int	j;

	i = game->map->rows;
	j = 0;
	while (j < size)
	{
		put_walls(game, (t_point){j, i});
		j++;
	}
	i++;
}

int	put_graphics(t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	put_background(game, game->map->columns);
	while (i < game->map->rows)
	{
		j = 0;
		while (j < game->map->columns)
		{
			if (pos(game, (t_point){j, i}) == WALL)
				put_walls(game, (t_point){j, i});
			else
				render_tile(game, (t_point){j, i});
			j++;
		}
		i++;
	}
	return (0);
}
