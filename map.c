/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:04:54 by abelarif          #+#    #+#             */
/*   Updated: 2021/02/18 16:39:26 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			skip_void(int fd)
{
	char		*line;
	int			r;

	r = 1;
	while ((r = get_next_line(fd, &line)))
	{
		if (skip_line(line) == 0)
		{
			check_line(line, 1);
			g_list = NULL;
			g_list = insertion(g_list, line);
			r = ft_strlen(line);
			return (r);
		}
		free(line);
	}
	if (r == 0)
		ft_error("No Map");
	return (0);
}

size_t		my_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t size_src;

	i = 0;
	if (!src)
		return (0);
	size_src = ft_strlen(src);
	if (size > 0)
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (size_src);
}

void		ft_move(int g_nb_line, int g_max_len)
{
	int			i;
	t_list		*tmp;

	g_nb_line--;
	tmp = g_list;
	while (g_list)
	{
		my_strlcpy(g_map[g_nb_line], g_list->str, ft_strlen(g_list->str));
		if ((i = ft_strlen(g_list->str)) < g_max_len)
		{
			if (i == 0 && g_nb_line > 0)
				ft_error("Empty line");
			while (i < g_max_len)
			{
				g_map[g_nb_line][i] = ' ';
				i++;
			}
			g_map[g_nb_line][i] = '\0';
		}
		g_list = g_list->next;
		g_nb_line--;
	}
	free(tmp);
}

void		map_2d(int g_nb_line, int g_max_len)
{
	int		i;

	i = 0;
	if ((g_map = my_malloc(sizeof(char *) * (g_nb_line + 1))) == 0)
		ft_error("malloc map 1");
	g_map[g_nb_line] = NULL;
	while (i < g_nb_line)
	{
		if ((g_map[i] = my_malloc(sizeof(char) * (g_max_len + 1))) == 0)
			ft_error("malloc map 2");
		i++;
	}
	ft_move(g_nb_line, g_max_len);
	horizontal_map(g_nb_line);
	cub3d(g_nb_line, g_max_len);
}

void		ft_map(int fd)
{
	int				r;
	char			*line;

	r = 1;
	g_nb_line = 0;
	g_max_len = skip_void(fd);
	g_nb_line++;
	while ((r = get_next_line(fd, &line)) > 0)
	{
		g_nb_line++;
		g_list = insertion(g_list, line);
		g_max_len = (g_max_len < (int)ft_strlen(line)
		? ((int)ft_strlen(line)) : (g_max_len));
		if (skip_line(line) == 0)
			check_line(line, g_max_len);
	}
	g_nb_line++;
	check_line(line, g_nb_line);
	g_list = insertion(g_list, line);
	map_2d(g_nb_line, g_max_len);
}
