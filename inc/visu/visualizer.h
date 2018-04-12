/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:17:19 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/12 21:35:20 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "libft.h"
# include "png.h"
# include "types.h"
# include "commands.h"
# include "sg.h"
# include "sg_commands.h"

# include <unistd.h>
# include <pthread.h>
# include <sched.h>
# include <time.h>

# include <SDL2/SDL.h>

# define ERR_MALLOC 01,"Malloc failed"
# define ERR_SDL_INIT 10,"Couldn't initialize SDL"
# define ERR_SDL_WINDOW 11,"Couldn't initialize SDL Window"
# define ERR_SDL_DISPLAY 12,"Couldn't get display bounds"
# define ERR_SDL_EVENT 13,"Couldn't create user event"
# define ERR_VISU_MEMTEX 20,"Couldnt initialize vm memory texture"

# define ERR_CRITICAL "Error", 1
# define ERR_WARNING "Warning", 0

# define FRAMES_PER_SECOND 60
# define CYCLES_PER_SECOND 1000

# define COREWAR_FONT "fonts/TheLightFont.ttf"
# define VM_MEMTEX "tex/mem_hex.png"
# define COREWAR_TOP_FONT_SIZE 30

# define COREWAR_EVENT_COMMAND 0

typedef struct timespec	t_time;

typedef	struct		s_pngtex
{
	png_uint_32		width;
	png_uint_32		height;
	int				bit_depth;
	int				color_type;
	unsigned char	*data;
}					t_pngtex;

typedef struct		s_mem_grid
{
	void			*frame;
}					t_mem_grid;

# define MAIN_SCENE_TOP_HEIGHT 50
# define MAIN_SCENE_BOTTOM_HEIGHT 100

# define MAIN_SCENE_MARGIN 20
# define MAIN_SCENE_CORNER_RADIUS 7
# define MAIN_SCENE_EDGE 1

typedef struct		s_main_scene
{
	void			*ptr;
	void			*top_frame;
	void			*title_label;
	t_mem_grid		mem_grid;
}					t_main_scene;

typedef struct		s_end_scene
{
	void			*ptr;
	void			*heckyeah;
	void			*msg;
	void			*vs;
	void			*score_1;
	void			*score_2;
	void			*popup;
	void			*background;
}					t_end_scene;

typedef union		u_scene
{
	void			*ptr;
	t_main_scene	main;
	t_end_scene		end;
}					t_scene;

typedef struct		s_color_set
{
	t_color			background;
	t_color			main_text;
	t_color			display_edge;
	t_color			display_grid_00;
	t_color			display_p1;
	t_color			display_p2;
	t_color			display_p3;
	t_color			display_p4;
	t_color			button_hover;
	t_color			button_pressed;
}					t_color_set;

# define COREWAR_SCENES_AMOUNT 2

# define COREWAR_SCENE_MAIN 0
# define COREWAR_SCENE_END 1

typedef struct		s_gui
{
	t_color_set		*colors;
	t_scene			*active_scene;
	t_scene			scenes[COREWAR_SCENES_AMOUNT];
	int				pause;
}					t_gui;

# define MEM_ROW 64

typedef struct		s_data
{
	char			content;
	char			writer;
}					t_data;

typedef struct		s_mem
{
	unsigned int	size;
	t_size			size_2d;
	t_data			*data;
	unsigned char	*raw_content;
	float			*raw_front;
	float			*raw_back;
	int				new_data;
}					t_mem;

typedef struct		s_process
{
	int				id;
	int				owner_id;
	int				owner_visu_id;
	int				pc;
}					t_process;

typedef struct		s_player
{
	int				vm_id;
	int				visu_id;
	char			*name;
	int				spawn;
	unsigned char	*champ;
}					t_player;

#define PROCESS_ARRAY_SIZE 10000

typedef struct		s_gamedata
{
	int				cycle;
	int				cycle_to_die;
	int				cycle_left;
}					t_gamedata;

typedef struct		s_visu
{
	int				run;
	pthread_mutex_t	run_mutex;
	SDL_Window		*window;
	SDL_GLContext	context;
	SDL_Rect		max_size;
	t_gui			gui;
	int				win_w;
	int				win_h;
	int				tps;
	t_mem			mem;
	t_gamedata		game;
	t_llist			*players;
	t_llist			*process[PROCESS_ARRAY_SIZE];
}					t_visu;

/*
** PNG tex
*/
t_pngtex			*pngtex_from_file(char *filename);

void				debug_command(t_command command);
pthread_t			run_read(t_visu *visu);
void				run_visu(t_visu *visu);

int					run_events(t_visu *visu);
unsigned int		get_user_event(void);
void				push_user_event(int code, void *data1, void *data2);

void				run_gui(t_visu *visu);
void				init_gui(t_visu *visu);
void				uninit_gui(t_visu *visu);
void				set_color_set(t_visu *visu, int set);

void				error(int errcode, char const *const errmsg, char *errtype,
						int errexit);

void				*create_display(void *scene, t_visu *visu);
void				set_display_ocolor(void *component, t_color color);
void				set_display_grid_color(void *component, t_color color);
void				set_display_edge(void *component, int edge);
void				set_display_player_color(int n, void *component,
						t_color color);

#endif
