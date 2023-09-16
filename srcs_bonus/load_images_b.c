/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:43:19 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/16 19:48:25 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	load_player_frames(t_game *g)
{
	g->player_sp = malloc(NUM_PLAYER_VERSIONS * sizeof(t_sprite));
	if (!g->player_sp)
		exit_message(g, "Failed allocation on player frames array\n");
	g->player_sp[MVUP].frames = malloc(NUM_PLAYER_FRAMES * sizeof(t_img));
	g->player_sp[MVDOWN].frames = malloc(NUM_PLAYER_FRAMES * sizeof(t_img));
	g->player_sp[MVRIGHT].frames = malloc(NUM_PLAYER_FRAMES * sizeof(t_img));
	g->player_sp[MVLEFT].frames = malloc(NUM_PLAYER_FRAMES * sizeof(t_img));
	if (!g->player_sp[MVUP].frames)
		exit_message(g, "Failed allocation on right player frames\n");
	if (!g->player_sp[MVDOWN].frames)
		exit_message(g, "Failed allocation on left player frames\n");
	if (!g->player_sp[MVRIGHT].frames)
		exit_message(g, "Failed allocation on right player frames\n");
	if (!g->player_sp[MVLEFT].frames)
		exit_message(g, "Failed allocation on left player frames\n");
	g->player_sp[MVUP].nframes = NUM_PLAYER_FRAMES;
	g->player_sp[MVDOWN].nframes = NUM_PLAYER_FRAMES;
	g->player_sp[MVRIGHT].nframes = NUM_PLAYER_FRAMES;
	g->player_sp[MVLEFT].nframes = NUM_PLAYER_FRAMES;
	load_xpm(g, &g->player_sp[MVUP], PLAYER_UP_PATH, NUM_PLAYER_FRAMES);
	load_xpm(g, &g->player_sp[MVDOWN], PLAYER_DOWN_PATH, NUM_PLAYER_FRAMES);
	load_xpm(g, &g->player_sp[MVRIGHT], PLAYER_RIGHT_PATH, NUM_PLAYER_FRAMES);
	load_xpm(g, &g->player_sp[MVLEFT], PLAYER_LEFT_PATH, NUM_PLAYER_FRAMES);
}

void	load_collectables(t_game *g)
{
	g->melon_sp.frames = malloc(NUM_MELON_FRAMES * sizeof(t_img));
	if (!g->melon_sp.frames)
		exit_message(g, "Failed on allocation melon frames\n");
	g->melon_sp.nframes = NUM_MELON_FRAMES;
	load_xpm(g, &g->melon_sp, MELON_PATH, NUM_MELON_FRAMES);
}

void	load_enemies_frames(t_game *g)
{
	g->enemies_sp.frames = malloc(NUM_ENEMY_FRAMES * sizeof(t_img));
	if (!g->enemies_sp.frames)
		exit_message(g, "Failed on allocation enemies frames\n");
	g->enemies_sp.nframes = NUM_ENEMY_FRAMES;
	load_xpm(g, &g->enemies_sp, ENEMY_PATH, NUM_ENEMY_FRAMES);
}

void	load_sprites(t_game *g)
{	
	load_player_frames(g);
	load_collectables(g);
	load_enemies_frames(g);
}

void	load_images(t_game *game)
{
	game->image = malloc(NUM_IMAGES * sizeof(t_img));
	if (!game->image)
		exit_message(game, "Error in allocating images.\n");
	game->image[F1].img_ptr = mlx_xpm_file_to_image(game->mlx, IF1,
			&game->image[F1].w, &game->image[F1].h);
	game->image[E1].img_ptr = mlx_xpm_file_to_image(game->mlx, IE1,
			&game->image[E1].w, &game->image[E1].h);
	game->image[E2].img_ptr = mlx_xpm_file_to_image(game->mlx, IE2,
			&game->image[E2].w, &game->image[E2].h);
	game->image[BG].img_ptr = mlx_xpm_file_to_image(game->mlx, IBG,
			&game->image[BG].w, &game->image[BG].h);
	game->image[GO].img_ptr = mlx_xpm_file_to_image(game->mlx, IGO,
			&game->image[GO].w, &game->image[GO].h);
	game->image[YW].img_ptr = mlx_xpm_file_to_image(game->mlx, IYW,
			&game->image[YW].w, &game->image[YW].h);
	load_sprites(game);
}
