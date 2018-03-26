/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:44:19 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/25 05:12:53 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		error_msg(char cse)
{
	if (cse == 1)
		ft_printf("%rgb%s%0rgb",0xff0000, "Error while opening the champ\n");
	if (cse == 2)
		ft_printf("%rgb%s%0rgb",0xff0000, "Bad file descriptor\n");
	if (cse == 3)
		ft_printf("%rgb%s%0rgb",0xff0000, "Error while reading the champ\n");
	if (cse == 4)
		ft_printf("%rgb%s%0rgb",0xff0000, "Champ magic number is wrong\n");
	if (cse == 5)
		ft_printf("%rgb%s%0rgb",0xff0000, "Champ name is too long or \
delimiter (empty int) between name and comment is absent\n");
	if (cse == 6)
		ft_printf("%rgb%s%0rgb",0xff0000, "Indicated champ size is too high\n");
	if (cse == 7)
		ft_printf("%rgb%s%0rgb",0xff0000, "Champ comment was too long or \
delimiter (empty int) between comment and champ was absent\n");
	if (cse == 8)
		ft_printf("%rgb%s%0rgb",0xff0000, "Champ is shorter than the indicated \
size\n");
	if (cse == 9)
		ft_printf("%rgb%s%0rgb",0xff0000, "Champ is longer than the indicated \
size\n");
	return (0);
}

int		error_msg_instr(char cse, int nbr)
{
	if (cse == 1)
		ft_printf("%rgbOpcode on instruction %d %s%0rgb",0xff0000, nbr
				,"is incorrect\n");
	if (cse == 2)
		ft_printf("%rgb%s on instruction %d\n%0rgb",0xff0000, "OPC is absent",
				nbr);
	if (cse == 3)
		ft_printf("%rgb%s on instruction %d\n%0rgb",0xff0000, "OPC is incorrect"
				, nbr);
	if (cse == 4)
		ft_printf("%rgb%s on instruction %d\n%0rgb",0xff0000, "Parameter is invalid"
				, nbr);

	return (0);
}
