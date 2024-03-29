/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 00:40:48 by abelarif          #+#    #+#             */
/*   Updated: 2021/02/18 16:39:40 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_resolution(char **content)
{
	if (ft_strlen(content[0]) != 1)
		ft_error("Invalid identifier");
	if (ft_strncmp("R", content[0], 1))
		ft_error("Invalid identifier");
	if (all_digit(content[1]) && all_digit(content[2]) && DATA.nb[0] == 0)
	{
		DATA.nb[0] = 1;
		DATA.resolution[0] = ft_atoi(content[1]);
		DATA.resolution[1] = ft_atoi(content[2]);
		if (!DATA.resolution[0] || !DATA.resolution[1])
			ft_error("resolution value");
		return (1);
	}
	else if (DATA.nb[0] == 1)
	{
		ft_error("Resolution : double inclusion");
		return (1);
	}
	else
		ft_error("Resolution value");
	return (0);
}

void	get_cl(int r, int g, int b)
{
	DATA.ce_color[0] = r;
	DATA.ce_color[1] = g;
	DATA.ce_color[2] = b;
}

void	get_fl(int r, int g, int b)
{
	DATA.fl_color[0] = r;
	DATA.fl_color[1] = g;
	DATA.fl_color[2] = b;
}

int		get_rgb(int index, const char *str)
{
	char	**rgb;
	int		nb;

	nb = 0;
	rgb = ft_split(str, ',');
	while (rgb[nb])
		nb++;
	if (nb != 3)
		ft_error("RGB");
	if (!(all_digit(rgb[0]) && all_digit(rgb[1]) && all_digit(rgb[2])))
		ft_error("RGB");
	if (index == 6)
		get_cl(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	else
		get_fl(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	DATA.nb[index] = 1;
	nb = -1;
	while (++nb <= 3)
		free(rgb[nb]);
	free(rgb);
	return (1);
}

int		get_path(int index, const char *str)
{
	if (DATA.nb[index] != 0)
	{
		if (1 <= index && index <= 5)
			ft_error("Texture : double inclusion");
		else
			ft_error("RGB  : double inclusion");
	}
	else if (index == 1 && DATA.nb[1] == 0)
		DATA.no_txt = ft_strdup(str);
	else if (index == 2 && DATA.nb[2] == 0)
		DATA.so_txt = ft_strdup(str);
	else if (index == 3 && DATA.nb[3] == 0)
		DATA.we_txt = ft_strdup(str);
	else if (index == 4 && DATA.nb[4] == 0)
		DATA.ea_txt = ft_strdup(str);
	else if (index == 5 && DATA.nb[5] == 0)
		DATA.sp_txt = ft_strdup(str);
	else if (index == 6 && DATA.nb[6] == 0)
		return (get_rgb(index, str));
	else if (index == 7 && DATA.nb[7] == 0)
		return (get_rgb(index, str));
	else
		ft_error("Texture exist");
	DATA.nb[index] = 1;
	return (1);
}
