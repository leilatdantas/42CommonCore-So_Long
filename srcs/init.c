/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:34:01 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/16 14:23:12 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game(char *map_name)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	read_map(&game, map_name);
	valid_map(&game);
	start_game(&game);
}
