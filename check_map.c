/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 09:36:05 by abelarif          #+#    #+#             */
/*   Updated: 2021/02/13 20:15:15 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		bad_char(const char *line, int i)
{
	if (!(line[i] == '1' || line[i] == '0' || line[i] == '2'
	|| line[i] == 'N' || line[i] == 'E' || line[i] == 'S'
	|| line[i] == 'W' || line[i] == ' '))
		ft_error("Invalid character");
}

void		check_horizontal(int x, int y, int y_max)
{
	if (y == 0)
		ft_error("Map must be closed");
	else if (y == y_max - 1)
		ft_error("Map must be closed");
	else if (g_map[y - 1][x] != '0' && g_map[y - 1][x] != '1'
	&& g_map[y - 1][x] != '2' && g_map[y - 1][x] != 'N'
	&& g_map[y - 1][x] != 'E' && g_map[y - 1][x] != 'S'
	&& g_map[y - 1][x] != 'W')
		ft_error("Map must be closed");
	else if (g_map[y + 1][x] != '0' && g_map[y + 1][x] != '1'
	&& g_map[y + 1][x] != '2' && g_map[y + 1][x] != 'N'
	&& g_map[y + 1][x] != 'E' && g_map[y + 1][x] != 'S'
	&& g_map[y + 1][x] != 'W')
		ft_error("Map must be closed");
}

void		horizontal_map(int y_max)
{
	int		y;
	int		i;
	int		x;
	char	*check_char;

	y = -1;
	check_char = "02ENSW";
	while (g_map[++y])
	{
		x = -1;
		while (++x < (int)ft_strlen(g_map[y]))
		{
			i = -1;
			while (++i != 6)
			{
				if (check_char[i] == g_map[y][x])
					check_horizontal(x, y, y_max);
				if (g_map[y][x] == '2')
					g_nb_sprite++;
			}
		}
	}
}

void		bef_aft(char check_char, const char *line, int g_nb_line, int i)
{
	if (check_char == 'N' || check_char == 'S'
	|| check_char == 'E' || check_char == 'W')
		get_player_angle(check_char, i, g_nb_line);
	if (i == 0 || i == (int)ft_strlen(line) - 1)
		ft_error("Map must be closed");
	else if (line[i - 1] == ' ')
		ft_error("Map must be closed");
	else if (line[i + 1]
	&& (line[i + 1] == ' '))
		ft_error("Map must be closed");
}

void		check_line(const char *line, int g_nb_line)
{
	int				i;
	int				j;
	const char		*check_char = "02NSEW";

	i = -1;
	while (line[++i])
	{
		j = -1;
		while (check_char[++j])
		{
			bad_char(line, i);
			if (check_char[j] == line[i])
			{
				bef_aft(check_char[j], line, g_nb_line, i);
			}
		}
	}
}
