/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:00:15 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/16 18:50:52 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	key_press(int keycode, t_game *g)
{
	if (keycode == ESC || keycode == Q)
		quit(g);
	if (keycode == UP || keycode == W)
	{
		g->player.next = (t_point){g->player.pos.x, g->player.pos.y - 1};
		g->player.dir = MVUP;
	}
	if (keycode == DOWN || keycode == S)
	{
		g->player.next = (t_point){g->player.pos.x, g->player.pos.y + 1};
		g->player.dir = MVDOWN;
	}
	else if (keycode == LEFT || keycode == A)
	{
		g->player.next = (t_point){g->player.pos.x - 1, g->player.pos.y};
		g->player.dir = MVLEFT;
	}
	else if (keycode == RIGHT || keycode == D)
	{
		g->player.next = (t_point){g->player.pos.x + 1, g->player.pos.y};
		g->player.dir = MVRIGHT;
	}
	return (keycode);
}

void	animate(t_game *g, t_entity *ent, t_sprite *frames, int n)
{
	int	i;
	int	frame_set;

	i = -1;
	while (++i < n)
	{
		if (++ent[i].curr_freq % ent[i].frame_freq == 0)
			ent[i].frame = (ent[i].frame + 1) % frames->nframes;
		frame_set = ent[i].dir;
		render(g, &frames[frame_set].frames[ent[i].frame], ent[i].pos);
	}
}
