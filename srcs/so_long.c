/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:11:56 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/16 14:01:24 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_exit(t_game *game)
{
	game->map->map_bytes[game->exit.y][game->exit.x] = DOOR;
	mlx_put_image_to_window(game->mlx, game->window, game->image[E2].img,
		(SIZE * game->exit.x), (SIZE * game->exit.y));
}

void	put_images(t_game *game, t_point pos)
{
	t_images	sprite;

	if (game->map->collectables == 0)
		put_exit(game);
	if (game->map->map_bytes[pos.y][pos.x] == WALL)
		sprite = game->image[W1];
	else if (game->map->map_bytes[pos.y][pos.x] == PLAYER)
		sprite = game->image[P1];
	else if (game->map->map_bytes[pos.y][pos.x] == PLAYER_PLATE)
		sprite = game->image[P2];
	else if (game->map->map_bytes[pos.y][pos.x] == PLAYER_EXIT)
		sprite = game->image[P3];
	else if (game->map->map_bytes[pos.y][pos.x] == COL)
		sprite = game->image[C1];
	else if (game->map->map_bytes[pos.y][pos.x] == EXIT)
		sprite = game->image[E1];
	else if (game->map->map_bytes[pos.y][pos.x] == DOOR)
		sprite = game->image[E2];
	else if (game->map->map_bytes[pos.y][pos.x] == PLATE)
		sprite = game->image[C2];
	else if (game->map->map_bytes[pos.y][pos.x] == FLOOR)
		sprite = game->image[F1];
	mlx_put_image_to_window(game->mlx, game->window, sprite.img,
		(SIZE * pos.x), (SIZE * pos.y));
}

int	put_graphics(t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (game->map->map_bytes[i])
	{
		j = 0;
		while (game->map->map_bytes[i][j])
		{
			put_images(game, (t_point){j, i});
			j++;
		}
		i++;
	}
	return (0);
}

void	load_images(t_game *game)
{
	game->image = malloc(NUM_IMAGES * sizeof(t_images));
	if (!game->image)
		exit_message(game, "Error in allocating images.\n");
	game->image[F1].img = mlx_xpm_file_to_image(game->mlx, IF1,
			&game->image[F1].width, &game->image[F1].height);
	game->image[W1].img = mlx_xpm_file_to_image(game->mlx, IW1,
			&game->image[W1].width, &game->image[W1].height);
	game->image[P1].img = mlx_xpm_file_to_image(game->mlx, IP1,
			&game->image[P1].width, &game->image[P1].height);
	game->image[P2].img = mlx_xpm_file_to_image(game->mlx, IP2,
			&game->image[P2].width, &game->image[P2].height);
	game->image[P3].img = mlx_xpm_file_to_image(game->mlx, IP3,
			&game->image[P3].width, &game->image[P3].height);
	game->image[C1].img = mlx_xpm_file_to_image(game->mlx, IC1,
			&game->image[C1].width, &game->image[C1].height);
	game->image[E1].img = mlx_xpm_file_to_image(game->mlx, IE1,
			&game->image[E1].width, &game->image[E1].height);
	game->image[E2].img = mlx_xpm_file_to_image(game->mlx, IE2,
			&game->image[E2].width, &game->image[E2].height);
	game->image[C2].img = mlx_xpm_file_to_image(game->mlx, IC2,
			&game->image[C2].width, &game->image[C2].height);
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_message(game, "Error in mlx_init().\n");
	game->window = mlx_new_window(game->mlx, game->map->width,
			game->map->height, "So Long");
	if (!game->window)
		exit_message(game, "Error in mlx_window().\n");
	load_images(game);
	put_graphics(game);
	mlx_hook(game->window, 2, KEY_MASK, &key_press, game);
	mlx_hook(game->window, 17, CLOSE_MASK, &quit, game);
	mlx_loop_hook(game->mlx, &put_game, game);
	mlx_loop(game->mlx);
}
