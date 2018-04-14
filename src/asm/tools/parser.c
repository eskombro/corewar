/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:44:19 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/14 23:10:59 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

int		error_msg(char cse)
{
	if (cse == 1)
		ft_dprintf(2, "%rgb%s%0rgb", RED, "Error while opening the champ\n");
	if (cse == 2)
		ft_dprintf(2, "%rgb%s%0rgb", RED, "Bad file descriptor\n");
	if (cse == 3)
		ft_dprintf(2, "%rgb%s%0rgb", RED, "Error while reading the champ\n");
	if (cse == 4)
		ft_dprintf(2, "%rgb%s%0rgb", RED, "Champ magic number is wrong\n");
	if (cse == 5)
		ft_dprintf(2, "%rgb%s%0rgb", RED, "Champ name is too long or \
delimiter (empty int) between name and comment is absent\n");
	if (cse == 6)
		ft_dprintf(2, "%rgb%s%0rgb", RED, "Indicated champ size is too high\n");
	if (cse == 7)
		ft_dprintf(2, "%rgb%s%0rgb", RED, "Champ comment was too long or \
delimiter (empty int) between comment and champ was absent\n");
	if (cse == 8)
		ft_dprintf(2, "%rgb%s%0rgb", RED, "Champ is shorter than the indicated \
size\n");
	if (cse == 9)
		ft_dprintf(2, "%rgb%s%0rgb", RED, "Champ is longer than the indicated \
size\n");
	return (0);
}

int		error_msg_instr(char cse, int nbr)
{
	if (cse == 1)
		ft_dprintf(2, "%rgbOpcode on instruction %d %s%0rgb", RED, nbr
				, "is incorrect\n");
	if (cse == 2)
		ft_dprintf(2, "%rgb%s on instruction %d\n%0rgb", RED, "OPC is absent",
				nbr);
	if (cse == 3)
		ft_dprintf(2, "%rgb%s on instruction %d\n%0rgb", RED, "OPC is incorrect"
				, nbr);
	if (cse == 4)
		ft_dprintf(2, "%rgb%s on instruction %d\n%0rgb", RED, "Parameter is \
invalid" , nbr);
	if (cse == 5)
		ft_dprintf(2, "%rgb%s %d is invalid to open\n%0rgb", RED, "Parameter"
				, nbr);
	if (cse == 6)
		ft_dprintf(2, "%rgbParameter %d is neither a .s or .cor file\n%0rgb",
				RED, nbr);
	return (0);
}

int		error_msg_asm(char cse, int nb)
{
	if (cse == 1)
		ft_dprintf(2, "%rgb%s%0rgb", RED, "Name format is incorrect\n");
	if (cse == 2)
		ft_dprintf(2, "%rgb%s%0rgb", RED, "New line before name\n");
	if (cse == 3)
		ft_dprintf(2, "%rgb%s : %c got no quotes mark\n%0rgb", RED,
				"Unexpected character", (char)nb);
	if (cse == 4)
		ft_dprintf(2, "%rgb%s%0rgb", RED, "File empty after name identifier\n");
	if (cse == 5)
		ft_dprintf(2, "%rgb%s%0rgb", RED, "Name is too long\n");
	if (cse == 6)
		ft_dprintf(2, "%rgb%s %c\n%0rgb", RED, "Unexpected character :", nb);
	if (cse == 7)
		ft_dprintf(2, "%rgb%s%0rgb", RED, "No newline between name/comment\n");
	if (cse == 8)
		ft_dprintf(2, "%rgb%s%0rgb", RED, "Comment format is incorrect\n");
	if (cse == 9)
		ft_dprintf(2, "%rgb%s%0rgb", RED, "New line before comment\n");
	if (cse == 11)
		ft_dprintf(2, "%rgb%s%0rgb", RED,
				"File is empty after comment identifier\n");
	if (cse == 12)
		ft_dprintf(2, "%rgb%s%0rgb", RED, "Comment is too long\n");
	return (0);
}

int		error_param(char cse, t_expr *expr, int nb)
{
	if (cse == 1)
		ft_dprintf(2, "%rgbWrong type for parameter %d in expression:\
\n%s\t<- line %d\n%0rgb", RED, nb + 1, expr->expr, expr->line);
	if (cse == 2)
		ft_dprintf(2, "%rgbLabel incorrect or missing in expression: \
\n%s\t<- line %d\n%0rgb", RED, expr->expr, expr->line);
	if (cse == 3)
		ft_dprintf(2, "%rgbParameter is empty in expression or invalid: \
\n%s\t<- line %d\n%0rgb", RED, expr->expr, expr->line);
	if (cse == 4)
		ft_dprintf(2, "%rgbREG_NUMBER is invalid on expression: \
\n%s\t<- line %d\n%0rgb", RED, expr->expr, expr->line);
	return (0);
}

int		error_instr(char cse, int line, char *instr)
{
	if (cse == 1)
		ft_dprintf(2, "%rgbSpace between LABEL_CHAR and label\n%0rgb", RED);
	if (cse == 2)
		ft_dprintf(2, "%rgbUnexpected character on first parameter of expre\
ssion :\n%s\t<- line %d\n%0rgb", RED, instr, line);
	if (cse == 3)
		ft_dprintf(2, "%rgbNumber of SEPARATOR_CHAR did not match the expected \
number of parameters:\n%s\t<- line %d\n%0rgb", RED, instr, line);
	if (cse == 4)
		ft_dprintf(2, "%rgbNumber of written parameter does not match the nu\
mber of actual parameters:\n%s\t<- line %d\n%0rgb", RED, instr, line);
	if (cse == 5)
		ft_dprintf(2, "%rgbUnknown instruction in expression:\n%s\n %0rgb",
				RED, instr);
	if (cse == 6)
		ft_dprintf(2, "%rgbA parameter contains an unexpected cararcter: \
%c\n%0rgb", RED, *instr);
	if (cse == 7)
		ft_dprintf(2, "%rgbLine contains and extra SEPARATOR_CHAR with no \
following parameter.\n%0rgb", RED);
	if (cse == 7)
		ft_dprintf(2, "%rgbBad format in label parameter.\n%0rgb", RED);
	return (0);
	if (cse == 8)
		ft_dprintf(2, "Error on champ %s\n", instr);
}
