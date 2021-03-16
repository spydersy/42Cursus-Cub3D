/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 10:03:00 by abelarif          #+#    #+#             */
/*   Updated: 2021/02/18 16:41:29 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_exit(int key, void *args)
{
	(void)key;
	(void)args;
	exit(EXIT_SUCCESS);
}

void		ft_move_v(int direction)
{
	get_new_position(
	(g_player.x + (direction * -1) * cosf(P.angle) * 100000000),
	(g_player.y + (direction * -1) * sinf(P.angle) * 100000000), 40);
}

void		ft_move_h(int direction)
{
	get_new_position(
	(g_player.x + (direction) * cosf(P.angle + PI / 2) * 100000000),
	(g_player.y + (direction) * sinf(P.angle + PI / 2) * 100000000), 18);
}

void		ft_new_frame(int key)
{
	mlx_destroy_image(g_mlx.mlx, g_img.img);
	g_img.img = mlx_new_image(g_mlx.mlx,
	DATA.resolution[0], DATA.resolution[1]);
	g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bpp,
								&g_img.len, &g_img.endian);
	if (key == L_KEY)
		P.angle = P.angle - PI / 80;
	if (key == R_KEY)
		P.angle = P.angle + PI / 80;
	if (key == W_KEY)
		ft_move_v(-1);
	if (key == S_KEY)
		ft_move_v(1);
	if (key == A_KEY)
		ft_move_h(-1);
	if (key == D_KEY)
		ft_move_h(1);
	if (key == L_KEY || key == R_KEY)
		P.angle = normalize(P.angle);
}

int			ft_key(int key, void *args)
{
	if (key == E_KEY)
	{
		exit(EXIT_SUCCESS);
	}
	else if (key == L_KEY || key == R_KEY || key == A_KEY || key == D_KEY
	|| key == W_KEY || key == S_KEY || args)
	{
		ft_new_frame(key);
		P.angle = normalize(P.angle);
	}
	malloc_sprite();
	return (ft_cast_rays());
}
