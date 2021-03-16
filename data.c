/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 12:48:01 by abelarif          #+#    #+#             */
/*   Updated: 2021/02/18 16:34:37 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float		deg(float x)
{
	return ((180 / PI) * x);
}

int			get_txt(char **content)
{
	int		index;

	index = 0;
	if (!ft_strncmp(content[0], "NO", max_of(ft_strlen(content[0]), 2)))
		index = 1;
	else if (!ft_strncmp(content[0], "SO", max_of(ft_strlen(content[0]), 2)))
		index = 2;
	else if (!ft_strncmp(content[0], "WE", max_of(ft_strlen(content[0]), 2)))
		index = 3;
	else if (!ft_strncmp(content[0], "EA", max_of(ft_strlen(content[0]), 2)))
		index = 4;
	else if (!ft_strncmp(content[0], "S", max_of(ft_strlen(content[0]), 2)))
		index = 5;
	else if (!ft_strncmp(content[0], "F", max_of(ft_strlen(content[0]), 1)))
		index = 6;
	else if (!ft_strncmp(content[0], "C", max_of(ft_strlen(content[0]), 1)))
		index = 7;
	else
		ft_error("Invalid identifier");
	return (get_path(index, content[1]));
}

void		check_comma(char *line)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	if (line[0] == 'F' || line[0] == 'C')
	{
		while (line[++i])
			if (line[i] == ',')
				nb++;
		if (nb != 2)
			ft_error("RGB value nust content 2 commas");
	}
}

void		get_player_angle(char orientation, int x, int y)
{
	if (P.angle)
		ft_error("Map must contain one player");
	g_player.x = x;
	g_player.y = y;
	if (orientation == 'N')
		P.angle = -(PI / 2);
	else if (orientation == 'S')
		P.angle = PI / 2;
	else if (orientation == 'E')
		P.angle = 0;
	else if (orientation == 'W')
		P.angle = PI;
}

void		ft_data(int fd)
{
	static int		nb = 0;
	char			*line;
	int				r;

	r = 1;
	ft_init();
	while (r && nb < 8)
	{
		if ((r = get_next_line(fd, &line)) < 0)
			ft_error("GNL");
		if (skip_line(line) == 0)
		{
			check_comma(line);
			if (manip_line(line) == 1)
				nb++;
		}
		free(line);
	}
}
