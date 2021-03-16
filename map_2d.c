/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 00:52:39 by abelarif          #+#    #+#             */
/*   Updated: 2021/02/18 16:39:32 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void		get_position(int y_max, int x_max)
{
	int			x;
	int			y;
	int			count;

	count = 0;
	y = -1;
	while (++y < y_max)
	{
		x = -1;
		while (++x < x_max)
		{
			if (ft_isalpha(g_map[y][x]))
			{
				count++;
				g_player.x = x * 64 + 32;
				g_player.y = y * 64 + 32;
			}
		}
	}
	if (count == 0)
		ft_error("No player");
	if (count > 1)
		ft_error("Map must contain one player");
}

void		malloc_sprite(void)
{
	if (SP != NULL)
		free(SP);
	if (!(SP = my_malloc(sizeof(t_sprite) * 10000)))
		ft_error("malloc");
	g_nb_sprite = 0;
}

void		init_text(void)
{
	TXT4.img = mlx_xpm_file_to_image(
		g_mlx.mlx, DATA.no_txt,
		&TXT1.resl[0], &TXT1.resl[1]);
	TXT3.img = mlx_xpm_file_to_image(
		g_mlx.mlx, DATA.so_txt,
		&TXT1.resl[0], &TXT1.resl[1]);
	TXT2.img = mlx_xpm_file_to_image(
		g_mlx.mlx, DATA.we_txt,
		&TXT1.resl[0], &TXT1.resl[1]);
	TXT1.img = mlx_xpm_file_to_image(
		g_mlx.mlx, DATA.ea_txt,
		&TXT1.resl[0], &TXT1.resl[1]);
	TXTS.img = mlx_xpm_file_to_image(
		g_mlx.mlx, DATA.sp_txt,
		&TXTS.resl[0], &TXTS.resl[1]);
	if (!TXT1.img || !TXT2.img || !TXT3.img || !TXT4.img || !TXTS.img)
		ft_error("TEXTURE");
	TXT1.addr = mlx_get_data_addr(TXT1.img, &TXT1.bpp, &TXT1.len, &TXT1.endian);
	TXT2.addr = mlx_get_data_addr(TXT2.img, &TXT2.bpp, &TXT2.len, &TXT2.endian);
	TXT3.addr = mlx_get_data_addr(TXT3.img, &TXT3.bpp, &TXT3.len, &TXT3.endian);
	TXT4.addr = mlx_get_data_addr(TXT4.img, &TXT4.bpp, &TXT4.len, &TXT4.endian);
	TXTS.addr = mlx_get_data_addr(TXTS.img, &TXTS.bpp, &TXTS.len, &TXTS.endian);
}

void		cub3d(int g_nb_line, int g_max_len)
{
	if (!(g_wall_distances = my_malloc(sizeof(float) * DATA.resolution[0])))
		ft_error("malloc");
	if (!(g_wall_pix = my_malloc(sizeof(float) * DATA.resolution[0])))
		ft_error("malloc");
	if (g_data.save)
		ft_save();
	g_mlx.win = mlx_new_window(g_mlx.mlx,
	DATA.resolution[0], DATA.resolution[1], "CUB3D");
	get_position(g_nb_line, g_max_len);
	g_img.img = mlx_new_image(g_mlx.mlx,
	DATA.resolution[0], DATA.resolution[1]);
	g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bpp,
								&g_img.len, &g_img.endian);
	malloc_sprite();
	ft_cast_rays();
	mlx_key_hook(g_mlx.win, ft_key, (void*)0);
	mlx_hook(g_mlx.win, 2, 1L << 0, ft_key, (void*)0);
	mlx_hook(g_mlx.win, 3, 1L << 0, ft_key, (void*)0);
	mlx_hook(g_mlx.win, 17, 0L, ft_exit, (void*)0);
	mlx_loop(g_mlx.mlx);
}
