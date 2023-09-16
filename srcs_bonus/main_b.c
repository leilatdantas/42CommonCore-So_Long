/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:52:45 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/16 19:04:07 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
#include <time.h>

int	valid_map_name(char *map_name)
{
	int	i;

	i = ft_strlen(map_name);
	if (!(ft_strnstr((map_name + (i - 4)), ".ber", 4)))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	char	*map_name;

	map_name = av[1];
	if (ac != 2)
		ft_printf("Usage: %s path_to_map_file.ber\n", av[0]);
	else if (!valid_map_name(map_name))
	{
		ft_printf("Map isn't a .ber file!\n");
		exit(1);
	}
	srand(time(NULL));
	init_game(map_name);
	return (0);
}
