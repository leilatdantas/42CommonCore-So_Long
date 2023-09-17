/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:05:21 by lebarbos          #+#    #+#             */
/*   Updated: 2023/09/17 12:08:50 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRAS_H
# define EXTRAS_H

# define NUM_PLAYER_FRAMES	4
# define NUM_MELON_FRAMES	17
# define NUM_ENEMY_FRAMES	8
# define NUM_PLAYER_VERSIONS 4

# define CALLS_PER_FRAME_PLAYER		2500
# define CALLS_PER_FRAME_MELON		700
# define CALLS_PER_FRAME_ENEMIES	2000
# define MOVE_CALLS					8000

# define PLAYER_RIGHT_PATH	"./images/bonus/player/right/player_"
# define PLAYER_UP_PATH		"./images/bonus/player/up/player_"
# define PLAYER_DOWN_PATH	"./images/bonus/player/down/player_"
# define PLAYER_LEFT_PATH	"./images/bonus/player/left/player_"
# define ENEMY_PATH			"./images/bonus/enemies/enemy_"
# define MELON_PATH			"./images/bonus/melon/melon_"

# define IWR "./images/bonus/wall/iwr.xpm"
# define IWL "./images/bonus/wall/iwl.xpm"
# define IWU "./images/bonus/wall/iwu.xpm"
# define IWD "./images/bonus/wall/iwd.xpm"
# define IWUR "./images/bonus/wall/iwur.xpm"
# define IWUL "./images/bonus/wall/iwul.xpm"
# define IWDR "./images/bonus/wall/iwdr.xpm"
# define IWDL "./images/bonus/wall/iwdl.xpm"
# define IWC "./images/bonus/wall/iwc.xpm"

typedef enum s_wall_pos
{
	WR,
	WL,
	WU,
	WD,
	WUR,
	WUL,
	WDR,
	WDL,
	WC
}	t_wall;

typedef enum e_direction
{
	MVDOWN = 0,
	MVUP = 1,
	MVRIGHT = 2,
	MVLEFT = 3
}	t_direction;

typedef enum e_type
{
	FLOOR = '0',
	WALL = '1',
	COL = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	DOOR = 'D',
	ENEMY = 'M'
}		t_type;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
}			t_point;

typedef struct s_sprite
{
	t_img	*frames;
	int		nframes;
}				t_sprite;

typedef struct s_entity
{
	int			frame;
	int			frame_freq;
	int			curr_freq;
	int			move_counter;
	int			move_freq;
	int			animate_speed;
	int			curr_speed;
	t_type		type;
	t_direction	dir;
	t_point		pos;
	t_point		next;
}				t_entity;

#endif
