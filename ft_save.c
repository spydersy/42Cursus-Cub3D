/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 08:54:53 by abelarif          #+#    #+#             */
/*   Updated: 2021/01/28 21:02:26 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			file_header(int fd)
{
	int	file_size;
	int	pixel_data_offset;

	pixel_data_offset = 54;
	file_size = pixel_data_offset + DATA.resolution[0] * DATA.resolution[1] * 4;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &pixel_data_offset, 4);
}

void			image_header(int fd)
{
	int	header_size;
	int	plane;
	int	image_size;

	header_size = 40;
	plane = 1;
	image_size = DATA.resolution[0] * DATA.resolution[1];
	write(fd, &header_size, 4);
	write(fd, &DATA.resolution[0], 4);
	write(fd, &DATA.resolution[1], 4);
	write(fd, &plane, 2);
	write(fd, &g_img.bpp, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &image_size, 4);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
}

void			fill_bitmap(int fd)
{
	int	x;
	int y;
	int	r;
	int	g;
	int	b;

	y = DATA.resolution[1] - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < DATA.resolution[0])
		{
			r = g_img.addr[y * g_img.len + x * g_img.bpp / 8];
			g = g_img.addr[y * g_img.len + x * g_img.bpp / 8 + 1];
			b = g_img.addr[y * g_img.len + x * g_img.bpp / 8 + 2];
			write(fd, &r, 1);
			write(fd, &g, 1);
			write(fd, &b, 1);
			write(fd, "\0", 1);
			x++;
		}
		y--;
	}
}

void			ft_save(void)
{
	int			fd;

	if ((fd = open("screenshot.bmp", O_CREAT | O_RDWR)) < 0)
		ft_error("Cant create the bitmap file");
	get_position(g_nb_line, g_max_len);
	g_img.img = mlx_new_image(g_mlx.mlx,
	DATA.resolution[0], DATA.resolution[1]);
	g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bpp,
								&g_img.len, &g_img.endian);
	malloc_sprite();
	ft_cast_rays();
	file_header(fd);
	image_header(fd);
	fill_bitmap(fd);
	close(fd);
	exit(EXIT_SUCCESS);
}
