/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:49:09 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/16 19:24:00 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "get_next_line.h"
# include "get_next_line_bonus.h"
# include "ft_printf.h"
# include <stdbool.h>
// # include <stdio.h>
// # include <unistd.h>
// # include <stdlib.h>
// # include <fcntl.h>

# define RESET	 "\033[0m"
# define RED 	 "\033[1;31m"
# define GREEN 	 "\033[1;32m"
# define YELLOW 	 "\033[1;33m"
# define BLUE	"\033[1;34m"
# define MAGENTA	 "\033[1;35m"
# define CYAN 	"\033[1;36m"
# define WHITE 	 "\033[1;37m"

/*MACROS*/
# define NUM_IMAGES 9
# define SIZE 48

# define IF1 "./images/floor.xpm"
# define IW1 "./images/walls.xpm"
# define IC1 "./images/burger.xpm"
# define IC2 "./images/plate.xpm"
# define IP1 "./images/player.xpm"
# define IP2 "./images/player_plate.xpm"
# define IP3 "./images/player_exit.xpm"
# define IE1 "./images/exit1.xpm"
# define IE2 "./images/exit2.xpm"

# ifdef __APPLE__

#  include "../mlx_mac/mlx.h"

# elif defined(__linux__)

#  include "../mlx_linux/mlx.h"

# endif

# ifdef __APPLE__

typedef enum e_key
{
	ESC = 53,
	A = 0,
	S = 1,
	D = 2,
	W = 13,
	UP = 126,
	DOWN = 125,
	RIGHT = 124,
	LEFT = 123
}		t_key;

typedef enum e_mask
{
	KEY_MASK = 0,
	CLOSE_MASK = 0
}	t_mask;

# elif defined(__linux__)

typedef enum e_key
{
	ESC = 65307,
	A = 97,
	S = 115,
	D = 100,
	W = 119,
	UP = 65362,
	DOWN = 65364,
	RIGHT = 65363,
	LEFT = 65361
}		t_key;

typedef enum e_mask
{
	KEY_MASK = (1L << 0),
	CLOSE_MASK = (1L << 17)
}	t_mask;

# endif

typedef enum e_index
{
	F1,
	W1,
	P1,
	P2,
	P3,
	C1,
	E1,
	E2,
	C2
}			t_index;

typedef enum e_map_caracters
{
	FLOOR = '0',
	WALL = '1',
	COL = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	DOOR = 'D',
	PLATE = 'K',
	PLAYER_PLATE = 'L',
	PLAYER_EXIT = 'F'
}		t_map_caracters;

/*STRUCTS*/
typedef struct s_map
{
	char			**map_bytes;
	unsigned int	columns;
	unsigned int	rows;
	unsigned int	player;
	unsigned int	collectables;
	unsigned int	exits;
	int				height;
	int				width;
}					t_map;

typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
}		t_point;

typedef struct s_images
{
	void	*img;
	int		height;
	int		width;
}			t_images;

typedef struct s_game
{
	t_map			*map;
	t_point			current;
	t_point			next;
	t_point			exit;
	t_images		*image;
	unsigned int	moves;
	unsigned int	path;
	unsigned int	path_collect;
	unsigned int	fg_plate;
	void			*mlx;
	void			*window;
}					t_game;

/*FUNCTIONS*/
void			map_matrix_delete(char **map_bytes);
void			destroy_map(t_map *map);
void			destroy_images(t_game *game);
void			destroy_game(t_game *game);
void			exit_message(t_game *game, char *message);
void			init_game(char *map_name);
int				quit(t_game *game);
t_map_caracters	pos(t_game *game, t_point pos);
int				check_move(t_game *game, t_point next);
void			move_player(t_game *game);
void			start_game(t_game *game);
int				put_game(t_game *game);
void			put_images(t_game *game, t_point pos);
void			floodfill(t_game *game, char **matrix, t_point cur);
int				key_press(int keycode, t_game *game);
void			map_components2(t_game *game);
void			valid_map(t_game *game);

#endif