/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:34:01 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/17 12:32:40 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_num_lines(t_game *game, char *map_name)
{
	int		fd;
	int		lines;
	char	*tmp;

	lines = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit_message(game, "Error in read map file.");
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		lines++;
		free(tmp);
	}
	close(fd);
	return (lines);
}

t_map	*new_map(unsigned int columns, unsigned int rows)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->map_bytes = ft_calloc((rows + 1), (sizeof(char *)));
	if (!map->map_bytes)
	{
		map_matrix_delete(map->map_bytes);
		return (NULL);
	}
	map->columns = columns;
	map->rows = rows;
	return (map);
}

t_map	*read_map(t_game *game, char *map_name)
{
	unsigned int		i;
	int					fd;
	char				*tmp;

	i = 0;
	game->map = new_map(0, get_num_lines(game, map_name));
	if (!game->map)
		exit_message(game, "Error in map allocation.");
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit_message(game, "Error in read map file.");
	while (i < game->map->rows)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			exit_message(game, "Error in getting lines from map.");
		game->map->map_bytes[i] = ft_strtrim(tmp, "\n");
		if (!game->map->map_bytes[i])
			exit_message(game, "Error in allocating map bytes.");
		i++;
		free(tmp);
	}
	game->map->map_bytes[i] = NULL;
	close(fd);
	return (game->map);
}

void	init_game(char *map_name)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	read_map(&game, map_name);
	valid_map(&game);
	start_game(&game);
}
