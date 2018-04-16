/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pngtex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:32:28 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 18:25:58 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static int			init_png(char *filename, png_structp *png_ptr,
						png_infop *info_ptr)
{
	unsigned char	header[8];
	FILE			*file;

	if (!(file = fopen(filename, "r")) || (read(file->_file, header, 8)) != 8
		|| !png_check_sig(header, 8))
		return (1);
	if (!(*png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING,
			NULL, NULL, NULL)))
		return (1);
	if (!(*info_ptr = png_create_info_struct(*png_ptr)))
	{
		png_destroy_read_struct(png_ptr, NULL, NULL);
		return (1);
	}
	if (setjmp(png_jmpbuf(*png_ptr)))
	{
		png_destroy_read_struct(png_ptr, info_ptr, NULL);
		return (1);
	}
	png_init_io(*png_ptr, file);
	png_set_sig_bytes(*png_ptr, 8);
	png_read_png(*png_ptr, *info_ptr, 0, NULL);
	fclose(file);
	return (0);
}

static t_pngtex		*get_texture(png_structp png_ptr, png_infop info_ptr)
{
	t_pngtex		*pngtex;
	png_bytepp		rows;
	int				i;

	if (!(pngtex = (t_pngtex *)malloc(sizeof(t_pngtex))))
		return (NULL);
	if (!(rows = png_get_rows(png_ptr, info_ptr)))
		return (NULL);
	png_get_IHDR(png_ptr, info_ptr, &pngtex->width, &pngtex->height,
		&pngtex->bit_depth, &pngtex->color_type, NULL, NULL, NULL);
	if (pngtex->bit_depth != 8)
		return (NULL);
	printf("Width: %d; Height: %d; Bit depth: %d\n", pngtex->width,
		pngtex->height, pngtex->bit_depth);
	if (!(pngtex->data = (unsigned char *)malloc(
			sizeof(unsigned char) * (pngtex->width * pngtex->height * 4))))
		return (NULL);
	i = -1;
	while ((unsigned int)++i < pngtex->width * pngtex->height * 4)
		pngtex->data[i] =
			rows[i / (pngtex->width * 4)][i % (pngtex->width * 4)];
	return (pngtex);
}

static void			uninit_png(png_structp *png_ptr, png_infop *info_ptr)
{
	png_destroy_read_struct(png_ptr, info_ptr, NULL);
}

t_pngtex			*pngtex_from_file(char *filename)
{
	png_structp		png_ptr;
	png_infop		info_ptr;
	t_pngtex		*pngtex;

	if (init_png(filename, &png_ptr, &info_ptr))
		return (NULL);
	if (!(pngtex = get_texture(png_ptr, info_ptr)))
	{
		uninit_png(&png_ptr, &info_ptr);
		return (NULL);
	}
	uninit_png(&png_ptr, &info_ptr);
	return (pngtex);
}
