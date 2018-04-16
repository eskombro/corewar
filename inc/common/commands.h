/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 20:15:45 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 19:15:01 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "libft.h"
# include <unistd.h>

# define MAX_COMMAND_DATA_SIZE 4096

typedef struct					s_command
{
	unsigned char				type;
	unsigned short				size;
	unsigned char				data[MAX_COMMAND_DATA_SIZE];
}								t_command;

# define			COMMAND_CHAMP_SPAWN 0x00
# define			COMMAND_CHAMP_WINS 0x01
# define			COMMAND_INSTR_INIT 0x10
# define			COMMAND_INSTR_EXEC 0x11
# define			COMMAND_LOGIC_CYCLE 0x20
# define			COMMAND_LOGIC_LIVE 0x21
# define			COMMAND_MEM_WRITE 0x30
# define			COMMAND_PROC_SPAWN 0x40
# define			COMMAND_PROC_MOVE 0x41
# define			COMMAND_PROC_DEATH 0x42
# define			COMMAND_CORE_BEGIN 0xfe
# define			COMMAND_CORE_END 0xff

void				send_command(t_command command);

int					write_int(unsigned char *buf, int val);
int					write_char(unsigned char *buf, char val);
int					write_short(unsigned char *buf, short val);
int					write_str(unsigned char *buf, char const *val);
int					write_buf(unsigned char *buf, char const *val, int size);

short				read_short(unsigned char *buf);
int					read_int(unsigned char *buf);
char				*read_str(unsigned char *buf, unsigned int size);

#endif
