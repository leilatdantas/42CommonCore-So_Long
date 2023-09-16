/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:11:50 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/16 18:55:07 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	load_image_wall(t_game *game)
{
	game->wall = malloc(NUM_WALL * sizeof(t_img));
	if (!game->wall)
		exit_message(game, "Error in allocating images.\n");
	game->wall[WR].img_ptr = mlx_xpm_file_to_image(game->mlx, IWR,
			&game->wall[WR].w, &game->wall[WR].h);
	game->wall[WL].img_ptr = mlx_xpm_file_to_image(game->mlx, IWL,
			&game->wall[WL].w, &game->wall[WL].h);
	game->wall[WU].img_ptr = mlx_xpm_file_to_image(game->mlx, IWU,
			&game->wall[WU].w, &game->wall[WU].h);
	game->wall[WD].img_ptr = mlx_xpm_file_to_image(game->mlx, IWD,
			&game->wall[WD].w, &game->wall[WD].h);
	game->wall[WUR].img_ptr = mlx_xpm_file_to_image(game->mlx, IWUR,
			&game->wall[WUR].w, &game->wall[WUR].h);
	game->wall[WUL].img_ptr = mlx_xpm_file_to_image(game->mlx, IWUL,
			&game->wall[WUL].w, &game->wall[WUL].h);
	game->wall[WDR].img_ptr = mlx_xpm_file_to_image(game->mlx, IWDR,
			&game->wall[WDR].w, &game->wall[WDR].h);
	game->wall[WDL].img_ptr = mlx_xpm_file_to_image(game->mlx, IWDL,
			&game->wall[WDL].w, &game->wall[WDL].h);
	game->wall[WC].img_ptr = mlx_xpm_file_to_image(game->mlx, IWC,
			&game->wall[WC].w, &game->wall[WC].h);
}

t_img	get_walls(t_game *game, t_point p)
{
	t_img	sprite;

	sprite = game->wall[WC];
	if (p.x == 0 && p.y == 0)
		sprite = game->wall[WUL];
	else if (p.x == 0 && p.y != 0 && (p.y != game->map->rows - 1))
		sprite = game->wall[WL];
	else if (p.x == 0 && p.y == game->map->rows - 1)
		sprite = game->wall[WDL];
	else if (p.x != 0 && p.y == 0 && (p.x != game->map->columns - 1))
		sprite = game->wall[WU];
	else if (p.x == game->map->columns - 1 && p.y == 0)
		sprite = game->wall[WUR];
	else if (p.x == game->map->columns - 1 && p.y != 0
		&& (p.y != game->map->rows - 1))
		sprite = game->wall[WR];
	else if ((p.x == game->map->columns - 1) && (p.y == game->map->rows - 1))
		sprite = game->wall[WDR];
	else if (p.x != 0 && (p.y == game->map->rows - 1))
		sprite = game->wall[WD];
	if (p.y == game->map->rows)
		sprite = game->image[BG];
	return (sprite);
}

void	destroy_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < NUM_WALL)
	{
		mlx_destroy_image(game->mlx, game->wall[i].img_ptr);
		i++;
	}
	free(game->wall);
}
