/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:34:01 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/16 18:52:25 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	init_enemies(t_game *g)
{
	int		i;
	t_point	p;

	i = 0;
	p = (t_point){-1, -1};
	g->enemies = ft_calloc(g->map->enemies, sizeof(t_entity));
	if (!g->enemies)
		exit_message(g, "Failed allocation on coins entity array\n");
	while (++p.y < g->map->rows)
	{
		p.x = -1;
		while (++p.x < g->map->columns)
		{
			if (pos(g, p) == ENEMY)
			{
				g->enemies[i].frame = rand() % NUM_ENEMY_FRAMES;
				g->enemies[i].frame_freq = CALLS_PER_FRAME_ENEMIES;
				g->enemies[i].move_freq = rand() % MOVE_CALLS + MOVE_CALLS;
				g->enemies[i].type = ENEMY;
				g->enemies[i].pos = p;
				g->enemies[i++].next = p;
			}
		}
	}
}

void	init_melons(t_game *g)
{
	int		i;
	t_point	p;

	i = 0;
	p = (t_point){-1, -1};
	g->melon = ft_calloc(g->map->collectables, sizeof(t_entity));
	if (!g->melon)
		exit_message(g, "Failed on allocation melons array\n");
	while (++p.y < g->map->rows)
	{
		p.x = -1;
		while (++p.x < g->map->columns)
		{
			if (pos(g, p) == COL)
			{
				g->melon[i].frame = rand() % NUM_MELON_FRAMES;
				g->melon[i].frame_freq = CALLS_PER_FRAME_MELON;
				g->melon[i].type = COL;
				g->melon[i++].pos = p;
			}
		}
	}
}

void	init_player(t_game *game)
{
	game->player.frame_freq = CALLS_PER_FRAME_PLAYER;
	game->player.type = PLAYER;
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_message(game, "Error in mlx_init().\n");
	game->window = mlx_new_window(game->mlx, game->map->width,
			game->map->height + SIZE, "So Long");
	if (!game->window)
		exit_message(game, "Error in mlx_window().\n");
	init_player(game);
	init_melons(game);
	init_enemies(game);
	load_images(game);
	load_image_wall(game);
	put_graphics(game);
	mlx_hook(game->window, 2, KEY_MASK, &key_press, game);
	mlx_hook(game->window, 17, CLOSE_MASK, &quit, game);
	mlx_loop_hook(game->mlx, &put_game, game);
	mlx_loop(game->mlx);
}

void	init_game(char *map_name)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	read_map(&game, map_name);
	valid_map(&game);
	start_game(&game);
}
