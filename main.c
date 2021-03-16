/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:12:35 by abelarif          #+#    #+#             */
/*   Updated: 2021/02/18 16:02:50 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		max_of(int i, int j)
{
	return ((i < j) ? (j) : (i));
}

int		min_of(int i, int j)
{
	return ((i > j) ? (j) : (i));
}

void	ft_error(char *str)
{
	ft_putstr_fd("\x1B[31m", 2);
	ft_putstr_fd("Error\n", 2);
	if (str == NULL)
		strerror(errno);
	else
	{
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\n', 2);
	}
	exit(EXIT_FAILURE);
}

int		check_args_errors(int argc, char *argv[])
{
	int		fd;

	if (argc == 3)
		DATA.save = 1;
	if (argc < 2 || argc > 3)
		ft_error("nb Args");
	if (ft_strlen(argv[argc - 2]) < 4)
		ft_error("len Arg");
	if (argc == 3 && ft_strncmp(".cub", argv[1] + ft_strlen(argv[1]) - 4, 4))
		ft_error("cpm Args");
	if (ft_strlen(argv[1]) <= 4)
		ft_error("Invalid .cub file");
	if (argc == 3 &&
	ft_strncmp("--save", argv[2], max_of(6, ft_strlen(argv[1]))))
		ft_error("arg Save");
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error("Read file");
	return (fd);
}

int		main(int argc, char *argv[])
{
	int		fd;
	int		i;

	DATA.save = 0;
	g_nb_sprite = 0;
	g_memory = NULL;
	fd = check_args_errors(argc, argv);
	g_mlx.mlx = mlx_init();
	ft_data(fd);
	DATA.resolution[0] = ((DATA.resolution[0] >= 2560)
						? (2560) : (DATA.resolution[0]));
	DATA.resolution[1] = ((DATA.resolution[1] >= 1440)
						? (1440) : (DATA.resolution[1]));
	i = -1;
	while (++i < 3)
		if (!(0 <= DATA.ce_color[i] && DATA.ce_color[i] <= 255))
			ft_error("RGB VALUE");
	i = -1;
	while (++i < 3)
		if (!(0 <= DATA.fl_color[i] && DATA.fl_color[i] <= 255))
			ft_error("RGB VALUE");
	init_text();
	ft_map(fd);
	return (0);
}
