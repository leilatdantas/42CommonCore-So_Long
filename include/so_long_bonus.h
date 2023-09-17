/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:49:09 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/17 12:07:39 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft.h"
# include "get_next_line.h"
# include "get_next_line_bonus.h"
# include "ft_printf.h"
# include "extras.h"

# define RESET		"\033[0m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"

/*MACROS*/
# define NUM_IMAGES 6
# define NUM_WALL 9
# define SIZE 32

# define IF1 "./images/bonus/floor.xpm"
# define IE1 "./images/bonus/exit1.xpm"
# define IE2 "./images/bonus/exit2.xpm"
# define IBG "./images/bonus/floor.xpm"
# define IGO "./images/bonus/bg.xpm"
# define IYW "./images/bonus/youwin.xpm"

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
	LEFT = 123,
	Q = 12
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
	Q = 113,
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
	E1,
	E2,
	BG,
	GO,
	YW
}			t_index;

/*STRUCTS*/
typedef struct s_map
{
	char			**map_bytes;
	unsigned int	columns;
	unsigned int	rows;
	unsigned int	player;
	unsigned int	enemies;
	unsigned int	collectables;
	unsigned int	exits;
	unsigned int	height;
	unsigned int	width;
}					t_map;

typedef struct s_game
{
	t_map			*map;
	t_sprite		*player_sp;
	t_sprite		enemies_sp;
	t_sprite		melon_sp;
	t_entity		player;
	t_entity		*enemies;
	t_entity		*melon;
	t_point			exit;
	t_point			current;
	t_point			next;
	t_img			*image;
	t_img			*wall;
	unsigned int	moves;
	unsigned int	path;
	unsigned int	path_collect;
	unsigned int	collected;
	void			*mlx;
	void			*window;
	int				game_over;
	char			*map_name;
}					t_game;

/*FUNCTIONS*/
void			init_game(char *map_name);
t_map			*read_map(t_game *game, char *map_name);
void			valid_map(t_game *game);
void			map_components2(t_game *game);
void			load_images(t_game *game);
void			load_xpm(t_game *g, t_sprite *s, char *prefix, int n);
void			load_image_wall(t_game *game);
int				put_graphics(t_game *game);
t_img			get_walls(t_game *game, t_point p);
int				key_press(int keycode, t_game *game);
void			destroy_walls(t_game *game);
void			set(t_game *game, t_point p, t_type type);
void			animate(t_game *g, t_entity *ent, t_sprite *frames, int n);
void			move_enemies(t_game *g);
void			move_player(t_game *game);
void			game_over(t_game *game, t_img img);
void			destroy_matrix(char **map_bytes);
t_type			pos(t_game *game, t_point pos);
void			floodfill(t_game *game, char **matrix, t_point cur);
void			exit_message(t_game *game, char *message);
void			destroy_game(t_game *game);
int				put_game(t_game *game);
void			render(t_game *g, t_img *img, t_point p);
int				is_same_point(t_point p1, t_point p2);
void			put_background(t_game *game, int size);
void			render_tile(t_game *g, t_point p);
int				quit(t_game *game);

#endif
