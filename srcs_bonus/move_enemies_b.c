/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:24:59 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/16 19:02:05 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	check_enemy_move(t_game *g, t_point p)
{
	if (pos(g, p) == FLOOR || pos(g, p) == PLAYER)
		return (1);
	return (0);
}

int	can_enemy_move(t_game *g, t_point *pos)
{
	int	can_move;

	can_move = 0;
	if (check_enemy_move(g, (t_point){pos->x + 1, pos->y}))
		can_move = 1;
	if (check_enemy_move(g, (t_point){pos->x - 1, pos->y}))
		can_move = 1;
	if (check_enemy_move(g, (t_point){pos->x, pos->y + 1}))
		can_move = 1;
	if (check_enemy_move(g, (t_point){pos->x, pos->y - 1}))
		can_move = 1;
	return (can_move);
}

void	enemy_movements(t_game *g, t_entity *enemy)
{
	unsigned int	num;

	while (1)
	{
		num = rand() % 3 - 1;
		if (rand() % 2)
			enemy->next = (t_point){enemy->pos.x + num, enemy->pos.y};
		else
			enemy->next = (t_point){enemy->pos.x, enemy->pos.y + num};
		if (check_enemy_move(g, enemy->next))
			break ;
	}
}

void	move_enemies(t_game *game)
{
	unsigned int	i;

	i = 0;
	while (i < game->map->enemies)
	{
		if (++game->enemies[i].move_counter % game->enemies[i].move_freq == 0)
		{
			if (can_enemy_move(game, &game->enemies[i].pos))
				enemy_movements(game, &game->enemies[i]);
			if (pos(game, game->enemies[i].next) == PLAYER)
				game_over(game, game->image[GO]);
			else
			{
				set(game, game->enemies[i].pos, FLOOR);
				render(game, &game->image[F1], game->enemies[i].pos);
				set(game, game->enemies[i].next, ENEMY);
				game->enemies[i].pos = game->enemies[i].next;
			}
		}
		i++;
	}
}
