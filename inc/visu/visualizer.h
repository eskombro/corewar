/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:17:19 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/07 01:14:17 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "libft.h"
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

# define ERR_CRITICAL "Error", 1
# define ERR_WARNING "Warning", 0

# define FRAME_PER_SECOND 60

# define COREWAR_FONT "fonts/TheLightFont.ttf"
# define COREWAR_TOP_FONT_SIZE 30

# define COREWAR_EVENT_COMMAND 0

typedef struct timespec	t_time;

typedef struct		s_main_scene
{
	void			*ptr;
	void			*top_frame;
	void			*title_label;
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
	t_color			display_grid;
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
}					t_visu;

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
#endif
