/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:21:07 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/16 19:13:00 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	destroy_matrix(char **map_bytes)
{
	int	i;

	i = 0;
	while (map_bytes[i])
	{
		free(map_bytes[i]);
		i++;
	}
	free(map_bytes);
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
		destroy_matrix(map->map_bytes);
		return (NULL);
	}
	map->columns = columns;
	map->rows = rows;
	return (map);
}

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
